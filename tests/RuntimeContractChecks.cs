using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using Godot;
using GodotUi.Manifest;
using GodotUi.Sample.Badge;
using GodotUi.Sample.Phone;
#if TOOLS
using GodotUi.Manifest.Editor;
#endif

namespace GodotUi.Tests;

internal static class RuntimeContractChecks
{
    private const string PhoneScene = "res://generated/ui/phone/PhoneWidget.tscn";
    private const string BadgeScene = "res://generated/ui/badge/BadgeWidget.tscn";
    private const string BasicEnglish = "res://examples/Basic/generated/ui/basic/translations/basic.en.tres";
    private const string BasicChinese = "res://examples/Basic/generated/ui/basic/translations/basic.zh_CN.tres";
    private const string InventoryEnglish = "res://examples/Inventory/generated/ui/inventory/translations/inventory.en.tres";

    public static void CheckStoreAndServices()
    {
        var store = new ViewModelStore();
        var firstCursor = store.CreateCursor();
        var secondCursor = store.CreateCursor();
        var firstRoot = CreateLabelRoot();
        var secondRoot = CreateLabelRoot();
        var bindings = new ManifestBindingSet(new[]
        {
            new ManifestPropertyBinding("Value", "text", "value", fallback: "fallback"),
        });

        ManifestBindingApplier.Apply(firstRoot, store, bindings, firstCursor, store.Revision);
        firstCursor.AdvanceTo(store.Revision);
        Require(firstRoot.GetNode<Label>("Value").Text == "fallback", "initial cursor should apply fallback");

        store.Set("value", "shared");
        var targetRevision = store.Revision;
        ManifestBindingApplier.Apply(firstRoot, store, bindings, firstCursor, targetRevision);
        firstCursor.AdvanceTo(targetRevision);
        ManifestBindingApplier.Apply(secondRoot, store, bindings, secondCursor, targetRevision);
        secondCursor.AdvanceTo(targetRevision);
        Require(firstRoot.GetNode<Label>("Value").Text == "shared", "first cursor should observe update");
        Require(secondRoot.GetNode<Label>("Value").Text == "shared", "second cursor should independently observe update");

        var notificationCount = 0;
        IReadOnlyList<string>? changedFields = null;
        store.Changed += (_, args) =>
        {
            notificationCount++;
            changedFields = args.Fields;
        };
        using (store.BeginBatch())
        {
            store.Set("a", 1);
            store.Set("b", 2);
            store.Invalidate("a");
        }

        Require(notificationCount == 1, "batch should emit one store notification");
        Require(changedFields is not null && changedFields.SequenceEqual(new[] { "a", "b" }), "batch fields should be stable and unique");

        var services = new ManifestServiceRegistry();
        services.Register("primary", "main");
        services.Register("secondary", "secondary");
        Require(services.Resolve<string>("main") == "primary", "keyed service lookup mismatch");
        Require(services.Resolve<string>("secondary") == "secondary", "second keyed service lookup mismatch");

        firstRoot.Free();
        secondRoot.Free();
    }

