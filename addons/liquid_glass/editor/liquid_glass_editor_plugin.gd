@tool
extends EditorPlugin

const TYPES := [
	["LiquidGlassPanel", "Control", "res://addons/liquid_glass/runtime/LiquidGlassPanel.cs"],
	["LiquidGlassButton", "Control", "res://addons/liquid_glass/runtime/LiquidGlassButton.cs"],
	["LiquidGlassSlider", "Control", "res://addons/liquid_glass/runtime/LiquidGlassSlider.cs"],
]


func _enter_tree() -> void:
	var icon := EditorInterface.get_editor_theme().get_icon(&"Control", &"EditorIcons")
	for type_entry: Array in TYPES:
		var script := load(type_entry[2]) as Script
		if script == null:
			push_error("[Liquid Glass] Could not load %s." % type_entry[2])
			continue
		add_custom_type(type_entry[0], type_entry[1], script, icon)


func _exit_tree() -> void:
	for index in range(TYPES.size() - 1, -1, -1):
		remove_custom_type(TYPES[index][0])
