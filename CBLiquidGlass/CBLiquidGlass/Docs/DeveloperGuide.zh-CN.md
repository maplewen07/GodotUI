# CBLiquidGlass 插件开发者文档

本文只说明 `CBLiquidGlass` 插件本身的使用、扩展、调试和性能特征。插件目标是在 UMG/Slate UI 中提供可调的 Liquid Glass 玻璃控件：采样控件背后的 backbuffer，经过模糊、折射、色散、tint、边缘光和内阴影后，再把子控件清晰绘制在玻璃上方。

## 插件能力概览

| 能力 | 说明 |
| --- | --- |
| UMG 控件 | `UCBLiquidGlass`，在 UMG 设计器中显示为 `Liquid Glass`。 |
| UMG 交互控件 | `UCBLiquidGlassButton`、`UCBLiquidGlassText`、`UCBLiquidGlassSlider`，用于按钮、文字玻璃和果冻滑动条。 |
| Slate 控件 | `SCBLiquidGlass`，可直接在 Slate 代码中使用。 |
| 形状 | `SuperellipseRect`、`Capsule`、`Circle`。 |
| 预设 | `Clear`、`Regular`、`FrostedMenu`、`PillLens`、`MatteLayer`、`SelfLayer`。 |
| 背景采样 | 使用 Slate custom element 在 render thread 中复制控件背后的 backbuffer 区域。 |
| Shader 效果 | downsample、separable blur、清晰/模糊背景混合、形状 SDF、折射、色散、tint、边缘光、内阴影。 |
| Demo | `CBLiquidGlass.Demo` 展示效果；`CBLiquidGlass.ControlDemo` 透明背景调参；`CBLiquidGlass.SliderDemo` 展示果冻滑动条。 |

## 目录结构

| 路径 | 作用 |
| --- | --- |
| `CBLiquidGlass.uplugin` | 插件描述文件，模块加载阶段为 `PostConfigInit`，用于保证 shader 目录映射尽早注册。 |
| `Source/CBLiquidGlass/Public/CBLiquidGlassTypes.h` | 蓝图可见枚举：预设和形状。 |
| `Source/CBLiquidGlass/Public/CBLiquidGlassWidget.h` | UMG 控件 API、蓝图属性和 Setter。 |
| `Source/CBLiquidGlass/Public/CBLiquidGlassSlider.h` | UMG 果冻滑动条 API、蓝图属性和数值变化事件。 |
| `Source/CBLiquidGlass/Public/SCBLiquidGlass.h` | Slate 控件 API。 |
| `Source/CBLiquidGlass/Public/SCBLiquidGlassSlider.h` | Slate 液体玻璃滑动条，包含弹簧追随和滑块 Q 弹形变。 |
| `Source/CBLiquidGlass/Private/CBLiquidGlassRenderer.cpp` | RDG 渲染流程：复制背景、降采样、模糊、最终合成。 |
| `Shaders/Private/CBLiquidGlass.usf` | 插件全局 shader。 |
| `Source/CBLiquidGlass/Private/CBLiquidGlassDemo.cpp` | Demo 和控制台命令。 |
| `Resources/1.jpg`–`4.jpg` | Demo 从中随机选用的展示背景图。 |
| `Source/CBLiquidGlass/Private/CBLiquidGlassRecipes.h/.cpp` | 集中的玻璃配方表：`FCBLiquidGlassRecipe` + 预设配方，预设与控件共用同一套参数来源。 |
| `Source/CBLiquidGlass/Private/CBLiquidGlassMotion.h` | 共享弹簧步进 `StepSpring`，供各动画控件复用。 |
| `Resources/Icons/*.svg` | Demo 使用的 SVG 图标。 |

## 快速使用

### 在 UMG 中使用

1. 在 UMG Widget Blueprint 中添加 `Liquid Glass` 控件。
2. 把文本、按钮、图标、菜单等内容作为 `Liquid Glass` 的子控件放进去。
3. 在 Details 面板选择 `Preset`，推荐从 `Regular` 或 `FrostedMenu` 开始。
4. 如果边角太圆，提高 `SquirclePower`；如果发灰，降低 `TintOpacity` 和 `FrostRadius`。

