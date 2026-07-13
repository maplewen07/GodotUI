using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.Json.Nodes;
using System.Threading.Tasks;
using System.Xml.Linq;
using Godot;
using GodotUi.Manifest;
using GodotUi.Manifest.EngineTooling;
using GodotUi.Manifest.Tooling;

namespace GodotUi.Tests;

public partial class SelfCheck : Node
{
    private const string PhoneScene = "res://generated/ui/phone/PhoneWidget.tscn";
    private readonly List<CheckResult> _results = new();

    public override async void _Ready()
    {
        try
        {
            await RunCaseAsync("Store", () => RunSync(CheckStore));
            await RunCaseAsync("MessageBus", () => RunSync(CheckBus));
            await RunCaseAsync("BindingConverters", () => RunSync(CheckBindingConverters));
#if TOOLS
            await RunCaseAsync("EngineVerify", () => RunSync(RuntimeContractChecks.CheckEngineVerify));
#endif
            await RunCaseAsync("SceneExport", () => RunSync(CheckSceneExport));
            await RunCaseAsync("StoreAndServices", () => RunSync(RuntimeContractChecks.CheckStoreAndServices));
            await RunCaseAsync("ScriptedBindingFallback", () => RunSync(RuntimeContractChecks.CheckScriptedBindingFallback));
            await RunCaseAsync("KeyedRepeaterPool", () => RunSync(RuntimeContractChecks.CheckKeyedRepeaterPool));
            await RunCaseAsync("AsyncLifecycleAndModal", () => RuntimeContractChecks.CheckBusAndAsyncLifecycle(this));
            await RunCaseAsync("VisibilityPriority", () => RuntimeContractChecks.CheckVisibilityPriority(this));
            await RunCaseAsync("ReplaceCancellationAndExternalFree", () => RuntimeContractChecks.CheckReplaceCancellationAndExternalFree(this));
            await RunCaseAsync("CatalogReplacementFailureAndLocalization", () => RuntimeContractChecks.CheckCatalogReplacementAndLocalization(this));
            await RunCaseAsync("LifecycleStress1000", () => RuntimeContractChecks.CheckLifecycleStress(this, 1000));
            await RunCaseAsync("LegacyImmediateLifecycle", CheckLifecycle);

            for (var pass = 0; pass < 3; pass++)
            {
                GC.Collect();
                GC.WaitForPendingFinalizers();
                await Task.Delay(5);
            }

            var reportPath = WriteJUnitReport();
            var failures = _results.Where(result => result.Exception is not null).ToArray();
            GD.Print($"Manifest UI JUnit report: {reportPath}");
            if (failures.Length == 0)
            {
                GD.Print($"Manifest UI self-check passed ({_results.Count} checks).");
                GetTree().Quit(0);
                return;
            }

            foreach (var failure in failures)
            {
                GD.PushError($"{failure.Name}: {failure.Exception}");
            }
            GetTree().Quit(1);
        }
        catch (Exception ex)
        {
            GD.PushError(ex.ToString());
            GetTree().Quit(1);
        }
    }

    private async Task RunCaseAsync(string name, Func<Task> check)
    {
        var filter = System.Environment.GetEnvironmentVariable("MANIFEST_UI_TEST_FILTER");
        if (!string.IsNullOrWhiteSpace(filter) &&
            !name.Contains(filter, StringComparison.OrdinalIgnoreCase))
        {
            return;
        }

        var stopwatch = Stopwatch.StartNew();
        Exception? failure = null;
        try
        {
            await check();
            GD.Print($"PASS {name}");
        }
        catch (Exception ex)
        {
            failure = ex;
            GD.PushError($"FAIL {name}: {ex.Message}");
        }
        finally
        {
            stopwatch.Stop();
            _results.Add(new CheckResult(name, stopwatch.Elapsed, failure));
        }
    }

    private static Task RunSync(Action check)
    {
        check();
        return Task.CompletedTask;
    }

