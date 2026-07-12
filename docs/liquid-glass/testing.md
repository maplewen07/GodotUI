# Testing Liquid Glass

Run the isolated C# compile check:

```powershell
dotnet build tests/LiquidGlass.Compile.csproj --configuration Release
```

Run the local visual gate with the Godot 4.7 Mono console executable:

```powershell
./tests/Run-LiquidGlassVisual.ps1 `
  -GodotBin $env:GODOT_BIN
```

The runner renders 640x360, 960x540, and 1440x810 screenshots under
`artifacts/test-results/liquid-glass/`. It verifies opaque coverage, color
variation, overlap ordering, distinct overlap pixels, action input, and a
coarse average frame-time budget.

The default 50 ms budget is a regression alarm, not a production GPU target.
Use `-FrameBudgetMilliseconds` for a documented device-specific gate.