`Liquid Glass` 是单子控件容器。玻璃效果绘制在子控件后方，子控件本身不会被模糊。

### 在 Slate 中使用

```cpp
SNew(SCBLiquidGlass)
    .Shape(ECBLiquidGlassShape::SuperellipseRect)
    .SquirclePower(7.0f)
    .BlurStrength(0.95f)
    .FrostRadius(0.28f)
    .RefractionStrength(0.9f)
    .RefractionThickness(34.0f)
    .IndexOfRefraction(1.85f)
    .TintOpacity(0.015f)
[
    SNew(STextBlock)
    .Text(FText::FromString(TEXT("Glass Content")))
];
```

## Demo 调用方式

所有 demo 都是运行时 viewport overlay。需要在 PIE 或运行中的游戏 viewport 中调用。

| 命令 | 背景 | 作用 | 交互 | 再次调用 |
| --- | --- | --- | --- | --- |
| `CBLiquidGlass.Demo` | 从 `Resources` 随机选用背景图 | 展示卡片、菜单、胶囊按钮、圆形镜片、Matte/Self Layer 示例 | 多数玻璃控件支持短暂长按后拖动 | 关闭 demo |
| `CBLiquidGlass.ControlDemo` | 透明，不绘制全屏背景 | 在当前场景上叠加调参面板和玻璃预览 | 拖动滑条实时修改预览参数 | 关闭 demo |
| `CBLiquidGlass.SliderDemo` | 从 `Resources` 随机选择背景 | 展示一条参考 Apple 风格的蓝色进度滑动条 | 拖动轨道或滑块时，玻璃滑块会轻微滞后、拉伸并带一点受控回弹 | 替换当前 feature demo |

### 在 PIE 控制台调用

1. 启动 PIE。
2. 打开控制台或 Output Log 的命令输入框。
3. 输入：

```text
CBLiquidGlass.Demo
```

或：

```text
CBLiquidGlass.ControlDemo
```

### 在蓝图中调用

使用 `Execute Console Command` 节点，命令字符串填写：

```text
CBLiquidGlass.Demo
```

或：

```text
CBLiquidGlass.ControlDemo
```

### 在 C++ 中调用

```cpp
if (GEngine && World)
{
    GEngine->Exec(World, TEXT("CBLiquidGlass.ControlDemo"));
}
```

## Demo 内容说明

### `CBLiquidGlass.Demo`

| 控件 | 参数方向 | 用途 |
| --- | --- | --- |
| Regular Glass 卡片 | 中等折射、低 tint、低霜化、较收的边角 | 展示常规卡片玻璃。 |
| Clear / Pill Lens / Prism 按钮 | `Capsule` 形状、中心清透、边缘折射 | 展示小型流体按钮。 |
| Frosted Menu | 更低饱和、轻内阴影、轻 tint | 展示菜单/上下文面板。 |
| Circle Lens | `Circle` 形状、低霜化、高折射 | 展示圆形镜片。 |
| Matte Layer | 高霜化、弱折射 | 展示磨砂层。 |
| Self Layer | 低霜化、强调边缘折射 | 展示清透层。 |

### `CBLiquidGlass.ControlDemo`

控制面板是透明背景 overlay，不会覆盖当前场景背景。它主要用于在真实场景或真实 UI 上调试参数。

| 滑条 | 对应参数 | 影响 |
| --- | --- | --- |
| Corner Power | `SquirclePower` | 控制矩形边角。值越高，边角越收；值越低，越圆。 |
| Blur | `BlurStrength` | 背景模糊强度。 |
| Frost | `FrostRadius` | 清晰背景与模糊背景的混合比例。 |
| Refraction | `RefractionStrength` | 折射总体强度。 |
| Thickness | `RefractionThickness` | 折射边缘宽度。 |
| IOR | `IndexOfRefraction` | 折射放大系数。 |
| Prism | `PrismIntensity` | 彩边/棱镜色散强度。 |
| Tint | `TintOpacity` | 玻璃 tint 强度。 |
| Rim | `RimIntensity` | 边缘亮线强度。 |
| Inner Shadow | `InnerShadowIntensity` | 内阴影强度。 |
| Opacity | `GlassOpacity` | 整体合成透明度。 |