    private string WriteJUnitReport()
    {
        var configuredPath = System.Environment.GetEnvironmentVariable("MANIFEST_UI_JUNIT_PATH");
        var reportPath = string.IsNullOrWhiteSpace(configuredPath)
            ? ProjectSettings.GlobalizePath("user://test-results/manifest-ui-self-check.xml")
            : Path.IsPathRooted(configuredPath!)
                ? configuredPath!
                : Path.GetFullPath(configuredPath!, ProjectSettings.GlobalizePath("res://"));
        Directory.CreateDirectory(Path.GetDirectoryName(reportPath)!);

        var failures = _results.Count(result => result.Exception is not null);
        var suite = new XElement(
            "testsuite",
            new XAttribute("name", "ManifestUi.Godot47.Headless"),
            new XAttribute("tests", _results.Count),
            new XAttribute("failures", failures),
            new XAttribute("errors", 0),
            new XAttribute("time", _results.Sum(result => result.Elapsed.TotalSeconds).ToString("0.000", CultureInfo.InvariantCulture)),
            new XAttribute("timestamp", DateTimeOffset.UtcNow.ToString("O", CultureInfo.InvariantCulture)),
            _results.Select(CreateJUnitCase));
        var xml = "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n" + suite + "\n";
        File.WriteAllText(reportPath, xml, new UTF8Encoding(encoderShouldEmitUTF8Identifier: false));
        return reportPath;
    }

    private static XElement CreateJUnitCase(CheckResult result)
    {
        var testCase = new XElement(
            "testcase",
            new XAttribute("classname", "GodotUi.Tests.SelfCheck"),
            new XAttribute("name", result.Name),
            new XAttribute("time", result.Elapsed.TotalSeconds.ToString("0.000", CultureInfo.InvariantCulture)));
        if (result.Exception is not null)
        {
            testCase.Add(new XElement(
                "failure",
                new XAttribute("type", result.Exception.GetType().FullName ?? "System.Exception"),
                new XAttribute("message", result.Exception.Message),
                result.Exception.ToString()));
        }

        return testCase;
    }

    private static void CheckStore()
    {
        var store = new ViewModelStore();
        store.Set("status", "Ready");
        Require(store.IsDirty("status"), "status should be dirty after Set");
        Require(store.TryGet("status", out var value) && (string)value! == "Ready", "status value mismatch");
        store.ClearDirty();
        Require(!store.IsDirty("status"), "status should not be dirty after ClearDirty");
    }

    private static void CheckBus()
    {
        var bus = new ManifestMessageBus();
        object? received = null;
        var subscription = bus.Subscribe("phone.open_contacts", payload => received = payload);
        bus.Publish("phone.open_contacts", "open_contacts");
        Require((string)received! == "open_contacts", "bus payload mismatch");

        subscription.Dispose();
        received = null;
        bus.Publish("phone.open_contacts", "open_contacts");
        Require(received is null, "disposed subscription should not receive messages");
        bus.Free();
    }

    private static void CheckBindingConverters()
    {
        ManifestBindingConverters.Register("selfcheckUpper", value => value?.ToString()?.ToUpperInvariant() ?? "");
        try
        {
            var root = new Control();
            var label = new Label { Name = "Label" };
            root.AddChild(label);

            var store = new ViewModelStore();
            store.Set("word", "ok");
            var bindings = new ManifestBindingSet(new[]
            {
                new ManifestPropertyBinding("Label", "text", "word", "selfcheckUpper"),
            });
            ManifestBindingApplier.Apply(root, store, bindings);
            Require(label.Text == "OK", "custom converter should apply");
            root.Free();
        }
        finally
        {
            ManifestBindingConverters.Unregister("selfcheckUpper");
        }
    }

