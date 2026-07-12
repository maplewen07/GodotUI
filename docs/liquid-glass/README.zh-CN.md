# Liquid Glass

Liquid Glass 是 GodotUI 中独立版本管理的第二个 addon。当前版本是基于 Godot 4.7
Mono 与 .NET 8 的 clean-room alpha，可在不安装 Manifest UI 的情况下单独使用。

当前包含：

- Rounded Rectangle、Superellipse、Capsule、Circle 四种 Panel 形状；
- blur、refraction、dispersion、tint、rim、inner shadow 与原创 presets；
- 支持鼠标、键盘和 `ui_accept/ui_left/ui_right` 的 Button 与 Slider；
- Godot 4.7 可用范围内的 accessibility role、名称、描述、禁用状态和数值范围；
- 三分辨率截图、重叠玻璃像素、粗略帧时预算和 ZIP-only 干净安装门禁。

安装时下载 `liquid-glass-X.Y.Z.zip`，校验同一 Release 中的
`SHA256SUMS.txt`，再解压到项目根目录。最终路径应为：

```text
addons/liquid_glass/plugin.cfg
```

编译 C# 项目后，在 **项目 > 项目设置 > 插件** 中启用
**GodotUI Liquid Glass**。该插件不创建 autoload，也不依赖 Manifest UI。

本地视觉验证：

```powershell
./tests/Run-LiquidGlassVisual.ps1 `
  -GodotBin $env:GODOT_BIN
```

仓库根项目同时启用 Manifest UI 与 Liquid Glass，并提供
`ui/liquid_glass/package.json` 集成演示。该演示使用 `scriptPath` 加载控件、
使用 `assetRef` 加载 `LiquidGlassStyle` 资源，并由 Manifest 生成按钮事件和
Slider 输入连接。它有独立的三分辨率门禁：

```powershell
./tests/Run-ManifestLiquidGlassVisual.ps1 `
  -GodotBin $env:GODOT_BIN
```

alpha 阶段的材质参数与序列化格式仍可能调整。稳定 1.0 路线安排在 Manifest UI
1.0 之后；项目发布前必须在目标分辨率、渲染器和 GPU 上重新验证效果与性能。

详细安装、Manifest scripted-control 接入和测试说明见同目录英文文档。
