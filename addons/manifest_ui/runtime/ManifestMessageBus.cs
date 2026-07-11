using System;
using System.Collections.Generic;
using Godot;

namespace GodotUi.Manifest;

public enum ManifestMessageScope
{
    Global,
    Package,
    Screen,
    Instance,
}

public enum ManifestMessageDelivery
{
    Immediate,
    Deferred,
}

public readonly struct ManifestMessageEnvelope
{
    public ManifestMessageEnvelope(
        StringName channel,
        StringName? eventId = null,
        Variant payload = default,
        ManifestMessageScope scope = ManifestMessageScope.Global,
        StringName? scopeId = null,
        StringName? sender = null,
        ManifestMessageDelivery delivery = ManifestMessageDelivery.Immediate)
    {
        if (string.IsNullOrWhiteSpace(channel.ToString()))
        {
            throw new ArgumentException("Channel is required.", nameof(channel));
        }

        Channel = channel;
        EventId = eventId ?? new StringName();
        Payload = payload;
        Scope = scope;
        ScopeId = scopeId ?? new StringName();
        Sender = sender ?? new StringName();
        Delivery = delivery;
        LegacyPayload = null;
    }

    internal ManifestMessageEnvelope(StringName channel, object? legacyPayload)
        : this(channel, payload: ManifestVariantConversion.FromObject(legacyPayload))
    {
        LegacyPayload = legacyPayload;
    }

    public StringName Channel { get; }
    public StringName EventId { get; }
    public Variant Payload { get; }
    public ManifestMessageScope Scope { get; }
    public StringName ScopeId { get; }
    public StringName Sender { get; }
    public ManifestMessageDelivery Delivery { get; }
    internal object? LegacyPayload { get; }
}

public partial class ManifestMessageBus : Node
{
    private readonly Dictionary<string, List<Subscription>> _handlers = new(StringComparer.Ordinal);
    private readonly Queue<ManifestMessageEnvelope> _deferred = new();

    public static ManifestMessageBus? Instance { get; private set; }

    public int SubscriptionCount
    {
        get
        {
            var count = 0;
            foreach (var subscriptions in _handlers.Values)
            {
                count += subscriptions.Count;
            }

            return count;
        }
    }

    public override void _EnterTree()
    {
        Instance = this;
        SetProcess(false);
    }

    public override void _ExitTree()
    {
        _deferred.Clear();
        if (Instance == this)
        {
            Instance = null;
        }
    }

    public override void _Process(double delta)
    {
        var pending = _deferred.Count;
        for (var i = 0; i < pending; i++)
        {
            Deliver(_deferred.Dequeue());
        }

        if (_deferred.Count == 0)
        {
            SetProcess(false);
        }
    }

    public IDisposable Subscribe(string channel, Action<object?> handler)
    {
        ArgumentNullException.ThrowIfNull(handler);
        return AddSubscription(channel, new Subscription(this, channel, handler));
    }

    public IDisposable SubscribeEnvelope(
        StringName channel,
        Action<ManifestMessageEnvelope> handler,
        ManifestMessageScope? scope = null,
        StringName? scopeId = null)
    {
        ArgumentNullException.ThrowIfNull(handler);
        var channelText = channel.ToString();
        return AddSubscription(channelText, new Subscription(this, channelText, handler, scope, scopeId));
    }

    public void Unsubscribe(string channel, Action<object?> handler)
    {
        if (_handlers.TryGetValue(channel, out var handlers))
        {
            handlers.RemoveAll(subscription => subscription.LegacyHandler == handler);
            if (handlers.Count == 0)
            {
                _handlers.Remove(channel);
            }
        }
    }

    public void Publish(string channel, object? payload = null)
    {
        Publish(new ManifestMessageEnvelope(channel, payload));
    }

    public void Publish(ManifestMessageEnvelope envelope)
    {
        if (envelope.Delivery == ManifestMessageDelivery.Deferred && IsInsideTree())
        {
            _deferred.Enqueue(envelope);
            SetProcess(true);
            return;
        }

        Deliver(envelope);
    }

    public void Publish(
        StringName channel,
        StringName eventId,
        Variant payload = default,
        ManifestMessageScope scope = ManifestMessageScope.Global,
        StringName? scopeId = null,
        StringName? sender = null,
        ManifestMessageDelivery delivery = ManifestMessageDelivery.Immediate)
    {
        Publish(new ManifestMessageEnvelope(channel, eventId, payload, scope, scopeId, sender, delivery));
    }