    public static void CheckScriptedBindingFallback()
    {
        var root = new Control();
        var disabledProbe = new ScriptedBindingProbeControl { Name = "DisabledProbe", Disabled = true };
        var enabledProbe = new ScriptedEnabledBindingProbeControl { Name = "EnabledProbe", Disabled = true };
        var invalidProbe = new ScriptedInvalidBindingProbeControl { Name = "InvalidProbe" };
        root.AddChild(disabledProbe);
        root.AddChild(enabledProbe);
        root.AddChild(invalidProbe);

        var texture = new GradientTexture1D();
        var store = new ViewModelStore();
        store.Set("text", 27);
        store.Set("value", "0.75");
        store.Set("enabled", true);
        store.Set("texture", texture);
        store.Set("invalidText", "not-a-color");
        var bindings = new ManifestBindingSet(new[]
        {
            new ManifestPropertyBinding("DisabledProbe", "text", "text"),
            new ManifestPropertyBinding("DisabledProbe", "value", "value"),
            new ManifestPropertyBinding("DisabledProbe", "enabled", "enabled"),
            new ManifestPropertyBinding("DisabledProbe", "texture", "texture"),
            new ManifestPropertyBinding("EnabledProbe", "enabled", "enabled"),
            new ManifestPropertyBinding("InvalidProbe", "text", "invalidText"),
        });

        var diagnostics = new List<ManifestRuntimeDiagnostic>();
        void Capture(ManifestRuntimeDiagnostic diagnostic) => diagnostics.Add(diagnostic);
        ManifestRuntimeDiagnostics.Emitted += Capture;
        try
        {
            ManifestBindingApplier.Apply(root, store, bindings);
        }
        finally
        {
            ManifestRuntimeDiagnostics.Emitted -= Capture;
        }

        Require(disabledProbe.Text == "27", "scripted text property should use the canonical string conversion");
        Require(Math.Abs(disabledProbe.Value - 0.75) < 0.0001, "scripted value property should use numeric conversion");
        Require(!disabledProbe.Disabled, "enabled should invert a scripted disabled property");
        Require(
            disabledProbe.Texture is not null && disabledProbe.Texture.GetInstanceId() == texture.GetInstanceId(),
            "scripted texture property should receive the Texture2D resource");
        Require(enabledProbe.Enabled, "enabled should prefer a scripted enabled property when present");
        Require(enabledProbe.Disabled, "enabled fallback should not write disabled when enabled exists");
        Require(diagnostics.Count(item => item.Code == "MUIR4003") == 1, "an incompatible scripted property type should emit one MUIR4003 diagnostic");
        Require(diagnostics.Single(item => item.Code == "MUIR4003").Message.Contains("incompatible", StringComparison.Ordinal), "type mismatch diagnostic should explain incompatibility");

        root.Free();
        texture.Dispose();
    }

#if TOOLS
    public static void CheckEngineVerify()
    {
        foreach (var resourcePath in new[] { "res://ui/phone/package.json", "res://ui/badge/package.json", "res://ui/liquid_glass/package.json" })
        {
            var packagePath = ProjectSettings.GlobalizePath(resourcePath);
            var diagnostics = ManifestUiEngineVerifier.Verify(packagePath);
            var errors = diagnostics.Where(diagnostic => diagnostic.Severity == GodotUi.Manifest.Tooling.ManifestDiagnosticSeverity.Error).ToArray();
            Require(errors.Length == 0, $"engine verify failed for {resourcePath}: " + string.Join(" | ", errors.Select(error => $"{error.Code} {error.File}{error.JsonPointer}: {error.Message}")));
        }

    }

#endif

    public static void CheckKeyedRepeaterPool()
    {
        var root = new Control();
        var container = new VBoxContainer { Name = "Items" };
        var template = new HBoxContainer { Name = "Template" };
        template.AddChild(new Label { Name = "Text" });
        container.AddChild(template);
        root.AddChild(container);

        var store = new ViewModelStore();
        var cursor = store.CreateCursor();
        var bindings = new ManifestBindingSet(
            Array.Empty<ManifestPropertyBinding>(),
            ManifestAssetCatalog.Empty,
            new[]
            {
                new ManifestRepeaterBinding(
                    "Items",
                    "Items/Template",
                    "items",
                    new[] { new ManifestItemBinding("Text", "text", "name") },
                    keyFieldId: "id",
                    poolCapacity: 4),
            });

        store.Set("items", new[]
        {
            new Dictionary<string, object?> { ["id"] = "a", ["name"] = "A" },
            new Dictionary<string, object?> { ["id"] = "b", ["name"] = "B" },
        });
        ApplyWithCursor(root, store, bindings, cursor);
        var originalA = FindRepeaterItem(container, "a");
        var originalB = FindRepeaterItem(container, "b");

        store.Set("items", new[]
        {
            new Dictionary<string, object?> { ["id"] = "b", ["name"] = "Bee" },
            new Dictionary<string, object?> { ["id"] = "a", ["name"] = "Aye" },
        });
        ApplyWithCursor(root, store, bindings, cursor);
        Require(ReferenceEquals(originalA, FindRepeaterItem(container, "a")), "keyed repeater should retain item a");
        Require(ReferenceEquals(originalB, FindRepeaterItem(container, "b")), "keyed repeater should retain item b");

        store.Set("items", new[]
        {
            new Dictionary<string, object?> { ["id"] = "a", ["name"] = "A" },
        });
        ApplyWithCursor(root, store, bindings, cursor);
        Require(!originalB.Visible && !originalB.HasMeta("manifest_repeater"), "removed repeater item should enter the pool");

        store.Set("items", new[]
        {
            new Dictionary<string, object?> { ["id"] = "a", ["name"] = "A" },
            new Dictionary<string, object?> { ["id"] = "b", ["name"] = "B" },
        });
        ApplyWithCursor(root, store, bindings, cursor);
        Require(ReferenceEquals(originalB, FindRepeaterItem(container, "b")), "pooled repeater item should be reused");
        root.Free();
    }