### `CBLiquidGlass.SliderDemo`

`SliderDemo` 展示 `SCBLiquidGlassSlider` 的主滑杆效果。滑条由三层组成：半透明玻璃轨道、蓝色进度条、液体玻璃滑块。真实数值会立即更新，视觉滑块用轻欠阻尼弹簧追随真实值，因此快速拖动时会有苹果式的轻微拉伸和受控回弹，不会出现橡皮筋式大幅弹跳。

| 参数 | 作用 |
| --- | --- |
| `ThumbBounce` | 控制滑块拉伸/压缩幅度，`0` 表示关闭额外液态形变。（旧名 `JellyStrength`） |
| `ThumbResponse` | 控制视觉滑块追随真实值的速度，越高越紧。（旧名 `JellyResponse`） |
| `ThumbDamping` | 控制阻尼比例，`8` 到 `10` 更接近苹果式轻回弹；越低越软，越高越硬。（旧名 `JellyDamping`） |
| `ThumbMotionStrength` | 控制底层玻璃 shader 的运动形变强度，苹果式效果建议保持较低。（旧名 `ThumbMotionDeformationStrength`） |

## 预设

| 预设 | 推荐场景 | 视觉特征 | 注意事项 |
| --- | --- | --- | --- |
| `Custom` | 手动调参 | 不自动改写参数 | 修改任意视觉参数后会回到 `Custom`。 |
| `Clear` | 小按钮、悬浮工具 | 清透、低 tint、低霜化 | 背景太复杂时可略加 `FrostRadius`。 |
| `Regular` | 通用卡片 | 清晰度、折射、边缘光较均衡 | 当前默认建议从这里开始。 |
| `FrostedMenu` | 右键菜单、浮层菜单 | 轻磨砂、轻内阴影、文字可读性更好 | 不要把 tint 调太高，否则发灰。 |
| `PillLens` | 胶囊按钮、Tab、浮动快捷入口 | 边缘折射更明显 | 适合 `Capsule` 形状。 |
| `MatteLayer` | 背景遮罩、弱玻璃面板 | 折射弱、霜化更明显 | 性能和普通玻璃接近，只是视觉更软。 |
| `SelfLayer` | 清透浮层 | 低霜化、轻折射 | 对背景内容依赖更强。 |

## 形状

| 形状 | 使用场景 | 参数建议 |
| --- | --- | --- |
| `SuperellipseRect` | 卡片、菜单、控制面板 | `SquirclePower` 建议 `6.0` 到 `9.0`。如果觉得角太圆，继续提高。 |
| `Capsule` | pill 按钮、标签、短条控件 | 不依赖 `SquirclePower`，由尺寸决定胶囊半径。 |
| `Circle` | 圆形镜片、关闭按钮、浮动光斑 | 控件宽高应尽量一致。 |

## 参数说明