    public void Clear()
    {
        foreach (var subscriptions in _handlers.Values)
        {
            foreach (var subscription in subscriptions)
            {
                subscription.Invalidate();
            }
        }

        _handlers.Clear();
        _deferred.Clear();
    }

    private IDisposable AddSubscription(string channel, Subscription subscription)
    {
        if (string.IsNullOrWhiteSpace(channel))
        {
            throw new ArgumentException("Channel is required.", nameof(channel));
        }

        if (!_handlers.TryGetValue(channel, out var handlers))
        {
            handlers = new List<Subscription>();
            _handlers[channel] = handlers;
        }

        handlers.Add(subscription);
        return subscription;
    }

    private void Deliver(ManifestMessageEnvelope envelope)
    {
        if (!_handlers.TryGetValue(envelope.Channel.ToString(), out var handlers))
        {
            return;
        }

        foreach (var subscription in handlers.ToArray())
        {
            if (!subscription.Matches(envelope))
            {
                continue;
            }

            try
            {
                subscription.Invoke(envelope);
            }
            catch (Exception exception)
            {
                ManifestRuntimeDiagnostics.Report(
                    "MUIR2001",
                    ManifestRuntimeDiagnosticSeverity.Error,
                    $"A message subscriber on channel '{envelope.Channel}' failed.",
                    exception);
            }
        }
    }

    private void Unsubscribe(Subscription subscription)
    {
        if (!_handlers.TryGetValue(subscription.Channel, out var handlers))
        {
            return;
        }

        handlers.Remove(subscription);
        if (handlers.Count == 0)
        {
            _handlers.Remove(subscription.Channel);
        }
    }

    private sealed class Subscription : IDisposable
    {
        private ManifestMessageBus? _owner;

        public Subscription(ManifestMessageBus owner, string channel, Action<object?> handler)
        {
            _owner = owner;
            Channel = channel;
            LegacyHandler = handler;
            ScopeId = new StringName();
        }

        public Subscription(
            ManifestMessageBus owner,
            string channel,
            Action<ManifestMessageEnvelope> handler,
            ManifestMessageScope? scope,
            StringName? scopeId)
        {
            _owner = owner;
            Channel = channel;
            EnvelopeHandler = handler;
            Scope = scope;
            ScopeId = scopeId ?? new StringName();
        }

        public string Channel { get; }
        public Action<object?>? LegacyHandler { get; }
        public Action<ManifestMessageEnvelope>? EnvelopeHandler { get; }
        public ManifestMessageScope? Scope { get; }
        public StringName ScopeId { get; }

        public bool Matches(ManifestMessageEnvelope envelope)
        {
            if (Scope is { } scope && scope != envelope.Scope)
            {
                return false;
            }

            return string.IsNullOrEmpty(ScopeId.ToString()) || ScopeId == envelope.ScopeId;
        }

        public void Invoke(ManifestMessageEnvelope envelope)
        {
            if (EnvelopeHandler is not null)
            {
                EnvelopeHandler(envelope);
                return;
            }

            LegacyHandler?.Invoke(envelope.LegacyPayload ?? envelope.Payload.Obj);
        }

        public void Dispose()
        {
            var owner = _owner;
            _owner = null;
            owner?.Unsubscribe(this);
        }

        public void Invalidate()
        {
            _owner = null;
        }
    }
}

internal static class ManifestVariantConversion
{
    public static Variant FromObject(object? value)
    {
        return value switch
        {
            null => default,
            bool typed => typed,
            byte typed => typed,
            sbyte typed => typed,
            short typed => typed,
            ushort typed => typed,
            int typed => typed,
            uint typed => typed,
            long typed => typed,
            ulong typed => typed,
            float typed => typed,
            double typed => typed,
            string typed => typed,
            StringName typed => typed,
            NodePath typed => typed,
            Vector2 typed => typed,
            Vector2I typed => typed,
            Vector3 typed => typed,
            Vector3I typed => typed,
            Vector4 typed => typed,
            Vector4I typed => typed,
            Color typed => typed,
            GodotObject typed => typed,
            Godot.Collections.Array typed => typed,
            Godot.Collections.Dictionary typed => typed,
            _ => value.ToString() ?? string.Empty,
        };
    }
}
