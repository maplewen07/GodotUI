# Known Issues

## Godot 4.7 threaded ResourceLoader leak report

Godot 4.7 stable reports a leaked `RefCounted` object after each distinct completed
`ResourceLoader.LoadThreadedRequest` / `LoadThreadedGet` cycle. The same result
occurs with `useSubThreads` enabled or disabled and after the returned resource
wrapper is disposed. Synchronous `ResourceLoader.Load` does not reproduce it.

Manifest UI keeps the threaded loader because asynchronous loading is part of
its runtime contract. Its own handles, Controllers, subscriptions, scene Nodes,
preload dictionary, and translation ownership return to baseline in the
1000-cycle stress test.

The behavior is isolated in `tests/Run-GodotSelfCheck.ps1`. Alpha verification
may allow only the exact known signature: between one and four `RefCounted`
instances with native reference count zero. The bound covers the independent
fixtures loaded by the suite. Any different type, nonzero reference count, or
additional instance fails immediately.
Beta, release-candidate, and stable channels treat this signature as a release
failure too.

Upstream references:

- [Godot issue #102476: ResourceLoader::LoadToken leaks](https://github.com/godotengine/godot/issues/102476)
- [Godot PR #118824: threaded request race and LoadToken leak fix](https://github.com/godotengine/godot/pull/118824)

The fix is merged into Godot's master branch but is not present in the supported
Godot 4.7 stable binary used by this repository. Re-run the strict gate when an
official compatible Godot build contains the fix.