| 参数 | 范围建议 | 成本影响 | 视觉影响 |
| --- | --- | --- | --- |
| `SquirclePower` | `2.0` 到 `12.0` | 很低 | 控制超椭圆矩形边角。 |
| `BlurStrength` | `0.0` 到 `3.5` | 中 | 控制 blur pass 的采样跨度。过高会糊。 |
| `DownsampleAmount` | `1` 到 `8` | 高 | 值越高，blur 纹理越小，性能更好但更软。 |
| `FrostRadius` | `0.0` 到 `1.0` | 很低 | 控制清晰背景和模糊背景混合。高值更磨砂。 |
| `RefractionStrength` | `0.0` 到 `1.0` | 很低 | 控制 UV 弯折强度。 |
| `RefractionPower` | `0.5` 到 `6.0` | 很低 | 控制折射向边缘集中的程度。 |
| `RefractionThickness` | `4` 到 `80` | 很低 | 控制折射边缘宽度。太高会像鼓包。 |
| `IndexOfRefraction` | `1.0` 到 `2.4` | 很低 | 折射放大系数。 |
| `ChromaticAberration` | `0.0` 到 `0.3` | 低 | RGB 分离基础强度。 |
| `PrismIntensity` | `0.0` 到 `2.0` | 低 | 彩边增强。过高会脏。 |
| `NoiseAmount` | `0.0` 到 `0.05` | 很低 | 打散 banding。高值会变颗粒。 |
| `TintOpacity` | `0.0` 到 `0.12` | 很低 | tint 强度。过高会发灰。 |
| `Saturation` | `0.8` 到 `1.5` | 很低 | 背景颜色增强或减弱。 |
| `AdaptiveTintStrength` | `0.0` 到 `0.15` | 很低 | 根据背景亮度调整 tint。 |
| `RimIntensity` | `0.0` 到 `0.6` | 很低 | 边缘亮线强度。 |
| `InnerGlowIntensity` | `0.0` 到 `0.3` | 很低 | 内部边缘发光。 |
| `InnerShadowIntensity` | `0.0` 到 `0.5` | 很低 | 内阴影和层次感。 |
| `GlassOpacity` | `0.1` 到 `1.0` | 很低 | 整体合成透明度。 |

## 新增组件

以下组件在 UMG 设计器的 `Liquid Glass` 分类下，对标  26 常见控件。文件位于 `CBLiquidGlassExtras.h/.cpp`（UMG）与 `SCBLiquidGlassExtras.h/.cpp`（Slate）。在 PIE 中运行控制台命令 `CBLiquidGlass.ComponentGallery` 可一次性预览全部新组件。

| 组件 | 对标苹果 | 关键参数 / 事件 |
| --- | --- | --- |
| `Liquid Glass Container` | `GlassEffectContainer(spacing:)` | `Blobs`（各 `FCBLiquidGlassFusionBlob`：归一化 `Position`、像素 `Size`、`Roundness`）、`Smoothing`（融合半径，越大越易融合）、`CanvasSize`、`Preset`。把多个圆角块用 smooth-union 合成单层玻璃，邻近时液态融合。 |
| `Liquid Glass Page Control` | `UIPageControl` | `NumPages`、`CurrentPage`、`DotSize`、`DotSpacing`、`ActiveColor`、`SpringSettings`；事件 `OnPageChanged`。活动页为弹簧滑动的胶囊点。 |
| `Liquid Glass Dialog` | Alert / ActionSheet / Sheet | `Title`、`Message`、`Buttons`、`DialogStyle`、`bDimBackground`、`bStartPresented`；方法 `Present()`/`Dismiss()`；事件 `OnButtonClicked`/`OnDismissed`。弹簧淡入的模态玻璃卡片。 |
| `Liquid Glass Navigation Bar` | `UINavigationBar` | `Title`、`bShowBackButton`、`bLargeTitle`、`TrailingItems`；事件 `OnBackClicked`/`OnTrailingItemClicked`。 |
| `Liquid Glass Badge` | UIKit 角标 | `Count`、`MaxCount`（超出显示 `N+`）、`bDotMode`、`Color`。计数 `<=0` 时在非圆点模式下自动隐藏。 |

> 融合容器的合并掩膜在 CPU 上光栅化为一张 transient 纹理（复用 `AlphaMaskTexture` 通路），仅在参数变化时重建；画布超过 1024px 会被夹断以控制成本。Page Control 的圆点直接绘制（苹果的分页点本就不是玻璃），开销极低。

## 渲染流程

| 阶段 | 位置 | 说明 |
| --- | --- | --- |
| 参数收集 | `SCBLiquidGlass::OnPaint` | 计算控件屏幕矩形，整理参数并提交给 custom Slate element。 |
| 背景复制 | `CBLiquidGlassRenderer.cpp` | 从 `Inputs.OutputTexture` 复制控件背后的 backbuffer 区域。 |
| 降采样 | `DownsamplePS` | 对背景区域做 4 tap box downsample。 |
| 模糊 | `BlurPS` | 水平和垂直 separable Gaussian blur。 |
| 合成 | `CompositePS` | 形状 SDF、清晰/模糊混合、折射、色散、tint、边缘光、内阴影。 |
| 子控件绘制 | Slate 正常绘制 | 子控件在玻璃上一层绘制，不参与玻璃 blur。 |

