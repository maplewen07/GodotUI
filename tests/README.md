# Test Suites

Manifest UI has two release-gate suites:

- `ManifestUi.Tooling.Tests` covers schema loading, stable diagnostics, CLI JSON/SARIF output, path safety, managed cleanup, atomic generation, user-stub preservation, naming conflicts, and deterministic UTF-8/LF output.
- `SelfCheck.tscn` runs the Godot 4.7 Mono runtime contracts and writes JUnit XML, including async lifecycle, modal pause ordering, cancellation, replacement, external `QueueFree`, and a 1000-cycle leak check.

Run the tooling suite:

```powershell
dotnet test tests/ManifestUi.Tooling.Tests/ManifestUi.Tooling.Tests.csproj
```

Run the Godot suite with the release-supported engine:

```powershell
$env:GODOT_BIN = "<Godot 4.7 Mono console executable>"
./tests/Run-GodotSelfCheck.ps1
```

The runner writes `artifacts/test-results/manifest-ui-self-check.xml` by default. Set `MANIFEST_UI_JUNIT_PATH` when invoking the scene directly, or pass `-JUnitPath` to the script. It also fails the release gate if Godot reports leaked ObjectDB instances even when the scene itself exits with code 0.

During the alpha channel, repository CI passes
`-AllowKnownGodotThreadedLoaderLeak`. That switch accepts only the isolated
Godot 4.7 signature documented in `docs/known-issues.md`: one to four
`RefCounted` leaks with native reference count zero. It never permits a
different type, nonzero reference count, or a count above the fixture bound,
and later release channels do not use the switch.

Set `MANIFEST_UI_TEST_FILTER` to a case-name substring when isolating a runtime failure. The release gate runs without a filter.
