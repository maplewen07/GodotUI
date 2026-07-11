using System;
using System.Collections.Generic;

namespace GodotUi.Manifest;

public sealed class ManifestServiceRegistry
{
    private readonly object _gate = new();
    private readonly Dictionary<ServiceKey, object> _services = new();

    public void Register<T>(T service, string key = "", bool replace = false) where T : notnull
    {
        Register(typeof(T), service, key, replace);
    }

    public void Register(Type serviceType, object service, string key = "", bool replace = false)
    {
        ArgumentNullException.ThrowIfNull(serviceType);
        ArgumentNullException.ThrowIfNull(service);
        if (!serviceType.IsInstanceOfType(service))
        {
            throw new ArgumentException($"Service instance is not assignable to '{serviceType.FullName}'.", nameof(service));
        }

        var serviceKey = new ServiceKey(serviceType, key ?? string.Empty);
        lock (_gate)
        {
            if (!replace && _services.ContainsKey(serviceKey))
            {
                throw new InvalidOperationException($"Service '{serviceType.FullName}' with key '{key}' is already registered.");
            }

            _services[serviceKey] = service;
        }
    }

    public bool TryResolve<T>(out T? service, string key = "")
    {
        if (TryResolve(typeof(T), out var value, key) && value is T typed)
        {
            service = typed;
            return true;
        }

        service = default;
        return false;
    }

    public bool TryResolve(Type serviceType, out object? service, string key = "")
    {
        ArgumentNullException.ThrowIfNull(serviceType);
        lock (_gate)
        {
            return _services.TryGetValue(new ServiceKey(serviceType, key ?? string.Empty), out service);
        }
    }

    public T Resolve<T>(string key = "")
    {
        if (TryResolve<T>(out var service, key) && service is not null)
        {
            return service;
        }

        throw new InvalidOperationException($"Service '{typeof(T).FullName}' with key '{key}' is not registered.");
    }

    public object Resolve(Type serviceType, string key = "")
    {
        if (TryResolve(serviceType, out var service, key) && service is not null)
        {
            return service;
        }

        throw new InvalidOperationException($"Service '{serviceType.FullName}' with key '{key}' is not registered.");
    }

    public bool Unregister<T>(string key = "")
    {
        lock (_gate)
        {
            return _services.Remove(new ServiceKey(typeof(T), key ?? string.Empty));
        }
    }

    public void Clear()
    {
        lock (_gate)
        {
            _services.Clear();
        }
    }

    private readonly record struct ServiceKey(Type Type, string Key);
}
