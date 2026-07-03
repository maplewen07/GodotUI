using System;
using System.Collections.Generic;
using Godot;

namespace GodotUi.Manifest;

public partial class ManifestMessageBus : Node
{
    private readonly Dictionary<string, List<Subscription>> _handlers = new();

    public static ManifestMessageBus? Instance { get; private set; }

    public override void _EnterTree()
    {
        Instance = this;
    }

    public override void _ExitTree()
    {
        if (Instance == this)
        {
            Instance = null;
        }
    }

    public IDisposable Subscribe(string channel, Action<object?> handler)
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

        var subscription = new Subscription(this, channel, handler);
        handlers.Add(subscription);
        return subscription;
    }

    public void Unsubscribe(string channel, Action<object?> handler)
    {
        if (_handlers.TryGetValue(channel, out var handlers))
        {
            handlers.RemoveAll(subscription => subscription.Handler == handler);
            if (handlers.Count == 0)
            {
                _handlers.Remove(channel);
            }
        }
    }

    public void Publish(string channel, object? payload = null)
    {
        if (!_handlers.TryGetValue(channel, out var handlers))
        {
            return;
        }

        foreach (var subscription in handlers.ToArray())
        {
            subscription.Handler(payload);
        }
    }

    public void Clear()
    {
        _handlers.Clear();
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
            Handler = handler;
        }

        public string Channel { get; }
        public Action<object?> Handler { get; }

        public void Dispose()
        {
            var owner = _owner;
            if (owner is null)
            {
                return;
            }

            _owner = null;
            owner.Unsubscribe(this);
        }
    }
}