    public static async Task CheckBusAndAsyncLifecycle(Node host)
    {
        var previewParent = new Control();
        previewParent.SetMeta(ManifestGeneratedWidget.EditorPreviewMeta, true);
        var previewWidget = new PreviewProbeWidget();
        previewWidget.AddChild(new Label { Name = "Value" });
        previewParent.AddChild(previewWidget);
        host.AddChild(previewParent);
        Require(previewWidget.IsEditorPreview, "preview meta should suppress controller attachment");
        Require(previewWidget.AttachedController is null, "preview must not create a controller");
        Require(previewWidget.GetNode<Label>("Value").Text == "preview", "preview should still apply binding fallback");
        previewParent.QueueFree();
        await host.ToSignal(host.GetTree(), SceneTree.SignalName.ProcessFrame);
        var bus = ManifestMessageBus.Instance ?? throw new InvalidOperationException("ManifestMessageBus autoload missing");
        string? received = null;
        using var subscription = bus.SubscribeEnvelope(
            "runtime.deferred",
            envelope => received = envelope.Payload.AsString(),
            ManifestMessageScope.Package,
            "ui.phone");
        bus.Publish(new ManifestMessageEnvelope(
            "runtime.deferred",
            "event",
            "payload",
            ManifestMessageScope.Package,
            "ui.phone",
            "runtime-test",
            ManifestMessageDelivery.Deferred));
        Require(received is null, "deferred message must not run inline");
        await host.ToSignal(host.GetTree(), SceneTree.SignalName.ProcessFrame);
        await host.ToSignal(host.GetTree(), SceneTree.SignalName.ProcessFrame);
        Require(received == "payload", "deferred scoped message was not delivered");
        var manager = ManifestUiManager.Instance ?? throw new InvalidOperationException("ManifestUiManager autoload missing");
        manager.RegisterCatalogEntry(new ManifestUiCatalogEntry(
            "ui.phone",
            PhoneScene,
            () => new PhoneController(),
            ManifestControllerScope.Package), replace: true);
        manager.RegisterCatalogEntry(new ManifestUiCatalogEntry(
            "ui.badge",
            BadgeScene,
            () => new BadgeController(),
            ManifestControllerScope.Instance,
            routes: new[]
            {
                new ManifestUiRoute("runtime.route.open", "open", "ui.badge"),
                new ManifestUiRoute("runtime.route.close", "close"),
            }), replace: true);

        await manager.PreloadAsync("ui.phone");
        var firstTask = manager.OpenAsync("ui.phone", new ManifestUiOpenOptions { ScreenId = "async_phone" });
        var secondTask = manager.OpenAsync("ui.phone", new ManifestUiOpenOptions { ScreenId = "async_phone" });
        var first = await firstTask;
        var second = await secondTask;
        Require(ReferenceEquals(first, second), "concurrent Reuse opens should share one handle");
        Require(first.State == ManifestUiState.Open && first.Widget is not null && first.Widget.IsInsideTree(), "async open should return an open handle");

        await manager.HideAsync(first);
        Require(first.State == ManifestUiState.Hidden && first.Widget is not null && !first.Widget.Visible, "hide should retain but hide the widget");
        first.Controller!.Store.Set("status", "Changed while hidden");
        await manager.ShowAsync(first);
        Require(first.State == ManifestUiState.Open && first.Widget is not null && first.Widget.Visible, "show should reopen hidden widget");
        Require(first.Widget!.GetNode<Label>("Panel/Content/StatusLabel").Text == "Changed while hidden", "show should catch up hidden bindings");

        await manager.CloseAsync(first, ManifestUiCloseReason.Programmatic);
        Require(first.State == ManifestUiState.Closed, "close should transition handle to Closed");
        await host.ToSignal(host.GetTree(), SceneTree.SignalName.ProcessFrame);

        var firstModal = await manager.OpenAsync("ui.badge", new ManifestUiOpenOptions
        {
            ScreenId = "pause_modal",
            Mode = ManifestUiOpenMode.Stack,
            IsModal = true,
            PauseTree = true,
        });
        var secondModal = await manager.OpenAsync("ui.badge", new ManifestUiOpenOptions
        {
            ScreenId = "pause_modal",
            Mode = ManifestUiOpenMode.Stack,
            IsModal = true,
            PauseTree = true,
        });
        Require(host.GetTree().Paused, "modal pause token should pause the tree");
        await manager.CloseAsync(firstModal, ManifestUiCloseReason.Programmatic);
        Require(host.GetTree().Paused, "closing a non-top pause owner must keep the tree paused");
        await manager.CloseAsync(secondModal, ManifestUiCloseReason.Programmatic);
        Require(!host.GetTree().Paused, "last pause owner should restore the prior pause state");
        await host.ToSignal(host.GetTree(), SceneTree.SignalName.ProcessFrame);

        bus.Publish("runtime.route.open");
        await host.ToSignal(host.GetTree(), SceneTree.SignalName.ProcessFrame);
        await host.ToSignal(host.GetTree(), SceneTree.SignalName.ProcessFrame);
        var routed = manager.Handles.Single(handle => handle.PackageId.ToString() == "ui.badge");
        Require(routed.State == ManifestUiState.Open, "open route should create an open handle");
        bus.Publish("runtime.route.close");
        await host.ToSignal(host.GetTree(), SceneTree.SignalName.ProcessFrame);
        Require(routed.State == ManifestUiState.Closed, "close route should close matching package handles");

        await manager.ReleaseAsync("ui.phone", closeInstances: true);
        await manager.ReleaseAsync("ui.badge", closeInstances: true);
    }

