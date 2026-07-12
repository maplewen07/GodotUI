#if TOOLS
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Loader;

namespace GodotUi.Manifest.Editor;

internal interface IManifestUiAssemblyUnloadParticipant
{
    void PrepareForAssemblyUnload();
}

internal static class ManifestUiAssemblyUnloadRegistry
{
    private static readonly object Sync = new();
    private static readonly List<WeakReference<IManifestUiAssemblyUnloadParticipant>> Participants = new();

    static ManifestUiAssemblyUnloadRegistry()
    {
        var context = AssemblyLoadContext.GetLoadContext(typeof(ManifestUiAssemblyUnloadRegistry).Assembly);
        if (context is not null)
        {
            context.Unloading += OnUnloading;
        }
    }

    public static void Register(IManifestUiAssemblyUnloadParticipant participant)
    {
        lock (Sync)
        {
            Participants.RemoveAll(reference => !reference.TryGetTarget(out _));
            if (!Participants.Any(reference => reference.TryGetTarget(out var target) && ReferenceEquals(target, participant)))
            {
                Participants.Add(new WeakReference<IManifestUiAssemblyUnloadParticipant>(participant));
            }
        }
    }

    public static void Unregister(IManifestUiAssemblyUnloadParticipant participant)
    {
        lock (Sync)
        {
            Participants.RemoveAll(reference =>
                !reference.TryGetTarget(out var target) || ReferenceEquals(target, participant));
        }
    }

    private static void OnUnloading(AssemblyLoadContext context)
    {
        IManifestUiAssemblyUnloadParticipant[] live;
        lock (Sync)
        {
            live = Participants
                .Select(reference => reference.TryGetTarget(out var target) ? target : null)
                .Where(target => target is not null)
                .Cast<IManifestUiAssemblyUnloadParticipant>()
                .ToArray();
            Participants.Clear();
        }

        foreach (var participant in live)
        {
            try
            {
                participant.PrepareForAssemblyUnload();
            }
            catch
            {
                // Assembly unloading must continue even if an editor object was already freed.
            }
        }
    }
}
#endif
