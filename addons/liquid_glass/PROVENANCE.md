# Clean-Room Provenance

Liquid Glass is an original Godot 4.7 implementation owned by `maplewen`.

## Boundary

- The implementation was written from a behavioral specification for a
  Godot-native glass surface and standard Godot Control interactions.
- Removed third-party source trees, Git history, assets, presets,
  documentation, parameter names, and implementation details were not used as
  implementation inputs.
- The addon uses only public Godot 4.7 APIs: `Control`, `BackBufferCopy`,
  screen textures, CanvasItem shaders, input actions, and the accessibility
  server.

## Original materials

The C# runtime, shader, editor registration shim, icon, presets, examples,
tests, documentation, and release scripts in this addon were created for this
repository. The public release process packages only files under
`addons/liquid_glass/` and separately prepared original examples.

## Review rule

Contributors must not submit code or assets copied or translated from a
third-party glass plugin. Changes should be justified by this addon's written
behavior specification, Godot's public API, or independently measured output.
Potential provenance concerns should be reported through the repository's
security contact before release.