    public static async Task CheckReplaceCancellationAndExternalFree(Node host)
    {
        var manager = ManifestUiManager.Instance ?? throw new InvalidOperationException("ManifestUiManager autoload missing");
        manager.RegisterCatalogEntry(new ManifestUiCatalogEntry(
            "ui.badge",
            BadgeScene,
            () => new BadgeController(),
            ManifestControllerScope.Instance), replace: true);

        using (var cancelled = new CancellationTokenSource())
        {
            cancelled.Cancel();
            await RequireThrowsAsync<OperationCanceledException>(() => manager.OpenAsync(
                "ui.badge",
                new ManifestUiOpenOptions { ScreenId = "cancelled" },
                cancelled.Token));
        }
        Require(manager.GetOpenCount("cancelled") == 0, "pre-cancelled open must not retain a handle");

        var first = await manager.OpenAsync("ui.badge", new ManifestUiOpenOptions
        {
            ScreenId = "replace_contract",
            Mode = ManifestUiOpenMode.Reuse,
        });
        var replacement = await manager.OpenAsync("ui.badge", new ManifestUiOpenOptions
        {
            ScreenId = "replace_contract",
            Mode = ManifestUiOpenMode.Replace,
        });
        Require(first.State == ManifestUiState.Closed, "Replace should close the previous handle");
        Require(first.Widget is null && first.Controller is null, "closed handles must release widget and controller references");
        Require(replacement.State == ManifestUiState.Open, "Replace should commit the new handle");
        Require(manager.GetOpenCount("replace_contract") == 1, "Replace should retain exactly one open handle");
        await manager.CloseAsync(replacement, ManifestUiCloseReason.Programmatic);
        await host.ToSignal(host.GetTree(), SceneTree.SignalName.ProcessFrame);

        ManifestUiCloseReason? observedReason = null;
        var external = await manager.OpenAsync("ui.badge", new ManifestUiOpenOptions
        {
            ScreenId = "external_free",
            OnHandleClosed = (_, reason) => observedReason = reason,
        });
        external.Widget!.QueueFree();
        await host.ToSignal(host.GetTree(), SceneTree.SignalName.ProcessFrame);
        await host.ToSignal(host.GetTree(), SceneTree.SignalName.ProcessFrame);
        Require(external.State == ManifestUiState.Closed, "external QueueFree should close the handle");
        Require(observedReason == ManifestUiCloseReason.OwnerFreed, "external QueueFree should report OwnerFreed");
        Require(manager.GetOpenCount("external_free") == 0, "external QueueFree must remove the open handle");

        await manager.ReleaseAsync("ui.badge", closeInstances: true);
    }

