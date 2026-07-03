using System.Collections.Generic;

namespace GodotUi.Manifest;

public sealed class ViewModelStore
{
    private readonly Dictionary<string, object?> _values = new();
    private readonly HashSet<string> _dirtyFields = new();

    public IReadOnlyCollection<string> DirtyFields => _dirtyFields;

    public void Set(string fieldId, object? value)
    {
        if (string.IsNullOrWhiteSpace(fieldId))
        {
            throw new System.ArgumentException("Field id is required.", nameof(fieldId));
        }

        if (_values.TryGetValue(fieldId, out var oldValue) && Equals(oldValue, value))
        {
            return;
        }

        _values[fieldId] = value;
        _dirtyFields.Add(fieldId);
    }

    public bool IsDirty(string fieldId)
    {
        return _dirtyFields.Contains(fieldId);
    }

    public bool TryGet(string fieldId, out object? value)
    {
        return _values.TryGetValue(fieldId, out value);
    }

    public object? Get(string fieldId)
    {
        _values.TryGetValue(fieldId, out var value);
        return value;
    }

    public void MarkAllDirty()
    {
        foreach (var fieldId in _values.Keys)
        {
            _dirtyFields.Add(fieldId);
        }
    }

    public void ClearDirty()
    {
        _dirtyFields.Clear();
    }
}