    private static void CheckSceneExport()
    {
        var projectRoot = Path.GetFullPath(ProjectSettings.GlobalizePath("res://"));
        var fixtureDirectory = Path.GetFullPath(Path.Combine(projectRoot, ".godot", "manifest_ui_export_selfcheck"));
        var allowedRoot = Path.GetFullPath(Path.Combine(projectRoot, ".godot")) + Path.DirectorySeparatorChar;
        Require(fixtureDirectory.StartsWith(allowedRoot, StringComparison.OrdinalIgnoreCase), "export fixture must stay under .godot");
        if (Directory.Exists(fixtureDirectory)) Directory.Delete(fixtureDirectory, recursive: true);
        Directory.CreateDirectory(Path.Combine(fixtureDirectory, "assets"));

        var sceneResourcePath = "res://.godot/manifest_ui_export_selfcheck/FixtureWidget.tscn";
        var textureResourcePath = "res://.godot/manifest_ui_export_selfcheck/assets/icon.tres";
        var image = Image.CreateEmpty(2, 2, false, Image.Format.Rgba8);
        image.Fill(new Color(0.2f, 0.7f, 1.0f, 1.0f));
        var texture = ImageTexture.CreateFromImage(image);
        Require(ResourceSaver.Save(texture, textureResourcePath) == Error.Ok, "fixture texture save failed");
        var savedTexture = ResourceLoader.Load<Texture2D>(textureResourcePath, cacheMode: ResourceLoader.CacheMode.Replace)
            ?? throw new InvalidOperationException("fixture texture load failed");

        var root = new Control { Name = "FixtureWidget" };
        root.SetMeta("_manifest_ui_id", "root");
        var panel = new ManifestUiExportFixtureControl
        {
            Name = "RenamedPanel",
            AccentColor = new Color(0.1f, 0.2f, 0.3f, 0.8f),
            TargetPath = new NodePath("Title"),
            GridSize = new Vector2I(32, 48),
            Icon = savedTexture,
        };
        panel.SetMeta("_manifest_ui_id", "panel");
        root.AddChild(panel);
        panel.Owner = root;
        var title = new Label { Name = "Title", Text = "Updated title" };
        title.SetMeta("_manifest_ui_id", "title");
        panel.AddChild(title);
        title.Owner = root;
        var added = new Label { Name = "NewLabel", Text = "New" };
        root.AddChild(added);
        added.Owner = root;

        var packedScene = new PackedScene();
        Require(packedScene.Pack(root) == Error.Ok, "fixture scene pack failed");
        Require(ResourceSaver.Save(packedScene, sceneResourcePath) == Error.Ok, "fixture scene save failed");
        root.Free();

        WriteFixtureFiles(fixtureDirectory);
        var packagePath = Path.Combine(fixtureDirectory, "package.json");
        var result = ManifestUiSceneExporter.Export(packagePath);
        Require(result.Success, string.Join("\n", result.Diagnostics.Select(item => $"{item.JsonPointer}: {item.Message}")));

        var layout = JsonNode.Parse(File.ReadAllText(Path.Combine(fixtureDirectory, "layout.json")))!.AsObject();
        var exportedRoot = layout["root"]!.AsObject();
        var rootChildren = exportedRoot["children"]!.AsArray();
        var exportedPanel = rootChildren[0]!.AsObject();
        Require(exportedPanel["id"]!.GetValue<string>() == "panel", "renamed node should keep metadata id");
        Require(exportedPanel["name"]!.GetValue<string>() == "RenamedPanel", "renamed node name was not exported");
        var properties = exportedPanel["properties"]!.AsObject();
        Require(properties["AccentColor"]!["color"]!.AsArray().Count == 4, "Color property was not exported");
        Require(properties["TargetPath"]!["nodePath"]!.GetValue<string>() == "Title", "NodePath property was not exported");
        Require(properties["GridSize"]!["vector2i"]![1]!.GetValue<int>() == 48, "Vector2i property was not exported");
        Require(!string.IsNullOrWhiteSpace(properties["Icon"]!["assetRef"]!.GetValue<string>()), "resource property was not exported");
        Require(rootChildren[1]!["id"]!.GetValue<string>() == "NewLabel", "new node id was not derived from its name");

        var assets = JsonNode.Parse(File.ReadAllText(Path.Combine(fixtureDirectory, "assets.json")))!.AsObject()["assets"]!.AsArray();
        Require(assets.Count == 1 && assets[0]!["relativePath"]!.GetValue<string>() == "assets/icon.tres", "new asset was not registered");
        var strings = JsonNode.Parse(File.ReadAllText(Path.Combine(fixtureDirectory, "strings.json")))!.AsObject();
        Require(strings["strings"]!["fixture.title"]!["en"]!.GetValue<string>() == "Updated title", "default locale was not updated");

        var generated = ManifestUiTool.Execute(new[] { "generate", packagePath }, projectRoot);
        Require(generated.Success, "fixture generation failed after scene export");
        var check = ManifestUiTool.Execute(new[] { "generate", packagePath, "--check" }, projectRoot);
        Require(check.Success, "generated output drifted after scene export");
        Require(File.ReadAllText(Path.Combine(fixtureDirectory, "FixtureWidget.tscn")).Contains("metadata/_manifest_ui_id", StringComparison.Ordinal), "generated scene omitted stable node ids");

        Directory.Delete(fixtureDirectory, recursive: true);
    }