    public static async Task CheckVisibilityPriority(Node host)
    {
        var manager = ManifestUiManager.Instance ?? throw new InvalidOperationException("ManifestUiManager autoload missing");
        var root = ManifestUiRoot.Instance ?? throw new InvalidOperationException("ManifestUiRoot autoload missing");
        manager.RegisterCatalogEntry(new ManifestUiCatalogEntry(
            "ui.phone",
            PhoneScene,
            () => new PhoneController(),
            ManifestControllerScope.Package), replace: true);
        manager.RegisterCatalogEntry(new ManifestUiCatalogEntry(
            "ui.badge",
            BadgeScene,
            () => new BadgeController(),
            ManifestControllerScope.Instance), replace: true);

        const string scope = "runtime.visibility";
        var low = await manager.OpenAsync("ui.phone", new ManifestUiOpenOptions
        {
            ScreenId = "visibility_low",
            Mode = ManifestUiOpenMode.Stack,
            VisibilityScope = $"  {scope}  ",
            VisibilityPriority = ManifestUiPriorities.Hud,
        });
        Require(low.Options.VisibilityScope == scope, "visibility scope should be trimmed");
        Require(low.Widget is { Visible: true }, "low-priority widget should initially be visible");

        var nonSuppressing = await manager.OpenAsync("ui.badge", new ManifestUiOpenOptions
        {
            ScreenId = "visibility_non_suppressing",
            Mode = ManifestUiOpenMode.Stack,
            VisibilityScope = scope,
            VisibilityPriority = ManifestUiPriorities.Overlay,
        });
        Require(low.Widget.Visible, "higher priority without suppression must not hide lower priority UI");
        await manager.CloseAsync(nonSuppressing, ManifestUiCloseReason.Programmatic);

        var equal = await manager.OpenAsync("ui.badge", new ManifestUiOpenOptions
        {
            ScreenId = "visibility_equal",
            Mode = ManifestUiOpenMode.Stack,
            VisibilityScope = scope,
            VisibilityPriority = ManifestUiPriorities.Hud,
            SuppressLowerPriority = true,
        });
        Require(low.Widget.Visible, "equal priority suppressor must coexist");
        await manager.CloseAsync(equal, ManifestUiCloseReason.Programmatic);

        var otherScope = await manager.OpenAsync("ui.badge", new ManifestUiOpenOptions
        {
            ScreenId = "visibility_other_scope",
            Mode = ManifestUiOpenMode.Stack,
            VisibilityScope = "runtime.visibility.other",
            VisibilityPriority = ManifestUiPriorities.Modal,
            SuppressLowerPriority = true,
        });
        Require(low.Widget.Visible, "different visibility scopes must not affect each other");
        await manager.CloseAsync(otherScope, ManifestUiCloseReason.Programmatic);

        var overlay = await manager.OpenAsync("ui.badge", new ManifestUiOpenOptions
        {
            ScreenId = "visibility_overlay",
            Mode = ManifestUiOpenMode.Stack,
            VisibilityScope = scope,
            VisibilityPriority = ManifestUiPriorities.Overlay,
            SuppressLowerPriority = true,
        });
        Require(low.State == ManifestUiState.Open && !low.Widget.Visible, "suppressed handles must remain Open but invisible");
        low.Controller!.Store.Set("status", "Changed while suppressed");

        var modal = await manager.OpenAsync("ui.badge", new ManifestUiOpenOptions
        {
            ScreenId = "visibility_modal",
            Mode = ManifestUiOpenMode.Stack,
            VisibilityScope = scope,
            VisibilityPriority = ManifestUiPriorities.Modal,
            SuppressLowerPriority = true,
        });
        Require(!overlay.Widget!.Visible && !low.Widget.Visible, "highest nested suppressor should hide all lower priorities");
        await manager.CloseAsync(modal, ManifestUiCloseReason.Programmatic);
        Require(overlay.Widget.Visible && !low.Widget.Visible, "closing the highest suppressor should restore the previous suppressor relationship");

        await manager.HideAsync(overlay);
        Require(low.Widget.Visible, "hiding a suppressor should restore lower-priority UI");
        Require(
            low.Widget.GetNode<Label>("Panel/Content/StatusLabel").Text == "Changed while suppressed",
            "restored generated UI should catch up Store changes made while suppressed");
        await manager.ShowAsync(overlay);
        Require(!low.Widget.Visible, "showing the suppressor should reapply priority visibility");
        await manager.CloseAsync(overlay, ManifestUiCloseReason.Programmatic);
        Require(low.Widget.Visible, "closing the suppressor should restore lower-priority UI");

        var external = await manager.OpenAsync("ui.badge", new ManifestUiOpenOptions
        {
            ScreenId = "visibility_external_free",
            Mode = ManifestUiOpenMode.Stack,
            VisibilityScope = scope,
            VisibilityPriority = ManifestUiPriorities.Overlay,
            SuppressLowerPriority = true,
        });
        Require(!low.Widget.Visible, "external-free fixture should suppress the low widget before deletion");
        external.Widget!.QueueFree();
        await host.ToSignal(host.GetTree(), SceneTree.SignalName.ProcessFrame);
        await host.ToSignal(host.GetTree(), SceneTree.SignalName.ProcessFrame);
        Require(low.Widget.Visible, "invalid suppressor cleanup should restore lower-priority UI");

        await manager.CloseAsync(low, ManifestUiCloseReason.Programmatic);

        const string modalScope = "runtime.visibility.modal";
        var lowModal = await manager.OpenAsync("ui.phone", new ManifestUiOpenOptions
        {
            ScreenId = "visibility_low_modal",
            Mode = ManifestUiOpenMode.Stack,
            VisibilityScope = modalScope,
            VisibilityPriority = ManifestUiPriorities.Hud,
            IsModal = true,
            PauseTree = true,
        });
        Require(host.GetTree().Paused && root.IsModalLayerActive(), "visible modal should own pause and modal input");
        var modalFocus = host.GetViewport().GuiGetFocusOwner();
        Require(
            modalFocus is not null && (ReferenceEquals(modalFocus, lowModal.Widget) || lowModal.Widget!.IsAncestorOf(modalFocus)),
            "visible modal should own focus");

        var modalSuppressor = await manager.OpenAsync("ui.badge", new ManifestUiOpenOptions
        {
            ScreenId = "visibility_modal_suppressor",
            Mode = ManifestUiOpenMode.Stack,
            VisibilityScope = modalScope,
            VisibilityPriority = ManifestUiPriorities.Overlay,
            SuppressLowerPriority = true,
        });
        Require(lowModal.State == ManifestUiState.Open && !lowModal.Widget!.Visible, "suppressed modal should remain Open");
        Require(!host.GetTree().Paused && !root.IsModalLayerActive(), "suppressed modal should release pause and modal input");
        var suppressedFocus = host.GetViewport().GuiGetFocusOwner();
        Require(
            suppressedFocus is null || !ReferenceEquals(suppressedFocus, lowModal.Widget) && !lowModal.Widget.IsAncestorOf(suppressedFocus),
            "suppressed modal should release focus from its subtree");

        await manager.CloseAsync(modalSuppressor, ManifestUiCloseReason.Programmatic);
        Require(lowModal.Widget.Visible && host.GetTree().Paused && root.IsModalLayerActive(), "restored modal should reacquire visibility, pause, and modal input");
        var restoredFocus = host.GetViewport().GuiGetFocusOwner();
        Require(
            restoredFocus is not null && (ReferenceEquals(restoredFocus, lowModal.Widget) || lowModal.Widget.IsAncestorOf(restoredFocus)),
            "restored modal should reacquire focus");
        await manager.CloseAsync(lowModal, ManifestUiCloseReason.Programmatic);
        Require(!host.GetTree().Paused, "closing the restored modal should release pause");

        await manager.ReleaseAsync("ui.phone", closeInstances: true);
        await manager.ReleaseAsync("ui.badge", closeInstances: true);
    }

