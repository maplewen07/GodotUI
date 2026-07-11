# Third-Party Notices

GodotUI does not redistribute the previously evaluated `CBLiquidGlass` Unreal
Engine plugin, its source code, binaries, documentation, or assets. The current
Liquid Glass alpha is a clean-room implementation based only on public Godot
4.7 APIs and an independently written behavior specification. Its addon
archive contains original project code, shader, icon, presets, documentation,
and examples, with no third-party source or asset payload.

Manifest UI and Liquid Glass depend on Godot Engine and the .NET runtime at
build and run time. Those products are not bundled in either addon archive and
remain under their respective licenses:

- Godot Engine: MIT License, copyright Juan Linietsky, Ariel Manzur, and
  contributors.
- .NET: MIT License, copyright the .NET Foundation and contributors.

Development and test dependencies are restored by their package managers and
are not redistributed in the addon archive. Their license files and package
metadata are the authoritative source for their terms.

User projects remain responsible for the licenses of assets, fonts, scenes,
and code referenced by their manifests.