    private static void WriteFixtureFiles(string directory)
    {
        File.WriteAllText(Path.Combine(directory, "package.json"), """
            {
              "schemaVersion": 1,
              "packageId": "ui.export_fixture",
              "displayName": "Export Fixture",
              "designResolution": [640, 480],
              "assets": "assets.json",
              "layout": "layout.json",
              "bindings": "bindings.json",
              "codegen": "codegen.json",
              "validation": "validation.json",
              "strings": "strings.json",
              "runtime": { "controllerScope": "package" },
              "godot": {
                "systemName": "export_fixture",
                "widgetClass": "FixtureWidget",
                "controllerClass": "GodotUi.Tests.FixtureController",
                "namespace": "GodotUi.Tests.Generated",
                "outputDir": ".godot/manifest_ui_export_selfcheck",
                "scenePath": "res://.godot/manifest_ui_export_selfcheck/FixtureWidget.tscn"
              }
            }
            """);
        File.WriteAllText(Path.Combine(directory, "assets.json"), "{ \"assets\": [] }\n");
        File.WriteAllText(Path.Combine(directory, "layout.json"), """
            {
              "root": {
                "id": "root", "type": "Control", "name": "FixtureWidget", "properties": {},
                "children": [
                  {
                    "id": "panel", "type": "Control", "name": "OldPanel",
                    "scriptPath": "res://tests/ManifestUiExportFixtureControl.cs", "properties": {},
                    "children": [
                      {
                        "id": "title", "type": "Label", "name": "Title", "properties": {},
                        "localization": { "text": { "key": "fixture.title", "context": "fixture", "arguments": [] } },
                        "children": []
                      }
                    ]
                  }
                ]
              }
            }
            """);
        File.WriteAllText(Path.Combine(directory, "bindings.json"), """
            { "mvvm": { "updatePolicy": "manual", "fields": [] }, "bindings": {}, "repeaters": [], "inputs": [], "controls": [], "events": { "channels": [] } }
            """);
        File.WriteAllText(Path.Combine(directory, "codegen.json"), """
            { "schemaVersion": 1, "generator": "ManifestUi", "requiredServices": [], "routes": [] }
            """);
        File.WriteAllText(Path.Combine(directory, "validation.json"), """
            { "commandletInputWhitelist": ["assets.json", "layout.json", "bindings.json", "codegen.json", "validation.json", "strings.json"], "checks": {} }
            """);
        File.WriteAllText(Path.Combine(directory, "strings.json"), """
            { "schemaVersion": 1, "defaultLocale": "en", "locales": ["en", "zh"], "strings": { "fixture.title": { "en": "Old title", "zh": "旧标题" } } }
            """);
    }