## 性能分析

### 每个玻璃控件的 GPU 工作量

每个可见的 `SCBLiquidGlass` 大致会产生以下 GPU 工作：

| 工作 | 次数 | 成本来源 |
| --- | --- | --- |
| Backbuffer 区域复制 | 1 次 | 与控件像素面积成正比。 |
| Downsample pass | 1 次 | 与降采样后的面积成正比。 |
| Blur pass | 2 次 | 水平一次、垂直一次；与降采样后的面积和采样 tap 数有关。 |
| Composite pass | 1 次 | 与控件原始像素面积成正比。 |

### 影响性能最大的因素

| 因素 | 影响程度 | 原因 | 优化建议 |
| --- | --- | --- | --- |
| 控件屏幕面积 | 高 | copy 和 composite 都按原始面积执行 | 避免给全屏大面板使用强玻璃；优先用于局部 UI。 |
| 控件数量 | 高 | 每个控件都有独立 RDG pass 链路 | 多个邻近玻璃可考虑合并成一个容器。 |
| `DownsampleAmount` | 高 | 直接影响 blur 纹理尺寸 | 大卡片可用 `2` 到 `4`；小按钮可用 `1` 到 `2`。 |
| `BlurStrength` | 中 | 增大 blur 采样跨度，不改变 pass 数 | 控制在视觉刚好够用的范围。 |
| 重叠玻璃 | 中 | 后绘制的玻璃会采样前面已经合成的结果 | 可接受但成本叠加，复杂 UI 中要控制数量。 |
| SVG 图标 | 低 | Demo 中使用 Slate vector brush | 图标数量少时影响很小。 |

### 参数对性能的真实影响

| 参数类型 | 典型参数 | 是否明显影响性能 |
| --- | --- | --- |
| 形状/折射/tint/边缘光 | `Shape`、`RefractionStrength`、`TintOpacity`、`RimIntensity` | 通常不明显，主要是 composite 中少量 ALU。 |
| blur 尺寸相关 | `DownsampleAmount`、控件面积 | 明显影响。 |
| blur 强度 | `BlurStrength` | 中等影响，主要影响采样偏移，不改变 pass 数。 |
| 透明度 | `GlassOpacity` | 几乎不影响。 |

### 推荐性能档位

| 场景 | 推荐参数 |
| --- | --- |
| 小按钮 | `DownsampleAmount=1` 或 `2`，`FrostRadius<0.25`，面积尽量小。 |
| 菜单/卡片 | `DownsampleAmount=2`，`BlurStrength=0.8~1.5`，`FrostRadius=0.25~0.5`。 |
| 大面板 | `DownsampleAmount=3` 或 `4`，降低 `BlurStrength`，避免多个大面板重叠。 |
| 移动端或低端设备 | 减少同时可见玻璃数量，增大 `DownsampleAmount`，降低控件面积。 |

## 常见问题

| 问题 | 处理方式 |
| --- | --- |
| 效果发灰、像白雾 | 降低 `TintOpacity`、`FrostRadius`、`AdaptiveTintStrength`。 |
| 边角太圆 | `SuperellipseRect` 下提高 `SquirclePower`；不要误用 `Capsule`。 |
| 白边太重 | 降低 `RimIntensity`、`InnerGlowIntensity`。 |
| 折射太夸张 | 降低 `RefractionStrength`、`IndexOfRefraction`、`RefractionThickness`。 |
| 背景看不到 | 检查平台是否支持 `FPlatformMisc::SupportsBackbufferSampling()`。不支持时插件会跳过玻璃绘制。 |
| Demo 背景不显示 | 确认 `Resources` 下存在 `1.jpg`–`4.jpg` 等背景图，且插件目录未移动到资源不可访问的位置。 |
| Shader 找不到 | 检查模块加载阶段是否仍为 `PostConfigInit`，以及 `StartupModule()` 是否注册 `/Plugin/CBLiquidGlass` shader 映射。 |

