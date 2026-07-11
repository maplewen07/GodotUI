# Installation and Releases

Liquid Glass supports Godot 4.7 Mono and .NET 8. Standard Godot builds without
C# support are not supported.

1. Download `liquid-glass-X.Y.Z.zip` from the matching
   `liquid-glass-vX.Y.Z` GitHub Release.
2. Verify the archive against `SHA256SUMS.txt` from the same release.
3. Extract it at the Godot project root. The archive's only top-level path is
   `addons/liquid_glass/`.
4. Build the project's C# solution.
5. Enable **GodotUI Liquid Glass** in Project Settings > Plugins.

The addon creates no autoloads and stores no project-global settings. Disable
the plugin and remove `addons/liquid_glass/` to uninstall it.

Alpha releases may change material parameters and scene serialization. Do not
ship a production project on an alpha without pinning the exact release ZIP
and testing every target renderer.