    private async Task CheckLifecycle()
    {
        var manager = ManifestUiManager.Instance ?? throw new InvalidOperationException("ManifestUiManager autoload missing");

        var previousFocus = new Button
        {
            Name = "PreviousFocus",
            FocusMode = Control.FocusModeEnum.All,
        };
        AddChild(previousFocus);
        previousFocus.GrabFocus();

        var first = manager.Open("phone_lifecycle", PhoneScene, new ManifestUiOpenOptions
        {
            LayerId = "Test",
            Mode = ManifestUiOpenMode.Reuse,
            GrabFocus = true,
            RestoreFocusOnClose = true,
        });
        await ToSignal(GetTree(), SceneTree.SignalName.ProcessFrame);

        var reused = manager.Open("phone_lifecycle", PhoneScene, new ManifestUiOpenOptions { Mode = ManifestUiOpenMode.Reuse });
        Require(ReferenceEquals(first, reused), "Reuse should return the existing widget");

        var controller = manager.FindController("ui.phone") ?? throw new InvalidOperationException("Phone controller missing");
        Require(controller.ActiveWidgetCount == 1, "controller should track opened widget");
        Require(first.GetNode<Label>("Panel/Content/TitleLabel").Text == "Phone", "first open should flush title");
        Require(first.GetNode<Label>("Panel/Content/CountLabel").Text == "Contacts opened 0 time(s)", "format text should apply");
        var contactsList = first.GetNode<VBoxContainer>("Panel/Content/Tabs/ContactsTab/ContactsList");
        var template = contactsList.GetNode<Control>("ContactItemTemplate");
        Require(!template.Visible, "repeater template should be hidden");
        Require(contactsList.GetChildren().OfType<Control>().Count(child => child.HasMeta("manifest_repeater")) == 2, "repeater should render initial contacts");
        Require(contactsList.GetNode<Label>("ContactItemTemplate_0/NameLabel").Text == "Ada", "repeater item name should bind");
        Require(contactsList.GetNode<Label>("ContactItemTemplate_1/PhoneLabel").Text == "1002", "repeater item phone should bind");
        Require(manager.FindController("ui.badge")?.ActiveWidgetCount == 1, "scene include generated child should attach controller");
        Require(Math.Abs(first.GetNode<ProgressBar>("Panel/Content/BatteryBar").Value - 7.0) < 0.01, "range value should apply");
        Require(!first.GetNode<Label>("Panel/Content/DetailsLabel").Visible, "visibility binding should apply");
        Require(!first.GetNode<Button>("Panel/Content/ContactsButton").Disabled, "enabled binding should apply");
        Require(first.GetNode<TextureRect>("Panel/Content/IconTexture").Texture is not null, "texture binding should load");
        Require(first.Theme is not null, "generated theme should load");
        var theme = first.Theme!;
        Require(theme.ResourcePath == "res://generated/ui/phone/assets/PhoneTheme.tres", "generated theme path mismatch");
        Require(theme.DefaultFont is not null, "generated theme should set default font");
        Require(theme.DefaultFontSize == 14, "generated theme should set default font size");
        Require(first.GetNode<Panel>("Panel").ThemeTypeVariation == "PhonePanel", "themeClass binding should apply");

        var search = first.GetNode<LineEdit>("Panel/Content/SearchInput");
        search.Text = "Ada";
        search.EmitSignal(LineEdit.SignalName.TextChanged, "Ada");
        Require(controller.Store.TryGet("searchText", out var searchValue) && (string)searchValue! == "Ada", "input should write back to store");
        Require(first.GetNode<Label>("Panel/Content/StatusLabel").Text == "Search: Ada", "input change should call controller hook");

        first.GetNode<TabContainer>("Panel/Content/Tabs").EmitSignal(TabContainer.SignalName.TabChanged, 1);
        Require(first.GetNode<Label>("Panel/Content/StatusLabel").Text == "Tab changed", "tab event should dispatch");

        first.GetNode<Button>("Panel/Content/ContactsButton").EmitSignal(BaseButton.SignalName.Pressed);
        Require(first.GetNode<Label>("Panel/Content/CountLabel").Text == "Contacts opened 1 time(s)", "button event should refresh formatted text");
        Require(first.GetNode<Label>("Panel/Content/DetailsLabel").Visible, "button event should refresh visibility");
        Require(contactsList.GetChildren().OfType<Control>().Count(child => child.HasMeta("manifest_repeater")) == 3, "repeater should rebuild after collection update");
        Require(manager.GetOpenCount("phone_modal") == 1, "controller modal helper should open modal");
        manager.Close("phone_modal");
        await ToSignal(GetTree(), SceneTree.SignalName.ProcessFrame);
        controller.Store.Set("lifecycle_marker", "kept");

        manager.Close("phone_lifecycle");
        await ToSignal(GetTree(), SceneTree.SignalName.ProcessFrame);
        Require(controller.ActiveWidgetCount == 0, "controller should detach closed widget");
        Require(ReferenceEquals(GetViewport().GuiGetFocusOwner(), previousFocus), "close should restore previous focus");

        var reopened = manager.Open("phone_lifecycle", PhoneScene);
        await ToSignal(GetTree(), SceneTree.SignalName.ProcessFrame);
        Require(ReferenceEquals(manager.FindController("ui.phone"), controller), "controller should be manager-owned and reused");
        Require(controller.Store.TryGet("lifecycle_marker", out var marker) && (string)marker! == "kept", "shared store should survive reopen");
        Require(reopened.GetNode<Label>("Panel/Content/TitleLabel").Text == "Phone", "reopen should flush retained title");
        manager.Close("phone_lifecycle");
        await ToSignal(GetTree(), SceneTree.SignalName.ProcessFrame);

        var replaceFirst = manager.Open("phone_replace", PhoneScene);
        await ToSignal(GetTree(), SceneTree.SignalName.ProcessFrame);
        var replaceSecond = manager.Open("phone_replace", PhoneScene, new ManifestUiOpenOptions { Mode = ManifestUiOpenMode.Replace });
        await ToSignal(GetTree(), SceneTree.SignalName.ProcessFrame);
        Require(!ReferenceEquals(replaceFirst, replaceSecond), "Replace should open a new widget");
        Require(manager.GetOpenCount("phone_replace") == 1, "Replace should leave one open widget");
        manager.Close("phone_replace");
        await ToSignal(GetTree(), SceneTree.SignalName.ProcessFrame);

        previousFocus.QueueFree();
    }

    private static void Require(bool condition, string message)
    {
        if (!condition)
        {
            throw new InvalidOperationException(message);
        }
    }

    private sealed record CheckResult(string Name, TimeSpan Elapsed, Exception? Exception);
}