    public static async Task CheckCatalogReplacementAndLocalization(Node host)
    {
        var manager = ManifestUiManager.Instance ?? throw new InvalidOperationException("ManifestUiManager autoload missing");
        const string domainName = "runtime.catalog.replace";
        manager.RegisterCatalogEntry(new ManifestUiCatalogEntry(
            "ui.badge",
            BadgeScene,
            () => new BadgeController(),
            ManifestControllerScope.Instance,
            domainName,
            new[] { BasicEnglish }), replace: true);

        await manager.PreloadAsync("ui.badge");
        var active = await manager.OpenAsync("ui.badge", new ManifestUiOpenOptions
        {
            ScreenId = "catalog_active",
            Mode = ManifestUiOpenMode.Stack,
        });
        Require(active.Widget is ManifestGeneratedWidget { PackageId: "ui.badge" }, "initial catalog scene should instantiate the badge widget");
        Require(Translate(domainName, "basic.title") == "Manifest UI Basic", "initial catalog translation should be available");

        manager.RegisterCatalogEntry(new ManifestUiCatalogEntry(
            "ui.badge",
            PhoneScene,
            () => new PhoneController(),
            ManifestControllerScope.Instance,
            domainName,
            new[] { InventoryEnglish }), replace: true);
        Require(Translate(domainName, "basic.title") == "Manifest UI Basic", "active translation domain should remain usable until replacement resources are ready");
        await manager.PreloadAsync("ui.badge");

        Require(active.State == ManifestUiState.Open, "catalog replacement must not close an active handle");
        Require(active.Widget is not null && GodotObject.IsInstanceValid(active.Widget), "catalog replacement must not free an active widget");
        Require(Translate(domainName, "inventory.title") == "Service-backed inventory", "replacement translation should replace the package cache");
        Require(Translate(domainName, "basic.title") == "basic.title", "stale translation must be removed after catalog replacement");

        var replacement = await manager.OpenAsync("ui.badge", new ManifestUiOpenOptions
        {
            ScreenId = "catalog_replacement",
            Mode = ManifestUiOpenMode.Stack,
        });
        Require(replacement.Widget is ManifestGeneratedWidget { PackageId: "ui.phone" }, "replacement open must use the new catalog scene");
        Require(!ReferenceEquals(active.Widget, replacement.Widget), "replacement open must not reuse the active old widget");

        await manager.CloseAsync(active, ManifestUiCloseReason.Programmatic);
        await manager.CloseAsync(replacement, ManifestUiCloseReason.Programmatic);
        await host.ToSignal(host.GetTree(), SceneTree.SignalName.ProcessFrame);
        await manager.ReleaseAsync("ui.badge", closeInstances: true);
        await manager.ReleaseAsync("ui.phone", closeInstances: true);

        var baselineHandles = manager.Handles.Count;
        var cachedNonScene = ResourceLoader.Load<Translation>(BasicEnglish)
            ?? throw new InvalidOperationException("failure rollback fixture could not be cached");
        try
        {
            manager.RegisterCatalogEntry(new ManifestUiCatalogEntry(
                "ui.load.failure",
                BasicEnglish,
                () => new BadgeController(),
                ManifestControllerScope.Instance), replace: true);
            await RequireThrowsAsync<Exception>(() => manager.OpenAsync("ui.load.failure"));
            Require(manager.Handles.Count == baselineHandles, "failed scene load must roll back its loading handle");
            Require(manager.GetOpenCount("ui.load.failure") == 0, "failed scene load must not remain visible to lifecycle queries");
            manager.UnregisterCatalogEntry("ui.load.failure");
        }
        finally
        {
            cachedNonScene.Dispose();
        }

        var previousLocale = TranslationServer.GetLocale();
        try
        {
            TranslationServer.SetLocale("en");
            manager.RegisterCatalogEntry(new ManifestUiCatalogEntry(
                "test.localization",
                BadgeScene,
                () => new LocalizationProbeController(),
                ManifestControllerScope.Instance,
                "test.localization",
                new[] { BasicEnglish, BasicChinese }), replace: true);
            await manager.PreloadAsync("test.localization");
            var localized = new LocalizationProbeWidget();
            localized.AddChild(new Label { Name = "Title" });
            host.AddChild(localized);
            Require(localized.GetNode<Label>("Title").Text == "Manifest UI Basic", "initial locale should apply the English translation");

            TranslationServer.SetLocale("zh_CN");
            await host.ToSignal(host.GetTree(), SceneTree.SignalName.ProcessFrame);
            await host.ToSignal(host.GetTree(), SceneTree.SignalName.ProcessFrame);
            Require(localized.GetNode<Label>("Title").Text == "Manifest UI 基础示例", "locale changes should refresh an open generated widget");

            localized.QueueFree();
            await host.ToSignal(host.GetTree(), SceneTree.SignalName.ProcessFrame);
            await manager.ReleaseAsync("test.localization", closeInstances: true);
            manager.UnregisterCatalogEntry("test.localization");
        }
        finally
        {
            TranslationServer.SetLocale(previousLocale);
            manager.RegisterCatalogEntry(new ManifestUiCatalogEntry(
                "ui.badge",
                BadgeScene,
                () => new BadgeController(),
                ManifestControllerScope.Instance), replace: true);
        }
    }

