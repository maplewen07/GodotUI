using System;
using Godot;

namespace GodotUi.Manifest;

public enum ManifestRuntimeDiagnosticSeverity
{
    Info,
    Warning,
    Error,
}

public sealed class ManifestRuntimeDiagnostic
{
    public ManifestRuntimeDiagnostic(
        string code,
        ManifestRuntimeDiagnosticSeverity severity,
        string message,
        Exception? exception = null,
        string packageId = "",
        Guid? instanceId = null)
    {
        Code = code;
        Severity = severity;
        Message = message;
        Exception = exception;
        PackageId = packageId;
        InstanceId = instanceId;
        Timestamp = DateTimeOffset.UtcNow;
    }

    public string Code { get; }
    public ManifestRuntimeDiagnosticSeverity Severity { get; }
    public string Message { get; }
    public Exception? Exception { get; }
    public string PackageId { get; }
    public Guid? InstanceId { get; }
    public DateTimeOffset Timestamp { get; }
}

public static class ManifestRuntimeDiagnostics
{
    public static event Action<ManifestRuntimeDiagnostic>? Emitted;

    public static void Report(
        string code,
        ManifestRuntimeDiagnosticSeverity severity,
        string message,
        Exception? exception = null,
        string packageId = "",
        Guid? instanceId = null)
    {
        var diagnostic = new ManifestRuntimeDiagnostic(code, severity, message, exception, packageId, instanceId);
        var formatted = $"[{code}] {message}";
        if (exception is not null)
        {
            formatted += $" {exception.GetType().Name}: {exception.Message}";
        }

        if (severity == ManifestRuntimeDiagnosticSeverity.Error)
        {
            GD.PushError(formatted);
        }
        else if (severity == ManifestRuntimeDiagnosticSeverity.Warning)
        {
            GD.PushWarning(formatted);
        }
        else
        {
            GD.Print(formatted);
        }

        if (Emitted is null)
        {
            return;
        }

        foreach (Action<ManifestRuntimeDiagnostic> handler in Emitted.GetInvocationList())
        {
            try
            {
                handler(diagnostic);
            }
            catch
            {
                // Diagnostic sinks must never interfere with runtime cleanup.
            }
        }
    }
}
