# GodotUI

GodotUI 是面向 Godot 4.7 Mono 的 C# UI 项目。首个可发布插件 **Manifest UI**
围绕同一套带版本的 UI Manifest，提供运行时、确定性代码生成、验证和编辑器工作流。

Manifest UI 当前处于 1.0 之前的 alpha 阶段。公开发布所需的包结构、API、测试和迁移
约定仍在完善；预发布版本可能发生变化，但会提供明确的迁移说明。

## 环境要求

- Godot 4.7 Mono；普通非 Mono 版本无法编译本插件。
- .NET SDK 8.0.400，或 `global.json` 允许的更新 .NET 8 补丁版本。
- PowerShell 7，用于仓库验证和发布打包。

仓库不会保存本机 Godot 绝对路径。如果 `godot` 不在 `PATH` 中，请设置：

```powershell
$env:GODOT_BIN = '<Godot 4.7 Mono console executable>'
```

## 安装

从 GitHub Release 下载 `manifest-ui-<version>.zip`，解压到 Godot 项目根目录。
最终路径必须是：

```text
addons/manifest_ui/plugin.cfg
```

编译 C# 项目，然后在 **项目 > 项目设置 > 插件** 中启用 **Manifest UI**。
源码安装、升级和卸载流程见 [安装指南](installation.md)。

## 文档索引

- [英文文档总览](README.md)
- [编辑器工作流](editor-workflow.md)
- [Manifest schema v1 参考](manifest-reference.md)
- [运行时 API](runtime-api.md)
- [问题代码](issue-codes.md)
- [故障排查](troubleshooting.md)
- [迁移与升级](migration.md)
- [Codex Skill](codex-skill.md)
- [Basic 与 Inventory 示例](../examples/README.md)
- [Liquid Glass 独立 alpha 文档](liquid-glass/README.zh-CN.md)

## 源码验证

```powershell
dotnet build GodotUI.csproj --configuration Release
dotnet run --project tools/ManifestUi.Cli -- --help
pwsh ./scripts/ci/Invoke-CI.ps1 -GodotBin $env:GODOT_BIN
```

编辑器插件和 CLI 使用同一个 tooling core。生成的 `.g.cs`、`.tscn` 和 `.tres`
属于受管输出；用户编写的 partial Widget 文件不会被生成器覆盖。

## 发布边界

正式 addon ZIP 只包含 `addons/manifest_ui/`，不依赖仓库其他源码。Manifest UI 使用
`manifest-ui-vX.Y.Z` tag，并依次通过 alpha、beta、RC 和 1.0 门禁。

Liquid Glass 现已有独立的 clean-room alpha 实现、版本元数据、tag、ZIP 和发布工作流；
其稳定 1.0 仍安排在 Manifest UI 1.0 之后。公开仓库与发布物不包含此前评估过的
Unreal Engine 第三方源码、二进制、素材或 Git 历史。

GodotUI 使用 [MIT License](../LICENSE)。第三方依赖说明见
[THIRD_PARTY_NOTICES.md](../THIRD_PARTY_NOTICES.md)。