    public static async Task CheckLifecycleStress(Node host, int iterations)
    {
        var manager = ManifestUiManager.Instance ?? throw new InvalidOperationException("ManifestUiManager autoload missing");
        var bus = ManifestMessageBus.Instance ?? throw new InvalidOperationException("ManifestMessageBus autoload missing");
        manager.RegisterCatalogEntry(new ManifestUiCatalogEntry(
            "ui.badge",
            BadgeScene,
            () => new BadgeController(),
            ManifestControllerScope.Instance), replace: true);

        await manager.PreloadAsync("ui.badge");
        var warmup = await manager.OpenAsync("ui.badge", new ManifestUiOpenOptions { ScreenId = "stress" });
        await manager.CloseAsync(warmup, ManifestUiCloseReason.Programmatic);
        await host.ToSignal(host.GetTree(), SceneTree.SignalName.ProcessFrame);
        await host.ToSignal(host.GetTree(), SceneTree.SignalName.ProcessFrame);

        var baselineHandles = manager.Handles.Count;
        var baselineSubscriptions = bus.SubscriptionCount;
        var root = ManifestUiRoot.Instance ?? throw new InvalidOperationException("ManifestUiRoot autoload missing");
        var baselineNodes = CountNodes(root);

        for (var i = 0; i < iterations; i++)
        {
            var handle = await manager.OpenAsync("ui.badge", new ManifestUiOpenOptions { ScreenId = "stress" });
            await manager.HideAsync(handle);
            Require(handle.State == ManifestUiState.Hidden && handle.Widget is not null, "Hide should retain the widget");
            await manager.ShowAsync(handle);
            Require(handle.State == ManifestUiState.Open, "Show should restore the open state");
            await manager.CloseAsync(handle, ManifestUiCloseReason.Programmatic);

            if ((i + 1) % 25 == 0)
            {
                await host.ToSignal(host.GetTree(), SceneTree.SignalName.ProcessFrame);
            }
        }

        await host.ToSignal(host.GetTree(), SceneTree.SignalName.ProcessFrame);
        await host.ToSignal(host.GetTree(), SceneTree.SignalName.ProcessFrame);
        GC.Collect();
        GC.WaitForPendingFinalizers();
        await manager.ReleaseAsync("ui.badge", closeInstances: true);

        Require(manager.Handles.Count == baselineHandles, "stress run leaked UI handles");
        Require(bus.SubscriptionCount == baselineSubscriptions, "stress run leaked message subscriptions");
        Require(CountNodes(root) == baselineNodes, "stress run leaked scene nodes");
        Require(manager.FindController("ui.badge") is null, "instance-scoped controllers must be released after close");
    }

