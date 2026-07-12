using System;
using System.Collections.Generic;
using System.Linq;

namespace GodotUi.Manifest;

public sealed class ViewModelStore
{
    private readonly object _gate = new();
    private readonly Dictionary<string, object?> _values = new(StringComparer.Ordinal);
    private readonly Dictionary<string, long> _fieldRevisions = new(StringComparer.Ordinal);
    private readonly HashSet<string> _dirtyFields = new(StringComparer.Ordinal);
    private readonly HashSet<string> _batchedFields = new(StringComparer.Ordinal);
    private long _revision;
    private int _batchDepth;

    public event EventHandler<ViewModelStoreChangedEventArgs>? Changed;

    public long Revision
    {
        get
        {
            lock (_gate)
            {
                return _revision;
            }
        }
    }

    // Retained for schema-v1 generated code. New consumers should use a cursor.
    public IReadOnlyCollection<string> DirtyFields
    {
        get
        {
            lock (_gate)
            {
                return _dirtyFields.ToArray();
            }
        }
    }

    public void Set<T>(string fieldId, T value)
    {
        Set(fieldId, (object?)value);
    }

    public void Set(string fieldId, object? value)
    {
        ValidateFieldId(fieldId);

        ViewModelStoreChangedEventArgs? change = null;
        lock (_gate)
        {
            if (_values.TryGetValue(fieldId, out var oldValue) && Equals(oldValue, value))
            {
                return;
            }

            _values[fieldId] = value;
            change = RecordChange(fieldId);
        }

        NotifyChanged(change);
    }

    public void Invalidate(string fieldId)
    {
        ValidateFieldId(fieldId);

        ViewModelStoreChangedEventArgs? change;
        lock (_gate)
        {
            change = RecordChange(fieldId);
        }

        NotifyChanged(change);
    }

    public IDisposable BeginBatch()
    {
        lock (_gate)
        {
            _batchDepth++;
        }

        return new BatchScope(this);
    }

    public bool IsDirty(string fieldId)
    {
        lock (_gate)
        {
            return _dirtyFields.Contains(fieldId);
        }
    }

    public bool HasChangedSince(string fieldId, long revision)
    {
        lock (_gate)
        {
            return _fieldRevisions.TryGetValue(fieldId, out var fieldRevision) && fieldRevision > revision;
        }
    }

    public long GetFieldRevision(string fieldId)
    {
        lock (_gate)
        {
            return _fieldRevisions.TryGetValue(fieldId, out var revision) ? revision : 0;
        }
    }

    public bool TryGet(string fieldId, out object? value)
    {
        lock (_gate)
        {
            return _values.TryGetValue(fieldId, out value);
        }
    }

    public bool TryGet<T>(string fieldId, out T? value)
    {
        lock (_gate)
        {
            if (_values.TryGetValue(fieldId, out var stored) && stored is T typed)
            {
                value = typed;
                return true;
            }
        }

        value = default;
        return false;
    }

    public object? Get(string fieldId)
    {
        TryGet(fieldId, out var value);
        return value;
    }

    public T? Get<T>(string fieldId, T? fallback = default)
    {
        return TryGet<T>(fieldId, out var value) ? value : fallback;
    }

    public void MarkAllDirty()
    {
        ViewModelStoreChangedEventArgs? change = null;
        lock (_gate)
        {
            if (_values.Count == 0)
            {
                return;
            }

            foreach (var fieldId in _values.Keys)
            {
                _revision++;
                _fieldRevisions[fieldId] = _revision;
                _dirtyFields.Add(fieldId);
                _batchedFields.Add(fieldId);
            }

            if (_batchDepth == 0)
            {
                change = DrainBatchedChange();
            }
        }

        NotifyChanged(change);
    }

    public void ClearDirty()
    {
        lock (_gate)
        {
            _dirtyFields.Clear();
        }
    }

    public ViewModelStoreCursor CreateCursor()
    {
        return new ViewModelStoreCursor();
    }

    private ViewModelStoreChangedEventArgs? RecordChange(string fieldId)
    {
        _revision++;
        _fieldRevisions[fieldId] = _revision;
        _dirtyFields.Add(fieldId);
        _batchedFields.Add(fieldId);
        return _batchDepth == 0 ? DrainBatchedChange() : null;
    }

    private ViewModelStoreChangedEventArgs DrainBatchedChange()
    {
        var fields = _batchedFields.OrderBy(field => field, StringComparer.Ordinal).ToArray();
        _batchedFields.Clear();
        return new ViewModelStoreChangedEventArgs(_revision, fields);
    }

    private void EndBatch()
    {
        ViewModelStoreChangedEventArgs? change = null;
        lock (_gate)
        {
            if (_batchDepth == 0)
            {
                return;
            }

            _batchDepth--;
            if (_batchDepth == 0 && _batchedFields.Count > 0)
            {
                change = DrainBatchedChange();
            }
        }

        NotifyChanged(change);
    }

    private void NotifyChanged(ViewModelStoreChangedEventArgs? change)
    {
        if (change is null || Changed is null)
        {
            return;
        }

        foreach (EventHandler<ViewModelStoreChangedEventArgs> handler in Changed.GetInvocationList())
        {
            try
            {
                handler(this, change);
            }
            catch (Exception exception)
            {
                ManifestRuntimeDiagnostics.Report(
                    "MUIR1001",
                    ManifestRuntimeDiagnosticSeverity.Error,
                    "A ViewModelStore change subscriber failed.",
                    exception);
            }
        }
    }

    private static void ValidateFieldId(string fieldId)
    {
        if (string.IsNullOrWhiteSpace(fieldId))
        {
            throw new ArgumentException("Field id is required.", nameof(fieldId));
        }
    }

    private sealed class BatchScope : IDisposable
    {
        private ViewModelStore? _store;

        public BatchScope(ViewModelStore store)
        {
            _store = store;
        }

        public void Dispose()
        {
            var store = _store;
            _store = null;
            store?.EndBatch();
        }
    }
}

public sealed class ViewModelStoreChangedEventArgs : EventArgs
{
    public ViewModelStoreChangedEventArgs(long revision, IReadOnlyList<string> fields)
    {
        Revision = revision;
        Fields = fields;
    }

    public long Revision { get; }
    public IReadOnlyList<string> Fields { get; }
}

public sealed class ViewModelStoreCursor
{
    public long Revision { get; private set; }
    public bool IsInitialized { get; private set; }

    public bool ShouldApply(ViewModelStore store, string fieldId, long targetRevision)
    {
        if (!IsInitialized)
        {
            return true;
        }

        var fieldRevision = store.GetFieldRevision(fieldId);
        return fieldRevision > Revision && fieldRevision <= targetRevision;
    }

    public void AdvanceTo(long revision)
    {
        Revision = revision;
        IsInitialized = true;
    }

    public void Reset()
    {
        Revision = 0;
        IsInitialized = false;
    }
}
