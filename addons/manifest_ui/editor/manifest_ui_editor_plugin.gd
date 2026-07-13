@tool
extends EditorPlugin

const SOURCE_ROOTS_SETTING := "manifest_ui/source_roots"
const GENERATED_ROOT_SETTING := "manifest_ui/generated_root"
const OWNED_AUTOLOAD_PREFIX := "manifest_ui/editor/owned_autoloads/"
const CSHARP_DOCK_SCENE := "res://addons/manifest_ui/editor/ManifestUiDock.tscn"
const AUTOLOADS := {
	"ManifestMessageBus": "res://addons/manifest_ui/autoload/ManifestMessageBus.cs",
	"ManifestUiRoot": "res://addons/manifest_ui/autoload/ManifestUiRoot.cs",
	"ManifestUiManager": "res://addons/manifest_ui/autoload/ManifestUiManager.cs",
}

var _dock_host: EditorDock
var _dock: Control
var _run_preview_generation := 0


func _log(phase: String, message: String) -> void:
	print("[Manifest UI] [%s] %s" % [phase, message])


func _enter_tree() -> void:
	if not Engine.is_editor_hint():
		return

	_log("Plugin", "Entering editor tree.")
	_ensure_project_settings()
	_ensure_autoloads()
	_load_csharp_dock()


func _exit_tree() -> void:
	_log("Plugin", "Exiting editor tree and releasing dock.")
	if is_instance_valid(_dock_host):
		remove_dock(_dock_host)
		_dock_host.queue_free()
	_dock_host = null
	_dock = null


func _enable_plugin() -> void:
	_ensure_project_settings()
	_ensure_autoloads()


func _disable_plugin() -> void:
	for autoload_name: String in AUTOLOADS:
		var owned_setting := OWNED_AUTOLOAD_PREFIX + autoload_name
		var autoload_setting := "autoload/" + autoload_name
		var owns_entry := (
			ProjectSettings.has_setting(owned_setting)
			and bool(ProjectSettings.get_setting(owned_setting, false))
		)
		if owns_entry and ProjectSettings.has_setting(autoload_setting):
			var configured := _resolve_configured_path(ProjectSettings.get_setting(autoload_setting))
			if configured == AUTOLOADS[autoload_name]:
				remove_autoload_singleton(autoload_name)
		if ProjectSettings.has_setting(owned_setting):
			ProjectSettings.clear(owned_setting)
	ProjectSettings.save()


func _load_csharp_dock() -> void:
	_log("Dock", "Loading C# dock scene: %s" % CSHARP_DOCK_SCENE)
	var dock_scene := load(CSHARP_DOCK_SCENE) as PackedScene
	if dock_scene == null:
		push_error("[Manifest UI] C# editor dock is unavailable. Build the project in Debug and reload the plugin.")
		return

	var candidate := dock_scene.instantiate()
	if not candidate is Control:
		push_error("[Manifest UI] C# editor dock does not inherit Control.")
		if candidate is Node:
			candidate.queue_free()
		return

	_dock = candidate as Control
	_dock.call(&"Initialize", self)
	_log("Dock", "C# dock initialized with %d child control(s)." % _dock.get_child_count())
	if _dock.get_child_count() == 0:
		push_error("[Manifest UI] C# editor dock initialization produced no controls.")
		_dock.queue_free()
		_dock = null
		return

	_dock_host = EditorDock.new()
	_dock_host.name = "ManifestUI"
	_dock_host.title = "Manifest UI"
	_dock_host.layout_key = "manifest_ui"
	_dock_host.icon_name = "Control"
	_dock_host.default_slot = EditorDock.DOCK_SLOT_LEFT_UL
	_dock_host.available_layouts = EditorDock.DOCK_LAYOUT_VERTICAL | EditorDock.DOCK_LAYOUT_FLOATING
	_dock_host.add_child(_dock)
	add_dock(_dock_host)
	_log("Dock", "Manifest UI dock registered.")


func request_run_preview(scene_path: String) -> void:
	_run_preview_generation += 1
	_log("RunPreview", "Queued generation %d for %s." % [_run_preview_generation, scene_path])
	_start_run_preview.call_deferred(scene_path, _run_preview_generation)


func _start_run_preview(scene_path: String, generation: int) -> void:
	# Let C# Verify continuations and the current editor frame release the old assembly first.
	_log("RunPreview", "Waiting two editor frames before generation %d." % generation)
	await get_tree().process_frame
	await get_tree().process_frame
	if generation != _run_preview_generation or not is_instance_valid(_dock):
		_log("RunPreview", "Canceled stale generation %d." % generation)
		return
	_log("RunPreview", "Starting custom scene %s." % scene_path)
	EditorInterface.play_custom_scene(scene_path)


func _ensure_project_settings() -> void:
	if not ProjectSettings.has_setting(SOURCE_ROOTS_SETTING):
		var default_roots := PackedStringArray(["res://ui"])
		ProjectSettings.set_setting(SOURCE_ROOTS_SETTING, default_roots)
		ProjectSettings.set_initial_value(SOURCE_ROOTS_SETTING, default_roots)
	ProjectSettings.add_property_info({
		"name": SOURCE_ROOTS_SETTING,
		"type": TYPE_PACKED_STRING_ARRAY,
	})

	if not ProjectSettings.has_setting(GENERATED_ROOT_SETTING):
		ProjectSettings.set_setting(GENERATED_ROOT_SETTING, "res://generated/ui")
		ProjectSettings.set_initial_value(GENERATED_ROOT_SETTING, "res://generated/ui")
	ProjectSettings.add_property_info({
		"name": GENERATED_ROOT_SETTING,
		"type": TYPE_STRING,
		"hint": PROPERTY_HINT_DIR,
	})
	ProjectSettings.save()


func _ensure_autoloads() -> void:
	for autoload_name: String in AUTOLOADS:
		var expected_path: String = AUTOLOADS[autoload_name]
		var setting := "autoload/" + autoload_name
		if not ProjectSettings.has_setting(setting):
			add_autoload_singleton(autoload_name, expected_path)
			ProjectSettings.set_setting(OWNED_AUTOLOAD_PREFIX + autoload_name, true)
			continue

		var configured := _resolve_configured_path(ProjectSettings.get_setting(setting))
		if configured != expected_path:
			push_error(
				"[Manifest UI] Autoload '%s' already points to '%s'. The plugin did not overwrite it."
				% [autoload_name, configured]
			)
	ProjectSettings.save()


func _resolve_configured_path(value: Variant) -> String:
	var configured := str(value).trim_prefix("*")
	if configured.begins_with("uid://"):
		var resource_id := ResourceUID.text_to_id(configured)
		if ResourceUID.has_id(resource_id):
			return ResourceUID.get_id_path(resource_id)
	return configured