    private static Control CreateLabelRoot()
    {
        var root = new Control();
        root.AddChild(new Label { Name = "Value" });
        return root;
    }

    private static void ApplyWithCursor(Control root, ViewModelStore store, ManifestBindingSet bindings, ViewModelStoreCursor cursor)
    {
        var revision = store.Revision;
        ManifestBindingApplier.Apply(root, store, bindings, cursor, revision);
        cursor.AdvanceTo(revision);
    }

    private static Control FindRepeaterItem(Control container, string key)
    {
        return container.GetChildren()
            .OfType<Control>()
            .Single(child => child.HasMeta("manifest_repeater_key") && child.GetMeta("manifest_repeater_key").AsString() == key);
    }

    private static int CountNodes(Node root)
    {
        var count = 1;
        foreach (var child in root.GetChildren())
        {
            count += CountNodes(child);
        }
        return count;
    }

    private static string Translate(string domainName, string message)
    {
        var domain = TranslationServer.GetOrAddDomain(domainName);
        try
        {
            domain.SetLocaleOverride("en");
            return domain.Translate(message).ToString();
        }
        finally
        {
            domain.Dispose();
        }
    }

    private static async Task RequireThrowsAsync<TException>(Func<Task> action)
        where TException : Exception
    {
        try
        {
            await action();
        }
        catch (TException)
        {
            return;
        }

        throw new InvalidOperationException($"Expected {typeof(TException).Name}.");
    }

    private static void Require(bool condition, string message)
    {
        if (!condition)
        {
            throw new InvalidOperationException(message);
        }
    }
}

internal partial class PreviewProbeWidget : ManifestGeneratedWidget
{
    public override string PackageId => "test.preview";

    protected override ManifestControllerBase CreateController()
    {
        throw new InvalidOperationException("Preview must not create a controller.");
    }

    protected override void BindNodes()
    {
        _ = GetNode<Label>("Value");
    }

    protected override ManifestBindingSet GetBindingSet()
    {
        return new ManifestBindingSet(new[]
        {
            new ManifestPropertyBinding("Value", "text", "missing", fallback: "preview"),
        });
    }
}

internal partial class LocalizationProbeWidget : ManifestGeneratedWidget
{
    public override string PackageId => "test.localization";
    public override ManifestControllerScope ControllerScope => ManifestControllerScope.Instance;
    public override string TranslationDomain => "test.localization";

    protected override ManifestControllerBase CreateController()
    {
        return new LocalizationProbeController();
    }

    protected override void BindNodes()
    {
        _ = GetNode<Label>("Title");
    }

    protected override ManifestBindingSet GetBindingSet()
    {
        return new ManifestBindingSet(
            Array.Empty<ManifestPropertyBinding>(),
            localizations: new[]
            {
                new ManifestLocalizedPropertyBinding("Title", "text", "basic.title"),
            },
            assets: null);
    }
}

internal sealed class LocalizationProbeController : ManifestControllerBase
{
}

internal partial class ScriptedBindingProbeControl : Control
{
    [Export] public string Text { get; set; } = string.Empty;
    [Export] public double Value { get; set; }
    [Export] public bool Disabled { get; set; }
    [Export] public Texture2D? Texture { get; set; }
}

internal partial class ScriptedEnabledBindingProbeControl : Control
{
    [Export] public bool Enabled { get; set; }
    [Export] public bool Disabled { get; set; }
}

internal partial class ScriptedInvalidBindingProbeControl : Control
{
    [Export] public Color Text { get; set; }
}
