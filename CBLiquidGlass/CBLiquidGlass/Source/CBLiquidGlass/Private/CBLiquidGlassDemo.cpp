// Copyright 2026-Present SteveSantoso. All Rights Reserved.
// Self-contained Liquid Glass showcase. Toggle with the console command: CBLiquidGlass.Demo
// (run it in Play-In-Editor or a packaged game). No content assets required.

#include "SCBLiquidGlass.h"
#include "SCBLiquidGlassButton.h"
#include "SCBLiquidGlassControls.h"
#include "SCBLiquidGlassExtras.h"
#include "SCBLiquidGlassSlider.h"
#include "SCBLiquidGlassText.h"

#include "Widgets/SCompoundWidget.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/SOverlay.h"
#include "Widgets/SCanvas.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Colors/SColorBlock.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SSlider.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Layout/SGridPanel.h"
#include "Widgets/Text/STextBlock.h"
#include "Brushes/SlateDynamicImageBrush.h"
#include "Brushes/SlateImageBrush.h"
#include "Fonts/CompositeFont.h"
#include "Styling/CoreStyle.h"
#include "Styling/SlateColor.h"
#include "Engine/GameViewportClient.h"
#include "Engine/Engine.h"
#include "Engine/Texture2D.h"
#include "Engine/World.h"
#include "HAL/IConsoleManager.h"
#include "HAL/PlatformMisc.h"
#include "HAL/FileManager.h"
#include "HAL/PlatformTime.h"
#include "Containers/Ticker.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "RHITypes.h"
#include "Rendering/SlateRenderTransform.h"
#include "UObject/StrongObjectPtr.h"

#define LOCTEXT_NAMESPACE "CBLiquidGlassDemo"

namespace CBLiquidGlassDemo
{
	// Viewport-owned overlay instances for the two console demos. They are global so the console
	// commands can toggle the same widget off even when called from a different world context.
	static TSharedPtr<SWidget> GDemoWidget;
	static TWeakObjectPtr<UGameViewportClient> GDemoViewport;
	static TSharedPtr<SWidget> GControlDemoWidget;
	static TWeakObjectPtr<UGameViewportClient> GControlDemoViewport;
	static TSharedPtr<SWidget> GFeatureDemoWidget;
	static TWeakObjectPtr<UGameViewportClient> GFeatureDemoViewport;
	static TSharedPtr<SWidget> GShowcaseDemoWidget;
	static TWeakObjectPtr<UGameViewportClient> GShowcaseDemoViewport;
	static TSharedPtr<SWidget> GGalleryDemoWidget;
	static TWeakObjectPtr<UGameViewportClient> GGalleryDemoViewport;

	static FString GetResourceDir()
	{
		const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("CBLiquidGlass"));
		return Plugin.IsValid()
			? FPaths::Combine(Plugin->GetBaseDir(), TEXT("Resources"))
			: FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("CBLiquidGlass/Resources"));
	}

	static bool IsBackgroundImageFile(const FString& FileName)
	{
		const FString Extension = FPaths::GetExtension(FileName, false).ToLower();
		const FString BaseName = FPaths::GetBaseFilename(FileName);
		return (Extension == TEXT("png")
			|| Extension == TEXT("jpg")
			|| Extension == TEXT("jpeg")
			|| Extension == TEXT("bmp"))
			&& !BaseName.StartsWith(TEXT("Icon"), ESearchCase::IgnoreCase);
	}

	static TArray<FString> GetBackgroundImagePaths()
	{
		TArray<FString> FileNames;
		const FString ResourceDir = GetResourceDir();
		IFileManager::Get().FindFiles(FileNames, *FPaths::Combine(ResourceDir, TEXT("*.*")), true, false);

		TArray<FString> ImagePaths;
		for (const FString& FileName : FileNames)
		{
			if (IsBackgroundImageFile(FileName))
			{
				ImagePaths.Add(FPaths::ConvertRelativePathToFull(FPaths::Combine(ResourceDir, FileName)));
			}
		}

		ImagePaths.Sort();
		return ImagePaths;
	}

	static void LogBackgroundImages()
	{
		const TArray<FString> ImagePaths = GetBackgroundImagePaths();
		if (ImagePaths.IsEmpty())
		{
			UE_LOG(LogTemp, Warning, TEXT("CBLiquidGlass: no background images found in %s"), *GetResourceDir());
			return;
		}

		UE_LOG(LogTemp, Display, TEXT("CBLiquidGlass: available demo backgrounds in %s:"), *GetResourceDir());
		for (int32 Index = 0; Index < ImagePaths.Num(); ++Index)
		{
			UE_LOG(LogTemp, Display, TEXT("  %d: %s"), Index + 1, *FPaths::GetCleanFilename(ImagePaths[Index]));
		}
	}

	static FString ResolveRandomBackgroundImagePath(const TCHAR* CommandName)
	{
		const TArray<FString> ImagePaths = GetBackgroundImagePaths();
		if (ImagePaths.IsEmpty())
		{
			UE_LOG(LogTemp, Warning, TEXT("%s: no demo background images were found in %s."), CommandName, *GetResourceDir());
			return FString();
		}

		const FString ImagePath = ImagePaths[FMath::RandHelper(ImagePaths.Num())];
		UE_LOG(LogTemp, Display, TEXT("%s: using random demo background '%s'."), CommandName, *FPaths::GetCleanFilename(ImagePath));
		return ImagePath;
	}

	struct FCBLGSvgPathMask
	{
		TArray<FVector2D> Points;
		bool bClosed = false;
		bool bFilled = false;
		bool bStroked = false;
		float GlyphThickness = 1.0f;
	};

	struct FCBLGSvgCircleMask
	{
		FVector2D Center = FVector2D::ZeroVector;
		float Radius = 0.0f;
		bool bFilled = false;
		bool bStroked = false;
		float GlyphThickness = 1.0f;
	};

	static float Smooth01(float Edge0, float Edge1, float X)
	{
		if (FMath::IsNearlyEqual(Edge0, Edge1))
		{
			return X >= Edge1 ? 1.0f : 0.0f;
		}

		const float T = FMath::Clamp((X - Edge0) / (Edge1 - Edge0), 0.0f, 1.0f);
		return T * T * (3.0f - 2.0f * T);
	}

	static bool IsSvgPathCommand(TCHAR Character)
	{
		switch (Character)
		{
		case TEXT('M'):
		case TEXT('m'):
		case TEXT('L'):
		case TEXT('l'):
		case TEXT('H'):
		case TEXT('h'):
		case TEXT('V'):
		case TEXT('v'):
		case TEXT('C'):
		case TEXT('c'):
		case TEXT('S'):
		case TEXT('s'):
		case TEXT('Z'):
		case TEXT('z'):
			return true;
		default:
			return false;
		}
	}

	static void SkipSvgSeparators(const FString& Text, int32& Position)
	{
		while (Position < Text.Len() && (FChar::IsWhitespace(Text[Position]) || Text[Position] == TEXT(',')))
		{
			++Position;
		}
	}

	static bool TryReadSvgNumber(const FString& Text, int32& Position, float& OutValue)
	{
		SkipSvgSeparators(Text, Position);
		if (Position >= Text.Len() || IsSvgPathCommand(Text[Position]))
		{
			return false;
		}

		const int32 StartPosition = Position;
		if (Text[Position] == TEXT('+') || Text[Position] == TEXT('-'))
		{
			++Position;
		}

		bool bHasDigits = false;
		while (Position < Text.Len() && FChar::IsDigit(Text[Position]))
		{
			bHasDigits = true;
			++Position;
		}

		if (Position < Text.Len() && Text[Position] == TEXT('.'))
		{
			++Position;
			while (Position < Text.Len() && FChar::IsDigit(Text[Position]))
			{
				bHasDigits = true;
				++Position;
			}
		}

		if (!bHasDigits)
		{
			Position = StartPosition;
			return false;
		}

		if (Position < Text.Len() && (Text[Position] == TEXT('e') || Text[Position] == TEXT('E')))
		{
			const int32 ExponentPosition = Position;
			++Position;
			if (Position < Text.Len() && (Text[Position] == TEXT('+') || Text[Position] == TEXT('-')))
			{
				++Position;
			}

			bool bHasExponentDigits = false;
			while (Position < Text.Len() && FChar::IsDigit(Text[Position]))
			{
				bHasExponentDigits = true;
				++Position;
			}

			if (!bHasExponentDigits)
			{
				Position = ExponentPosition;
			}
		}

		OutValue = FCString::Atof(*Text.Mid(StartPosition, Position - StartPosition));
		return true;
	}

	static bool TryExtractSvgAttribute(const FString& Tag, const TCHAR* AttributeName, FString& OutValue)
	{
		const FString Prefix = FString::Printf(TEXT("%s=\""), AttributeName);
		int32 StartIndex = Tag.Find(Prefix, ESearchCase::IgnoreCase, ESearchDir::FromStart);
		if (StartIndex == INDEX_NONE)
		{
			return false;
		}

		StartIndex += Prefix.Len();
		const int32 EndIndex = Tag.Find(TEXT("\""), ESearchCase::CaseSensitive, ESearchDir::FromStart, StartIndex);
		if (EndIndex == INDEX_NONE)
		{
			return false;
		}

		OutValue = Tag.Mid(StartIndex, EndIndex - StartIndex);
		return true;
	}

	static float ExtractSvgFloatAttribute(const FString& Tag, const TCHAR* AttributeName, float DefaultValue)
	{
		FString RawValue;
		return TryExtractSvgAttribute(Tag, AttributeName, RawValue)
			? FCString::Atof(*RawValue)
			: DefaultValue;
	}

	static bool IsSvgAttributeVisible(const FString& Tag, const TCHAR* AttributeName, bool bDefaultVisible)
	{
		FString RawValue;
		if (!TryExtractSvgAttribute(Tag, AttributeName, RawValue))
		{
			return bDefaultVisible;
		}

		return !RawValue.Equals(TEXT("none"), ESearchCase::IgnoreCase)
			&& !RawValue.Equals(TEXT("transparent"), ESearchCase::IgnoreCase);
	}

	static TArray<float> ParseSvgNumberList(const FString& Text)
	{
		TArray<float> Values;
		int32 Position = 0;
		float Value = 0.0f;
		while (TryReadSvgNumber(Text, Position, Value))
		{
			Values.Add(Value);
		}
		return Values;
	}

	static FVector2D CubicBezierPoint(const FVector2D& P0, const FVector2D& P1, const FVector2D& P2, const FVector2D& P3, float T)
	{
		const float OneMinusT = 1.0f - T;
		return P0 * (OneMinusT * OneMinusT * OneMinusT)
			+ P1 * (3.0f * OneMinusT * OneMinusT * T)
			+ P2 * (3.0f * OneMinusT * T * T)
			+ P3 * (T * T * T);
	}

	static float DistanceToSegment(const FVector2D& Point, const FVector2D& A, const FVector2D& B)
	{
		const FVector2D Segment = B - A;
		const float SegmentLengthSquared = Segment.SizeSquared();
		if (SegmentLengthSquared <= UE_SMALL_NUMBER)
		{
			return FVector2D::Distance(Point, A);
		}

		const float T = FMath::Clamp(FVector2D::DotProduct(Point - A, Segment) / SegmentLengthSquared, 0.0f, 1.0f);
		return FVector2D::Distance(Point, A + Segment * T);
	}

	static bool IsPointInsidePolygon(const TArray<FVector2D>& Points, const FVector2D& Point)
	{
		bool bInside = false;
		for (int32 PointIndex = 0, PreviousIndex = Points.Num() - 1; PointIndex < Points.Num(); PreviousIndex = PointIndex++)
		{
			const FVector2D& A = Points[PointIndex];
			const FVector2D& B = Points[PreviousIndex];
			const bool bCrossesY = (A.Y > Point.Y) != (B.Y > Point.Y);
			if (bCrossesY)
			{
				const float Denominator = B.Y - A.Y;
				if (!FMath::IsNearlyZero(Denominator))
				{
					const float XAtY = (B.X - A.X) * (Point.Y - A.Y) / Denominator + A.X;
					if (Point.X < XAtY)
					{
						bInside = !bInside;
					}
				}
			}
		}
		return bInside;
	}

	static float PolygonDistance(const TArray<FVector2D>& Points, const FVector2D& Point)
	{
		float Distance = TNumericLimits<float>::Max();
		for (int32 Index = 0; Index < Points.Num(); ++Index)
		{
			const FVector2D& A = Points[Index];
			const FVector2D& B = Points[(Index + 1) % Points.Num()];
			Distance = FMath::Min(Distance, DistanceToSegment(Point, A, B));
		}
		return Distance;
	}

	static float RasterizeFilledPolygonAlpha(const TArray<FVector2D>& Points, const FVector2D& Point, float Feather)
	{
		if (Points.Num() < 3)
		{
			return 0.0f;
		}

		if (IsPointInsidePolygon(Points, Point))
		{
			return 1.0f;
		}

		return 1.0f - Smooth01(0.0f, Feather, PolygonDistance(Points, Point));
	}

	static float RasterizeStrokeAlpha(const TArray<FVector2D>& Points, const FVector2D& Point, float GlyphThickness, float Feather, bool bClosed)
	{
		if (Points.Num() < 2)
		{
			return 0.0f;
		}

		float Distance = TNumericLimits<float>::Max();
		const int32 SegmentCount = bClosed ? Points.Num() : Points.Num() - 1;
		for (int32 Index = 0; Index < SegmentCount; ++Index)
		{
			Distance = FMath::Min(Distance, DistanceToSegment(Point, Points[Index], Points[(Index + 1) % Points.Num()]));
		}

		return 1.0f - Smooth01(GlyphThickness * 0.5f, GlyphThickness * 0.5f + Feather, Distance);
	}

	static void AppendSvgLinePoint(TArray<FVector2D>& Points, const FVector2D& Point)
	{
		if (Points.IsEmpty() || !Points.Last().Equals(Point, KINDA_SMALL_NUMBER))
		{
			Points.Add(Point);
		}
	}

	static bool ParseSvgPathData(const FString& PathData, FCBLGSvgPathMask& OutPath)
	{
		FVector2D CurrentPoint = FVector2D::ZeroVector;
		FVector2D SubpathStart = FVector2D::ZeroVector;
		FVector2D LastCubicControl = FVector2D::ZeroVector;
		bool bHasLastCubicControl = false;
		TCHAR Command = 0;
		int32 Position = 0;

		while (Position < PathData.Len())
		{
			SkipSvgSeparators(PathData, Position);
			if (Position >= PathData.Len())
			{
				break;
			}

			if (IsSvgPathCommand(PathData[Position]))
			{
				Command = PathData[Position++];
			}

			if (Command == 0)
			{
				return false;
			}

			const bool bRelative = FChar::IsLower(Command);
			switch (FChar::ToUpper(Command))
			{
			case TEXT('M'):
			{
				float X = 0.0f;
				float Y = 0.0f;
				if (!TryReadSvgNumber(PathData, Position, X) || !TryReadSvgNumber(PathData, Position, Y))
				{
					return false;
				}

				CurrentPoint = FVector2D(X, Y) + (bRelative ? CurrentPoint : FVector2D::ZeroVector);
				SubpathStart = CurrentPoint;
				AppendSvgLinePoint(OutPath.Points, CurrentPoint);
				bHasLastCubicControl = false;

				float NextX = 0.0f;
				float NextY = 0.0f;
				while (TryReadSvgNumber(PathData, Position, NextX))
				{
					if (!TryReadSvgNumber(PathData, Position, NextY))
					{
						return false;
					}
					CurrentPoint = FVector2D(NextX, NextY) + (bRelative ? CurrentPoint : FVector2D::ZeroVector);
					AppendSvgLinePoint(OutPath.Points, CurrentPoint);
				}
				break;
			}
			case TEXT('L'):
			{
				float X = 0.0f;
				float Y = 0.0f;
				while (TryReadSvgNumber(PathData, Position, X))
				{
					if (!TryReadSvgNumber(PathData, Position, Y))
					{
						return false;
					}
					CurrentPoint = FVector2D(X, Y) + (bRelative ? CurrentPoint : FVector2D::ZeroVector);
					AppendSvgLinePoint(OutPath.Points, CurrentPoint);
				}
				bHasLastCubicControl = false;
				break;
			}
			case TEXT('H'):
			{
				float X = 0.0f;
				while (TryReadSvgNumber(PathData, Position, X))
				{
					CurrentPoint.X = bRelative ? CurrentPoint.X + X : X;
					AppendSvgLinePoint(OutPath.Points, CurrentPoint);
				}
				bHasLastCubicControl = false;
				break;
			}
			case TEXT('V'):
			{
				float Y = 0.0f;
				while (TryReadSvgNumber(PathData, Position, Y))
				{
					CurrentPoint.Y = bRelative ? CurrentPoint.Y + Y : Y;
					AppendSvgLinePoint(OutPath.Points, CurrentPoint);
				}
				bHasLastCubicControl = false;
				break;
			}
			case TEXT('C'):
			{
				float X1 = 0.0f;
				float Y1 = 0.0f;
				float X2 = 0.0f;
				float Y2 = 0.0f;
				float X = 0.0f;
				float Y = 0.0f;
				while (TryReadSvgNumber(PathData, Position, X1))
				{
					if (!TryReadSvgNumber(PathData, Position, Y1)
						|| !TryReadSvgNumber(PathData, Position, X2)
						|| !TryReadSvgNumber(PathData, Position, Y2)
						|| !TryReadSvgNumber(PathData, Position, X)
						|| !TryReadSvgNumber(PathData, Position, Y))
					{
						return false;
					}

					const FVector2D P0 = CurrentPoint;
					const FVector2D P1 = FVector2D(X1, Y1) + (bRelative ? CurrentPoint : FVector2D::ZeroVector);
					const FVector2D P2 = FVector2D(X2, Y2) + (bRelative ? CurrentPoint : FVector2D::ZeroVector);
					const FVector2D P3 = FVector2D(X, Y) + (bRelative ? CurrentPoint : FVector2D::ZeroVector);
					for (int32 Step = 1; Step <= 16; ++Step)
					{
						AppendSvgLinePoint(OutPath.Points, CubicBezierPoint(P0, P1, P2, P3, Step / 16.0f));
					}
					CurrentPoint = P3;
					LastCubicControl = P2;
					bHasLastCubicControl = true;
				}
				break;
			}
			case TEXT('S'):
			{
				float X2 = 0.0f;
				float Y2 = 0.0f;
				float X = 0.0f;
				float Y = 0.0f;
				while (TryReadSvgNumber(PathData, Position, X2))
				{
					if (!TryReadSvgNumber(PathData, Position, Y2)
						|| !TryReadSvgNumber(PathData, Position, X)
						|| !TryReadSvgNumber(PathData, Position, Y))
					{
						return false;
					}

					const FVector2D P0 = CurrentPoint;
					const FVector2D P1 = bHasLastCubicControl ? CurrentPoint * 2.0f - LastCubicControl : CurrentPoint;
					const FVector2D P2 = FVector2D(X2, Y2) + (bRelative ? CurrentPoint : FVector2D::ZeroVector);
					const FVector2D P3 = FVector2D(X, Y) + (bRelative ? CurrentPoint : FVector2D::ZeroVector);
					for (int32 Step = 1; Step <= 16; ++Step)
					{
						AppendSvgLinePoint(OutPath.Points, CubicBezierPoint(P0, P1, P2, P3, Step / 16.0f));
					}
					CurrentPoint = P3;
					LastCubicControl = P2;
					bHasLastCubicControl = true;
				}
				break;
			}
			case TEXT('Z'):
				AppendSvgLinePoint(OutPath.Points, SubpathStart);
				CurrentPoint = SubpathStart;
				OutPath.bClosed = true;
				bHasLastCubicControl = false;
				break;
			default:
				return false;
			}
		}

		return OutPath.Points.Num() >= 2;
	}

	static bool RasterizeSvgMask(const FString& SvgPath, FIntPoint PixelSize, TArray<uint8>& OutBgraPixels)
	{
		FString SvgText;
		if (!FFileHelper::LoadFileToString(SvgText, *SvgPath))
		{
			UE_LOG(LogTemp, Warning, TEXT("CBLiquidGlass: failed to load SVG mask '%s'."), *SvgPath);
			return false;
		}

		FVector2D ViewMin = FVector2D::ZeroVector;
		FVector2D ViewSize(24.0f, 24.0f);
		FString SvgTag;
		const int32 SvgTagStart = SvgText.Find(TEXT("<svg"), ESearchCase::IgnoreCase);
		if (SvgTagStart != INDEX_NONE)
		{
			const int32 SvgTagEnd = SvgText.Find(TEXT(">"), ESearchCase::CaseSensitive, ESearchDir::FromStart, SvgTagStart);
			if (SvgTagEnd != INDEX_NONE)
			{
				SvgTag = SvgText.Mid(SvgTagStart, SvgTagEnd - SvgTagStart + 1);
				FString ViewBoxText;
				if (TryExtractSvgAttribute(SvgTag, TEXT("viewBox"), ViewBoxText))
				{
					const TArray<float> ViewBox = ParseSvgNumberList(ViewBoxText);
					if (ViewBox.Num() == 4 && ViewBox[2] > 0.0f && ViewBox[3] > 0.0f)
					{
						ViewMin = FVector2D(ViewBox[0], ViewBox[1]);
						ViewSize = FVector2D(ViewBox[2], ViewBox[3]);
					}
				}
			}
		}

		TArray<FCBLGSvgPathMask> Paths;
		int32 SearchPosition = 0;
		while (true)
		{
			const int32 TagStart = SvgText.Find(TEXT("<path"), ESearchCase::IgnoreCase, ESearchDir::FromStart, SearchPosition);
			if (TagStart == INDEX_NONE)
			{
				break;
			}

			const int32 TagEnd = SvgText.Find(TEXT(">"), ESearchCase::CaseSensitive, ESearchDir::FromStart, TagStart);
			if (TagEnd == INDEX_NONE)
			{
				break;
			}

			const FString PathTag = SvgText.Mid(TagStart, TagEnd - TagStart + 1);
			FString PathData;
			if (TryExtractSvgAttribute(PathTag, TEXT("d"), PathData))
			{
				FCBLGSvgPathMask Path;
				Path.bFilled = IsSvgAttributeVisible(PathTag, TEXT("fill"), true);
				Path.bStroked = IsSvgAttributeVisible(PathTag, TEXT("stroke"), false);
				Path.GlyphThickness = ExtractSvgFloatAttribute(PathTag, TEXT("stroke-width"), 1.0f);
				if (ParseSvgPathData(PathData, Path))
				{
					Paths.Add(Path);
				}
			}

			SearchPosition = TagEnd + 1;
		}

		TArray<FCBLGSvgCircleMask> Circles;
		SearchPosition = 0;
		while (true)
		{
			const int32 TagStart = SvgText.Find(TEXT("<circle"), ESearchCase::IgnoreCase, ESearchDir::FromStart, SearchPosition);
			if (TagStart == INDEX_NONE)
			{
				break;
			}

			const int32 TagEnd = SvgText.Find(TEXT(">"), ESearchCase::CaseSensitive, ESearchDir::FromStart, TagStart);
			if (TagEnd == INDEX_NONE)
			{
				break;
			}

			const FString CircleTag = SvgText.Mid(TagStart, TagEnd - TagStart + 1);
			FCBLGSvgCircleMask Circle;
			Circle.Center = FVector2D(
				ExtractSvgFloatAttribute(CircleTag, TEXT("cx"), 0.0f),
				ExtractSvgFloatAttribute(CircleTag, TEXT("cy"), 0.0f));
			Circle.Radius = ExtractSvgFloatAttribute(CircleTag, TEXT("r"), 0.0f);
			Circle.bFilled = IsSvgAttributeVisible(CircleTag, TEXT("fill"), true);
			Circle.bStroked = IsSvgAttributeVisible(CircleTag, TEXT("stroke"), false);
			Circle.GlyphThickness = ExtractSvgFloatAttribute(CircleTag, TEXT("stroke-width"), 1.0f);
			if (Circle.Radius > 0.0f)
			{
				Circles.Add(Circle);
			}

			SearchPosition = TagEnd + 1;
		}

		if (Paths.IsEmpty() && Circles.IsEmpty())
		{
			UE_LOG(LogTemp, Warning, TEXT("CBLiquidGlass: SVG mask '%s' does not contain supported path/circle geometry."), *SvgPath);
			return false;
		}

		const float Feather = FMath::Max(ViewSize.GetMin() / FMath::Max(PixelSize.GetMin(), 1), 0.01f) * 1.25f;
		OutBgraPixels.SetNumZeroed(PixelSize.X * PixelSize.Y * 4);
		for (int32 Y = 0; Y < PixelSize.Y; ++Y)
		{
			for (int32 X = 0; X < PixelSize.X; ++X)
			{
				const FVector2D SvgPoint(
					ViewMin.X + (X + 0.5f) / PixelSize.X * ViewSize.X,
					ViewMin.Y + (Y + 0.5f) / PixelSize.Y * ViewSize.Y);

				float Alpha = 0.0f;
				for (const FCBLGSvgPathMask& Path : Paths)
				{
					if (Path.bFilled)
					{
						Alpha = FMath::Max(Alpha, RasterizeFilledPolygonAlpha(Path.Points, SvgPoint, Feather));
					}
					if (Path.bStroked)
					{
						Alpha = FMath::Max(Alpha, RasterizeStrokeAlpha(Path.Points, SvgPoint, Path.GlyphThickness, Feather, Path.bClosed));
					}
				}

				for (const FCBLGSvgCircleMask& Circle : Circles)
				{
					const float Distance = FVector2D::Distance(SvgPoint, Circle.Center);
					if (Circle.bFilled)
					{
						Alpha = FMath::Max(Alpha, 1.0f - Smooth01(Circle.Radius, Circle.Radius + Feather, Distance));
					}
					if (Circle.bStroked)
					{
						Alpha = FMath::Max(Alpha, 1.0f - Smooth01(Circle.GlyphThickness * 0.5f, Circle.GlyphThickness * 0.5f + Feather, FMath::Abs(Distance - Circle.Radius)));
					}
				}

				const uint8 AlphaByte = static_cast<uint8>(FMath::RoundToInt(FMath::Clamp(Alpha, 0.0f, 1.0f) * 255.0f));
				const int32 PixelIndex = (Y * PixelSize.X + X) * 4;
				OutBgraPixels[PixelIndex + 0] = AlphaByte;
				OutBgraPixels[PixelIndex + 1] = AlphaByte;
				OutBgraPixels[PixelIndex + 2] = AlphaByte;
				OutBgraPixels[PixelIndex + 3] = AlphaByte;
			}
		}

		return true;
	}

	static TStrongObjectPtr<UTexture2D> CreateTextureFromSvgMask(const FString& SvgPath, FIntPoint PixelSize)
	{
		PixelSize.X = FMath::Max(PixelSize.X, 4);
		PixelSize.Y = FMath::Max(PixelSize.Y, 4);

		TArray<uint8> BgraPixels;
		if (!RasterizeSvgMask(SvgPath, PixelSize, BgraPixels) || BgraPixels.Num() != PixelSize.X * PixelSize.Y * 4)
		{
			return TStrongObjectPtr<UTexture2D>();
		}

		const FName TextureName = MakeUniqueObjectName(
			GetTransientPackage(),
			UTexture2D::StaticClass(),
			*FString::Printf(TEXT("CBLG_%s_Mask"), *FPaths::GetBaseFilename(SvgPath)));
		UTexture2D* Texture = UTexture2D::CreateTransient(
			PixelSize.X,
			PixelSize.Y,
			PF_B8G8R8A8,
			TextureName,
			TConstArrayView64<uint8>(BgraPixels));

		if (!Texture)
		{
			return TStrongObjectPtr<UTexture2D>();
		}

		Texture->SRGB = false;
		Texture->Filter = TF_Bilinear;
		Texture->AddressX = TA_Clamp;
		Texture->AddressY = TA_Clamp;
		Texture->UpdateResource();
		return TStrongObjectPtr<UTexture2D>(Texture);
	}

	static void Remove()
	{
		// Remove only from the viewport that originally received this overlay.
		if (GDemoWidget.IsValid() && GDemoViewport.IsValid())
		{
			GDemoViewport->RemoveViewportWidgetContent(GDemoWidget.ToSharedRef());
		}
		GDemoWidget.Reset();
		GDemoViewport.Reset();
	}

	static void RemoveControlDemo()
	{
		// Kept separate from Remove() so the showcase and tuning overlay can be toggled independently.
		if (GControlDemoWidget.IsValid() && GControlDemoViewport.IsValid())
		{
			GControlDemoViewport->RemoveViewportWidgetContent(GControlDemoWidget.ToSharedRef());
		}
		GControlDemoWidget.Reset();
		GControlDemoViewport.Reset();
	}

	static void RemoveFeatureDemo()
	{
		if (GFeatureDemoWidget.IsValid() && GFeatureDemoViewport.IsValid())
		{
			GFeatureDemoViewport->RemoveViewportWidgetContent(GFeatureDemoWidget.ToSharedRef());
		}
		GFeatureDemoWidget.Reset();
		GFeatureDemoViewport.Reset();
	}

	static void RemoveShowcaseDemo()
	{
		if (GShowcaseDemoWidget.IsValid() && GShowcaseDemoViewport.IsValid())
		{
			GShowcaseDemoViewport->RemoveViewportWidgetContent(GShowcaseDemoWidget.ToSharedRef());
		}
		GShowcaseDemoWidget.Reset();
		GShowcaseDemoViewport.Reset();
	}

	static void RemoveGalleryDemo()
	{
		if (GGalleryDemoWidget.IsValid() && GGalleryDemoViewport.IsValid())
		{
			GGalleryDemoViewport->RemoveViewportWidgetContent(GGalleryDemoWidget.ToSharedRef());
		}
		GGalleryDemoWidget.Reset();
		GGalleryDemoViewport.Reset();
	}
}

/** A draggable wrapper that starts dragging after a short hold and then reports cursor deltas. */
class SCBLGDemoDraggable : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLGDemoDraggable) {}
		SLATE_ARGUMENT(float, HoldSeconds)
		SLATE_DEFAULT_SLOT(FArguments, Content)
	SLATE_END_ARGS()

	TFunction<void(const FVector2D&)> OnDragDelta;

	void Construct(const FArguments& InArgs)
	{
		// A small hold delay prevents accidental drags when clicking glass controls.
		HoldSeconds = InArgs._HoldSeconds > 0.0f ? InArgs._HoldSeconds : 0.18f;
		ChildSlot[ InArgs._Content.Widget ];
	}

	virtual FReply OnMouseButtonDown(const FGeometry&, const FPointerEvent& MouseEvent) override
	{
		if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
		{
			bPressed = true;
			bDragging = false;
			PressTime = FPlatformTime::Seconds();
			return FReply::Handled().CaptureMouse(SharedThis(this));
		}
		return FReply::Unhandled();
	}

	virtual FReply OnMouseMove(const FGeometry&, const FPointerEvent& MouseEvent) override
	{
		if (bPressed && HasMouseCapture())
		{
			// Convert a press into a drag only after the hold threshold.
			if (!bDragging && FPlatformTime::Seconds() - PressTime >= HoldSeconds)
			{
				bDragging = true;
			}

			if (bDragging && OnDragDelta)
			{
				// Let the owner decide which position value to mutate.
				const FVector2D Delta(MouseEvent.GetCursorDelta());
				if (!Delta.IsNearlyZero())
				{
					OnDragDelta(Delta);
				}
			}
			return FReply::Handled();
		}
		return FReply::Unhandled();
	}

	virtual FReply OnMouseButtonUp(const FGeometry&, const FPointerEvent& MouseEvent) override
	{
		if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton && bPressed)
		{
			bPressed = false;
			bDragging = false;
			return FReply::Handled().ReleaseMouseCapture();
		}
		return FReply::Unhandled();
	}

private:
	bool bPressed = false;
	bool bDragging = false;
	double PressTime = 0.0;
	float HoldSeconds = 0.18f;
};

/** A click-to-close glass button that defers removal to the next tick (safe during input). */
class SCBLGDemoClose : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLGDemoClose) {}
		SLATE_EVENT(FSimpleDelegate, OnClicked)
		SLATE_DEFAULT_SLOT(FArguments, Content)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs)
	{
		OnClicked = InArgs._OnClicked;
		ChildSlot[ InArgs._Content.Widget ];
	}

	virtual FReply OnMouseButtonDown(const FGeometry&, const FPointerEvent& MouseEvent) override
	{
		return MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton ? FReply::Handled() : FReply::Unhandled();
	}

	virtual FReply OnMouseButtonUp(const FGeometry&, const FPointerEvent& MouseEvent) override
	{
		if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
		{
			const FSimpleDelegate ClickHandler = OnClicked;
			FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateLambda([ClickHandler](float)
			{
				if (ClickHandler.IsBound())
				{
					ClickHandler.Execute();
				}
				else
				{
					CBLiquidGlassDemo::Remove();
				}
				return false;
			}), 0.0f);
			return FReply::Handled();
		}
		return FReply::Unhandled();
	}

private:
	FSimpleDelegate OnClicked;
};

/** Single-pass fusion demo: all blobs are rasterized into one live alpha mask and drawn by one glass widget. */
class SCBLGFusionGroup : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLGFusionGroup)
		: _FrostRadius(0.24f)
		, _PrismIntensity(0.48f)
		, _RimIntensity(0.32f)
	{}
		SLATE_ARGUMENT(float, FrostRadius)
		SLATE_ARGUMENT(float, PrismIntensity)
		SLATE_ARGUMENT(float, RimIntensity)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs)
	{
		FrostRadius = InArgs._FrostRadius;
		PrismIntensity = InArgs._PrismIntensity;
		RimIntensity = InArgs._RimIntensity;

		MaskPixels.SetNumZeroed(MaskWidth * MaskHeight * 4);
		RenderMaskPixels();

		const FName TextureName = MakeUniqueObjectName(GetTransientPackage(), UTexture2D::StaticClass(), TEXT("CBLG_Fusion_Group_Mask"));
		UTexture2D* Texture = UTexture2D::CreateTransient(
			MaskWidth,
			MaskHeight,
			PF_B8G8R8A8,
			TextureName,
			TConstArrayView64<uint8>(MaskPixels));

		if (Texture)
		{
			Texture->SRGB = false;
			Texture->Filter = TF_Bilinear;
			Texture->AddressX = TA_Clamp;
			Texture->AddressY = TA_Clamp;
			Texture->UpdateResource();
			FusionMaskTexture = TStrongObjectPtr<UTexture2D>(Texture);
		}

		ChildSlot
		[
			SNew(SBox)
			.WidthOverride(CanvasSize.X)
			.HeightOverride(CanvasSize.Y)
			[
				SAssignNew(FusionGlass, SCBLiquidGlass)
				.AlphaMaskTexture(FusionMaskTexture.Get())
				.AlphaMaskThreshold(0.5f)
				.AlphaMaskSoftness(0.035f)
				.BlurStrength(1.22f)
				.FrostRadius(FrostRadius)
				.RefractionStrength(0.78f)
				.RefractionPower(3.0f)
				.RefractionThickness(58.0f)
				.IndexOfRefraction(1.82f)
				.ChromaticAberration(0.055f)
				.PrismIntensity(PrismIntensity)
				.NoiseAmount(0.0f)
				.GlowAmount(0.34f)
				.RimIntensity(RimIntensity)
				.InnerGlowIntensity(0.16f)
				.InnerShadowIntensity(0.18f)
				.TintColor(FLinearColor(0.72f, 0.93f, 1.0f, 1.0f))
				.TintOpacity(0.065f)
				.Saturation(1.12f)
				.GlassOpacity(0.9f)
				.Quality(ECBLiquidGlassQuality::Quality)
				.MotionStrength(0.55f)
				.MotionMaxOffset(44.0f)
				[
					SNew(SCanvas)
					+ SCanvas::Slot()
					.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLGFusionGroup::GetALabelPos))
					.Size(FVector2D(64.0f, 40.0f))
					[
						BuildLabel(LOCTEXT("FusionLabelA", "A"), 24)
					]
					+ SCanvas::Slot()
					.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLGFusionGroup::GetBLabelPos))
					.Size(FVector2D(64.0f, 40.0f))
					[
						BuildLabel(LOCTEXT("FusionLabelB", "B"), 24)
					]
					+ SCanvas::Slot()
					.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLGFusionGroup::GetFreeLabelPos))
					.Size(FVector2D(92.0f, 40.0f))
					[
						BuildLabel(LOCTEXT("FusionLabelFree", "Free"), 18)
					]
				]
			]
		];
	}

	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override
	{
		if (MouseEvent.GetEffectingButton() != EKeys::LeftMouseButton)
		{
			return FReply::Unhandled();
		}

		const FVector2D LocalMouse = MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition());
		ActiveNode = HitTestNode(LocalMouse);
		if (ActiveNode == INDEX_NONE)
		{
			return FReply::Unhandled();
		}

		bPressed = true;
		bDragging = false;
		PressTime = FPlatformTime::Seconds();
		LastLocalMouse = LocalMouse;
		return FReply::Handled().CaptureMouse(SharedThis(this));
	}

	virtual FReply OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override
	{
		if (!bPressed || !HasMouseCapture())
		{
			return FReply::Unhandled();
		}

		const FVector2D LocalMouse = MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition());
		if (!bDragging && FPlatformTime::Seconds() - PressTime >= HoldSeconds)
		{
			bDragging = true;
		}

		if (bDragging)
		{
			const FVector2D Delta = LocalMouse - LastLocalMouse;
			if (!Delta.IsNearlyZero())
			{
				MoveActiveNode(Delta);
				RenderMaskPixels();
				UploadMaskTexture();
				Invalidate(EInvalidateWidgetReason::Layout);
				if (FusionGlass.IsValid())
				{
					FusionGlass->Invalidate(EInvalidateWidgetReason::Paint);
				}
			}
		}

		LastLocalMouse = LocalMouse;
		return FReply::Handled();
	}

	virtual FReply OnMouseButtonUp(const FGeometry&, const FPointerEvent& MouseEvent) override
	{
		if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton && bPressed)
		{
			bPressed = false;
			bDragging = false;
			ActiveNode = INDEX_NONE;
			return FReply::Handled().ReleaseMouseCapture();
		}
		return FReply::Unhandled();
	}

private:
	static constexpr int32 MaskWidth = 1024;
	static constexpr int32 MaskHeight = 512;
	const FVector2D CanvasSize = FVector2D(780.0f, 390.0f);
	const float CircleRadius = 76.0f;
	const FVector2D CapsuleHalfSize = FVector2D(98.0f, 54.0f);
	const float HoldSeconds = 0.12f;
	float FrostRadius = 0.24f;
	float PrismIntensity = 0.48f;
	float RimIntensity = 0.32f;

	FVector2D NodeA = FVector2D(310.0f, 220.0f);
	FVector2D NodeB = FVector2D(438.0f, 220.0f);
	FVector2D FreeNode = FVector2D(610.0f, 216.0f);
	TArray<uint8> MaskPixels;
	TStrongObjectPtr<UTexture2D> FusionMaskTexture;
	TSharedPtr<SCBLiquidGlass> FusionGlass;
	FVector2D LastLocalMouse = FVector2D::ZeroVector;
	int32 ActiveNode = INDEX_NONE;
	bool bPressed = false;
	bool bDragging = false;
	double PressTime = 0.0;

	TSharedRef<SWidget> BuildLabel(FText Text, int32 FontSize) const
	{
		return SNew(SBox)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(Text)
				.Font(FCoreStyle::GetDefaultFontStyle("Bold", FontSize))
				.ColorAndOpacity(FLinearColor::White)
			];
	}

	FVector2D GetALabelPos() const { return NodeA - FVector2D(32.0f, 20.0f); }
	FVector2D GetBLabelPos() const { return NodeB - FVector2D(32.0f, 20.0f); }
	FVector2D GetFreeLabelPos() const { return FreeNode - FVector2D(46.0f, 20.0f); }

	static float SignedDistanceCircle(const FVector2D& Point, const FVector2D& Center, float Radius)
	{
		return FVector2D::Distance(Point, Center) - Radius;
	}

	static float SignedDistanceCapsule(const FVector2D& Point, const FVector2D& Center, const FVector2D& HalfSize)
	{
		const float Radius = HalfSize.Y;
		const FVector2D A = Center - FVector2D(FMath::Max(HalfSize.X - Radius, 0.0f), 0.0f);
		const FVector2D B = Center + FVector2D(FMath::Max(HalfSize.X - Radius, 0.0f), 0.0f);
		return CBLiquidGlassDemo::DistanceToSegment(Point, A, B) - Radius;
	}

	static float SmoothUnion(float DistanceA, float DistanceB, float K)
	{
		const float SafeK = FMath::Max(K, 0.001f);
		const float H = FMath::Clamp(0.5f + 0.5f * (DistanceB - DistanceA) / SafeK, 0.0f, 1.0f);
		return FMath::Lerp(DistanceB, DistanceA, H) - SafeK * H * (1.0f - H);
	}

	static float MergeKernel(float Gap)
	{
		const float Strength = 1.0f - FMath::Clamp((Gap - 26.0f) / 120.0f, 0.0f, 1.0f);
		return FMath::Lerp(16.0f, 86.0f, Strength);
	}

	static float DistanceToCapsuleCenterApprox(const FVector2D& Point, const FVector2D& CapsuleCenter, const FVector2D& HalfSize)
	{
		const FVector2D AxisPoint(
			FMath::Clamp(Point.X, CapsuleCenter.X - FMath::Max(HalfSize.X - HalfSize.Y, 0.0f), CapsuleCenter.X + FMath::Max(HalfSize.X - HalfSize.Y, 0.0f)),
			CapsuleCenter.Y);
		return FVector2D::Distance(Point, AxisPoint);
	}

	float CombinedDistance(const FVector2D& Point) const
	{
		const float DA = SignedDistanceCircle(Point, NodeA, CircleRadius);
		const float DB = SignedDistanceCircle(Point, NodeB, CircleRadius);
		const float DFree = SignedDistanceCapsule(Point, FreeNode, CapsuleHalfSize);

		const float GapAB = FVector2D::Distance(NodeA, NodeB) - CircleRadius * 2.0f;
		const float GapAFree = DistanceToCapsuleCenterApprox(NodeA, FreeNode, CapsuleHalfSize) - CircleRadius - CapsuleHalfSize.Y;
		const float GapBFree = DistanceToCapsuleCenterApprox(NodeB, FreeNode, CapsuleHalfSize) - CircleRadius - CapsuleHalfSize.Y;

		float Distance = SmoothUnion(DA, DB, MergeKernel(GapAB));
		Distance = SmoothUnion(Distance, DFree, MergeKernel(FMath::Min(GapAFree, GapBFree)));
		return Distance;
	}

	void RenderMaskPixels()
	{
		const float DistanceFieldRange = 92.0f;
		for (int32 Y = 0; Y < MaskHeight; ++Y)
		{
			for (int32 X = 0; X < MaskWidth; ++X)
			{
				const FVector2D LocalPoint(
					(X + 0.5f) / MaskWidth * CanvasSize.X,
					(Y + 0.5f) / MaskHeight * CanvasSize.Y);

				const float Distance = CombinedDistance(LocalPoint);
				const float Alpha = FMath::Clamp(0.5f - Distance / (DistanceFieldRange * 2.0f), 0.0f, 1.0f);
				const uint8 AlphaByte = static_cast<uint8>(FMath::RoundToInt(FMath::Clamp(Alpha, 0.0f, 1.0f) * 255.0f));
				const int32 PixelIndex = (Y * MaskWidth + X) * 4;
				MaskPixels[PixelIndex + 0] = AlphaByte;
				MaskPixels[PixelIndex + 1] = AlphaByte;
				MaskPixels[PixelIndex + 2] = AlphaByte;
				MaskPixels[PixelIndex + 3] = AlphaByte;
			}
		}
	}

	void UploadMaskTexture()
	{
		UTexture2D* Texture = FusionMaskTexture.Get();
		if (!Texture || !Texture->GetResource())
		{
			return;
		}

		uint8* UploadData = new uint8[MaskPixels.Num()];
		FMemory::Memcpy(UploadData, MaskPixels.GetData(), MaskPixels.Num());

		FUpdateTextureRegion2D* Region = new FUpdateTextureRegion2D(0, 0, 0, 0, MaskWidth, MaskHeight);
		Texture->UpdateTextureRegions(
			0,
			1,
			Region,
			MaskWidth * 4,
			4,
			UploadData,
			[](uint8* SrcData, const FUpdateTextureRegion2D* Regions)
			{
				delete[] SrcData;
				delete Regions;
			});
	}

	int32 HitTestNode(const FVector2D& Point) const
	{
		if (SignedDistanceCapsule(Point, FreeNode, CapsuleHalfSize + FVector2D(12.0f, 12.0f)) <= 0.0f)
		{
			return 2;
		}
		if (SignedDistanceCircle(Point, NodeB, CircleRadius + 12.0f) <= 0.0f)
		{
			return 1;
		}
		if (SignedDistanceCircle(Point, NodeA, CircleRadius + 12.0f) <= 0.0f)
		{
			return 0;
		}
		return INDEX_NONE;
	}

	void MoveActiveNode(const FVector2D& Delta)
	{
		switch (ActiveNode)
		{
		case 0:
			NodeA += Delta;
			NodeA.X = FMath::Clamp(NodeA.X, CircleRadius + 10.0f, CanvasSize.X - CircleRadius - 10.0f);
			NodeA.Y = FMath::Clamp(NodeA.Y, 86.0f + CircleRadius, CanvasSize.Y - CircleRadius - 10.0f);
			break;
		case 1:
			NodeB += Delta;
			NodeB.X = FMath::Clamp(NodeB.X, CircleRadius + 10.0f, CanvasSize.X - CircleRadius - 10.0f);
			NodeB.Y = FMath::Clamp(NodeB.Y, 86.0f + CircleRadius, CanvasSize.Y - CircleRadius - 10.0f);
			break;
		case 2:
			FreeNode += Delta;
			FreeNode.X = FMath::Clamp(FreeNode.X, CapsuleHalfSize.X + 10.0f, CanvasSize.X - CapsuleHalfSize.X - 10.0f);
			FreeNode.Y = FMath::Clamp(FreeNode.Y, 86.0f + CapsuleHalfSize.Y, CanvasSize.Y - CapsuleHalfSize.Y - 10.0f);
			break;
		default:
			break;
		}
	}
};

/** The full demo overlay: vivid background + liquid glass panels. */
class SCBLiquidGlassDemo : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLiquidGlassDemo) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs)
	{
		// Resolve resources at runtime so the demo works from the plugin folder without project assets.
		const FString ResourceDir = CBLiquidGlassDemo::GetResourceDir();
		const FString IconDir = FPaths::Combine(ResourceDir, TEXT("Icons"));
		const FString BackgroundImagePath = CBLiquidGlassDemo::ResolveRandomBackgroundImagePath(TEXT("CBLiquidGlass.Demo"));

		BackgroundBrush = MakeShared<FSlateDynamicImageBrush>(
			FName(*FPaths::ConvertRelativePathToFull(BackgroundImagePath)),
			FVector2D(1920.0f, 1080.0f));
		// SVG icons live in Resources/Icons and are loaded as vector brushes for DPI-independent UI.
		StarBrush = MakeShared<FSlateVectorImageBrush>(FPaths::Combine(IconDir, TEXT("star.svg")), FVector2D(24.0f, 24.0f));
		SearchBrush = MakeShared<FSlateVectorImageBrush>(FPaths::Combine(IconDir, TEXT("search.svg")), FVector2D(24.0f, 24.0f));
		FolderBrush = MakeShared<FSlateVectorImageBrush>(FPaths::Combine(IconDir, TEXT("folder.svg")), FVector2D(24.0f, 24.0f));
		FormatBrush = MakeShared<FSlateVectorImageBrush>(FPaths::Combine(IconDir, TEXT("format.svg")), FVector2D(24.0f, 24.0f));
		TrashBrush = MakeShared<FSlateVectorImageBrush>(FPaths::Combine(IconDir, TEXT("trash.svg")), FVector2D(24.0f, 24.0f));
		ChevronBrush = MakeShared<FSlateVectorImageBrush>(FPaths::Combine(IconDir, TEXT("chevron-right.svg")), FVector2D(18.0f, 18.0f));
		CloseBrush = MakeShared<FSlateVectorImageBrush>(FPaths::Combine(IconDir, TEXT("x.svg")), FVector2D(20.0f, 20.0f));
		DropletBrush = MakeShared<FSlateVectorImageBrush>(FPaths::Combine(IconDir, TEXT("droplet.svg")), FVector2D(22.0f, 22.0f));

		// Initial positions are intentionally spread across high-contrast parts of the background.
		CardPos = FVector2D(410.0f, 245.0f);
		ClearButtonPos = FVector2D(44.0f, 52.0f);
		PillButtonPos = FVector2D(174.0f, 52.0f);
		PrismButtonPos = FVector2D(338.0f, 52.0f);
		MenuPos = FVector2D(760.0f, 110.0f);
		CirclePos = FVector2D(610.0f, 120.0f);
		MattePos = FVector2D(62.0f, 160.0f);
		SelfPos = FVector2D(62.0f, 260.0f);

		ChildSlot
		[
			SNew(SOverlay)

			// --- Vivid background (rainbow tiles + big text) so the refraction is obvious ---
			+ SOverlay::Slot()
			[
				BuildBackground()
			]

			// --- Foreground glass widgets on a canvas ---
			+ SOverlay::Slot()
			[
				SAssignNew(Canvas, SCanvas)

				// Draggable glass card.
				+ SCanvas::Slot()
				.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassDemo::GetCardPos))
				.Size(FVector2D(420.0f, 220.0f))
				[
					BuildDraggableCard()
				]

				+ SCanvas::Slot()
				.Position(TAttribute<FVector2D>::Create(TAttribute<FVector2D>::FGetter::CreateSP(this, &SCBLiquidGlassDemo::GetClearButtonPos)))
				.Size(FVector2D(120.0f, 58.0f))
				[
					MakeDraggable(BuildPillButton(LOCTEXT("ClearPill", "Clear"), DropletBrush.Get(), 0.12f, 0.9f, 42.0f, 2.0f), &SCBLiquidGlassDemo::ClearButtonPos)
				]

				+ SCanvas::Slot()
				.Position(TAttribute<FVector2D>::Create(TAttribute<FVector2D>::FGetter::CreateSP(this, &SCBLiquidGlassDemo::GetPillButtonPos)))
				.Size(FVector2D(150.0f, 58.0f))
				[
					MakeDraggable(BuildPillButton(LOCTEXT("PillLensPill", "Pill Lens"), StarBrush.Get(), 0.22f, 1.0f, 48.0f, 2.0f), &SCBLiquidGlassDemo::PillButtonPos)
				]

				+ SCanvas::Slot()
				.Position(TAttribute<FVector2D>::Create(TAttribute<FVector2D>::FGetter::CreateSP(this, &SCBLiquidGlassDemo::GetPrismButtonPos)))
				.Size(FVector2D(130.0f, 58.0f))
				[
					MakeDraggable(BuildPillButton(LOCTEXT("PrismPill", "Prism"), SearchBrush.Get(), 0.18f, 1.0f, 52.0f, 2.15f), &SCBLiquidGlassDemo::PrismButtonPos)
				]

				// Screenshot-style frosted menu glass.
				+ SCanvas::Slot()
				.Position(TAttribute<FVector2D>::Create(TAttribute<FVector2D>::FGetter::CreateSP(this, &SCBLiquidGlassDemo::GetMenuPos)))
				.Size(FVector2D(360.0f, 420.0f))
				[
					MakeDraggable(BuildMenuCard(), &SCBLiquidGlassDemo::MenuPos)
				]

				// Circular lens and layer comparison.
				+ SCanvas::Slot()
				.Position(TAttribute<FVector2D>::Create(TAttribute<FVector2D>::FGetter::CreateSP(this, &SCBLiquidGlassDemo::GetCirclePos)))
				.Size(FVector2D(120.0f, 120.0f))
				[
					MakeDraggable(BuildCircleLens(), &SCBLiquidGlassDemo::CirclePos)
				]

				+ SCanvas::Slot()
				.Position(TAttribute<FVector2D>::Create(TAttribute<FVector2D>::FGetter::CreateSP(this, &SCBLiquidGlassDemo::GetMattePos)))
				.Size(FVector2D(270.0f, 92.0f))
				[
					MakeDraggable(BuildLayerSample(
						LOCTEXT("MatteLayerDemo", "Matte Layer"),
						1.25f, 0.48f, 0.35f, 22.0f, 1.3f, 0.28f,
						0.08f, 1.05f, 0.05f, 0.12f), &SCBLiquidGlassDemo::MattePos)
				]

				+ SCanvas::Slot()
				.Position(TAttribute<FVector2D>::Create(TAttribute<FVector2D>::FGetter::CreateSP(this, &SCBLiquidGlassDemo::GetSelfPos)))
				.Size(FVector2D(270.0f, 92.0f))
				[
					MakeDraggable(BuildLayerSample(
						LOCTEXT("SelfLayerDemo", "Self Layer"),
						0.35f, 0.05f, 0.85f, 32.0f, 1.9f, 0.55f,
						0.0f, 1.25f, 0.04f, 0.04f), &SCBLiquidGlassDemo::SelfPos)
				]
			]

			// --- Hint + close ---
			+ SOverlay::Slot()
			.HAlign(HAlign_Right)
			.VAlign(VAlign_Top)
			.Padding(24.0f)
			[
				BuildCloseButton()
			]

			+ SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Bottom)
			.Padding(40.0f)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("Hint", "Hold any glass control briefly, then drag it across the background"))
				.Font(FCoreStyle::GetDefaultFontStyle("Regular", 14))
				.ColorAndOpacity(FLinearColor(1, 1, 1, 0.7f))
			]
		];
	}

private:
	// Mutable canvas positions. SCanvas reads them through attributes so dragging only needs
	// a layout invalidation, not a full widget rebuild.
	FVector2D CardPos = FVector2D::ZeroVector;
	FVector2D ClearButtonPos = FVector2D::ZeroVector;
	FVector2D PillButtonPos = FVector2D::ZeroVector;
	FVector2D PrismButtonPos = FVector2D::ZeroVector;
	FVector2D MenuPos = FVector2D::ZeroVector;
	FVector2D CirclePos = FVector2D::ZeroVector;
	FVector2D MattePos = FVector2D::ZeroVector;
	FVector2D SelfPos = FVector2D::ZeroVector;
	TSharedPtr<SCanvas> Canvas;
	TSharedPtr<FSlateDynamicImageBrush> BackgroundBrush;
	TSharedPtr<FSlateVectorImageBrush> StarBrush;
	TSharedPtr<FSlateVectorImageBrush> SearchBrush;
	TSharedPtr<FSlateVectorImageBrush> FolderBrush;
	TSharedPtr<FSlateVectorImageBrush> FormatBrush;
	TSharedPtr<FSlateVectorImageBrush> TrashBrush;
	TSharedPtr<FSlateVectorImageBrush> ChevronBrush;
	TSharedPtr<FSlateVectorImageBrush> CloseBrush;
	TSharedPtr<FSlateVectorImageBrush> DropletBrush;

	FVector2D GetCardPos() const { return CardPos; }
	FVector2D GetClearButtonPos() const { return ClearButtonPos; }
	FVector2D GetPillButtonPos() const { return PillButtonPos; }
	FVector2D GetPrismButtonPos() const { return PrismButtonPos; }
	FVector2D GetMenuPos() const { return MenuPos; }
	FVector2D GetCirclePos() const { return CirclePos; }
	FVector2D GetMattePos() const { return MattePos; }
	FVector2D GetSelfPos() const { return SelfPos; }

	TSharedRef<SWidget> MakeDraggable(TSharedRef<SWidget> Content, FVector2D SCBLiquidGlassDemo::* PositionMember)
	{
		// Generic wrapper used by most demo controls. The pointer-to-member keeps each drag handler tiny.
		TSharedRef<SCBLGDemoDraggable> Draggable = SNew(SCBLGDemoDraggable)
			.HoldSeconds(0.18f)
			[
				Content
			];

		Draggable->OnDragDelta = [this, PositionMember](const FVector2D& Delta)
		{
			this->*PositionMember += Delta;
			if (Canvas.IsValid())
			{
				// Canvas slot positions are attribute-driven, so layout invalidation is enough.
				Canvas->Invalidate(EInvalidateWidgetReason::Layout);
			}
		};

		return Draggable;
	}

	TSharedRef<SWidget> BuildBackground()
	{
		// The image background gives real colour/detail for backbuffer sampling. A light darkening
		// layer keeps white labels legible without hiding the texture.
		return SNew(SOverlay)
			+ SOverlay::Slot()
			[
				SNew(SImage)
				.Image(BackgroundBrush.Get())
			]
			+ SOverlay::Slot()
			[
				SNew(SColorBlock).Color(FLinearColor(0.0f, 0.0f, 0.0f, 0.12f))
			];
	}

	TSharedRef<SWidget> BuildDraggableCard()
	{
		// Regular glass sample: balanced blur/frost/refraction for a reusable panel.
		TSharedRef<SCBLGDemoDraggable> Draggable = SNew(SCBLGDemoDraggable)
		[
			SNew(SCBLiquidGlass)
			.Shape(ECBLiquidGlassShape::SuperellipseRect)
			.SquirclePower(7.0f)
			.BlurStrength(0.95f)
			.FrostRadius(0.24f)
			.RefractionStrength(1.0f)
			.RefractionThickness(34.0f)
			.IndexOfRefraction(1.85f)
			.ChromaticAberration(0.1f)
			.PrismIntensity(0.75f)
			.Saturation(1.35f)
			.GlowAmount(0.3f)
			.RimIntensity(0.22f)
			.InnerGlowIntensity(0.05f)
			.InnerShadowIntensity(0.1f)
			.TintOpacity(0.012f)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight().Padding(28, 26, 28, 4)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("CardTitle", "Regular Glass"))
					.Font(FCoreStyle::GetDefaultFontStyle("Bold", 30))
					.ColorAndOpacity(FLinearColor::White)
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(28, 0, 28, 26)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("CardSub", "Hold, then drag me across the image"))
					.Font(FCoreStyle::GetDefaultFontStyle("Regular", 16))
					.ColorAndOpacity(FLinearColor(1, 1, 1, 0.85f))
				]
			]
		];

		Draggable->OnDragDelta = [this](const FVector2D& Delta)
		{
			CardPos += Delta;
			if (Canvas.IsValid())
			{
				Canvas->Invalidate(EInvalidateWidgetReason::Layout);
			}
		};

		return Draggable;
	}

	TSharedRef<SWidget> BuildPillButton(FText Label, const FSlateBrush* IconBrush, float Frost, float Refraction, float Thickness, float Ior)
	{
		// Pills emphasize a thick refractive edge and a clearer center, matching compact toolbar glass.
		return SNew(SCBLiquidGlass)
			.Shape(ECBLiquidGlassShape::Capsule)
			.SquirclePower(3.0f)
			.BlurStrength(0.45f)
			.FrostRadius(Frost)
			.RefractionStrength(Refraction)
			.RefractionPower(3.5f)
			.RefractionThickness(Thickness)
			.IndexOfRefraction(Ior)
			.ChromaticAberration(0.1f)
			.PrismIntensity(0.9f)
			.Saturation(1.3f)
			.GlowAmount(0.42f)
			.RimIntensity(0.34f)
			.InnerGlowIntensity(0.08f)
			.InnerShadowIntensity(0.06f)
			.TintOpacity(0.01f)
			[
				SNew(SBox).Padding(FMargin(17, 11))
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot().AutoWidth().VAlign(VAlign_Center).Padding(0, 0, 8, 0)
					[
						SNew(SImage)
						.Image(IconBrush)
						.ColorAndOpacity(FLinearColor::White)
					]
					+ SHorizontalBox::Slot().AutoWidth().VAlign(VAlign_Center)
					[
						SNew(STextBlock)
						.Text(Label)
						.Font(FCoreStyle::GetDefaultFontStyle("Bold", 17))
						.ColorAndOpacity(FLinearColor::White)
					]
				]
			];
	}

	TSharedRef<SWidget> BuildCircleLens()
	{
		// Empty content is enough: the circle demonstrates pure background lensing.
		return SNew(SCBLiquidGlass)
			.Shape(ECBLiquidGlassShape::Circle)
			.BlurStrength(0.45f)
			.FrostRadius(0.08f)
			.RefractionStrength(1.0f)
			.RefractionPower(3.3f)
			.RefractionThickness(42.0f)
			.IndexOfRefraction(2.0f)
			.ChromaticAberration(0.09f)
			.PrismIntensity(0.8f)
			.GlowAmount(0.34f)
			.RimIntensity(0.28f)
			.InnerGlowIntensity(0.06f)
			.InnerShadowIntensity(0.04f)
			.TintOpacity(0.01f)
			[
				SNew(SBox)
			];
	}

	TSharedRef<SWidget> BuildLayerComparison()
	{
		return SNew(SVerticalBox)
			+ SVerticalBox::Slot().AutoHeight().Padding(0, 0, 0, 12)
			[
				BuildLayerSample(
					LOCTEXT("MatteLayerDemo", "Matte Layer"),
					2.3f, 1.0f, 0.22f, 18.0f, 1.2f, 0.18f,
					0.3f, 0.9f, 0.08f, 0.18f)
			]
			+ SVerticalBox::Slot().AutoHeight()
			[
				BuildLayerSample(
					LOCTEXT("SelfLayerDemo", "Self Layer"),
					0.35f, 0.06f, 0.85f, 36.0f, 2.1f, 0.7f,
					0.0f, 1.1f, 0.08f, 0.05f)
			];
	}

	TSharedRef<SWidget> BuildLayerSample(
		FText Label,
		float Blur,
		float Frost,
		float Refraction,
		float Thickness,
		float Ior,
		float Prism,
		float Tint,
		float Saturation,
		float InnerGlow,
		float InnerShadow)
	{
		// Shared helper for Matte/Self layer comparisons. Callers pass the material character
		// rather than duplicating long SCBLiquidGlass argument lists.
		return SNew(SVerticalBox)
			+ SVerticalBox::Slot().AutoHeight().Padding(0, 0, 0, 5)
			[
				SNew(STextBlock)
				.Text(Label)
				.Font(FCoreStyle::GetDefaultFontStyle("Bold", 16))
				.ColorAndOpacity(FLinearColor(1, 1, 1, 0.85f))
			]
			+ SVerticalBox::Slot().AutoHeight()
			[
				SNew(SBox).WidthOverride(240.0f).HeightOverride(58.0f)
				[
					SNew(SCBLiquidGlass)
					.Shape(ECBLiquidGlassShape::SuperellipseRect)
					.SquirclePower(7.0f)
					.BlurStrength(Blur)
					.DownsampleAmount(Frost > 0.9f ? 3 : 1)
					.FrostRadius(Frost)
					.RefractionStrength(Refraction)
					.RefractionPower(2.2f)
					.RefractionThickness(Thickness)
					.IndexOfRefraction(Ior)
					.ChromaticAberration(0.08f)
					.PrismIntensity(Prism)
					.NoiseAmount(0.02f)
					.GlowAmount(0.25f)
					.RimIntensity(0.24f)
					.InnerGlowIntensity(InnerGlow)
					.InnerShadowIntensity(InnerShadow)
					.TintOpacity(Tint)
					.Saturation(Saturation)
					[
						SNew(SBox).HAlign(HAlign_Center).VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Text(Label)
							.Font(FCoreStyle::GetDefaultFontStyle("Regular", 15))
							.ColorAndOpacity(FLinearColor::White)
						]
					]
				]
			];
	}

	TSharedRef<SWidget> BuildSeparator()
	{
		return SNew(SBox).HeightOverride(1.0f)
			[
				SNew(SColorBlock).Color(FLinearColor(1, 1, 1, 0.16f))
			];
	}

	TSharedRef<SWidget> BuildMenuRow(const FSlateBrush* IconBrush, FText Label, FLinearColor Color, bool bDimmed = false)
	{
		// Menu rows keep their text and arrow colours separate so disabled rows remain readable.
		const FLinearColor TextColor = bDimmed ? FLinearColor(Color.R, Color.G, Color.B, 0.38f) : Color;
		const FLinearColor ArrowColor = bDimmed ? FLinearColor(1, 1, 1, 0.28f) : FLinearColor(1, 1, 1, 0.85f);

		return SNew(SBox).HeightOverride(54.0f)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot().AutoWidth().VAlign(VAlign_Center).Padding(18, 0, 14, 0)
				[
					SNew(SBox).WidthOverride(24.0f).HeightOverride(24.0f)
					[
						SNew(SImage)
						.Image(IconBrush)
						.ColorAndOpacity(TextColor)
					]
				]
				+ SHorizontalBox::Slot().FillWidth(1.0f).VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(Label)
					.Font(FCoreStyle::GetDefaultFontStyle("Regular", 20))
					.ColorAndOpacity(TextColor)
				]
				+ SHorizontalBox::Slot().AutoWidth().VAlign(VAlign_Center).Padding(10, 0, 18, 0)
				[
					SNew(SBox).WidthOverride(18.0f).HeightOverride(18.0f)
					[
						SNew(SImage)
						.Image(ChevronBrush.Get())
						.ColorAndOpacity(ArrowColor)
					]
				]
			];
	}

	TSharedRef<SWidget> BuildMenuCard()
	{
		// Frosted menu sample: higher blur, lower refraction and subtle tint for a floating sheet.
		return SNew(SCBLiquidGlass)
			.Shape(ECBLiquidGlassShape::SuperellipseRect)
			.SquirclePower(7.5f)
			.BlurStrength(1.35f)
			.FrostRadius(0.42f)
			.RefractionStrength(0.62f)
			.RefractionPower(2.6f)
			.RefractionThickness(30.0f)
			.IndexOfRefraction(1.55f)
			.ChromaticAberration(0.055f)
			.PrismIntensity(0.5f)
			.NoiseAmount(0.018f)
			.GlowAmount(0.28f)
			.RimIntensity(0.22f)
			.GlowAngle(-125.0f)
			.InnerGlowIntensity(0.08f)
			.InnerShadowIntensity(0.2f)
			.TintColor(FLinearColor(0.72f, 0.78f, 0.82f, 1.0f))
			.TintOpacity(0.08f)
			.Saturation(1.08f)
			.AdaptiveTintStrength(0.06f)
			.GlassOpacity(0.9f)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight().Padding(20, 18, 20, 14)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot().FillWidth(1.0f).HAlign(HAlign_Center)
					[
						BuildMenuStar(LOCTEXT("MenuLabelA", "Label"), FLinearColor::White)
					]
					+ SHorizontalBox::Slot().FillWidth(1.0f).HAlign(HAlign_Center)
					[
						BuildMenuStar(LOCTEXT("MenuLabelB", "Label"), FLinearColor::White)
					]
					+ SHorizontalBox::Slot().FillWidth(1.0f).HAlign(HAlign_Center)
					[
						BuildMenuStar(LOCTEXT("MenuLabelC", "Label"), FLinearColor(1.0f, 0.32f, 0.42f, 1.0f))
					]
				]
				+ SVerticalBox::Slot().AutoHeight()[ BuildSeparator() ]
				+ SVerticalBox::Slot().AutoHeight()
				[
					BuildMenuRow(SearchBrush.Get(), LOCTEXT("FindInNote", "Find in Note"), FLinearColor::White)
				]
				+ SVerticalBox::Slot().AutoHeight()
				[
					BuildMenuRow(FolderBrush.Get(), LOCTEXT("MoveNote", "Move Note"), FLinearColor(1, 1, 1, 0.85f), true)
				]
				+ SVerticalBox::Slot().AutoHeight()[ BuildSeparator() ]
				+ SVerticalBox::Slot().AutoHeight().Padding(18, 13, 18, 4)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("MenuSectionTitle", "Section Title"))
					.Font(FCoreStyle::GetDefaultFontStyle("Regular", 16))
					.ColorAndOpacity(FLinearColor(1, 1, 1, 0.72f))
				]
				+ SVerticalBox::Slot().AutoHeight()
				[
					BuildMenuRow(FormatBrush.Get(), LOCTEXT("Format", "Format"), FLinearColor::White)
				]
				+ SVerticalBox::Slot().AutoHeight()
				[
					BuildMenuRow(TrashBrush.Get(), LOCTEXT("Delete", "Delete"), FLinearColor(1.0f, 0.38f, 0.44f, 1.0f))
				]
			];
	}

	TSharedRef<SWidget> BuildMenuStar(FText Label, FLinearColor Color)
	{
		return SNew(SVerticalBox)
			+ SVerticalBox::Slot().AutoHeight().HAlign(HAlign_Center)
			[
				SNew(SBox).WidthOverride(24.0f).HeightOverride(24.0f)
				[
					SNew(SImage)
					.Image(StarBrush.Get())
					.ColorAndOpacity(Color)
				]
			]
			+ SVerticalBox::Slot().AutoHeight().HAlign(HAlign_Center)
			[
				SNew(STextBlock)
				.Text(Label)
				.Font(FCoreStyle::GetDefaultFontStyle("Bold", 15))
				.ColorAndOpacity(Color)
			];
	}

	TSharedRef<SWidget> BuildCloseButton()
	{
		// The close button is glass too so it validates circular shape rendering and click handling.
		return SNew(SCBLGDemoClose)
			[
				SNew(SBox).WidthOverride(44.0f).HeightOverride(44.0f)
				[
					SNew(SCBLiquidGlass)
					.Shape(ECBLiquidGlassShape::Circle)
					.SquirclePower(3.0f)
					.FrostRadius(0.25f)
					.RimIntensity(0.5f)
					.InnerGlowIntensity(0.15f)
					[
						SNew(SBox).HAlign(HAlign_Center).VAlign(VAlign_Center)
						[
							SNew(SBox).WidthOverride(20.0f).HeightOverride(20.0f)
							[
								SNew(SImage)
								.Image(CloseBrush.Get())
								.ColorAndOpacity(FLinearColor::White)
							]
						]
					]
				]
			];
	}
};

enum class ECBLGControlMaskMode : uint8
{
	None,
	StarSvg,
	DropSvg,
};

struct FCBLGControlValues
{
	// Values mirrored by the sliders in SCBLiquidGlassControlDemo. Keep these aligned with
	// BuildControlPanel and ApplyValuesToPreview when adding new live controls.
	ECBLiquidGlassPreset Preset = ECBLiquidGlassPreset::Regular;
	ECBLiquidGlassShape Shape = ECBLiquidGlassShape::SuperellipseRect;
	ECBLiquidGlassQuality Quality = ECBLiquidGlassQuality::Balanced;
	ECBLGControlMaskMode MaskMode = ECBLGControlMaskMode::None;
	float SquirclePower = 7.0f;
	float BlurStrength = 0.9f;
	float FrostRadius = 0.25f;
	float RefractionStrength = 0.9f;
	float RefractionThickness = 34.0f;
	float IndexOfRefraction = 1.85f;
	float PrismIntensity = 0.75f;
	float TintOpacity = 0.015f;
	float RimIntensity = 0.24f;
	float InnerShadowIntensity = 0.12f;
	float GlassOpacity = 0.92f;
	float MotionStrength = 0.0f;
	float MotionMaxOffset = 32.0f;
};

/** Transparent-background tuning overlay for live Liquid Glass parameter control. */
class SCBLiquidGlassControlDemo : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLiquidGlassControlDemo) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs)
	{
		const FString IconDir = FPaths::Combine(CBLiquidGlassDemo::GetResourceDir(), TEXT("Icons"));
		StarMaskTexture = CBLiquidGlassDemo::CreateTextureFromSvgMask(FPaths::Combine(IconDir, TEXT("star.svg")), FIntPoint(256, 256));
		DropletMaskTexture = CBLiquidGlassDemo::CreateTextureFromSvgMask(FPaths::Combine(IconDir, TEXT("droplet.svg")), FIntPoint(256, 256));

		// No background slot is added on purpose: this overlay is transparent and samples the
		// underlying game viewport or the showcase demo if both are visible.
		ChildSlot
		[
			SNew(SOverlay)

			+ SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			.Padding(180.0f, 0.0f, 0.0f, 80.0f)
			[
				BuildPreview()
			]

			+ SOverlay::Slot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Center)
			.Padding(36.0f)
			[
				BuildControlPanel()
			]

			+ SOverlay::Slot()
			.HAlign(HAlign_Right)
			.VAlign(VAlign_Top)
			.Padding(24.0f)
			[
				BuildCloseButton()
			]
		];
	}

private:
	FCBLGControlValues Values;
	TSharedPtr<SCBLiquidGlass> PreviewGlass;
	TStrongObjectPtr<UTexture2D> StarMaskTexture;
	TStrongObjectPtr<UTexture2D> DropletMaskTexture;

	TSharedRef<SWidget> BuildPreview()
	{
		return SNew(SBox)
			.WidthOverride(480.0f)
			.HeightOverride(260.0f)
			[
				SAssignNew(PreviewGlass, SCBLiquidGlass)
				.Shape(Values.Shape)
				.SquirclePower(Values.SquirclePower)
				.BlurStrength(Values.BlurStrength)
				.FrostRadius(Values.FrostRadius)
				.RefractionStrength(Values.RefractionStrength)
				.RefractionPower(3.0f)
				.RefractionThickness(Values.RefractionThickness)
				.IndexOfRefraction(Values.IndexOfRefraction)
				.ChromaticAberration(0.1f)
				.PrismIntensity(Values.PrismIntensity)
				.NoiseAmount(0.014f)
				.GlowAmount(0.3f)
				.RimIntensity(Values.RimIntensity)
				.InnerGlowIntensity(0.05f)
				.InnerShadowIntensity(Values.InnerShadowIntensity)
				.TintOpacity(Values.TintOpacity)
				.Saturation(1.35f)
				.GlassOpacity(Values.GlassOpacity)
				.Quality(Values.Quality)
				.MotionStrength(Values.MotionStrength)
				.MotionMaxOffset(Values.MotionMaxOffset)
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot().AutoHeight().Padding(34, 30, 34, 6)
					[
						SNew(STextBlock)
						.Text(LOCTEXT("ControlPreviewTitle", "Liquid Glass Preview"))
						.Font(FCoreStyle::GetDefaultFontStyle("Bold", 30))
						.ColorAndOpacity(FLinearColor::White)
					]
					+ SVerticalBox::Slot().AutoHeight().Padding(34, 0, 34, 12)
					[
						SNew(STextBlock)
						.Text_Lambda([this]()
						{
							return FText::FromString(FString::Printf(TEXT("%s / %s / %s"),
								*PresetLabel(Values.Preset).ToString(),
								*ShapeLabel(Values.Shape).ToString(),
								*QualityLabel(Values.Quality).ToString()));
						})
						.Font(FCoreStyle::GetDefaultFontStyle("Regular", 16))
						.ColorAndOpacity(FLinearColor(1, 1, 1, 0.78f))
					]
				]
			];
	}

	void ApplyValuesToPreview()
	{
		// Slider callbacks update the existing Slate widget in place so the preview responds instantly.
		if (!PreviewGlass.IsValid())
		{
			return;
		}

		PreviewGlass->SetShape(Values.Shape);
		PreviewGlass->SetSquirclePower(Values.SquirclePower);
		PreviewGlass->SetBlurStrength(Values.BlurStrength);
		PreviewGlass->SetFrostRadius(Values.FrostRadius);
		PreviewGlass->SetRefractionStrength(Values.RefractionStrength);
		PreviewGlass->SetRefractionThickness(Values.RefractionThickness);
		PreviewGlass->SetIndexOfRefraction(Values.IndexOfRefraction);
		PreviewGlass->SetPrismIntensity(Values.PrismIntensity);
		PreviewGlass->SetTintOpacity(Values.TintOpacity);
		PreviewGlass->SetRimIntensity(Values.RimIntensity);
		PreviewGlass->SetInnerShadowIntensity(Values.InnerShadowIntensity);
		PreviewGlass->SetGlassOpacity(Values.GlassOpacity);
		PreviewGlass->SetQuality(Values.Quality);
		PreviewGlass->SetMotionStrength(Values.MotionStrength);
		PreviewGlass->SetMotionMaxOffset(Values.MotionMaxOffset);
		PreviewGlass->SetAlphaMaskTexture(GetSelectedMaskTexture());
		PreviewGlass->SetAlphaMaskThreshold(Values.MaskMode == ECBLGControlMaskMode::None ? 0.5f : 0.08f);
		PreviewGlass->SetAlphaMaskSoftness(Values.MaskMode == ECBLGControlMaskMode::None ? 0.08f : 0.025f);
	}

	UTexture2D* GetSelectedMaskTexture() const
	{
		switch (Values.MaskMode)
		{
		case ECBLGControlMaskMode::StarSvg:
			return StarMaskTexture.Get();
		case ECBLGControlMaskMode::DropSvg:
			return DropletMaskTexture.Get();
		case ECBLGControlMaskMode::None:
		default:
			return nullptr;
		}
	}

	static FText PresetLabel(ECBLiquidGlassPreset Preset)
	{
		switch (Preset)
		{
		case ECBLiquidGlassPreset::Clear: return LOCTEXT("PresetClear", "Clear");
		case ECBLiquidGlassPreset::FrostedMenu: return LOCTEXT("PresetMenu", "Menu");
		case ECBLiquidGlassPreset::PillLens: return LOCTEXT("PresetPill", "Pill");
		case ECBLiquidGlassPreset::MatteLayer: return LOCTEXT("PresetMatte", "Matte");
		case ECBLiquidGlassPreset::SelfLayer: return LOCTEXT("PresetSelf", "Self");
		case ECBLiquidGlassPreset::Regular: return LOCTEXT("PresetRegular", "Regular");
		case ECBLiquidGlassPreset::Custom:
		default: return LOCTEXT("PresetCustom", "Custom");
		}
	}

	static FText ShapeLabel(ECBLiquidGlassShape Shape)
	{
		switch (Shape)
		{
		case ECBLiquidGlassShape::Capsule: return LOCTEXT("ShapeCapsule", "Capsule");
		case ECBLiquidGlassShape::Circle: return LOCTEXT("ShapeCircle", "Circle");
		case ECBLiquidGlassShape::Diamond: return LOCTEXT("ShapeDiamond", "Diamond");
		case ECBLiquidGlassShape::Hexagon: return LOCTEXT("ShapeHexagon", "Hexagon");
		case ECBLiquidGlassShape::Star: return LOCTEXT("ShapeStar", "Star");
		case ECBLiquidGlassShape::Blob: return LOCTEXT("ShapeBlob", "Blob");
		case ECBLiquidGlassShape::SuperellipseRect:
		default: return LOCTEXT("ShapeRect", "Rect");
		}
	}

	static FText QualityLabel(ECBLiquidGlassQuality Quality)
	{
		switch (Quality)
		{
		case ECBLiquidGlassQuality::Performance: return LOCTEXT("QualityPerf", "Perf");
		case ECBLiquidGlassQuality::Quality: return LOCTEXT("QualityHigh", "Quality");
		case ECBLiquidGlassQuality::Balanced:
		default: return LOCTEXT("QualityBalanced", "Balanced");
		}
	}

	static FText MaskLabel(ECBLGControlMaskMode MaskMode)
	{
		switch (MaskMode)
		{
		case ECBLGControlMaskMode::StarSvg: return LOCTEXT("MaskStar", "SVG Star");
		case ECBLGControlMaskMode::DropSvg: return LOCTEXT("MaskDrop", "SVG Drop");
		case ECBLGControlMaskMode::None:
		default: return LOCTEXT("MaskNone", "None");
		}
	}

	void ApplyPresetToValues(ECBLiquidGlassPreset Preset)
	{
		Values.Preset = Preset;
		switch (Preset)
		{
		case ECBLiquidGlassPreset::Clear:
			Values.BlurStrength = 0.45f;
			Values.FrostRadius = 0.08f;
			Values.RefractionStrength = 1.0f;
			Values.RefractionThickness = 42.0f;
			Values.IndexOfRefraction = 2.0f;
			Values.PrismIntensity = 1.15f;
			Values.TintOpacity = 0.01f;
			Values.RimIntensity = 0.24f;
			Values.GlassOpacity = 1.0f;
			break;
		case ECBLiquidGlassPreset::FrostedMenu:
			Values.BlurStrength = 1.35f;
			Values.FrostRadius = 0.48f;
			Values.RefractionStrength = 0.62f;
			Values.RefractionThickness = 30.0f;
			Values.IndexOfRefraction = 1.55f;
			Values.PrismIntensity = 0.5f;
			Values.TintOpacity = 0.08f;
			Values.RimIntensity = 0.22f;
			Values.GlassOpacity = 0.9f;
			break;
		case ECBLiquidGlassPreset::PillLens:
			Values.Shape = ECBLiquidGlassShape::Capsule;
			Values.BlurStrength = 0.85f;
			Values.FrostRadius = 0.22f;
			Values.RefractionStrength = 1.0f;
			Values.RefractionThickness = 48.0f;
			Values.IndexOfRefraction = 2.0f;
			Values.PrismIntensity = 1.25f;
			Values.TintOpacity = 0.025f;
			Values.RimIntensity = 0.55f;
			Values.Quality = ECBLiquidGlassQuality::Quality;
			break;
		case ECBLiquidGlassPreset::MatteLayer:
			Values.BlurStrength = 2.3f;
			Values.FrostRadius = 0.65f;
			Values.RefractionStrength = 0.22f;
			Values.RefractionThickness = 18.0f;
			Values.IndexOfRefraction = 1.2f;
			Values.PrismIntensity = 0.18f;
			Values.TintOpacity = 0.12f;
			Values.RimIntensity = 0.16f;
			Values.GlassOpacity = 0.88f;
			Values.Quality = ECBLiquidGlassQuality::Performance;
			break;
		case ECBLiquidGlassPreset::Regular:
		default:
			Values.BlurStrength = 0.9f;
			Values.FrostRadius = 0.25f;
			Values.RefractionStrength = 0.9f;
			Values.RefractionThickness = 34.0f;
			Values.IndexOfRefraction = 1.85f;
			Values.PrismIntensity = 0.75f;
			Values.TintOpacity = 0.015f;
			Values.RimIntensity = 0.24f;
			Values.GlassOpacity = 0.92f;
			break;
		}

		ApplyValuesToPreview();
	}

	float GetNormalizedValue(float FCBLGControlValues::* Member, float MinValue, float MaxValue) const
	{
		// SSlider works in [0,1], while the glass parameters use artist-friendly ranges.
		return (Values.*Member - MinValue) / (MaxValue - MinValue);
	}

	TSharedRef<SWidget> BuildSlider(FText Label, float FCBLGControlValues::* Member, float MinValue, float MaxValue)
	{
		// The pointer-to-member keeps slider creation data-driven without introducing a separate model.
		return SNew(SVerticalBox)
			+ SVerticalBox::Slot().AutoHeight()
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot().FillWidth(1.0f)
				[
					SNew(STextBlock)
					.Text(Label)
					.Font(FCoreStyle::GetDefaultFontStyle("Regular", 13))
					.ColorAndOpacity(FLinearColor(1, 1, 1, 0.86f))
				]
				+ SHorizontalBox::Slot().AutoWidth()
				[
					SNew(STextBlock)
					.Text_Lambda([this, Member]()
					{
						return FText::AsNumber(Values.*Member);
					})
					.Font(FCoreStyle::GetDefaultFontStyle("Regular", 12))
					.ColorAndOpacity(FLinearColor(1, 1, 1, 0.62f))
				]
			]
			+ SVerticalBox::Slot().AutoHeight().Padding(0, 4, 0, 10)
			[
				SNew(SSlider)
				.Value(TAttribute<float>::Create(TAttribute<float>::FGetter::CreateLambda([this, Member, MinValue, MaxValue]()
				{
					return GetNormalizedValue(Member, MinValue, MaxValue);
				})))
				.OnValueChanged_Lambda([this, Member, MinValue, MaxValue](float InValue)
				{
					Values.*Member = FMath::Lerp(MinValue, MaxValue, InValue);
					ApplyValuesToPreview();
				})
				.SliderBarColor(FLinearColor(0.75f, 0.95f, 1.0f, 0.55f))
				.SliderHandleColor(FLinearColor::White)
			];
	}

	TSharedRef<SWidget> BuildChoiceButton(FText Label, TFunction<bool()> IsSelected, TFunction<void()> OnClicked)
	{
		return SNew(SButton)
			.ContentPadding(FMargin(9.0f, 5.0f))
			.ButtonColorAndOpacity_Lambda([IsSelected]()
			{
				return IsSelected()
					? FLinearColor(0.58f, 0.88f, 1.0f, 0.42f)
					: FLinearColor(1.0f, 1.0f, 1.0f, 0.08f);
			})
			.OnClicked_Lambda([OnClicked]()
			{
				OnClicked();
				return FReply::Handled();
			})
			[
				SNew(STextBlock)
				.Text(Label)
				.Font(FCoreStyle::GetDefaultFontStyle("Bold", 11))
				.ColorAndOpacity(FLinearColor::White)
			];
	}

	TSharedRef<SWidget> BuildEnumSection(FText Label, TSharedRef<SWidget> Choices)
	{
		return SNew(SVerticalBox)
			+ SVerticalBox::Slot().AutoHeight()
			[
				SNew(STextBlock)
				.Text(Label)
				.Font(FCoreStyle::GetDefaultFontStyle("Regular", 13))
				.ColorAndOpacity(FLinearColor(1, 1, 1, 0.86f))
			]
			+ SVerticalBox::Slot().AutoHeight().Padding(0, 5, 0, 12)
			[
				Choices
			];
	}

	TSharedRef<SWidget> BuildPresetChoices()
	{
		return BuildEnumSection(
			LOCTEXT("ControlPresetLabel", "Preset"),
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().AutoWidth().Padding(0, 0, 5, 0)
			[
				BuildChoiceButton(PresetLabel(ECBLiquidGlassPreset::Regular),
					[this]() { return Values.Preset == ECBLiquidGlassPreset::Regular; },
					[this]() { ApplyPresetToValues(ECBLiquidGlassPreset::Regular); })
			]
			+ SHorizontalBox::Slot().AutoWidth().Padding(0, 0, 5, 0)
			[
				BuildChoiceButton(PresetLabel(ECBLiquidGlassPreset::Clear),
					[this]() { return Values.Preset == ECBLiquidGlassPreset::Clear; },
					[this]() { ApplyPresetToValues(ECBLiquidGlassPreset::Clear); })
			]
			+ SHorizontalBox::Slot().AutoWidth().Padding(0, 0, 5, 0)
			[
				BuildChoiceButton(PresetLabel(ECBLiquidGlassPreset::FrostedMenu),
					[this]() { return Values.Preset == ECBLiquidGlassPreset::FrostedMenu; },
					[this]() { ApplyPresetToValues(ECBLiquidGlassPreset::FrostedMenu); })
			]
			+ SHorizontalBox::Slot().AutoWidth()
			[
				BuildChoiceButton(PresetLabel(ECBLiquidGlassPreset::PillLens),
					[this]() { return Values.Preset == ECBLiquidGlassPreset::PillLens; },
					[this]() { ApplyPresetToValues(ECBLiquidGlassPreset::PillLens); })
			]);
	}

	TSharedRef<SWidget> BuildShapeChoices()
	{
		return BuildEnumSection(
			LOCTEXT("ControlShapeLabel", "Shape"),
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().AutoWidth().Padding(0, 0, 5, 0)
			[
				BuildChoiceButton(ShapeLabel(ECBLiquidGlassShape::SuperellipseRect),
					[this]() { return Values.Shape == ECBLiquidGlassShape::SuperellipseRect; },
					[this]() { Values.Shape = ECBLiquidGlassShape::SuperellipseRect; ApplyValuesToPreview(); })
			]
			+ SHorizontalBox::Slot().AutoWidth().Padding(0, 0, 5, 0)
			[
				BuildChoiceButton(ShapeLabel(ECBLiquidGlassShape::Capsule),
					[this]() { return Values.Shape == ECBLiquidGlassShape::Capsule; },
					[this]() { Values.Shape = ECBLiquidGlassShape::Capsule; ApplyValuesToPreview(); })
			]
			+ SHorizontalBox::Slot().AutoWidth().Padding(0, 0, 5, 0)
			[
				BuildChoiceButton(ShapeLabel(ECBLiquidGlassShape::Circle),
					[this]() { return Values.Shape == ECBLiquidGlassShape::Circle; },
					[this]() { Values.Shape = ECBLiquidGlassShape::Circle; ApplyValuesToPreview(); })
			]
			+ SHorizontalBox::Slot().AutoWidth()
			[
				BuildChoiceButton(ShapeLabel(ECBLiquidGlassShape::Blob),
					[this]() { return Values.Shape == ECBLiquidGlassShape::Blob; },
					[this]() { Values.Shape = ECBLiquidGlassShape::Blob; ApplyValuesToPreview(); })
			]);
	}

	TSharedRef<SWidget> BuildQualityChoices()
	{
		return BuildEnumSection(
			LOCTEXT("ControlQualityLabel", "Quality"),
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().AutoWidth().Padding(0, 0, 5, 0)
			[
				BuildChoiceButton(QualityLabel(ECBLiquidGlassQuality::Performance),
					[this]() { return Values.Quality == ECBLiquidGlassQuality::Performance; },
					[this]() { Values.Quality = ECBLiquidGlassQuality::Performance; ApplyValuesToPreview(); })
			]
			+ SHorizontalBox::Slot().AutoWidth().Padding(0, 0, 5, 0)
			[
				BuildChoiceButton(QualityLabel(ECBLiquidGlassQuality::Balanced),
					[this]() { return Values.Quality == ECBLiquidGlassQuality::Balanced; },
					[this]() { Values.Quality = ECBLiquidGlassQuality::Balanced; ApplyValuesToPreview(); })
			]
			+ SHorizontalBox::Slot().AutoWidth()
			[
				BuildChoiceButton(QualityLabel(ECBLiquidGlassQuality::Quality),
					[this]() { return Values.Quality == ECBLiquidGlassQuality::Quality; },
					[this]() { Values.Quality = ECBLiquidGlassQuality::Quality; ApplyValuesToPreview(); })
			]);
	}

	TSharedRef<SWidget> BuildMaskChoices()
	{
		return BuildEnumSection(
			LOCTEXT("ControlMaskLabel", "Alpha Mask"),
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().AutoWidth().Padding(0, 0, 5, 0)
			[
				BuildChoiceButton(MaskLabel(ECBLGControlMaskMode::None),
					[this]() { return Values.MaskMode == ECBLGControlMaskMode::None; },
					[this]() { Values.MaskMode = ECBLGControlMaskMode::None; ApplyValuesToPreview(); })
			]
			+ SHorizontalBox::Slot().AutoWidth().Padding(0, 0, 5, 0)
			[
				BuildChoiceButton(MaskLabel(ECBLGControlMaskMode::StarSvg),
					[this]() { return Values.MaskMode == ECBLGControlMaskMode::StarSvg; },
					[this]() { Values.MaskMode = ECBLGControlMaskMode::StarSvg; ApplyValuesToPreview(); })
			]
			+ SHorizontalBox::Slot().AutoWidth()
			[
				BuildChoiceButton(MaskLabel(ECBLGControlMaskMode::DropSvg),
					[this]() { return Values.MaskMode == ECBLGControlMaskMode::DropSvg; },
					[this]() { Values.MaskMode = ECBLGControlMaskMode::DropSvg; ApplyValuesToPreview(); })
			]);
	}

	TSharedRef<SWidget> BuildControlPanel()
	{
		// The controls panel itself uses a lighter glass recipe so it remains readable on any background.
		return SNew(SCBLiquidGlass)
			.Shape(ECBLiquidGlassShape::SuperellipseRect)
			.SquirclePower(7.0f)
			.BlurStrength(0.9f)
			.FrostRadius(0.22f)
			.RefractionStrength(0.55f)
			.RefractionThickness(24.0f)
			.IndexOfRefraction(1.45f)
			.ChromaticAberration(0.05f)
			.PrismIntensity(0.35f)
			.TintOpacity(0.05f)
			.Saturation(1.15f)
			.RimIntensity(0.18f)
			.InnerShadowIntensity(0.12f)
			.GlassOpacity(0.86f)
			[
				SNew(SBox).WidthOverride(390.0f).HeightOverride(680.0f).Padding(22.0f)
				[
					SNew(SScrollBox)
					+ SScrollBox::Slot()
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot().AutoHeight().Padding(0, 0, 0, 14)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("ControlTitle", "Glass Controls"))
							.Font(FCoreStyle::GetDefaultFontStyle("Bold", 22))
							.ColorAndOpacity(FLinearColor::White)
						]
						+ SVerticalBox::Slot().AutoHeight()[ BuildPresetChoices() ]
						+ SVerticalBox::Slot().AutoHeight()[ BuildShapeChoices() ]
						+ SVerticalBox::Slot().AutoHeight()[ BuildQualityChoices() ]
						+ SVerticalBox::Slot().AutoHeight()[ BuildMaskChoices() ]
						+ SVerticalBox::Slot().AutoHeight()[ BuildSlider(LOCTEXT("CornerSlider", "Corner Power"), &FCBLGControlValues::SquirclePower, 2.0f, 12.0f) ]
						+ SVerticalBox::Slot().AutoHeight()[ BuildSlider(LOCTEXT("BlurSlider", "Blur"), &FCBLGControlValues::BlurStrength, 0.0f, 3.5f) ]
						+ SVerticalBox::Slot().AutoHeight()[ BuildSlider(LOCTEXT("FrostSlider", "Frost"), &FCBLGControlValues::FrostRadius, 0.0f, 1.0f) ]
						+ SVerticalBox::Slot().AutoHeight()[ BuildSlider(LOCTEXT("RefractionSlider", "Refraction"), &FCBLGControlValues::RefractionStrength, 0.0f, 1.0f) ]
						+ SVerticalBox::Slot().AutoHeight()[ BuildSlider(LOCTEXT("ThicknessSlider", "Thickness"), &FCBLGControlValues::RefractionThickness, 4.0f, 80.0f) ]
						+ SVerticalBox::Slot().AutoHeight()[ BuildSlider(LOCTEXT("IORSlider", "IOR"), &FCBLGControlValues::IndexOfRefraction, 1.0f, 2.4f) ]
						+ SVerticalBox::Slot().AutoHeight()[ BuildSlider(LOCTEXT("PrismSlider", "Prism"), &FCBLGControlValues::PrismIntensity, 0.0f, 2.0f) ]
						+ SVerticalBox::Slot().AutoHeight()[ BuildSlider(LOCTEXT("TintSlider", "Tint"), &FCBLGControlValues::TintOpacity, 0.0f, 0.25f) ]
						+ SVerticalBox::Slot().AutoHeight()[ BuildSlider(LOCTEXT("RimSlider", "Rim"), &FCBLGControlValues::RimIntensity, 0.0f, 0.8f) ]
						+ SVerticalBox::Slot().AutoHeight()[ BuildSlider(LOCTEXT("ShadowSlider", "Inner Shadow"), &FCBLGControlValues::InnerShadowIntensity, 0.0f, 0.8f) ]
						+ SVerticalBox::Slot().AutoHeight()[ BuildSlider(LOCTEXT("OpacitySlider", "Opacity"), &FCBLGControlValues::GlassOpacity, 0.1f, 1.0f) ]
						+ SVerticalBox::Slot().AutoHeight()[ BuildSlider(LOCTEXT("MotionSlider", "Motion"), &FCBLGControlValues::MotionStrength, 0.0f, 2.0f) ]
						+ SVerticalBox::Slot().AutoHeight()[ BuildSlider(LOCTEXT("MotionOffsetSlider", "Motion Max"), &FCBLGControlValues::MotionMaxOffset, 0.0f, 96.0f) ]
					]
				]
			];
	}

	TSharedRef<SWidget> BuildCloseButton()
	{
		return SNew(SCBLGDemoClose)
			.OnClicked(FSimpleDelegate::CreateStatic(&CBLiquidGlassDemo::RemoveControlDemo))
			[
				SNew(SBox).WidthOverride(42.0f).HeightOverride(42.0f)
				[
					SNew(SCBLiquidGlass)
					.Shape(ECBLiquidGlassShape::Circle)
					.FrostRadius(0.08f)
					.BlurStrength(0.4f)
					.RimIntensity(0.24f)
					.TintOpacity(0.01f)
					[
						SNew(SBox).HAlign(HAlign_Center).VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Text(FText::FromString(TEXT("X")))
							.Font(FCoreStyle::GetDefaultFontStyle("Bold", 18))
							.ColorAndOpacity(FLinearColor::White)
						]
					]
				]
			];
	}
};

enum class ECBLGFeatureDemoKind : uint8
{
	Motion,
	Button,
	Mask,
	Text,
	Fusion,
	Slider,
	Performance,
};

/** Shared shell for the smaller feature demos exposed as separate console commands. */
class SCBLiquidGlassFeatureDemo : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLiquidGlassFeatureDemo) {}
		SLATE_ARGUMENT(ECBLGFeatureDemoKind, Kind)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs)
	{
		Kind = InArgs._Kind;

		const FString BackgroundImagePath = CBLiquidGlassDemo::ResolveRandomBackgroundImagePath(TEXT("CBLiquidGlass.FeatureDemo"));

		BackgroundBrush = MakeShared<FSlateDynamicImageBrush>(
			FName(*FPaths::ConvertRelativePathToFull(BackgroundImagePath)),
			FVector2D(1920.0f, 1080.0f));

		const FString IconDir = FPaths::Combine(CBLiquidGlassDemo::GetResourceDir(), TEXT("Icons"));
		StarMaskTexture = CBLiquidGlassDemo::CreateTextureFromSvgMask(FPaths::Combine(IconDir, TEXT("star.svg")), FIntPoint(256, 256));
		DropletMaskTexture = CBLiquidGlassDemo::CreateTextureFromSvgMask(FPaths::Combine(IconDir, TEXT("droplet.svg")), FIntPoint(256, 256));
		SearchMaskTexture = CBLiquidGlassDemo::CreateTextureFromSvgMask(FPaths::Combine(IconDir, TEXT("search.svg")), FIntPoint(256, 256));

		PrimaryPos = FVector2D(240.0f, 210.0f);
		SecondaryPos = FVector2D(680.0f, 260.0f);
		ThirdPos = FVector2D(420.0f, 430.0f);
		FourthPos = FVector2D(820.0f, 430.0f);

		ChildSlot
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			[
				BuildBackground()
			]
			+ SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				BuildContent()
			]
			+ SOverlay::Slot()
			.HAlign(HAlign_Right)
			.VAlign(VAlign_Top)
			.Padding(24.0f)
			[
				BuildCloseButton()
			]
		];
	}

private:
	ECBLGFeatureDemoKind Kind = ECBLGFeatureDemoKind::Motion;
	FVector2D PrimaryPos = FVector2D::ZeroVector;
	FVector2D SecondaryPos = FVector2D::ZeroVector;
	FVector2D ThirdPos = FVector2D::ZeroVector;
	FVector2D FourthPos = FVector2D::ZeroVector;
	TSharedPtr<SCanvas> Canvas;
	TSharedPtr<FSlateDynamicImageBrush> BackgroundBrush;
	TStrongObjectPtr<UTexture2D> StarMaskTexture;
	TStrongObjectPtr<UTexture2D> DropletMaskTexture;
	TStrongObjectPtr<UTexture2D> SearchMaskTexture;

	FVector2D GetPrimaryPos() const { return PrimaryPos; }
	FVector2D GetSecondaryPos() const { return SecondaryPos; }
	FVector2D GetThirdPos() const { return ThirdPos; }
	FVector2D GetFourthPos() const { return FourthPos; }

	TSharedRef<SWidget> BuildBackground()
	{
		return SNew(SOverlay)
			+ SOverlay::Slot()
			[
				SNew(SImage).Image(BackgroundBrush.Get())
			]
			+ SOverlay::Slot()
			[
				SNew(SColorBlock).Color(FLinearColor(0.0f, 0.0f, 0.0f, 0.18f))
			];
	}

	TSharedRef<SWidget> BuildContent()
	{
		switch (Kind)
		{
		case ECBLGFeatureDemoKind::Button:
			return BuildButtonDemo();
		case ECBLGFeatureDemoKind::Mask:
			return BuildMaskDemo();
		case ECBLGFeatureDemoKind::Text:
			return BuildTextDemo();
		case ECBLGFeatureDemoKind::Fusion:
			return BuildFusionDemo();
		case ECBLGFeatureDemoKind::Slider:
			return BuildSliderDemo();
		case ECBLGFeatureDemoKind::Performance:
			return BuildPerformanceDemo();
		case ECBLGFeatureDemoKind::Motion:
		default:
			return BuildMotionDemo();
		}
	}

	TSharedRef<SWidget> MakeDraggable(TSharedRef<SWidget> Content, FVector2D SCBLiquidGlassFeatureDemo::* PositionMember)
	{
		TSharedRef<SCBLGDemoDraggable> Draggable = SNew(SCBLGDemoDraggable)
			.HoldSeconds(0.12f)
			[
				Content
			];

		Draggable->OnDragDelta = [this, PositionMember](const FVector2D& Delta)
		{
			this->*PositionMember += Delta;
			if (Canvas.IsValid())
			{
				Canvas->Invalidate(EInvalidateWidgetReason::Layout);
			}
		};

		return Draggable;
	}

	TSharedRef<SWidget> BuildMotionDemo()
	{
		PrimaryPos = FVector2D(40.0f, 130.0f);
		SecondaryPos = FVector2D(530.0f, 115.0f);

		return SNew(SBox)
			.WidthOverride(760.0f)
			.HeightOverride(390.0f)
			[
				SAssignNew(Canvas, SCanvas)
				+ SCanvas::Slot()
				.Position(FVector2D(260.0f, 20.0f))
				.Size(FVector2D(260.0f, 44.0f))
				[
					BuildDemoTitle(LOCTEXT("MotionDemoHeading", "Motion Glass"))
				]
				+ SCanvas::Slot()
				.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassFeatureDemo::GetPrimaryPos))
				.Size(FVector2D(380.0f, 150.0f))
				[
					MakeDraggable(
						SNew(SCBLiquidGlass)
						.Shape(ECBLiquidGlassShape::SuperellipseRect)
						.SquirclePower(7.0f)
						.FrostRadius(0.22f)
						.MotionStrength(1.05f)
						.MotionMaxOffset(58.0f)
						.MotionResponse(24.0f)
						.MotionDamping(8.0f)
						.Quality(ECBLiquidGlassQuality::Quality)
						[
							SNew(SBox).Padding(30.0f).VAlign(VAlign_Center)
							[
								SNew(STextBlock)
								.Text(LOCTEXT("MotionDemoTitle", "Drag Me"))
								.Font(FCoreStyle::GetDefaultFontStyle("Bold", 30))
								.ColorAndOpacity(FLinearColor::White)
							]
						],
						&SCBLiquidGlassFeatureDemo::PrimaryPos)
				]
				+ SCanvas::Slot()
				.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassFeatureDemo::GetSecondaryPos))
				.Size(FVector2D(180.0f, 180.0f))
				[
					MakeDraggable(
						SNew(SCBLiquidGlass)
						.Shape(ECBLiquidGlassShape::Blob)
						.FrostRadius(0.12f)
						.RefractionStrength(1.0f)
						.MotionStrength(1.35f)
						.MotionMaxOffset(64.0f)
						.MotionResponse(26.0f)
						.MotionDamping(7.0f)
						[
							SNew(SBox)
						],
						&SCBLiquidGlassFeatureDemo::SecondaryPos)
				]
			];
	}

	TSharedRef<SWidget> BuildButtonDemo()
	{
		PrimaryPos = FVector2D(50.0f, 95.0f);
		SecondaryPos = FVector2D(50.0f, 185.0f);
		ThirdPos = FVector2D(50.0f, 275.0f);

		return SNew(SBox)
			.WidthOverride(420.0f)
			.HeightOverride(390.0f)
			[
				SAssignNew(Canvas, SCanvas)
				+ SCanvas::Slot()
				.Position(FVector2D(40.0f, 20.0f))
				.Size(FVector2D(360.0f, 44.0f))
				[
					BuildDemoTitle(LOCTEXT("ButtonDemoTitle", "Liquid Glass Button"))
				]
				+ SCanvas::Slot()
				.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassFeatureDemo::GetPrimaryPos))
				.Size(FVector2D(320.0f, 70.0f))
				[
					MakeDraggable(BuildSlateButton(LOCTEXT("ButtonPrimary", "Primary"), ECBLiquidGlassPreset::PillLens, ECBLiquidGlassShape::Capsule), &SCBLiquidGlassFeatureDemo::PrimaryPos)
				]
				+ SCanvas::Slot()
				.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassFeatureDemo::GetSecondaryPos))
				.Size(FVector2D(320.0f, 70.0f))
				[
					MakeDraggable(BuildSlateButton(LOCTEXT("ButtonMenu", "Frosted Menu Action"), ECBLiquidGlassPreset::FrostedMenu, ECBLiquidGlassShape::SuperellipseRect), &SCBLiquidGlassFeatureDemo::SecondaryPos)
				]
				+ SCanvas::Slot()
				.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassFeatureDemo::GetThirdPos))
				.Size(FVector2D(320.0f, 70.0f))
				[
					MakeDraggable(BuildSlateButton(LOCTEXT("ButtonBlob", "Blob Button"), ECBLiquidGlassPreset::Clear, ECBLiquidGlassShape::Blob), &SCBLiquidGlassFeatureDemo::ThirdPos)
				]
			];
	}

	TSharedRef<SWidget> BuildSlateButton(FText Label, ECBLiquidGlassPreset Preset, ECBLiquidGlassShape Shape)
	{
		return SNew(SBox).WidthOverride(300.0f).HeightOverride(64.0f)
			[
				SNew(SCBLiquidGlassButton)
				.Preset(Preset)
				.Shape(Shape)
				[
					SNew(STextBlock)
					.Text(Label)
					.Font(FCoreStyle::GetDefaultFontStyle("Bold", 18))
					.ColorAndOpacity(FLinearColor::White)
				]
			];
	}

	TSharedRef<SWidget> BuildMaskDemo()
	{
		PrimaryPos = FVector2D(0.0f, 90.0f);
		SecondaryPos = FVector2D(190.0f, 90.0f);
		ThirdPos = FVector2D(380.0f, 90.0f);
		FourthPos = FVector2D(570.0f, 90.0f);

		return SNew(SBox)
			.WidthOverride(740.0f)
			.HeightOverride(330.0f)
			[
				SAssignNew(Canvas, SCanvas)
				+ SCanvas::Slot()
				.Position(FVector2D(200.0f, 0.0f))
				.Size(FVector2D(360.0f, 44.0f))
				[
					BuildDemoTitle(LOCTEXT("MaskDemoTitle", "Texture / SVG Masks"))
				]
				+ SCanvas::Slot()
				.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassFeatureDemo::GetPrimaryPos))
				.Size(FVector2D(170.0f, 190.0f))
				[
					MakeDraggable(BuildTextureMaskSample(StarMaskTexture.Get(), LOCTEXT("StarMask", "SVG Star")), &SCBLiquidGlassFeatureDemo::PrimaryPos)
				]
				+ SCanvas::Slot()
				.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassFeatureDemo::GetSecondaryPos))
				.Size(FVector2D(170.0f, 190.0f))
				[
					MakeDraggable(BuildTextureMaskSample(DropletMaskTexture.Get(), LOCTEXT("DropletMask", "SVG Drop")), &SCBLiquidGlassFeatureDemo::SecondaryPos)
				]
				+ SCanvas::Slot()
				.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassFeatureDemo::GetThirdPos))
				.Size(FVector2D(170.0f, 190.0f))
				[
					MakeDraggable(BuildTextureMaskSample(SearchMaskTexture.Get(), LOCTEXT("SearchMask", "SVG Search")), &SCBLiquidGlassFeatureDemo::ThirdPos)
				]
				+ SCanvas::Slot()
				.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassFeatureDemo::GetFourthPos))
				.Size(FVector2D(170.0f, 190.0f))
				[
					MakeDraggable(BuildShapeSample(ECBLiquidGlassShape::Blob, LOCTEXT("BlobShape", "SDF Blob")), &SCBLiquidGlassFeatureDemo::FourthPos)
				]
			];
	}

	TSharedRef<SWidget> BuildTextureMaskSample(UTexture2D* MaskTexture, FText Label)
	{
		return SNew(SVerticalBox)
			+ SVerticalBox::Slot().AutoHeight()
			[
				SNew(SBox).WidthOverride(150.0f).HeightOverride(150.0f)
				[
					SNew(SCBLiquidGlass)
					.AlphaMaskTexture(MaskTexture)
					.AlphaMaskThreshold(0.08f)
					.AlphaMaskSoftness(0.025f)
					.FrostRadius(0.08f)
					.BlurStrength(0.55f)
					.RefractionStrength(1.0f)
					.RefractionThickness(42.0f)
					.IndexOfRefraction(2.15f)
					.PrismIntensity(1.05f)
					.RimIntensity(0.34f)
					.InnerGlowIntensity(0.18f)
					.Quality(ECBLiquidGlassQuality::Quality)
					[
						SNew(SBox)
					]
				]
			]
			+ SVerticalBox::Slot().AutoHeight().HAlign(HAlign_Center).Padding(0, 8, 0, 0)
			[
				SNew(STextBlock)
				.Text(Label)
				.Font(FCoreStyle::GetDefaultFontStyle("Regular", 14))
				.ColorAndOpacity(FLinearColor::White)
			];
	}

	TSharedRef<SWidget> BuildShapeSample(ECBLiquidGlassShape Shape, FText Label)
	{
		return SNew(SVerticalBox)
			+ SVerticalBox::Slot().AutoHeight()
			[
				SNew(SBox).WidthOverride(150.0f).HeightOverride(150.0f)
				[
					SNew(SCBLiquidGlass)
					.Shape(Shape)
					.FrostRadius(0.12f)
					.RefractionStrength(1.0f)
					.RefractionThickness(38.0f)
					.IndexOfRefraction(2.0f)
					.PrismIntensity(0.95f)
					.Quality(ECBLiquidGlassQuality::Quality)
					[
						SNew(SBox)
					]
				]
			]
			+ SVerticalBox::Slot().AutoHeight().HAlign(HAlign_Center).Padding(0, 8, 0, 0)
			[
				SNew(STextBlock)
				.Text(Label)
				.Font(FCoreStyle::GetDefaultFontStyle("Regular", 14))
				.ColorAndOpacity(FLinearColor::White)
			];
	}

	TSharedRef<SWidget> BuildTextDemo()
	{
		PrimaryPos = FVector2D(42.0f, 8.0f);
		SecondaryPos = FVector2D(120.0f, 276.0f);

		return SNew(SBox)
			.WidthOverride(760.0f)
			.HeightOverride(420.0f)
			[
				SAssignNew(Canvas, SCanvas)
				+ SCanvas::Slot()
				.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassFeatureDemo::GetPrimaryPos))
				.Size(FVector2D(675.0f, 205.0f))
				[
					MakeDraggable(BuildGlassTextPanel(LOCTEXT("TextDemoGlassHello", "hello"), 128, 675.0f, 205.0f), &SCBLiquidGlassFeatureDemo::PrimaryPos)
				]
				+ SCanvas::Slot()
				.Position(FVector2D(0.0f, 232.0f))
				.Size(FVector2D(760.0f, 188.0f))
				[
					SNew(SOverlay)
					+ SOverlay::Slot()
					[
						BuildCheckerboard(FVector2D(760.0f, 188.0f), 32.0f)
					]
					+ SOverlay::Slot()
					.HAlign(HAlign_Left)
					.VAlign(VAlign_Top)
					.Padding(18.0f, 14.0f, 0.0f, 0.0f)
					[
						SNew(STextBlock)
						.Text(LOCTEXT("TextDemoMatteSource", "Matte Source:"))
						.Font(FCoreStyle::GetDefaultFontStyle("Mono", 20))
						.ColorAndOpacity(FLinearColor::White)
					]
				]
				+ SCanvas::Slot()
				.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassFeatureDemo::GetSecondaryPos))
				.Size(FVector2D(560.0f, 126.0f))
				[
					MakeDraggable(BuildMatteSourceTextPanel(LOCTEXT("TextDemoSourceHello", "hello"), 124, 560.0f, 126.0f), &SCBLiquidGlassFeatureDemo::SecondaryPos)
				]
			];
	}

	TSharedRef<SWidget> BuildGlassTextPanel(FText Text, int32 FontSize, float Width, float Height)
	{
		return SNew(SBox)
			.WidthOverride(Width)
			.HeightOverride(Height)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(SCBLiquidGlassText)
				.Text(Text)
				.Font(BuildScriptDemoFont(FontSize))
				.ColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.32f))
				.FontSize(FontSize)
				.GlyphThickness(9.0f)
				.LetterSpacing(0.0f)
				.LineSpacing(0.0f)
				.Preset(ECBLiquidGlassPreset::PillLens)
				.Quality(ECBLiquidGlassQuality::Quality)
				.FrostRadius(0.035f)
				.MotionStrength(0.32f)
			];
	}

	TSharedRef<SWidget> BuildMatteSourceTextPanel(FText Text, int32 FontSize, float Width, float Height)
	{
		return SNew(SBox)
			.WidthOverride(Width)
			.HeightOverride(Height)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(Text)
				.Font(BuildScriptDemoFont(FontSize))
				.ColorAndOpacity(FLinearColor::White)
			];
	}

	TSharedRef<SWidget> BuildCheckerboard(FVector2D Size, float ApproxCellSize) const
	{
		const int32 Columns = FMath::Max(1, FMath::RoundToInt(Size.X / FMath::Max(ApproxCellSize, 1.0f)));
		const int32 Rows = FMath::Max(1, FMath::RoundToInt(Size.Y / FMath::Max(ApproxCellSize, 1.0f)));
		const float CellWidth = Size.X / static_cast<float>(Columns);
		const float CellHeight = Size.Y / static_cast<float>(Rows);
		const FLinearColor DarkCell(0.075f, 0.075f, 0.075f, 1.0f);
		const FLinearColor LightCell(0.16f, 0.16f, 0.16f, 1.0f);

		TSharedRef<SGridPanel> Grid = SNew(SGridPanel);
		for (int32 Row = 0; Row < Rows; ++Row)
		{
			for (int32 Column = 0; Column < Columns; ++Column)
			{
				Grid->AddSlot(Column, Row)
				[
					SNew(SBox)
					.WidthOverride(CellWidth)
					.HeightOverride(CellHeight)
					[
						SNew(SColorBlock)
						.Color(((Row + Column) % 2) == 0 ? DarkCell : LightCell)
					]
				];
			}
		}

		return SNew(SBox)
			.WidthOverride(Size.X)
			.HeightOverride(Size.Y)
			[
				Grid
			];
	}

	FSlateFontInfo BuildScriptDemoFont(int32 FontSize) const
	{
		// Use a common Windows script font for the "hello" sample; the widget still accepts any Slate font from UMG.
		static TSharedPtr<const FCompositeFont> ScriptCompositeFont;
		const FString WindowsDir = FPlatformMisc::GetEnvironmentVariable(TEXT("WINDIR"));
		const FString ScriptFontPath = FPaths::Combine(WindowsDir.IsEmpty() ? TEXT("C:/Windows") : WindowsDir, TEXT("Fonts/segoesc.ttf"));
		if (FPaths::FileExists(ScriptFontPath))
		{
			if (!ScriptCompositeFont.IsValid())
			{
				TSharedRef<FStandaloneCompositeFont> MutableFont = MakeShared<FStandaloneCompositeFont>();
				MutableFont->DefaultTypeface.AppendFont(TEXT("Regular"), ScriptFontPath, EFontHinting::Default, EFontLoadingPolicy::LazyLoad);
				ScriptCompositeFont = MutableFont;
			}

			return FSlateFontInfo(ScriptCompositeFont, FontSize, TEXT("Regular"));
		}

		return FCoreStyle::GetDefaultFontStyle("Bold", FontSize);
	}

	TSharedRef<SWidget> BuildFusionDemo()
	{
		return SNew(SBox)
			.WidthOverride(780.0f)
			.HeightOverride(390.0f)
			[
				SNew(SOverlay)
				+ SOverlay::Slot()
				[
					SNew(SCBLGFusionGroup)
				]
				+ SOverlay::Slot()
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Top)
				.Padding(0.0f, 20.0f, 0.0f, 0.0f)
				[
					BuildDemoTitle(LOCTEXT("FusionDemoTitle", "Fusion Group"))
				]
			];
	}

	TSharedRef<SWidget> BuildSliderDemo()
	{
		return SNew(SBox)
			.WidthOverride(820.0f)
			.HeightOverride(230.0f)
			[
				SAssignNew(Canvas, SCanvas)
				+ SCanvas::Slot()
				.Position(FVector2D(40.0f, 78.0f))
				.Size(FVector2D(740.0f, 84.0f))
				[
					SNew(SCBLiquidGlassSlider)
					.Value(0.56f)
					.SliderLength(740.0f)
					.SliderHeight(84.0f)
					.TrackHeight(12.0f)
					.ThumbSize(FVector2D(112.0f, 50.0f))
					.FillColor(FLinearColor(0.0f, 0.44f, 1.0f, 1.0f))
					.TrackOpacity(0.68f)
					.ThumbPreset(ECBLiquidGlassPreset::PillLens)
					.Quality(ECBLiquidGlassQuality::Quality)
					.ThumbBounce(0.72f)
					.ThumbResponse(23.0f)
					.ThumbDamping(8.2f)
					.ThumbMotionStrength(0.76f)
				]
			];
	}

	TSharedRef<SWidget> BuildPerformanceDemo()
	{
		PrimaryPos = FVector2D(0.0f, 100.0f);
		SecondaryPos = FVector2D(255.0f, 100.0f);
		ThirdPos = FVector2D(510.0f, 100.0f);

		return SNew(SBox)
			.WidthOverride(740.0f)
			.HeightOverride(320.0f)
			[
				SAssignNew(Canvas, SCanvas)
				+ SCanvas::Slot()
				.Position(FVector2D(240.0f, 15.0f))
				.Size(FVector2D(360.0f, 44.0f))
				[
					BuildDemoTitle(LOCTEXT("PerformanceDemoTitle", "Quality Profiles"))
				]
				+ SCanvas::Slot()
				.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassFeatureDemo::GetPrimaryPos))
				.Size(FVector2D(230.0f, 160.0f))
				[
					MakeDraggable(BuildQualitySample(LOCTEXT("PerfProfile", "Performance"), ECBLiquidGlassQuality::Performance), &SCBLiquidGlassFeatureDemo::PrimaryPos)
				]
				+ SCanvas::Slot()
				.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassFeatureDemo::GetSecondaryPos))
				.Size(FVector2D(230.0f, 160.0f))
				[
					MakeDraggable(BuildQualitySample(LOCTEXT("BalancedProfile", "Balanced"), ECBLiquidGlassQuality::Balanced), &SCBLiquidGlassFeatureDemo::SecondaryPos)
				]
				+ SCanvas::Slot()
				.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassFeatureDemo::GetThirdPos))
				.Size(FVector2D(230.0f, 160.0f))
				[
					MakeDraggable(BuildQualitySample(LOCTEXT("QualityProfile", "Quality"), ECBLiquidGlassQuality::Quality), &SCBLiquidGlassFeatureDemo::ThirdPos)
				]
			];
	}

	TSharedRef<SWidget> BuildQualitySample(FText Label, ECBLiquidGlassQuality Quality)
	{
		return SNew(SBox).WidthOverride(220.0f).HeightOverride(150.0f)
			[
				SNew(SCBLiquidGlass)
				.Shape(ECBLiquidGlassShape::SuperellipseRect)
				.SquirclePower(7.0f)
				.BlurStrength(1.2f)
				.FrostRadius(0.34f)
				.RefractionStrength(0.9f)
				.PrismIntensity(1.0f)
				.Quality(Quality)
				[
					SNew(SBox).HAlign(HAlign_Center).VAlign(VAlign_Center)
					[
						SNew(STextBlock)
						.Text(Label)
						.Font(FCoreStyle::GetDefaultFontStyle("Bold", 20))
						.ColorAndOpacity(FLinearColor::White)
					]
				]
			];
	}

	TSharedRef<SWidget> BuildDemoTitle(FText Text) const
	{
		return SNew(STextBlock)
			.Text(Text)
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 30))
			.ColorAndOpacity(FLinearColor::White);
	}

	TSharedRef<SWidget> BuildCloseButton()
	{
		return SNew(SCBLGDemoClose)
			.OnClicked(FSimpleDelegate::CreateStatic(&CBLiquidGlassDemo::RemoveFeatureDemo))
			[
				SNew(SBox).WidthOverride(42.0f).HeightOverride(42.0f)
				[
					SNew(SCBLiquidGlass)
					.Shape(ECBLiquidGlassShape::Circle)
					.FrostRadius(0.08f)
					.BlurStrength(0.4f)
					.RimIntensity(0.24f)
					.TintOpacity(0.01f)
					[
						SNew(SBox).HAlign(HAlign_Center).VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Text(FText::FromString(TEXT("X")))
							.Font(FCoreStyle::GetDefaultFontStyle("Bold", 18))
							.ColorAndOpacity(FLinearColor::White)
						]
					]
				]
			];
	}
};

enum class ECBLGShowcaseTab : uint8
{
	Glass,
	Button,
	Toggle,
	Slider,
	Text,
	Mask,
	Fusion,
	Motion,
	Performance,
	Segmented,
	TabBar,
	Toolbar,
	Menu,
	SearchBar,
	Progress,
	Stepper,
	Container,
	PageControl,
	Dialog,
	NavBar,
	Badge,
};

struct FCBLGShowcaseValues
{
	FCBLGShowcaseValues()
	{
		Glass.Quality = ECBLiquidGlassQuality::Quality;
		Glass.BlurStrength = 0.72f;
		Glass.FrostRadius = 0.16f;
		Glass.RefractionStrength = 0.9f;
		Glass.RefractionThickness = 44.0f;
		Glass.IndexOfRefraction = 1.86f;
		Glass.PrismIntensity = 0.58f;
		Glass.RimIntensity = 0.46f;
		Glass.InnerShadowIntensity = 0.14f;
		Glass.GlassOpacity = 0.98f;
		Glass.MotionStrength = 0.42f;
	}

	// General glass controls shared by the simple preview tabs.
	FCBLGControlValues Glass;

	// Component-specific controls are kept beside the shared glass recipe so tab switching
	// preserves the user's tuning without rebuilding a separate model per tab.
	float ButtonHoverGlowBoost = 0.18f;
	float ButtonPressedRefractionBoost = 0.14f;
	float SliderValue = 0.62f;
	float SliderThumbBounce = 0.56f;
	float SliderThumbResponse = 24.0f;
	float SliderThumbDamping = 9.0f;
	bool bToggleChecked = true;
	int32 SegmentedIndex = 1;
	int32 TabBarIndex = 0;
	int32 ToolbarIndex = 1;
	FText SearchText = FText::GetEmpty();
	bool bSearchShowIcon = true;
	bool bSearchShowLabel = true;
	bool bSearchShowClearButton = true;
	FCBLiquidGlassSearchBoxStyle SearchBoxStyle;
	float ProgressValue = 0.64f;
	float ProgressThickness = 10.0f;
	float ProgressFrostRadius = 0.18f;
	float ProgressRefractionStrength = 0.48f;
	float ProgressPrismIntensity = 0.12f;
	float ProgressTrackOpacity = 0.48f;
	bool bProgressShowPercent = true;
	float StepperValue = 3.0f;
	float TextFontSize = 112.0f;
	float TextGlyphThickness = 7.0f;
	float TextFrostRadius = 0.02f;
	float MaskThreshold = 0.035f;
	float MaskSoftness = 0.012f;
	float FusionRimIntensity = 0.34f;
	float FusionPrismIntensity = 0.28f;
	float ContainerSmoothing = 54.0f;
	float ContainerFrostRadius = 0.24f;
	float ContainerRefractionStrength = 0.98f;
	float ContainerPrismIntensity = 0.42f;
	float ContainerRimIntensity = 0.68f;
	float ContainerOpacity = 1.0f;
	float PageIndex = 2.0f;
	float BadgeCount = 8.0f;
	bool bBadgeDotMode = false;
	bool bDialogDimBackground = false;
	float DialogDimOpacity = 0.24f;
	float DialogBlurStrength = 1.15f;
	float DialogFrostRadius = 0.42f;
	float DialogRefractionStrength = 0.72f;
	float DialogPrismIntensity = 0.22f;
	float DialogOpacity = 0.94f;
};

/** Unified component browser with a liquid tab bar and draggable live previews. */
class SCBLiquidGlassShowcaseDemo : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLiquidGlassShowcaseDemo)
		: _InitialTab(ECBLGShowcaseTab::Glass)
	{}
		SLATE_ARGUMENT(ECBLGShowcaseTab, InitialTab)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs)
	{
		ActiveTab = InArgs._InitialTab;
		TabVisualX = GetTabTargetX();

		const FString ResourceDir = CBLiquidGlassDemo::GetResourceDir();
		const FString IconDir = FPaths::Combine(ResourceDir, TEXT("Icons"));
		const FString BackgroundImagePath = CBLiquidGlassDemo::ResolveRandomBackgroundImagePath(TEXT("CBLiquidGlass.ShowcaseDemo"));
		BackgroundBrush = MakeShared<FSlateDynamicImageBrush>(
			FName(*FPaths::ConvertRelativePathToFull(BackgroundImagePath)),
			FVector2D(1920.0f, 1080.0f));

		GlassIconBrush = MakeShared<FSlateVectorImageBrush>(FPaths::Combine(IconDir, TEXT("showcase-glass.svg")), FVector2D(24.0f, 24.0f));
		ButtonIconBrush = MakeShared<FSlateVectorImageBrush>(FPaths::Combine(IconDir, TEXT("showcase-button.svg")), FVector2D(24.0f, 24.0f));
		ToggleIconBrush = MakeShared<FSlateVectorImageBrush>(FPaths::Combine(IconDir, TEXT("showcase-toggle.svg")), FVector2D(24.0f, 24.0f));
		SliderIconBrush = MakeShared<FSlateVectorImageBrush>(FPaths::Combine(IconDir, TEXT("showcase-slider.svg")), FVector2D(24.0f, 24.0f));
		TextIconBrush = MakeShared<FSlateVectorImageBrush>(FPaths::Combine(IconDir, TEXT("showcase-text.svg")), FVector2D(24.0f, 24.0f));
		MaskIconBrush = MakeShared<FSlateVectorImageBrush>(FPaths::Combine(IconDir, TEXT("showcase-mask.svg")), FVector2D(24.0f, 24.0f));
		FusionIconBrush = MakeShared<FSlateVectorImageBrush>(FPaths::Combine(IconDir, TEXT("showcase-fusion.svg")), FVector2D(24.0f, 24.0f));
		MotionIconBrush = MakeShared<FSlateVectorImageBrush>(FPaths::Combine(IconDir, TEXT("showcase-motion.svg")), FVector2D(24.0f, 24.0f));
		PerformanceIconBrush = MakeShared<FSlateVectorImageBrush>(FPaths::Combine(IconDir, TEXT("showcase-performance.svg")), FVector2D(24.0f, 24.0f));
		SegmentedIconBrush = MakeShared<FSlateVectorImageBrush>(FPaths::Combine(IconDir, TEXT("showcase-segmented.svg")), FVector2D(24.0f, 24.0f));
		TabBarIconBrush = MakeShared<FSlateVectorImageBrush>(FPaths::Combine(IconDir, TEXT("showcase-tabbar.svg")), FVector2D(24.0f, 24.0f));
		ToolbarIconBrush = MakeShared<FSlateVectorImageBrush>(FPaths::Combine(IconDir, TEXT("showcase-toolbar.svg")), FVector2D(24.0f, 24.0f));
		MenuIconBrush = MakeShared<FSlateVectorImageBrush>(FPaths::Combine(IconDir, TEXT("showcase-menu.svg")), FVector2D(24.0f, 24.0f));
		SearchBarIconBrush = MakeShared<FSlateVectorImageBrush>(FPaths::Combine(IconDir, TEXT("showcase-searchbar.svg")), FVector2D(24.0f, 24.0f));
		ProgressIconBrush = MakeShared<FSlateVectorImageBrush>(FPaths::Combine(IconDir, TEXT("showcase-progress.svg")), FVector2D(24.0f, 24.0f));
		StepperIconBrush = MakeShared<FSlateVectorImageBrush>(FPaths::Combine(IconDir, TEXT("showcase-stepper.svg")), FVector2D(24.0f, 24.0f));
		CloseBrush = MakeShared<FSlateVectorImageBrush>(FPaths::Combine(IconDir, TEXT("x.svg")), FVector2D(20.0f, 20.0f));

		StarMaskTexture = CBLiquidGlassDemo::CreateTextureFromSvgMask(FPaths::Combine(IconDir, TEXT("star.svg")), FIntPoint(256, 256));
		DropletMaskTexture = CBLiquidGlassDemo::CreateTextureFromSvgMask(FPaths::Combine(IconDir, TEXT("droplet.svg")), FIntPoint(256, 256));
		SearchMaskTexture = CBLiquidGlassDemo::CreateTextureFromSvgMask(FPaths::Combine(IconDir, TEXT("search.svg")), FIntPoint(256, 256));

		ChildSlot
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			[
				BuildBackground()
			]
			+ SOverlay::Slot()
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot().FillHeight(1.0f).Padding(44.0f, 34.0f, 44.0f, 14.0f)
				[
					BuildMainArea()
				]
				+ SVerticalBox::Slot().AutoHeight().HAlign(HAlign_Center).Padding(0.0f, 0.0f, 0.0f, 30.0f)
				[
					BuildTabBar()
				]
			]
			+ SOverlay::Slot()
			.HAlign(HAlign_Right)
			.VAlign(VAlign_Top)
			.Padding(24.0f)
			[
				BuildCloseButton()
			]
		];

		RefreshParameterPanel();
		RefreshPreview();
	}

	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override
	{
		SCompoundWidget::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);

		const float TargetX = GetTabTargetX();
		const float DeltaTime = FMath::Clamp(InDeltaTime, 0.0f, 1.0f / 30.0f);
		if (DeltaTime <= 0.0f)
		{
			return;
		}

		float RemainingTime = DeltaTime;
		while (RemainingTime > 0.0f)
		{
			const float StepTime = FMath::Min(RemainingTime, 1.0f / 120.0f);
			const float Response = 24.0f;
			const float DampingRatio = 0.78f;
			const float SpringForce = (TargetX - TabVisualX) * Response * Response;
			const float DampingForce = 2.0f * Response * DampingRatio * TabVisualVelocity;
			TabVisualVelocity += (SpringForce - DampingForce) * StepTime;
			TabVisualX += TabVisualVelocity * StepTime;
			RemainingTime -= StepTime;
		}

		if (FMath::Abs(TargetX - TabVisualX) < 0.05f && FMath::Abs(TabVisualVelocity) < 0.05f)
		{
			TabVisualX = TargetX;
			TabVisualVelocity = 0.0f;
		}

		if (TabHighlightCanvas.IsValid())
		{
			TabHighlightCanvas->Invalidate(EInvalidateWidgetReason::LayoutAndVolatility);
		}
	}

private:
	static constexpr int32 TabCount = 21;
	static constexpr float TabWidth = 58.0f;
	static constexpr float TabHeight = 68.0f;
	static constexpr float TabBarPadding = 12.0f;
	static constexpr float TabBarWidth = TabBarPadding * 2.0f + TabWidth * TabCount;
	static constexpr float TabBarHeight = 86.0f;
	static constexpr float TabHighlightWidth = 54.0f;
	static constexpr float TabHighlightHeight = 60.0f;
	static constexpr float PreviewWidth = 760.0f;
	static constexpr float PreviewHeight = 500.0f;

	ECBLGShowcaseTab ActiveTab = ECBLGShowcaseTab::Glass;
	FCBLGShowcaseValues Values;

	float TabVisualX = 0.0f;
	float TabVisualVelocity = 0.0f;

	FVector2D GlassPos = FVector2D(210.0f, 150.0f);
	FVector2D ButtonPos = FVector2D(210.0f, 180.0f);
	FVector2D SliderPos = FVector2D(64.0f, 202.0f);
	FVector2D TextPos = FVector2D(54.0f, 105.0f);
	FVector2D MaskPosA = FVector2D(76.0f, 128.0f);
	FVector2D MaskPosB = FVector2D(300.0f, 128.0f);
	FVector2D MaskPosC = FVector2D(524.0f, 128.0f);
	FVector2D ToolbarPos = FVector2D(205.0f, 210.0f);
	FVector2D MenuPos = FVector2D(220.0f, 92.0f);
	FVector2D FusionPosA = FVector2D(150.0f, 150.0f);
	FVector2D FusionPosB = FVector2D(330.0f, 150.0f);
	FVector2D FusionPosC = FVector2D(500.0f, 270.0f);
	FVector2D MotionPosA = FVector2D(95.0f, 150.0f);
	FVector2D MotionPosB = FVector2D(520.0f, 160.0f);
	FVector2D PerformancePosA = FVector2D(50.0f, 170.0f);
	FVector2D PerformancePosB = FVector2D(270.0f, 170.0f);
	FVector2D PerformancePosC = FVector2D(490.0f, 170.0f);
	FVector2D ContainerPos = FVector2D(150.0f, 150.0f);
	FVector2D PageControlPos = FVector2D(255.0f, 220.0f);
	FVector2D DialogPos = FVector2D(210.0f, 82.0f);
	FVector2D NavBarPos = FVector2D(130.0f, 190.0f);
	FVector2D BadgePos = FVector2D(185.0f, 190.0f);

	TSharedPtr<SBox> ParameterHost;
	TSharedPtr<SBox> PreviewHost;
	TSharedPtr<SCanvas> PreviewCanvas;
	TSharedPtr<SCanvas> TabHighlightCanvas;
	TSharedPtr<FSlateDynamicImageBrush> BackgroundBrush;
	TSharedPtr<FSlateVectorImageBrush> GlassIconBrush;
	TSharedPtr<FSlateVectorImageBrush> ButtonIconBrush;
	TSharedPtr<FSlateVectorImageBrush> ToggleIconBrush;
	TSharedPtr<FSlateVectorImageBrush> SliderIconBrush;
	TSharedPtr<FSlateVectorImageBrush> TextIconBrush;
	TSharedPtr<FSlateVectorImageBrush> MaskIconBrush;
	TSharedPtr<FSlateVectorImageBrush> FusionIconBrush;
	TSharedPtr<FSlateVectorImageBrush> MotionIconBrush;
	TSharedPtr<FSlateVectorImageBrush> PerformanceIconBrush;
	TSharedPtr<FSlateVectorImageBrush> SegmentedIconBrush;
	TSharedPtr<FSlateVectorImageBrush> TabBarIconBrush;
	TSharedPtr<FSlateVectorImageBrush> ToolbarIconBrush;
	TSharedPtr<FSlateVectorImageBrush> MenuIconBrush;
	TSharedPtr<FSlateVectorImageBrush> SearchBarIconBrush;
	TSharedPtr<FSlateVectorImageBrush> ProgressIconBrush;
	TSharedPtr<FSlateVectorImageBrush> StepperIconBrush;
	TSharedPtr<FSlateVectorImageBrush> CloseBrush;
	TStrongObjectPtr<UTexture2D> StarMaskTexture;
	TStrongObjectPtr<UTexture2D> DropletMaskTexture;
	TStrongObjectPtr<UTexture2D> SearchMaskTexture;

	FVector2D GetGlassPos() const { return GlassPos; }
	FVector2D GetButtonPos() const { return ButtonPos; }
	FVector2D GetSliderPos() const { return SliderPos; }
	FVector2D GetTextPos() const { return TextPos; }
	FVector2D GetMaskPosA() const { return MaskPosA; }
	FVector2D GetMaskPosB() const { return MaskPosB; }
	FVector2D GetMaskPosC() const { return MaskPosC; }
	FVector2D GetToolbarPos() const { return ToolbarPos; }
	FVector2D GetMenuPos() const { return MenuPos; }
	FVector2D GetFusionPosA() const { return FusionPosA; }
	FVector2D GetFusionPosB() const { return FusionPosB; }
	FVector2D GetFusionPosC() const { return FusionPosC; }
	FVector2D GetMotionPosA() const { return MotionPosA; }
	FVector2D GetMotionPosB() const { return MotionPosB; }
	FVector2D GetPerformancePosA() const { return PerformancePosA; }
	FVector2D GetPerformancePosB() const { return PerformancePosB; }
	FVector2D GetPerformancePosC() const { return PerformancePosC; }
	FVector2D GetContainerPos() const { return ContainerPos; }
	FVector2D GetPageControlPos() const { return PageControlPos; }
	FVector2D GetDialogPos() const { return DialogPos; }
	FVector2D GetNavBarPos() const { return NavBarPos; }
	FVector2D GetBadgePos() const { return BadgePos; }

	static int32 GetTabIndex(ECBLGShowcaseTab Tab)
	{
		return static_cast<int32>(Tab);
	}

	float GetTabTargetX() const
	{
		return TabBarPadding + GetTabIndex(ActiveTab) * TabWidth + (TabWidth - TabHighlightWidth) * 0.5f;
	}

	FVector2D GetTabHighlightPosition() const
	{
		const float Stretch = GetTabHighlightStretch();
		const float Direction = TabVisualVelocity >= 0.0f ? 1.0f : -1.0f;
		const float LeadOffset = FMath::Clamp(TabVisualVelocity * 0.012f, -8.0f, 8.0f);
		const float TrailCompensation = Direction * Stretch * 0.34f;
		return FVector2D(TabVisualX + LeadOffset - TrailCompensation, (TabBarHeight - TabHighlightHeight) * 0.5f);
	}

	FVector2D GetTabHighlightSize() const
	{
		return FVector2D(TabHighlightWidth + GetTabHighlightStretch(), TabHighlightHeight);
	}

	float GetTabHighlightStretch() const
	{
		return FMath::Clamp(FMath::Abs(TabVisualVelocity) * 0.014f, 0.0f, 26.0f);
	}

	TSharedRef<SWidget> BuildBackground()
	{
		return SNew(SOverlay)
			+ SOverlay::Slot()
			[
				SNew(SImage).Image(BackgroundBrush.Get())
			]
			+ SOverlay::Slot()
			[
				SNew(SColorBlock).Color(FLinearColor(0.0f, 0.0f, 0.0f, 0.20f))
			];
	}

	TSharedRef<SWidget> BuildMainArea()
	{
		return SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().AutoWidth().Padding(0.0f, 0.0f, 22.0f, 0.0f)
			[
				SAssignNew(ParameterHost, SBox)
				.WidthOverride(360.0f)
			]
			+ SHorizontalBox::Slot().FillWidth(1.0f).HAlign(HAlign_Center).VAlign(VAlign_Center)
			[
				SAssignNew(PreviewHost, SBox)
				.WidthOverride(PreviewWidth)
				.HeightOverride(PreviewHeight)
			];
	}

	void RefreshParameterPanel()
	{
		if (ParameterHost.IsValid())
		{
			ParameterHost->SetContent(BuildParameterPanel());
		}
	}

	void RefreshPreview()
	{
		if (PreviewHost.IsValid())
		{
			PreviewHost->SetContent(BuildPreviewPanel());
		}
	}

	void SelectTab(ECBLGShowcaseTab Tab)
	{
		if (ActiveTab == Tab)
		{
			return;
		}

		ActiveTab = Tab;
		RefreshParameterPanel();
		RefreshPreview();
	}

	TSharedRef<SWidget> BuildTabBar()
	{
		return SNew(SBox)
			.WidthOverride(TabBarWidth)
			.HeightOverride(TabBarHeight)
			[
				SNew(SOverlay)
				+ SOverlay::Slot()
				[
					SNew(SCBLiquidGlass)
					.Shape(ECBLiquidGlassShape::Capsule)
					.BlurStrength(0.82f)
					.FrostRadius(0.22f)
					.RefractionStrength(0.54f)
					.RefractionThickness(24.0f)
					.IndexOfRefraction(1.48f)
					.PrismIntensity(0.2f)
					.TintOpacity(0.08f)
					.RimIntensity(0.2f)
					.InnerShadowIntensity(0.16f)
					.GlassOpacity(0.88f)
					[ SNew(SBox) ]
				]
				+ SOverlay::Slot()
				[
					SAssignNew(TabHighlightCanvas, SCanvas)
					+ SCanvas::Slot()
					.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetTabHighlightPosition))
					.Size(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetTabHighlightSize))
					[
						SNew(SCBLiquidGlass)
						.Shape(ECBLiquidGlassShape::Capsule)
						.BlurStrength(0.24f)
						.FrostRadius(0.035f)
						.RefractionStrength(0.78f)
						.RefractionThickness(42.0f)
						.IndexOfRefraction(1.78f)
						.ChromaticAberration(0.01f)
						.PrismIntensity(0.16f)
						.TintOpacity(0.01f)
						.RimIntensity(0.58f)
						.GlowAmount(0.64f)
						.InnerGlowIntensity(0.16f)
						.InnerShadowIntensity(0.1f)
						.GlassOpacity(1.0f)
						.EdgeSoftness(0.42f)
						.MotionStrength(0.72f)
						.MotionMaxOffset(48.0f)
						.MotionResponse(24.0f)
						.MotionDamping(8.0f)
						[ SNew(SBox) ]
					]
				]
				+ SOverlay::Slot()
				.Padding(TabBarPadding, 8.0f)
				[
					BuildTabButtons()
				]
			];
	}

	TSharedRef<SWidget> BuildTabButtons()
	{
		return SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().AutoWidth()[ BuildTabButton(ECBLGShowcaseTab::Glass) ]
			+ SHorizontalBox::Slot().AutoWidth()[ BuildTabButton(ECBLGShowcaseTab::Button) ]
			+ SHorizontalBox::Slot().AutoWidth()[ BuildTabButton(ECBLGShowcaseTab::Toggle) ]
			+ SHorizontalBox::Slot().AutoWidth()[ BuildTabButton(ECBLGShowcaseTab::Slider) ]
			+ SHorizontalBox::Slot().AutoWidth()[ BuildTabButton(ECBLGShowcaseTab::Text) ]
			+ SHorizontalBox::Slot().AutoWidth()[ BuildTabButton(ECBLGShowcaseTab::Mask) ]
			+ SHorizontalBox::Slot().AutoWidth()[ BuildTabButton(ECBLGShowcaseTab::Fusion) ]
			+ SHorizontalBox::Slot().AutoWidth()[ BuildTabButton(ECBLGShowcaseTab::Motion) ]
			+ SHorizontalBox::Slot().AutoWidth()[ BuildTabButton(ECBLGShowcaseTab::Performance) ]
			+ SHorizontalBox::Slot().AutoWidth()[ BuildTabButton(ECBLGShowcaseTab::Segmented) ]
			+ SHorizontalBox::Slot().AutoWidth()[ BuildTabButton(ECBLGShowcaseTab::TabBar) ]
			+ SHorizontalBox::Slot().AutoWidth()[ BuildTabButton(ECBLGShowcaseTab::Toolbar) ]
			+ SHorizontalBox::Slot().AutoWidth()[ BuildTabButton(ECBLGShowcaseTab::Menu) ]
			+ SHorizontalBox::Slot().AutoWidth()[ BuildTabButton(ECBLGShowcaseTab::SearchBar) ]
			+ SHorizontalBox::Slot().AutoWidth()[ BuildTabButton(ECBLGShowcaseTab::Progress) ]
			+ SHorizontalBox::Slot().AutoWidth()[ BuildTabButton(ECBLGShowcaseTab::Stepper) ]
			+ SHorizontalBox::Slot().AutoWidth()[ BuildTabButton(ECBLGShowcaseTab::Container) ]
			+ SHorizontalBox::Slot().AutoWidth()[ BuildTabButton(ECBLGShowcaseTab::PageControl) ]
			+ SHorizontalBox::Slot().AutoWidth()[ BuildTabButton(ECBLGShowcaseTab::Dialog) ]
			+ SHorizontalBox::Slot().AutoWidth()[ BuildTabButton(ECBLGShowcaseTab::NavBar) ]
			+ SHorizontalBox::Slot().AutoWidth()[ BuildTabButton(ECBLGShowcaseTab::Badge) ];
	}

	TSharedRef<SWidget> BuildTabButton(ECBLGShowcaseTab Tab)
	{
		return SNew(SButton)
			.ButtonStyle(FCoreStyle::Get(), "NoBorder")
			.ContentPadding(0.0f)
			.OnClicked_Lambda([this, Tab]()
			{
				SelectTab(Tab);
				return FReply::Handled();
			})
			[
				SNew(SBox)
				.WidthOverride(TabWidth)
				.HeightOverride(TabHeight)
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot().AutoHeight().HAlign(HAlign_Center)
					[
						SNew(SImage)
						.Image(GetTabIcon(Tab))
						.ColorAndOpacity_Lambda([this, Tab]()
						{
							return GetTabTint(Tab);
						})
					]
					+ SVerticalBox::Slot().AutoHeight().HAlign(HAlign_Center).Padding(0.0f, 5.0f, 0.0f, 0.0f)
					[
						SNew(STextBlock)
						.Text(GetTabLabel(Tab))
						.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
						.ColorAndOpacity_Lambda([this, Tab]()
						{
							return GetTabTint(Tab);
						})
					]
				]
			];
	}

	const FSlateBrush* GetTabIcon(ECBLGShowcaseTab Tab) const
	{
		switch (Tab)
		{
		case ECBLGShowcaseTab::Glass: return GlassIconBrush.Get();
		case ECBLGShowcaseTab::Button: return ButtonIconBrush.Get();
		case ECBLGShowcaseTab::Toggle: return ToggleIconBrush.Get();
		case ECBLGShowcaseTab::Slider: return SliderIconBrush.Get();
		case ECBLGShowcaseTab::Text: return TextIconBrush.Get();
		case ECBLGShowcaseTab::Mask: return MaskIconBrush.Get();
		case ECBLGShowcaseTab::Fusion: return FusionIconBrush.Get();
		case ECBLGShowcaseTab::Motion: return MotionIconBrush.Get();
		case ECBLGShowcaseTab::Performance: return PerformanceIconBrush.Get();
		case ECBLGShowcaseTab::Segmented: return SegmentedIconBrush.Get();
		case ECBLGShowcaseTab::TabBar: return TabBarIconBrush.Get();
		case ECBLGShowcaseTab::Toolbar: return ToolbarIconBrush.Get();
		case ECBLGShowcaseTab::Menu: return MenuIconBrush.Get();
		case ECBLGShowcaseTab::SearchBar: return SearchBarIconBrush.Get();
		case ECBLGShowcaseTab::Progress: return ProgressIconBrush.Get();
		case ECBLGShowcaseTab::Container: return FusionIconBrush.Get();
		case ECBLGShowcaseTab::PageControl: return ProgressIconBrush.Get();
		case ECBLGShowcaseTab::Dialog: return MenuIconBrush.Get();
		case ECBLGShowcaseTab::NavBar: return TabBarIconBrush.Get();
		case ECBLGShowcaseTab::Badge: return ButtonIconBrush.Get();
		case ECBLGShowcaseTab::Stepper:
		default: return StepperIconBrush.Get();
		}
	}

	FText GetTabLabel(ECBLGShowcaseTab Tab) const
	{
		switch (Tab)
		{
		case ECBLGShowcaseTab::Glass: return LOCTEXT("ShowcaseTabGlass", "Glass");
		case ECBLGShowcaseTab::Button: return LOCTEXT("ShowcaseTabButton", "Button");
		case ECBLGShowcaseTab::Toggle: return LOCTEXT("ShowcaseTabToggle", "Toggle");
		case ECBLGShowcaseTab::Slider: return LOCTEXT("ShowcaseTabSlider", "Slider");
		case ECBLGShowcaseTab::Text: return LOCTEXT("ShowcaseTabText", "Text");
		case ECBLGShowcaseTab::Mask: return LOCTEXT("ShowcaseTabMask", "Mask");
		case ECBLGShowcaseTab::Fusion: return LOCTEXT("ShowcaseTabFusion", "Fusion");
		case ECBLGShowcaseTab::Motion: return LOCTEXT("ShowcaseTabMotion", "Motion");
		case ECBLGShowcaseTab::Performance: return LOCTEXT("ShowcaseTabPerf", "Perf");
		case ECBLGShowcaseTab::Segmented: return LOCTEXT("ShowcaseTabSegmented", "Segment");
		case ECBLGShowcaseTab::TabBar: return LOCTEXT("ShowcaseTabTabBar", "TabBar");
		case ECBLGShowcaseTab::Toolbar: return LOCTEXT("ShowcaseTabToolbar", "Toolbar");
		case ECBLGShowcaseTab::Menu: return LOCTEXT("ShowcaseTabMenu", "Menu");
		case ECBLGShowcaseTab::SearchBar: return LOCTEXT("ShowcaseTabSearch", "Search");
		case ECBLGShowcaseTab::Progress: return LOCTEXT("ShowcaseTabProgress", "Progress");
		case ECBLGShowcaseTab::Container: return LOCTEXT("ShowcaseTabContainer", "Contain");
		case ECBLGShowcaseTab::PageControl: return LOCTEXT("ShowcaseTabPageControl", "Page");
		case ECBLGShowcaseTab::Dialog: return LOCTEXT("ShowcaseTabDialog", "Dialog");
		case ECBLGShowcaseTab::NavBar: return LOCTEXT("ShowcaseTabNavBar", "Nav");
		case ECBLGShowcaseTab::Badge: return LOCTEXT("ShowcaseTabBadge", "Badge");
		case ECBLGShowcaseTab::Stepper:
		default: return LOCTEXT("ShowcaseTabStepper", "Stepper");
		}
	}

	FSlateColor GetTabTint(ECBLGShowcaseTab Tab) const
	{
		return ActiveTab == Tab
			? FSlateColor(FLinearColor(0.32f, 0.78f, 1.0f, 1.0f))
			: FSlateColor(FLinearColor(1.0f, 1.0f, 1.0f, 0.88f));
	}

	TSharedRef<SWidget> BuildParameterPanel()
	{
		return SNew(SCBLiquidGlass)
			.Shape(ECBLiquidGlassShape::SuperellipseRect)
			.SquirclePower(13.0f)
			.BlurStrength(0.28f)
			.FrostRadius(0.08f)
			.RefractionStrength(0.1f)
			.RefractionThickness(8.0f)
			.IndexOfRefraction(1.12f)
			.PrismIntensity(0.025f)
			.TintOpacity(0.03f)
			.RimIntensity(0.12f)
			.InnerShadowIntensity(0.06f)
			.GlassOpacity(0.68f)
			.EdgeSoftness(0.34f)
			[
				SNew(SBox)
				.WidthOverride(360.0f)
				.HeightOverride(PreviewHeight)
				.Padding(18.0f)
				[
					SNew(SScrollBox)
					+ SScrollBox::Slot()
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot().AutoHeight().Padding(0.0f, 0.0f, 0.0f, 12.0f)
						[
							SNew(STextBlock)
							.Text(GetTabTitle())
							.Font(FCoreStyle::GetDefaultFontStyle("Bold", 22))
							.ColorAndOpacity(FLinearColor::White)
						]
						+ SVerticalBox::Slot().AutoHeight()
						[
							BuildTabParameters()
						]
					]
				]
			];
	}

	FText GetTabTitle() const
	{
		switch (ActiveTab)
		{
		case ECBLGShowcaseTab::Glass: return LOCTEXT("ShowcaseGlassTitle", "Glass Parameters");
		case ECBLGShowcaseTab::Button: return LOCTEXT("ShowcaseButtonTitle", "Button Parameters");
		case ECBLGShowcaseTab::Toggle: return LOCTEXT("ShowcaseToggleTitle", "Toggle Parameters");
		case ECBLGShowcaseTab::Slider: return LOCTEXT("ShowcaseSliderTitle", "Slider Parameters");
		case ECBLGShowcaseTab::Text: return LOCTEXT("ShowcaseTextTitle", "Text Parameters");
		case ECBLGShowcaseTab::Mask: return LOCTEXT("ShowcaseMaskTitle", "Mask Parameters");
		case ECBLGShowcaseTab::Fusion: return LOCTEXT("ShowcaseFusionTitle", "Fusion Parameters");
		case ECBLGShowcaseTab::Motion: return LOCTEXT("ShowcaseMotionTitle", "Motion Parameters");
		case ECBLGShowcaseTab::Performance: return LOCTEXT("ShowcasePerformanceTitle", "Performance Parameters");
		case ECBLGShowcaseTab::Segmented: return LOCTEXT("ShowcaseSegmentedTitle", "Segmented Parameters");
		case ECBLGShowcaseTab::TabBar: return LOCTEXT("ShowcaseTabBarTitle", "Tab Bar Parameters");
		case ECBLGShowcaseTab::Toolbar: return LOCTEXT("ShowcaseToolbarTitle", "Toolbar Parameters");
		case ECBLGShowcaseTab::Menu: return LOCTEXT("ShowcaseMenuTitle", "Menu Parameters");
		case ECBLGShowcaseTab::SearchBar: return LOCTEXT("ShowcaseSearchTitle", "Search Parameters");
		case ECBLGShowcaseTab::Progress: return LOCTEXT("ShowcaseProgressTitle", "Progress Parameters");
		case ECBLGShowcaseTab::Container: return LOCTEXT("ShowcaseContainerTitle", "Container Parameters");
		case ECBLGShowcaseTab::PageControl: return LOCTEXT("ShowcasePageControlTitle", "Page Control Parameters");
		case ECBLGShowcaseTab::Dialog: return LOCTEXT("ShowcaseDialogTitle", "Dialog Parameters");
		case ECBLGShowcaseTab::NavBar: return LOCTEXT("ShowcaseNavBarTitle", "Navigation Bar Parameters");
		case ECBLGShowcaseTab::Badge: return LOCTEXT("ShowcaseBadgeTitle", "Badge Parameters");
		case ECBLGShowcaseTab::Stepper:
		default: return LOCTEXT("ShowcaseStepperTitle", "Stepper Parameters");
		}
	}

	TSharedRef<SWidget> BuildTabParameters()
	{
		switch (ActiveTab)
		{
		case ECBLGShowcaseTab::Glass:
			return SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight()[ BuildPresetChoices() ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildShapeChoices() ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildQualityChoices() ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseGlassBlur", "Blur"), [this]() { return Values.Glass.BlurStrength; }, [this](float V) { Values.Glass.BlurStrength = V; }, 0.0f, 2.0f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseGlassFrost", "Frost"), [this]() { return Values.Glass.FrostRadius; }, [this](float V) { Values.Glass.FrostRadius = V; }, 0.0f, 0.7f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseGlassRefraction", "Refraction"), [this]() { return Values.Glass.RefractionStrength; }, [this](float V) { Values.Glass.RefractionStrength = V; }, 0.0f, 1.5f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseGlassPrism", "Prism"), [this]() { return Values.Glass.PrismIntensity; }, [this](float V) { Values.Glass.PrismIntensity = V; }, 0.0f, 1.2f) ];
		case ECBLGShowcaseTab::Button:
			return SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight()[ BuildPresetChoices() ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseButtonHover", "Hover Glow"), [this]() { return Values.ButtonHoverGlowBoost; }, [this](float V) { Values.ButtonHoverGlowBoost = V; }, 0.0f, 0.6f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseButtonPress", "Press Refraction"), [this]() { return Values.ButtonPressedRefractionBoost; }, [this](float V) { Values.ButtonPressedRefractionBoost = V; }, 0.0f, 0.5f) ];
		case ECBLGShowcaseTab::Toggle:
			return SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight()[ BuildQualityChoices() ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildChoiceButton(LOCTEXT("ShowcaseToggleState", "Toggle"), ToggleIconBrush.Get(), [this]() { return Values.bToggleChecked; }, [this]() { Values.bToggleChecked = !Values.bToggleChecked; RefreshPreview(); }) ];
		case ECBLGShowcaseTab::Slider:
			return SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight()[ BuildQualityChoices() ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseSliderValue", "Value"), [this]() { return Values.SliderValue; }, [this](float V) { Values.SliderValue = V; }, 0.0f, 1.0f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseSliderJelly", "Jelly"), [this]() { return Values.SliderThumbBounce; }, [this](float V) { Values.SliderThumbBounce = V; }, 0.0f, 1.4f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseSliderResponse", "Response"), [this]() { return Values.SliderThumbResponse; }, [this](float V) { Values.SliderThumbResponse = V; }, 8.0f, 38.0f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseSliderDamping", "Damping"), [this]() { return Values.SliderThumbDamping; }, [this](float V) { Values.SliderThumbDamping = V; }, 4.0f, 14.0f) ];
		case ECBLGShowcaseTab::Text:
			return SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight()[ BuildQualityChoices() ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseTextFontSize", "Font Size"), [this]() { return Values.TextFontSize; }, [this](float V) { Values.TextFontSize = V; }, 56.0f, 160.0f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseTextStroke", "Tube Width"), [this]() { return Values.TextGlyphThickness; }, [this](float V) { Values.TextGlyphThickness = V; }, 2.0f, 16.0f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseTextFrost", "Frost"), [this]() { return Values.TextFrostRadius; }, [this](float V) { Values.TextFrostRadius = V; }, 0.0f, 0.2f) ];
		case ECBLGShowcaseTab::Mask:
			return SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight()[ BuildQualityChoices() ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseMaskThreshold", "Threshold"), [this]() { return Values.MaskThreshold; }, [this](float V) { Values.MaskThreshold = V; }, 0.0f, 0.18f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseMaskSoftness", "Softness"), [this]() { return Values.MaskSoftness; }, [this](float V) { Values.MaskSoftness = V; }, 0.0f, 0.08f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseMaskPrism", "Prism"), [this]() { return Values.Glass.PrismIntensity; }, [this](float V) { Values.Glass.PrismIntensity = V; }, 0.0f, 1.2f) ];
		case ECBLGShowcaseTab::Fusion:
			return SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight()[ BuildQualityChoices() ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseFusionRim", "Rim"), [this]() { return Values.FusionRimIntensity; }, [this](float V) { Values.FusionRimIntensity = V; }, 0.0f, 0.8f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseFusionPrism", "Prism"), [this]() { return Values.FusionPrismIntensity; }, [this](float V) { Values.FusionPrismIntensity = V; }, 0.0f, 0.8f) ];
		case ECBLGShowcaseTab::Motion:
			return SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight()[ BuildQualityChoices() ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseMotionDeform", "Deform"), [this]() { return Values.Glass.MotionStrength; }, [this](float V) { Values.Glass.MotionStrength = V; }, 0.0f, 1.2f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseMotionOffset", "Max Offset"), [this]() { return Values.Glass.MotionMaxOffset; }, [this](float V) { Values.Glass.MotionMaxOffset = V; }, 0.0f, 120.0f) ];
		case ECBLGShowcaseTab::Performance:
			return SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight()[ BuildQualityChoices() ];
		case ECBLGShowcaseTab::Segmented:
			return SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight()[ BuildQualityChoices() ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseSegmentedIndex", "Selected"), [this]() { return static_cast<float>(Values.SegmentedIndex); }, [this](float V) { Values.SegmentedIndex = FMath::RoundToInt(V); }, 0.0f, 2.0f) ];
		case ECBLGShowcaseTab::TabBar:
			return SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight()[ BuildQualityChoices() ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseTabBarIndex", "Selected"), [this]() { return static_cast<float>(Values.TabBarIndex); }, [this](float V) { Values.TabBarIndex = FMath::RoundToInt(V); }, 0.0f, 3.0f) ];
		case ECBLGShowcaseTab::Toolbar:
			return SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight()[ BuildQualityChoices() ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseToolbarIndex", "Selected"), [this]() { return static_cast<float>(Values.ToolbarIndex); }, [this](float V) { Values.ToolbarIndex = FMath::RoundToInt(V); }, 0.0f, 3.0f) ];
		case ECBLGShowcaseTab::Menu:
			return SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight()[ BuildQualityChoices() ];
		case ECBLGShowcaseTab::SearchBar:
			return SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight()[ BuildQualityChoices() ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildEnumRow(LOCTEXT("ShowcaseSearchVisibility", "Visibility"),
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot().AutoWidth().Padding(0, 0, 6, 0)[ BuildChoiceButton(LOCTEXT("ShowcaseSearchIconToggle", "Icon"), SearchBarIconBrush.Get(), [this]() { return Values.bSearchShowIcon; }, [this]() { Values.bSearchShowIcon = !Values.bSearchShowIcon; RefreshPreview(); }) ]
					+ SHorizontalBox::Slot().AutoWidth().Padding(0, 0, 6, 0)[ BuildChoiceButton(LOCTEXT("ShowcaseSearchTextToggle", "Text"), TextIconBrush.Get(), [this]() { return Values.bSearchShowLabel; }, [this]() { Values.bSearchShowLabel = !Values.bSearchShowLabel; RefreshPreview(); }) ]
					+ SHorizontalBox::Slot().AutoWidth()[ BuildChoiceButton(LOCTEXT("ShowcaseSearchClearToggle", "Clear"), CloseBrush.Get(), [this]() { return Values.bSearchShowClearButton; }, [this]() { Values.bSearchShowClearButton = !Values.bSearchShowClearButton; RefreshPreview(); }) ]) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseSearchOuterFrost", "Outer Frost"), [this]() { return Values.SearchBoxStyle.OuterFrostRadius; }, [this](float V) { Values.SearchBoxStyle.OuterFrostRadius = V; }, 0.0f, 1.0f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseSearchInnerFrost", "Inner Frost"), [this]() { return Values.SearchBoxStyle.InnerFrostRadius; }, [this](float V) { Values.SearchBoxStyle.InnerFrostRadius = V; }, 0.0f, 1.0f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseSearchOuterTint", "Outer Tint"), [this]() { return Values.SearchBoxStyle.OuterTintOpacity; }, [this](float V) { Values.SearchBoxStyle.OuterTintOpacity = V; }, 0.0f, 0.8f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseSearchInnerTint", "Inner Tint"), [this]() { return Values.SearchBoxStyle.InnerTintOpacity; }, [this](float V) { Values.SearchBoxStyle.InnerTintOpacity = V; }, 0.0f, 0.8f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseSearchTextLayerHeight", "Text Layer"), [this]() { return Values.SearchBoxStyle.TextLayerHeight; }, [this](float V) { Values.SearchBoxStyle.TextLayerHeight = V; }, 28.0f, 76.0f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseSearchIconSize", "Icon Size"), [this]() { return Values.SearchBoxStyle.IconSize; }, [this](float V) { Values.SearchBoxStyle.IconSize = V; }, 14.0f, 48.0f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseSearchClearSize", "Clear Size"), [this]() { return Values.SearchBoxStyle.ClearButtonSize; }, [this](float V) { Values.SearchBoxStyle.ClearButtonSize = V; }, 22.0f, 60.0f) ];
		case ECBLGShowcaseTab::Progress:
			return SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight()[ BuildQualityChoices() ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildChoiceButton(LOCTEXT("ShowcaseProgressPercent", "Percent"), ProgressIconBrush.Get(), [this]() { return Values.bProgressShowPercent; }, [this]() { Values.bProgressShowPercent = !Values.bProgressShowPercent; RefreshPreview(); }) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseProgressValue", "Value"), [this]() { return Values.ProgressValue; }, [this](float V) { Values.ProgressValue = V; }, 0.0f, 1.0f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseProgressThickness", "Thickness"), [this]() { return Values.ProgressThickness; }, [this](float V) { Values.ProgressThickness = V; }, 4.0f, 22.0f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseProgressFrost", "Frost"), [this]() { return Values.ProgressFrostRadius; }, [this](float V) { Values.ProgressFrostRadius = V; }, 0.0f, 0.6f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseProgressRefraction", "Refraction"), [this]() { return Values.ProgressRefractionStrength; }, [this](float V) { Values.ProgressRefractionStrength = V; }, 0.0f, 1.1f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseProgressPrism", "Prism"), [this]() { return Values.ProgressPrismIntensity; }, [this](float V) { Values.ProgressPrismIntensity = V; }, 0.0f, 0.8f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseProgressTrackOpacity", "Track Opacity"), [this]() { return Values.ProgressTrackOpacity; }, [this](float V) { Values.ProgressTrackOpacity = V; }, 0.0f, 1.0f) ];
		case ECBLGShowcaseTab::Container:
			return SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight()[ BuildQualityChoices() ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseContainerSmoothing", "Smoothing"), [this]() { return Values.ContainerSmoothing; }, [this](float V) { Values.ContainerSmoothing = V; }, 0.0f, 110.0f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseContainerFrost", "Frost"), [this]() { return Values.ContainerFrostRadius; }, [this](float V) { Values.ContainerFrostRadius = V; }, 0.0f, 0.7f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseContainerRefraction", "Refraction"), [this]() { return Values.ContainerRefractionStrength; }, [this](float V) { Values.ContainerRefractionStrength = V; }, 0.0f, 1.6f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseContainerPrism", "Prism"), [this]() { return Values.ContainerPrismIntensity; }, [this](float V) { Values.ContainerPrismIntensity = V; }, 0.0f, 1.2f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseContainerRim", "Rim"), [this]() { return Values.ContainerRimIntensity; }, [this](float V) { Values.ContainerRimIntensity = V; }, 0.0f, 1.2f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseContainerOpacity", "Opacity"), [this]() { return Values.ContainerOpacity; }, [this](float V) { Values.ContainerOpacity = V; }, 0.1f, 1.0f) ];
		case ECBLGShowcaseTab::PageControl:
			return SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcasePageIndex", "Page"), [this]() { return Values.PageIndex; }, [this](float V) { Values.PageIndex = FMath::RoundToFloat(V); }, 0.0f, 5.0f) ];
		case ECBLGShowcaseTab::Dialog:
			return SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight()[ BuildQualityChoices() ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildChoiceButton(LOCTEXT("ShowcaseDialogDim", "Dim"), MenuIconBrush.Get(), [this]() { return Values.bDialogDimBackground; }, [this]() { Values.bDialogDimBackground = !Values.bDialogDimBackground; RefreshPreview(); }) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseDialogDimOpacity", "Dim Opacity"), [this]() { return Values.DialogDimOpacity; }, [this](float V) { Values.DialogDimOpacity = V; }, 0.0f, 0.7f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseDialogBlur", "Blur"), [this]() { return Values.DialogBlurStrength; }, [this](float V) { Values.DialogBlurStrength = V; }, 0.0f, 2.4f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseDialogFrost", "Frost"), [this]() { return Values.DialogFrostRadius; }, [this](float V) { Values.DialogFrostRadius = V; }, 0.0f, 0.9f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseDialogRefraction", "Refraction"), [this]() { return Values.DialogRefractionStrength; }, [this](float V) { Values.DialogRefractionStrength = V; }, 0.0f, 1.4f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseDialogPrism", "Prism"), [this]() { return Values.DialogPrismIntensity; }, [this](float V) { Values.DialogPrismIntensity = V; }, 0.0f, 1.0f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseDialogOpacity", "Opacity"), [this]() { return Values.DialogOpacity; }, [this](float V) { Values.DialogOpacity = V; }, 0.1f, 1.0f) ];
		case ECBLGShowcaseTab::NavBar:
			return SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight()[ BuildQualityChoices() ];
		case ECBLGShowcaseTab::Badge:
			return SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight()[ BuildQualityChoices() ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseBadgeCount", "Count"), [this]() { return Values.BadgeCount; }, [this](float V) { Values.BadgeCount = FMath::RoundToFloat(V); }, 0.0f, 140.0f) ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildChoiceButton(LOCTEXT("ShowcaseBadgeDot", "Dot"), ButtonIconBrush.Get(), [this]() { return Values.bBadgeDotMode; }, [this]() { Values.bBadgeDotMode = !Values.bBadgeDotMode; RefreshPreview(); }) ];
		case ECBLGShowcaseTab::Stepper:
		default:
			return SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight()[ BuildQualityChoices() ]
				+ SVerticalBox::Slot().AutoHeight()[ BuildParamSlider(LOCTEXT("ShowcaseStepperValue", "Value"), [this]() { return Values.StepperValue; }, [this](float V) { Values.StepperValue = V; }, 0.0f, 10.0f) ];
		}
	}

	TSharedRef<SWidget> BuildParamSlider(FText Label, TFunction<float()> Getter, TFunction<void(float)> Setter, float MinValue, float MaxValue)
	{
		return SNew(SVerticalBox)
			+ SVerticalBox::Slot().AutoHeight()
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot().FillWidth(1.0f)
				[
					SNew(STextBlock)
					.Text(Label)
					.Font(FCoreStyle::GetDefaultFontStyle("Regular", 13))
					.ColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.86f))
				]
				+ SHorizontalBox::Slot().AutoWidth()
				[
					SNew(STextBlock)
					.Text_Lambda([Getter]()
					{
						return FText::AsNumber(Getter());
					})
					.Font(FCoreStyle::GetDefaultFontStyle("Regular", 12))
					.ColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.64f))
				]
			]
			+ SVerticalBox::Slot().AutoHeight().Padding(0.0f, 3.0f, 0.0f, 12.0f)
			[
				SNew(SCBLiquidGlassSlider)
				.Value(Getter())
				.MinValue(MinValue)
				.MaxValue(MaxValue)
				.SliderLength(286.0f)
				.SliderHeight(50.0f)
				.TrackHeight(5.0f)
				.ThumbSize(FVector2D(82.0f, 34.0f))
				.TrackOpacity(0.34f)
				.FillColor(FLinearColor(0.0f, 0.52f, 1.0f, 1.0f))
				.ThumbPreset(ECBLiquidGlassPreset::PillLens)
				.Quality(ECBLiquidGlassQuality::Balanced)
				.ThumbBounce(0.5f)
				.ThumbResponse(25.0f)
				.ThumbDamping(9.2f)
				.ThumbMotionStrength(0.82f)
				.OnValueChanged(FCBLiquidGlassSliderValueChanged::CreateLambda([this, Setter](float InValue)
				{
					Setter(InValue);
					RefreshPreview();
				}))
			];
	}

	TSharedRef<SWidget> BuildPresetChoices()
	{
		return BuildEnumRow(LOCTEXT("ShowcasePresetLabel", "Preset"),
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().AutoWidth().Padding(0, 0, 6, 0)[ BuildChoiceButton(LOCTEXT("ShowcasePresetRegular", "Regular"), GlassIconBrush.Get(), [this]() { return Values.Glass.Preset == ECBLiquidGlassPreset::Regular; }, [this]() { ApplyPreset(ECBLiquidGlassPreset::Regular); }) ]
			+ SHorizontalBox::Slot().AutoWidth().Padding(0, 0, 6, 0)[ BuildChoiceButton(LOCTEXT("ShowcasePresetClear", "Clear"), ToggleIconBrush.Get(), [this]() { return Values.Glass.Preset == ECBLiquidGlassPreset::Clear; }, [this]() { ApplyPreset(ECBLiquidGlassPreset::Clear); }) ]
			+ SHorizontalBox::Slot().AutoWidth().Padding(0, 0, 6, 0)[ BuildChoiceButton(LOCTEXT("ShowcasePresetMenu", "Menu"), ButtonIconBrush.Get(), [this]() { return Values.Glass.Preset == ECBLiquidGlassPreset::FrostedMenu; }, [this]() { ApplyPreset(ECBLiquidGlassPreset::FrostedMenu); }) ]
			+ SHorizontalBox::Slot().AutoWidth()[ BuildChoiceButton(LOCTEXT("ShowcasePresetPill", "Pill"), SliderIconBrush.Get(), [this]() { return Values.Glass.Preset == ECBLiquidGlassPreset::PillLens; }, [this]() { ApplyPreset(ECBLiquidGlassPreset::PillLens); }) ]);
	}

	TSharedRef<SWidget> BuildShapeChoices()
	{
		return BuildEnumRow(LOCTEXT("ShowcaseShapeLabel", "Shape"),
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().AutoWidth().Padding(0, 0, 6, 0)[ BuildChoiceButton(LOCTEXT("ShowcaseShapeRect", "Rect"), SegmentedIconBrush.Get(), [this]() { return Values.Glass.Shape == ECBLiquidGlassShape::SuperellipseRect; }, [this]() { Values.Glass.Shape = ECBLiquidGlassShape::SuperellipseRect; RefreshPreview(); }) ]
			+ SHorizontalBox::Slot().AutoWidth().Padding(0, 0, 6, 0)[ BuildChoiceButton(LOCTEXT("ShowcaseShapeCapsule", "Capsule"), ButtonIconBrush.Get(), [this]() { return Values.Glass.Shape == ECBLiquidGlassShape::Capsule; }, [this]() { Values.Glass.Shape = ECBLiquidGlassShape::Capsule; RefreshPreview(); }) ]
			+ SHorizontalBox::Slot().AutoWidth().Padding(0, 0, 6, 0)[ BuildChoiceButton(LOCTEXT("ShowcaseShapeCircle", "Circle"), ProgressIconBrush.Get(), [this]() { return Values.Glass.Shape == ECBLiquidGlassShape::Circle; }, [this]() { Values.Glass.Shape = ECBLiquidGlassShape::Circle; RefreshPreview(); }) ]
			+ SHorizontalBox::Slot().AutoWidth()[ BuildChoiceButton(LOCTEXT("ShowcaseShapeBlob", "Blob"), GlassIconBrush.Get(), [this]() { return Values.Glass.Shape == ECBLiquidGlassShape::Blob; }, [this]() { Values.Glass.Shape = ECBLiquidGlassShape::Blob; RefreshPreview(); }) ]);
	}

	TSharedRef<SWidget> BuildQualityChoices()
	{
		return BuildEnumRow(LOCTEXT("ShowcaseQualityLabel", "Quality"),
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().AutoWidth().Padding(0, 0, 6, 0)[ BuildChoiceButton(LOCTEXT("ShowcaseQualityPerf", "Perf"), ProgressIconBrush.Get(), [this]() { return Values.Glass.Quality == ECBLiquidGlassQuality::Performance; }, [this]() { Values.Glass.Quality = ECBLiquidGlassQuality::Performance; RefreshPreview(); }) ]
			+ SHorizontalBox::Slot().AutoWidth().Padding(0, 0, 6, 0)[ BuildChoiceButton(LOCTEXT("ShowcaseQualityBalanced", "Balanced"), SliderIconBrush.Get(), [this]() { return Values.Glass.Quality == ECBLiquidGlassQuality::Balanced; }, [this]() { Values.Glass.Quality = ECBLiquidGlassQuality::Balanced; RefreshPreview(); }) ]
			+ SHorizontalBox::Slot().AutoWidth()[ BuildChoiceButton(LOCTEXT("ShowcaseQualityHigh", "Quality"), GlassIconBrush.Get(), [this]() { return Values.Glass.Quality == ECBLiquidGlassQuality::Quality; }, [this]() { Values.Glass.Quality = ECBLiquidGlassQuality::Quality; RefreshPreview(); }) ]);
	}

	TSharedRef<SWidget> BuildEnumRow(FText Label, TSharedRef<SWidget> Choices)
	{
		return SNew(SVerticalBox)
			+ SVerticalBox::Slot().AutoHeight()
			[
				SNew(STextBlock)
				.Text(Label)
				.Font(FCoreStyle::GetDefaultFontStyle("Regular", 13))
				.ColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.86f))
			]
			+ SVerticalBox::Slot().AutoHeight().Padding(0.0f, 5.0f, 0.0f, 12.0f)
			[
				Choices
			];
	}

	TSharedRef<SWidget> BuildChoiceButton(FText Label, const FSlateBrush* IconBrush, TFunction<bool()> IsSelected, TFunction<void()> OnClicked)
	{
		const bool bSelected = IsSelected();

		return SNew(SButton)
			.ButtonStyle(FCoreStyle::Get(), "NoBorder")
			.ContentPadding(0.0f)
			.OnClicked_Lambda([this, OnClicked]()
			{
				OnClicked();
				RefreshParameterPanel();
				return FReply::Handled();
			})
			[
				SNew(SBox)
				.WidthOverride(76.0f)
				.HeightOverride(60.0f)
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				[
					SNew(SCBLiquidGlass)
					.Shape(ECBLiquidGlassShape::SuperellipseRect)
					.SquirclePower(12.0f)
					.BlurStrength(bSelected ? 0.32f : 0.16f)
					.FrostRadius(bSelected ? 0.05f : 0.02f)
					.RefractionStrength(bSelected ? 0.16f : 0.06f)
					.RefractionThickness(bSelected ? 12.0f : 6.0f)
					.IndexOfRefraction(bSelected ? 1.18f : 1.08f)
					.ChromaticAberration(bSelected ? 0.006f : 0.002f)
					.PrismIntensity(bSelected ? 0.04f : 0.01f)
					.RimIntensity(bSelected ? 0.22f : 0.08f)
					.GlowAmount(bSelected ? 0.24f : 0.08f)
					.TintColor(bSelected ? FLinearColor(0.08f, 0.62f, 1.0f, 1.0f) : FLinearColor::White)
					.TintOpacity(bSelected ? 0.11f : 0.035f)
					.GlassOpacity(bSelected ? 0.72f : 0.34f)
					.EdgeSoftness(0.34f)
					.Quality(ECBLiquidGlassQuality::Performance)
					[
						SNew(SBox)
						.Padding(FMargin(4.0f, 5.0f))
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(SVerticalBox)
							+ SVerticalBox::Slot().AutoHeight().HAlign(HAlign_Center)
							[
								SNew(SImage)
								.Image(IconBrush)
								.ColorAndOpacity_Lambda([IsSelected]()
								{
									return IsSelected()
										? FLinearColor(0.74f, 0.96f, 1.0f, 1.0f)
										: FLinearColor(1.0f, 1.0f, 1.0f, 0.82f);
								})
							]
							+ SVerticalBox::Slot().AutoHeight().HAlign(HAlign_Center).Padding(0.0f, 4.0f, 0.0f, 0.0f)
							[
								SNew(STextBlock)
								.Text(Label)
								.Justification(ETextJustify::Center)
								.Font(FCoreStyle::GetDefaultFontStyle("Bold", 10))
								.ColorAndOpacity_Lambda([IsSelected]()
								{
									return IsSelected()
										? FLinearColor(0.82f, 0.97f, 1.0f, 1.0f)
									: FLinearColor(1.0f, 1.0f, 1.0f, 0.84f);
								})
							]
						]
					]
				]
			];
	}

	void ApplyPreset(ECBLiquidGlassPreset Preset)
	{
		Values.Glass.Preset = Preset;
		switch (Preset)
		{
		case ECBLiquidGlassPreset::Clear:
			Values.Glass.BlurStrength = 0.42f;
			Values.Glass.FrostRadius = 0.08f;
			Values.Glass.RefractionStrength = 0.82f;
			Values.Glass.RefractionThickness = 38.0f;
			Values.Glass.IndexOfRefraction = 1.72f;
			Values.Glass.PrismIntensity = 0.34f;
			Values.Glass.GlassOpacity = 1.0f;
			break;
		case ECBLiquidGlassPreset::FrostedMenu:
			Values.Glass.BlurStrength = 1.3f;
			Values.Glass.FrostRadius = 0.48f;
			Values.Glass.RefractionStrength = 0.58f;
			Values.Glass.RefractionThickness = 28.0f;
			Values.Glass.IndexOfRefraction = 1.45f;
			Values.Glass.PrismIntensity = 0.26f;
			Values.Glass.GlassOpacity = 0.9f;
			break;
		case ECBLiquidGlassPreset::PillLens:
			Values.Glass.Shape = ECBLiquidGlassShape::Capsule;
			Values.Glass.BlurStrength = 0.55f;
			Values.Glass.FrostRadius = 0.12f;
			Values.Glass.RefractionStrength = 0.82f;
			Values.Glass.RefractionThickness = 42.0f;
			Values.Glass.IndexOfRefraction = 1.78f;
			Values.Glass.PrismIntensity = 0.32f;
			Values.Glass.GlassOpacity = 1.0f;
			break;
		case ECBLiquidGlassPreset::Regular:
		default:
			Values.Glass.Shape = ECBLiquidGlassShape::SuperellipseRect;
			Values.Glass.BlurStrength = 0.9f;
			Values.Glass.FrostRadius = 0.25f;
			Values.Glass.RefractionStrength = 0.75f;
			Values.Glass.RefractionThickness = 34.0f;
			Values.Glass.IndexOfRefraction = 1.62f;
			Values.Glass.PrismIntensity = 0.34f;
			Values.Glass.GlassOpacity = 0.94f;
			break;
		}

		RefreshParameterPanel();
		RefreshPreview();
	}

	TSharedRef<SWidget> BuildPreviewPanel()
	{
		TSharedRef<SOverlay> PreviewOverlay = SNew(SOverlay);
		if (ShouldShowPreviewBackgroundMarks())
		{
			PreviewOverlay->AddSlot()
			[
				BuildPreviewBackgroundMarks()
			];
		}
		PreviewOverlay->AddSlot()
		[
			BuildActivePreview()
		];

		return SNew(SCBLiquidGlass)
			.Shape(ECBLiquidGlassShape::SuperellipseRect)
			.SquirclePower(7.0f)
			.BlurStrength(0.18f)
			.FrostRadius(0.035f)
			.RefractionStrength(0.08f)
			.RefractionThickness(10.0f)
			.IndexOfRefraction(1.12f)
			.PrismIntensity(0.04f)
			.TintOpacity(0.008f)
			.RimIntensity(0.045f)
			.GlassOpacity(0.32f)
			[
				SNew(SBox)
				.WidthOverride(PreviewWidth)
				.HeightOverride(PreviewHeight)
				[
					PreviewOverlay
				]
			];
	}

	bool ShouldShowPreviewBackgroundMarks() const
	{
		return false;
	}

	TSharedRef<SWidget> BuildPreviewBackgroundMarks()
	{
		return SNew(SOverlay)
			+ SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("ShowcasePreviewWatermark", "LIQUID GLASS"))
				.Font(FCoreStyle::GetDefaultFontStyle("Bold", 70))
				.ColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.15f))
			]
			+ SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Top)
			.Padding(0.0f, 18.0f, 0.0f, 0.0f)
			[
				SNew(STextBlock)
				.Text(GetTabTitle())
				.Font(FCoreStyle::GetDefaultFontStyle("Bold", 26))
				.ColorAndOpacity(FLinearColor::White)
			];
	}

	TSharedRef<SWidget> BuildActivePreview()
	{
		switch (ActiveTab)
		{
		case ECBLGShowcaseTab::Glass: return BuildGlassPreview();
		case ECBLGShowcaseTab::Button: return BuildButtonPreview();
		case ECBLGShowcaseTab::Toggle: return BuildTogglePreview();
		case ECBLGShowcaseTab::Slider: return BuildSliderPreview();
		case ECBLGShowcaseTab::Text: return BuildTextPreview();
		case ECBLGShowcaseTab::Mask: return BuildMaskPreview();
		case ECBLGShowcaseTab::Fusion: return BuildFusionPreview();
		case ECBLGShowcaseTab::Motion: return BuildMotionPreview();
		case ECBLGShowcaseTab::Performance: return BuildPerformancePreview();
		case ECBLGShowcaseTab::Segmented: return BuildSegmentedPreview();
		case ECBLGShowcaseTab::TabBar: return BuildTabBarPreview();
		case ECBLGShowcaseTab::Toolbar: return BuildToolbarPreview();
		case ECBLGShowcaseTab::Menu: return BuildMenuPreview();
		case ECBLGShowcaseTab::SearchBar: return BuildSearchBarPreview();
		case ECBLGShowcaseTab::Progress: return BuildProgressPreview();
		case ECBLGShowcaseTab::Container: return BuildContainerPreview();
		case ECBLGShowcaseTab::PageControl: return BuildPageControlPreview();
		case ECBLGShowcaseTab::Dialog: return BuildDialogPreview();
		case ECBLGShowcaseTab::NavBar: return BuildNavBarPreview();
		case ECBLGShowcaseTab::Badge: return BuildBadgePreview();
		case ECBLGShowcaseTab::Stepper:
		default: return BuildStepperPreview();
		}
	}

	FCBLiquidGlassControlStyle BuildControlStyle(ECBLiquidGlassPreset Preset = ECBLiquidGlassPreset::PillLens) const
	{
		FCBLiquidGlassControlStyle Style;
		Style.Preset = Preset;
		Style.Quality = Values.Glass.Quality;
		Style.Size = ECBLiquidGlassControlSize::Medium;
		Style.AccentColor = FLinearColor(0.0f, 0.56f, 1.0f, 1.0f);
		Style.TintColor = FLinearColor::White;
		return Style;
	}

	FCBLiquidGlassItem MakeShowcaseItem(FText Label, int32 Value, const FSlateBrush* Brush, ECBLiquidGlassItemState State = ECBLiquidGlassItemState::Normal) const
	{
		FCBLiquidGlassItem Item;
		Item.Label = Label;
		Item.Value = Value;
		Item.State = State;
		Item.bEnabled = State != ECBLiquidGlassItemState::Disabled && State != ECBLiquidGlassItemState::Separator;
		if (Brush)
		{
			Item.Icon = *Brush;
		}
		return Item;
	}

	TArray<FCBLiquidGlassItem> BuildThreeItems() const
	{
		return {
			MakeShowcaseItem(LOCTEXT("ShowcaseItemHome", "Home"), 0, ButtonIconBrush.Get()),
			MakeShowcaseItem(LOCTEXT("ShowcaseItemEdit", "Edit"), 1, SliderIconBrush.Get()),
			MakeShowcaseItem(LOCTEXT("ShowcaseItemShare", "Share"), 2, MenuIconBrush.Get()),
		};
	}

	TArray<FCBLiquidGlassItem> BuildTabItems() const
	{
		return {
			MakeShowcaseItem(LOCTEXT("ShowcaseTabHome", "Home"), 0, ButtonIconBrush.Get()),
			MakeShowcaseItem(LOCTEXT("ShowcaseTabTune", "Tune"), 1, SliderIconBrush.Get()),
			MakeShowcaseItem(LOCTEXT("ShowcaseTabSearch", "Search"), 2, SearchBarIconBrush.Get()),
			MakeShowcaseItem(LOCTEXT("ShowcaseTabMore", "More"), 3, MenuIconBrush.Get()),
		};
	}

	TArray<FCBLiquidGlassItem> BuildMenuItems() const
	{
		return {
			MakeShowcaseItem(LOCTEXT("ShowcaseMenuFind", "Find in Note"), 0, SearchBarIconBrush.Get()),
			MakeShowcaseItem(LOCTEXT("ShowcaseMenuMove", "Move Note"), 1, ToolbarIconBrush.Get(), ECBLiquidGlassItemState::Disabled),
			MakeShowcaseItem(FText::GetEmpty(), 0, nullptr, ECBLiquidGlassItemState::Separator),
			MakeShowcaseItem(LOCTEXT("ShowcaseMenuFormat", "Format"), 2, SegmentedIconBrush.Get()),
			MakeShowcaseItem(LOCTEXT("ShowcaseMenuDelete", "Delete"), 3, StepperIconBrush.Get(), ECBLiquidGlassItemState::Danger),
		};
	}

	TSharedRef<SWidget> MakePreviewDraggable(TSharedRef<SWidget> Content, FVector2D SCBLiquidGlassShowcaseDemo::* PositionMember)
	{
		TSharedRef<SCBLGDemoDraggable> Draggable = SNew(SCBLGDemoDraggable)
			.HoldSeconds(0.12f)
			[
				Content
			];

		Draggable->OnDragDelta = [this, PositionMember](const FVector2D& Delta)
		{
			this->*PositionMember += Delta;
			if (PreviewCanvas.IsValid())
			{
				PreviewCanvas->Invalidate(EInvalidateWidgetReason::Layout);
			}
		};

		return Draggable;
	}

	TSharedRef<SWidget> BuildGlassPreview()
	{
		return SAssignNew(PreviewCanvas, SCanvas)
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetGlassPos))
			.Size(FVector2D(340.0f, 190.0f))
			[
				MakePreviewDraggable(
					SNew(SCBLiquidGlass)
					.Shape(Values.Glass.Shape)
					.SquirclePower(Values.Glass.SquirclePower)
					.BlurStrength(Values.Glass.BlurStrength)
					.FrostRadius(Values.Glass.FrostRadius)
					.RefractionStrength(Values.Glass.RefractionStrength)
					.RefractionThickness(Values.Glass.RefractionThickness)
					.IndexOfRefraction(Values.Glass.IndexOfRefraction)
					.PrismIntensity(Values.Glass.PrismIntensity)
					.TintOpacity(Values.Glass.TintOpacity)
					.RimIntensity(Values.Glass.RimIntensity)
					.InnerShadowIntensity(Values.Glass.InnerShadowIntensity)
					.GlassOpacity(Values.Glass.GlassOpacity)
					.Quality(Values.Glass.Quality)
					.MotionStrength(Values.Glass.MotionStrength)
					.MotionMaxOffset(Values.Glass.MotionMaxOffset)
					[
						SNew(SBox).Padding(30.0f).VAlign(VAlign_Center)
						[
							SNew(SVerticalBox)
							+ SVerticalBox::Slot().AutoHeight()
							[
								SNew(STextBlock)
								.Text(LOCTEXT("ShowcaseGlassPreviewTitle", "Regular Glass"))
								.Font(FCoreStyle::GetDefaultFontStyle("Bold", 30))
								.ColorAndOpacity(FLinearColor::White)
							]
							+ SVerticalBox::Slot().AutoHeight().Padding(0.0f, 6.0f, 0.0f, 0.0f)
							[
								SNew(STextBlock)
								.Text(LOCTEXT("ShowcaseGlassPreviewHint", "Hold, then drag this card"))
								.Font(FCoreStyle::GetDefaultFontStyle("Regular", 16))
								.ColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.78f))
							]
						]
					],
					&SCBLiquidGlassShowcaseDemo::GlassPos)
			];
	}

	TSharedRef<SWidget> BuildButtonPreview()
	{
		return SAssignNew(PreviewCanvas, SCanvas)
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetButtonPos))
			.Size(FVector2D(340.0f, 86.0f))
			[
				MakePreviewDraggable(
					SNew(SBox).WidthOverride(320.0f).HeightOverride(72.0f)
					[
						SNew(SCBLiquidGlassButton)
						.Preset(Values.Glass.Preset)
						.Shape(Values.Glass.Shape)
						.HoverGlowBoost(Values.ButtonHoverGlowBoost)
						.PressedRefractionBoost(Values.ButtonPressedRefractionBoost)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("ShowcaseButtonPreview", "Liquid Button"))
							.Font(FCoreStyle::GetDefaultFontStyle("Bold", 20))
							.ColorAndOpacity(FLinearColor::White)
						]
					],
					&SCBLiquidGlassShowcaseDemo::ButtonPos)
			];
	}

	TSharedRef<SWidget> BuildSliderPreview()
	{
		return SAssignNew(PreviewCanvas, SCanvas)
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetSliderPos))
			.Size(FVector2D(660.0f, 132.0f))
			[
				MakePreviewDraggable(
					SNew(SBox).WidthOverride(660.0f).HeightOverride(132.0f).VAlign(VAlign_Center)
					[
						SNew(SCBLiquidGlassSlider)
						.Value(Values.SliderValue)
						.SliderLength(650.0f)
						.SliderHeight(96.0f)
						.TrackHeight(10.0f)
						.ThumbSize(FVector2D(142.0f, 58.0f))
						.FillColor(FLinearColor(0.0f, 0.48f, 1.0f, 1.0f))
						.TrackOpacity(0.54f)
						.ThumbPreset(ECBLiquidGlassPreset::PillLens)
						.Quality(Values.Glass.Quality)
						.ThumbBounce(Values.SliderThumbBounce)
						.ThumbResponse(Values.SliderThumbResponse)
						.ThumbDamping(Values.SliderThumbDamping)
						.ThumbMotionStrength(0.86f)
						.OnValueChanged(FCBLiquidGlassSliderValueChanged::CreateLambda([this](float InValue)
						{
							Values.SliderValue = InValue;
						}))
					],
					&SCBLiquidGlassShowcaseDemo::SliderPos)
			];
	}

	TSharedRef<SWidget> BuildTogglePreview()
	{
		return SAssignNew(PreviewCanvas, SCanvas)
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetButtonPos))
			.Size(FVector2D(260.0f, 120.0f))
			[
				MakePreviewDraggable(
					SNew(SBox).WidthOverride(260.0f).HeightOverride(120.0f).HAlign(HAlign_Center).VAlign(VAlign_Center)
					[
						SNew(SCBLiquidGlassToggle)
						.Checked(Values.bToggleChecked)
						.Style(BuildControlStyle())
						.OnCheckStateChanged(FCBLiquidGlassCheckChanged::CreateLambda([this](bool bChecked)
						{
							Values.bToggleChecked = bChecked;
						}))
					],
					&SCBLiquidGlassShowcaseDemo::ButtonPos)
			];
	}

	TSharedRef<SWidget> BuildSegmentedPreview()
	{
		return SAssignNew(PreviewCanvas, SCanvas)
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetTextPos))
			.Size(FVector2D(390.0f, 70.0f))
			[
				MakePreviewDraggable(
					SNew(SBox).WidthOverride(372.0f).HeightOverride(56.0f)
					[
						SNew(SCBLiquidGlassSegmentedControl)
						.Items(BuildThreeItems())
						.SelectedIndex(FMath::Clamp(Values.SegmentedIndex, 0, 2))
						.Style(BuildControlStyle())
						.OnSelectionChanged(FCBLiquidGlassIndexChanged::CreateLambda([this](int32 Index, int32)
						{
							Values.SegmentedIndex = Index;
						}))
					],
					&SCBLiquidGlassShowcaseDemo::TextPos)
			];
	}

	TSharedRef<SWidget> BuildTabBarPreview()
	{
		return SAssignNew(PreviewCanvas, SCanvas)
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetSliderPos))
			.Size(FVector2D(420.0f, 86.0f))
			[
				MakePreviewDraggable(
					SNew(SBox).WidthOverride(404.0f).HeightOverride(78.0f)
					[
						SNew(SCBLiquidGlassTabBar)
						.Items(BuildTabItems())
						.SelectedIndex(FMath::Clamp(Values.TabBarIndex, 0, 3))
						.Style(BuildControlStyle())
						.OnTabChanged(FCBLiquidGlassIndexChanged::CreateLambda([this](int32 Index, int32)
						{
							Values.TabBarIndex = Index;
						}))
					],
					&SCBLiquidGlassShowcaseDemo::SliderPos)
			];
	}

	TSharedRef<SWidget> BuildToolbarPreview()
	{
		return SAssignNew(PreviewCanvas, SCanvas)
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetToolbarPos))
			.Size(FVector2D(360.0f, 82.0f))
			[
				MakePreviewDraggable(
					SNew(SBox).WidthOverride(348.0f).HeightOverride(74.0f)
					[
						SNew(SCBLiquidGlassToolbar)
						.Items(BuildTabItems())
						.SelectedIndex(FMath::Clamp(Values.ToolbarIndex, 0, 3))
						.bToggleMode(true)
						.Style(BuildControlStyle())
						.OnToolClicked(FCBLiquidGlassItemClicked::CreateLambda([this](int32 Index, int32)
						{
							Values.ToolbarIndex = Index;
						}))
					],
					&SCBLiquidGlassShowcaseDemo::ToolbarPos)
			];
	}

	TSharedRef<SWidget> BuildMenuPreview()
	{
		return SAssignNew(PreviewCanvas, SCanvas)
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetMenuPos))
			.Size(FVector2D(340.0f, 320.0f))
			[
				MakePreviewDraggable(
					SNew(SCBLiquidGlassMenu)
					.Items(BuildMenuItems())
					.Style(BuildControlStyle(ECBLiquidGlassPreset::FrostedMenu)),
					&SCBLiquidGlassShowcaseDemo::MenuPos)
			];
	}

	TSharedRef<SWidget> BuildSearchBarPreview()
	{
		FCBLiquidGlassControlStyle SearchStyle = BuildControlStyle(ECBLiquidGlassPreset::FrostedMenu);

		return SAssignNew(PreviewCanvas, SCanvas)
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetSliderPos))
			.Size(FVector2D(590.0f, 96.0f))
			[
				MakePreviewDraggable(
					SNew(SBox).WidthOverride(560.0f).HeightOverride(78.0f)
					[
						SNew(SCBLiquidGlassSearchBar)
						.Text(Values.SearchText)
						.HintText(LOCTEXT("ShowcaseSearchHint", "Search anything..."))
						.bShowClearButton(Values.bSearchShowClearButton)
						.bShowSearchIcon(Values.bSearchShowIcon)
						.bShowText(Values.bSearchShowLabel)
						.Style(SearchStyle)
						.SearchBoxStyle(Values.SearchBoxStyle)
						.OnTextChanged(FCBLiquidGlassTextChanged::CreateLambda([this](const FText& InText)
						{
							Values.SearchText = InText;
						}))
					],
					&SCBLiquidGlassShowcaseDemo::SliderPos)
			];
	}

	TSharedRef<SWidget> BuildProgressPreview()
	{
		return SAssignNew(PreviewCanvas, SCanvas)
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetSliderPos))
			.Size(FVector2D(600.0f, 260.0f))
			[
				MakePreviewDraggable(
					SNew(SVerticalBox)
					+ SVerticalBox::Slot().AutoHeight().HAlign(HAlign_Center)
					[
						SNew(SCBLiquidGlassProgress)
						.Value(Values.ProgressValue)
						.ProgressStyle(ECBLiquidGlassProgressStyle::Circular)
						.Thickness(Values.ProgressThickness)
						.FillColor(FLinearColor(0.0f, 0.56f, 1.0f, 1.0f))
						.TrackOpacity(Values.ProgressTrackOpacity)
						.bShowPercentText(Values.bProgressShowPercent)
						.FrostRadius(Values.ProgressFrostRadius)
						.RefractionStrength(Values.ProgressRefractionStrength)
						.PrismIntensity(Values.ProgressPrismIntensity)
						.Quality(Values.Glass.Quality)
					]
					+ SVerticalBox::Slot().AutoHeight().Padding(0.0f, 28.0f, 0.0f, 0.0f).HAlign(HAlign_Center)
					[
						SNew(SCBLiquidGlassProgress)
						.Value(Values.ProgressValue)
						.ProgressStyle(ECBLiquidGlassProgressStyle::Linear)
						.Thickness(Values.ProgressThickness)
						.FillColor(FLinearColor(0.0f, 0.56f, 1.0f, 1.0f))
						.TrackOpacity(Values.ProgressTrackOpacity)
						.bShowPercentText(Values.bProgressShowPercent)
						.FrostRadius(Values.ProgressFrostRadius)
						.RefractionStrength(Values.ProgressRefractionStrength)
						.PrismIntensity(Values.ProgressPrismIntensity)
						.Quality(Values.Glass.Quality)
					],
					&SCBLiquidGlassShowcaseDemo::SliderPos)
			];
	}

	TSharedRef<SWidget> BuildStepperPreview()
	{
		return SAssignNew(PreviewCanvas, SCanvas)
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetButtonPos))
			.Size(FVector2D(300.0f, 90.0f))
			[
				MakePreviewDraggable(
					SNew(SCBLiquidGlassStepper)
					.Value(Values.StepperValue)
					.MinValue(0.0f)
					.MaxValue(10.0f)
					.Step(1.0f)
					.bIntegerOnly(true)
					.Style(BuildControlStyle())
					.OnValueChanged(FCBLiquidGlassFloatChanged::CreateLambda([this](float InValue)
					{
						Values.StepperValue = InValue;
					})),
					&SCBLiquidGlassShowcaseDemo::ButtonPos)
			];
	}

	TSharedRef<SWidget> BuildContainerPreview()
	{
		FCBLiquidGlassFusionBlob LeftBlob;
		LeftBlob.Position = FVector2D(0.24f, 0.55f);
		LeftBlob.Size = FVector2D(178.0f, 136.0f);
		LeftBlob.Roundness = 1.0f;

		FCBLiquidGlassFusionBlob CenterBlob;
		CenterBlob.Position = FVector2D(0.49f, 0.45f);
		CenterBlob.Size = FVector2D(194.0f, 148.0f);
		CenterBlob.Roundness = 1.0f;

		FCBLiquidGlassFusionBlob RightBlob;
		RightBlob.Position = FVector2D(0.75f, 0.56f);
		RightBlob.Size = FVector2D(160.0f, 120.0f);
		RightBlob.Roundness = 1.0f;

		FCBLiquidGlassFusionBlob TopBlob;
		TopBlob.Position = FVector2D(0.56f, 0.2f);
		TopBlob.Size = FVector2D(96.0f, 86.0f);
		TopBlob.Roundness = 1.0f;

		TArray<FCBLiquidGlassFusionBlob> Blobs = { LeftBlob, CenterBlob, RightBlob, TopBlob };

		return SAssignNew(PreviewCanvas, SCanvas)
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetContainerPos))
			.Size(FVector2D(480.0f, 250.0f))
			[
				MakePreviewDraggable(
					SNew(SCBLiquidGlassContainer)
					.Blobs(Blobs)
					.Smoothing(Values.ContainerSmoothing)
					.CanvasSize(FVector2D(460.0f, 230.0f))
					.MaskResolution(FVector2D(512.0f, 256.0f))
					.BlurStrength(1.15f)
					.FrostRadius(Values.ContainerFrostRadius)
					.RefractionStrength(Values.ContainerRefractionStrength)
					.RefractionThickness(60.0f)
					.PrismIntensity(Values.ContainerPrismIntensity)
					.RimIntensity(Values.ContainerRimIntensity)
					.GlassOpacity(Values.ContainerOpacity)
					.Preset(ECBLiquidGlassPreset::Regular)
					.Quality(Values.Glass.Quality)
					[
						SNew(SBox).HAlign(HAlign_Center).VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("ShowcaseContainerPreview", "Fusion Container"))
							.Font(FCoreStyle::GetDefaultFontStyle("Bold", 24))
							.ColorAndOpacity(FLinearColor::White)
						]
					],
					&SCBLiquidGlassShowcaseDemo::ContainerPos)
			];
	}

	TSharedRef<SWidget> BuildPageControlPreview()
	{
		return SAssignNew(PreviewCanvas, SCanvas)
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetPageControlPos))
			.Size(FVector2D(260.0f, 96.0f))
			[
				MakePreviewDraggable(
					SNew(SBox).WidthOverride(250.0f).HeightOverride(86.0f).HAlign(HAlign_Center).VAlign(VAlign_Center)
					[
						SNew(SCBLiquidGlass)
						.Shape(ECBLiquidGlassShape::Capsule)
						.BlurStrength(0.52f)
						.FrostRadius(0.16f)
						.RefractionStrength(0.38f)
						.RefractionThickness(18.0f)
						.RimIntensity(0.22f)
						.TintOpacity(0.04f)
						.GlassOpacity(0.72f)
						.Quality(Values.Glass.Quality)
						[
							SNew(SBox).Padding(FMargin(28.0f, 0.0f)).HAlign(HAlign_Center).VAlign(VAlign_Center)
							[
								SNew(SCBLiquidGlassPageControl)
								.NumPages(6)
								.CurrentPage(FMath::Clamp(FMath::RoundToInt(Values.PageIndex), 0, 5))
								.DotSize(14.0f)
								.DotSpacing(14.0f)
								.OnPageChanged(FCBLiquidGlassPageChanged::CreateLambda([this](int32 InPage)
								{
									Values.PageIndex = static_cast<float>(InPage);
									RefreshParameterPanel();
								}))
							]
						]
					],
					&SCBLiquidGlassShowcaseDemo::PageControlPos)
			];
	}

	TSharedRef<SWidget> BuildDialogPreview()
	{
		TArray<FCBLiquidGlassItem> DialogButtons =
		{
			MakeShowcaseItem(LOCTEXT("ShowcaseDialogCancel", "Cancel"), 0, nullptr),
			MakeShowcaseItem(LOCTEXT("ShowcaseDialogOK", "OK"), 1, nullptr, ECBLiquidGlassItemState::Selected)
		};

		return SAssignNew(PreviewCanvas, SCanvas)
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetDialogPos))
			.Size(FVector2D(380.0f, 330.0f))
			[
				MakePreviewDraggable(
					SNew(SBox).WidthOverride(380.0f).HeightOverride(330.0f)
					[
						SNew(SCBLiquidGlassDialog)
						.Title(LOCTEXT("ShowcaseDialogPreviewTitle", "Liquid Glass"))
						.Message(LOCTEXT("ShowcaseDialogPreviewMessage", "A spring-presented glass dialog."))
						.Buttons(DialogButtons)
						.DialogStyle(ECBLiquidGlassDialogStyle::Alert)
						.bDimBackground(Values.bDialogDimBackground)
						.bStartPresented(true)
						.DimOpacity(Values.DialogDimOpacity)
						.CardBlurStrength(Values.DialogBlurStrength)
						.CardFrostRadius(Values.DialogFrostRadius)
						.CardRefractionStrength(Values.DialogRefractionStrength)
						.CardRefractionThickness(36.0f)
						.CardPrismIntensity(Values.DialogPrismIntensity)
						.CardRimIntensity(0.42f)
						.CardGlassOpacity(Values.DialogOpacity)
						.Style(BuildControlStyle(ECBLiquidGlassPreset::FrostedMenu))
					],
					&SCBLiquidGlassShowcaseDemo::DialogPos)
			];
	}

	TSharedRef<SWidget> BuildNavBarPreview()
	{
		TArray<FCBLiquidGlassItem> Trailing =
		{
			MakeShowcaseItem(LOCTEXT("ShowcaseNavDone", "Done"), 0, ButtonIconBrush.Get())
		};

		return SAssignNew(PreviewCanvas, SCanvas)
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetNavBarPos))
			.Size(FVector2D(520.0f, 88.0f))
			[
				MakePreviewDraggable(
					SNew(SBox).WidthOverride(500.0f).HeightOverride(72.0f)
					[
						SNew(SCBLiquidGlassNavigationBar)
						.Title(LOCTEXT("ShowcaseNavTitlePreview", "Liquid Glass"))
						.bShowBackButton(true)
						.bLargeTitle(false)
						.TrailingItems(Trailing)
						.Style(BuildControlStyle(ECBLiquidGlassPreset::FrostedMenu))
					],
					&SCBLiquidGlassShowcaseDemo::NavBarPos)
			];
	}

	TSharedRef<SWidget> BuildBadgePreview()
	{
		const int32 Count = FMath::Clamp(FMath::RoundToInt(Values.BadgeCount), 0, 999);

		return SAssignNew(PreviewCanvas, SCanvas)
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetBadgePos))
			.Size(FVector2D(410.0f, 170.0f))
			[
				MakePreviewDraggable(
					SNew(SCBLiquidGlass)
					.Shape(ECBLiquidGlassShape::SuperellipseRect)
					.SquirclePower(8.0f)
					.BlurStrength(0.62f)
					.FrostRadius(0.18f)
					.RefractionStrength(0.32f)
					.RefractionThickness(18.0f)
					.RimIntensity(0.22f)
					.TintOpacity(0.04f)
					.GlassOpacity(0.72f)
					.Quality(Values.Glass.Quality)
					[
						SNew(SBox).WidthOverride(390.0f).HeightOverride(150.0f).Padding(26.0f)
						[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot().FillWidth(1.0f).VAlign(VAlign_Center)
							[
								SNew(STextBlock)
								.Text(LOCTEXT("ShowcaseBadgePreviewLabel", "Notifications"))
								.Font(FCoreStyle::GetDefaultFontStyle("Bold", 24))
								.ColorAndOpacity(FLinearColor::White)
							]
							+ SHorizontalBox::Slot().AutoWidth().VAlign(VAlign_Center).Padding(0.0f, 0.0f, 14.0f, 0.0f)
							[
								SNew(SCBLiquidGlassBadge)
								.Count(Count)
								.bDotMode(Values.bBadgeDotMode)
								.Style(BuildControlStyle())
							]
							+ SHorizontalBox::Slot().AutoWidth().VAlign(VAlign_Center)
							[
								SNew(SCBLiquidGlassBadge)
								.Count(250)
								.MaxCount(99)
								.Style(BuildControlStyle())
							]
						]
					],
					&SCBLiquidGlassShowcaseDemo::BadgePos)
			];
	}

	TSharedRef<SWidget> BuildTextPreview()
	{
		return SAssignNew(PreviewCanvas, SCanvas)
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetTextPos))
			.Size(FVector2D(660.0f, 285.0f))
			[
				MakePreviewDraggable(
					SNew(SBox)
					.WidthOverride(660.0f)
					.HeightOverride(285.0f)
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
					[
						SNew(SCBLiquidGlassText)
						.Text(FText::FromString(TEXT("Glass 2026\n\u4E2D\u6587 ABC")))
						.Font(FCoreStyle::GetDefaultFontStyle("Bold", FMath::RoundToInt(Values.TextFontSize)))
						.ColorAndOpacity(FLinearColor(0.82f, 0.98f, 1.0f, 0.9f))
						.FontSize(FMath::RoundToInt(Values.TextFontSize))
						.GlyphThickness(Values.TextGlyphThickness)
						.LetterSpacing(0.0f)
						.LineSpacing(8.0f)
						.Preset(ECBLiquidGlassPreset::PillLens)
						.Quality(Values.Glass.Quality)
						.FrostRadius(Values.TextFrostRadius)
						.MotionStrength(Values.Glass.MotionStrength)
					],
					&SCBLiquidGlassShowcaseDemo::TextPos)
			];
	}

	TSharedRef<SWidget> BuildMaskPreview()
	{
		return SAssignNew(PreviewCanvas, SCanvas)
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetMaskPosA))
			.Size(FVector2D(190.0f, 220.0f))
			[
				MakePreviewDraggable(BuildMaskSample(StarMaskTexture.Get(), LOCTEXT("ShowcaseMaskStar", "Star")), &SCBLiquidGlassShowcaseDemo::MaskPosA)
			]
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetMaskPosB))
			.Size(FVector2D(190.0f, 220.0f))
			[
				MakePreviewDraggable(BuildMaskSample(DropletMaskTexture.Get(), LOCTEXT("ShowcaseMaskDrop", "Drop")), &SCBLiquidGlassShowcaseDemo::MaskPosB)
			]
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetMaskPosC))
			.Size(FVector2D(190.0f, 220.0f))
			[
				MakePreviewDraggable(BuildMaskSample(SearchMaskTexture.Get(), LOCTEXT("ShowcaseMaskSearch", "Search")), &SCBLiquidGlassShowcaseDemo::MaskPosC)
			];
	}

	TSharedRef<SWidget> BuildMaskSample(UTexture2D* MaskTexture, FText Label)
	{
		return SNew(SVerticalBox)
			+ SVerticalBox::Slot().AutoHeight().HAlign(HAlign_Center)
			[
				SNew(SBox).WidthOverride(182.0f).HeightOverride(182.0f)
				[
					SNew(SCBLiquidGlass)
					.AlphaMaskTexture(MaskTexture)
					.AlphaMaskThreshold(Values.MaskThreshold)
					.AlphaMaskSoftness(Values.MaskSoftness)
					.FrostRadius(FMath::Min(Values.Glass.FrostRadius, 0.11f))
					.BlurStrength(0.36f)
					.RefractionStrength(1.0f)
					.RefractionThickness(58.0f)
					.IndexOfRefraction(1.96f)
					.ChromaticAberration(0.055f)
					.PrismIntensity(Values.Glass.PrismIntensity)
					.RimIntensity(0.64f)
					.GlowAmount(0.58f)
					.TintOpacity(0.004f)
					.GlassOpacity(1.0f)
					.EdgeSoftness(0.52f)
					.InnerGlowIntensity(0.22f)
					.InnerShadowIntensity(0.18f)
					.Quality(Values.Glass.Quality)
					[ SNew(SBox) ]
				]
			]
			+ SVerticalBox::Slot().AutoHeight().HAlign(HAlign_Center).Padding(0.0f, 8.0f, 0.0f, 0.0f)
			[
				SNew(STextBlock)
				.Text(Label)
				.Font(FCoreStyle::GetDefaultFontStyle("Bold", 14))
				.ColorAndOpacity(FLinearColor::White)
			];
	}

	TSharedRef<SWidget> BuildFusionPreview()
	{
		return SAssignNew(PreviewCanvas, SCanvas)
			+ SCanvas::Slot()
			.Position(FVector2D(-10.0f, 76.0f))
			.Size(FVector2D(780.0f, 390.0f))
			[
				SNew(SCBLGFusionGroup)
				.FrostRadius(Values.Glass.FrostRadius)
				.PrismIntensity(Values.FusionPrismIntensity)
				.RimIntensity(Values.FusionRimIntensity)
			];
	}

	TSharedRef<SWidget> BuildFusionBubble(FText Label, ECBLiquidGlassShape Shape)
	{
		return SNew(SCBLiquidGlass)
			.Shape(Shape)
			.BlurStrength(0.56f)
			.FrostRadius(Values.Glass.FrostRadius)
			.RefractionStrength(0.66f)
			.RefractionThickness(32.0f)
			.IndexOfRefraction(1.62f)
			.PrismIntensity(Values.FusionPrismIntensity)
			.RimIntensity(Values.FusionRimIntensity)
			.TintOpacity(0.012f)
			.GlassOpacity(0.96f)
			.Quality(Values.Glass.Quality)
			.MotionStrength(0.54f)
			[
				SNew(SBox).HAlign(HAlign_Center).VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(Label)
					.Font(FCoreStyle::GetDefaultFontStyle("Bold", 22))
					.ColorAndOpacity(FLinearColor::White)
				]
			];
	}

	TSharedRef<SWidget> BuildMotionPreview()
	{
		return SAssignNew(PreviewCanvas, SCanvas)
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetMotionPosA))
			.Size(FVector2D(360.0f, 160.0f))
			[
				MakePreviewDraggable(
					SNew(SCBLiquidGlass)
					.Shape(ECBLiquidGlassShape::SuperellipseRect)
					.SquirclePower(7.0f)
					.BlurStrength(Values.Glass.BlurStrength)
					.FrostRadius(0.18f)
					.RefractionStrength(Values.Glass.RefractionStrength)
					.RefractionThickness(34.0f)
					.IndexOfRefraction(1.7f)
					.PrismIntensity(0.24f)
					.MotionStrength(Values.Glass.MotionStrength)
					.MotionMaxOffset(Values.Glass.MotionMaxOffset)
					.MotionResponse(24.0f)
					.MotionDamping(8.0f)
					.Quality(Values.Glass.Quality)
					[
						SNew(SBox).Padding(30.0f).VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("ShowcaseMotionDragMe", "Drag Me"))
							.Font(FCoreStyle::GetDefaultFontStyle("Bold", 30))
							.ColorAndOpacity(FLinearColor::White)
						]
					],
					&SCBLiquidGlassShowcaseDemo::MotionPosA)
			]
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetMotionPosB))
			.Size(FVector2D(150.0f, 150.0f))
			[
				MakePreviewDraggable(
					SNew(SCBLiquidGlass)
					.Shape(ECBLiquidGlassShape::Blob)
					.FrostRadius(0.08f)
					.RefractionStrength(0.82f)
					.RefractionThickness(32.0f)
					.IndexOfRefraction(1.68f)
					.PrismIntensity(0.22f)
					.MotionStrength(FMath::Max(Values.Glass.MotionStrength, 0.8f))
					.MotionMaxOffset(Values.Glass.MotionMaxOffset)
					[ SNew(SBox) ],
					&SCBLiquidGlassShowcaseDemo::MotionPosB)
			];
	}

	TSharedRef<SWidget> BuildPerformancePreview()
	{
		return SAssignNew(PreviewCanvas, SCanvas)
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetPerformancePosA))
			.Size(FVector2D(205.0f, 150.0f))
			[
				MakePreviewDraggable(BuildQualityCard(LOCTEXT("ShowcasePerfCard", "Performance"), ECBLiquidGlassQuality::Performance), &SCBLiquidGlassShowcaseDemo::PerformancePosA)
			]
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetPerformancePosB))
			.Size(FVector2D(205.0f, 150.0f))
			[
				MakePreviewDraggable(BuildQualityCard(LOCTEXT("ShowcaseBalancedCard", "Balanced"), ECBLiquidGlassQuality::Balanced), &SCBLiquidGlassShowcaseDemo::PerformancePosB)
			]
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassShowcaseDemo::GetPerformancePosC))
			.Size(FVector2D(205.0f, 150.0f))
			[
				MakePreviewDraggable(BuildQualityCard(LOCTEXT("ShowcaseQualityCard", "Quality"), ECBLiquidGlassQuality::Quality), &SCBLiquidGlassShowcaseDemo::PerformancePosC)
			];
	}

	TSharedRef<SWidget> BuildQualityCard(FText Label, ECBLiquidGlassQuality Quality)
	{
		return SNew(SCBLiquidGlass)
			.Shape(ECBLiquidGlassShape::SuperellipseRect)
			.SquirclePower(7.0f)
			.BlurStrength(Values.Glass.BlurStrength)
			.FrostRadius(Values.Glass.FrostRadius)
			.RefractionStrength(0.78f)
			.PrismIntensity(0.34f)
			.Quality(Quality)
			[
				SNew(SBox).HAlign(HAlign_Center).VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(Label)
					.Font(FCoreStyle::GetDefaultFontStyle("Bold", 18))
					.ColorAndOpacity(FLinearColor::White)
				]
			];
	}

	TSharedRef<SWidget> BuildCloseButton()
	{
		return SNew(SCBLGDemoClose)
			.OnClicked(FSimpleDelegate::CreateStatic(&CBLiquidGlassDemo::RemoveShowcaseDemo))
			[
				SNew(SBox).WidthOverride(42.0f).HeightOverride(42.0f)
				[
					SNew(SCBLiquidGlass)
					.Shape(ECBLiquidGlassShape::Circle)
					.FrostRadius(0.08f)
					.BlurStrength(0.4f)
					.RimIntensity(0.24f)
					.TintOpacity(0.01f)
					[
						SNew(SBox).HAlign(HAlign_Center).VAlign(VAlign_Center)
						[
							SNew(SImage)
							.Image(CloseBrush.Get())
							.ColorAndOpacity(FLinearColor::White)
						]
					]
				]
			];
	}
};

/** Legacy overlay that shows the new Liquid Glass components together; not registered as a console command. */
class SCBLiquidGlassGalleryDemo : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLiquidGlassGalleryDemo) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs)
	{
		auto MakeItem = [](const FText& Label, int32 Value, ECBLiquidGlassItemState State = ECBLiquidGlassItemState::Normal)
		{
			FCBLiquidGlassItem Item;
			Item.Label = Label;
			Item.Value = Value;
			Item.State = State;
			return Item;
		};

		auto Section = [](const FText& Title, const TSharedRef<SWidget>& Content) -> TSharedRef<SWidget>
		{
			return SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight().Padding(0.0f, 18.0f, 0.0f, 8.0f)
				[
					SNew(STextBlock).Text(Title)
					.Font(FCoreStyle::GetDefaultFontStyle("Bold", 17))
					.ColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.95f))
				]
				+ SVerticalBox::Slot().AutoHeight().HAlign(HAlign_Left)
				[
					Content
				];
		};

		TArray<FCBLiquidGlassItem> NavTrailing = { MakeItem(LOCTEXT("GalleryDone", "Done"), 0) };
		TArray<FCBLiquidGlassItem> DialogButtons =
		{
			MakeItem(LOCTEXT("GalleryCancel", "Cancel"), 0),
			MakeItem(LOCTEXT("GalleryOK", "OK"), 1, ECBLiquidGlassItemState::Selected),
		};

		TSharedRef<SHorizontalBox> BadgeRow = SNew(SHorizontalBox);
		const int32 BadgeCounts[] = { 1, 8, 99, 250 };
		for (int32 BadgeCount : BadgeCounts)
		{
			BadgeRow->AddSlot().AutoWidth().VAlign(VAlign_Center).Padding(0.0f, 0.0f, 16.0f, 0.0f)
			[
				SNew(SCBLiquidGlassBadge).Count(BadgeCount)
			];
		}
		BadgeRow->AddSlot().AutoWidth().VAlign(VAlign_Center)
		[
			SNew(SCBLiquidGlassBadge).bDotMode(true)
		];

		ChildSlot
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			[
				SNew(SColorBlock).Color(FLinearColor(0.02f, 0.03f, 0.05f, 0.55f))
			]
			+ SOverlay::Slot().HAlign(HAlign_Center).VAlign(VAlign_Center)
			[
				SNew(SBox).WidthOverride(720.0f).MaxDesiredHeight(840.0f)
				[
					SNew(SCBLiquidGlass)
					.Shape(ECBLiquidGlassShape::SuperellipseRect)
					.SquirclePower(6.0f)
					.BlurStrength(1.2f).FrostRadius(0.4f)
					.RefractionStrength(0.55f).RefractionThickness(28.0f).IndexOfRefraction(1.5f)
					.TintColor(FLinearColor(0.72f, 0.78f, 0.82f, 1.0f)).TintOpacity(0.07f)
					.RimIntensity(0.26f).GlowAmount(0.26f).GlassOpacity(0.92f)
					[
						SNew(SBox).Padding(26.0f)
						[
							SNew(SScrollBox)
							+ SScrollBox::Slot()
							[
								SNew(SVerticalBox)
								+ SVerticalBox::Slot().AutoHeight()
								[
									SNew(SCBLiquidGlassNavigationBar)
									.Title(LOCTEXT("GalleryNavTitle", "Components"))
									.bShowBackButton(true)
									.bLargeTitle(true)
									.TrailingItems(NavTrailing)
								]
								+ SVerticalBox::Slot().AutoHeight()
								[
									Section(LOCTEXT("GalleryPage", "Page Control"),
										SNew(SCBLiquidGlassPageControl).NumPages(5).CurrentPage(2).DotSize(12.0f).DotSpacing(12.0f))
								]
								+ SVerticalBox::Slot().AutoHeight()
								[
									Section(LOCTEXT("GalleryBadge", "Badge"), BadgeRow)
								]
								+ SVerticalBox::Slot().AutoHeight()
								[
									Section(LOCTEXT("GalleryFusion", "Fusion Container"),
										SNew(SCBLiquidGlassContainer).Smoothing(54.0f).CanvasSize(FVector2D(380.0f, 150.0f)))
								]
								+ SVerticalBox::Slot().AutoHeight()
								[
									Section(LOCTEXT("GalleryDialog", "Dialog"),
										SNew(SCBLiquidGlassButton)
										.Preset(ECBLiquidGlassPreset::PillLens).Shape(ECBLiquidGlassShape::Capsule)
										.OnClicked(FSimpleDelegate::CreateSP(this, &SCBLiquidGlassGalleryDemo::ShowDialog))
										[
											SNew(SBox).Padding(FMargin(22.0f, 9.0f))
											[
												SNew(STextBlock).Text(LOCTEXT("GalleryShowDialog", "Present Dialog"))
												.Font(FCoreStyle::GetDefaultFontStyle("Bold", 15)).ColorAndOpacity(FLinearColor::White)
											]
										])
								]
							]
						]
					]
				]
			]
			+ SOverlay::Slot().HAlign(HAlign_Right).VAlign(VAlign_Top).Padding(22.0f)
			[
				SNew(SCBLGDemoClose)
				.OnClicked(FSimpleDelegate::CreateStatic(&CBLiquidGlassDemo::RemoveGalleryDemo))
				[
					SNew(SBox).WidthOverride(42.0f).HeightOverride(42.0f)
					[
						SNew(SCBLiquidGlass).Shape(ECBLiquidGlassShape::Circle).FrostRadius(0.08f).BlurStrength(0.4f).RimIntensity(0.24f).TintOpacity(0.01f)
						[
							SNew(SBox).HAlign(HAlign_Center).VAlign(VAlign_Center)
							[
								SNew(STextBlock).Text(FText::FromString(TEXT("✕")))
								.Font(FCoreStyle::GetDefaultFontStyle("Bold", 20)).ColorAndOpacity(FLinearColor::White)
							]
						]
					]
				]
			]
			+ SOverlay::Slot()
			[
				SAssignNew(GalleryDialog, SCBLiquidGlassDialog)
				.Title(LOCTEXT("GalleryDialogTitle", "Liquid Glass"))
				.Message(LOCTEXT("GalleryDialogMsg", "A glass alert presented with a spring entrance."))
				.Buttons(DialogButtons)
				.DialogStyle(ECBLiquidGlassDialogStyle::Alert)
			]
		];
	}

private:
	void ShowDialog()
	{
		if (GalleryDialog.IsValid())
		{
			GalleryDialog->Present();
		}
	}

	TSharedPtr<SCBLiquidGlassDialog> GalleryDialog;
};

namespace CBLiquidGlassDemo
{
	static UGameViewportClient* ResolveViewport(UWorld* World)
	{
		// Console commands may be called with or without a world. Fall back to GEngine for PIE.
		UGameViewportClient* Viewport = World ? World->GetGameViewport() : nullptr;
		if (!Viewport && GEngine)
		{
			Viewport = GEngine->GameViewport;
		}
		return Viewport;
	}

	static void Toggle(const TArray<FString>& Args, UWorld* World)
	{
		// Toggle semantics keep repeated console execution simple during iteration.
		if (GDemoWidget.IsValid())
		{
			Remove();
			return;
		}

		UGameViewportClient* Viewport = ResolveViewport(World);

		if (!Viewport)
		{
			UE_LOG(LogTemp, Warning, TEXT("CBLiquidGlass.Demo: no active game viewport. Start Play-In-Editor first."));
			return;
		}

		TSharedRef<SCBLiquidGlassDemo> Demo = SNew(SCBLiquidGlassDemo);
		Viewport->AddViewportWidgetContent(Demo, /*ZOrder*/ 1000);
		GDemoWidget = Demo;
		GDemoViewport = Viewport;
	}

	static FAutoConsoleCommandWithWorldAndArgs GToggleCmd(
		TEXT("CBLiquidGlass.Demo"),
		TEXT("Toggle a Liquid Glass showcase overlay (run during Play)."),
		FConsoleCommandWithWorldAndArgsDelegate::CreateStatic(&Toggle));

	static void OpenShowcaseDemo(const TArray<FString>& Args, UWorld* World, ECBLGShowcaseTab InitialTab, const TCHAR* CommandName)
	{
		if (GShowcaseDemoWidget.IsValid())
		{
			RemoveShowcaseDemo();
		}

		UGameViewportClient* Viewport = ResolveViewport(World);
		if (!Viewport)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s: no active game viewport. Start Play-In-Editor first."), CommandName);
			return;
		}

		TSharedRef<SCBLiquidGlassShowcaseDemo> Demo = SNew(SCBLiquidGlassShowcaseDemo)
			.InitialTab(InitialTab);
		Viewport->AddViewportWidgetContent(Demo, /*ZOrder*/ 1003);
		GShowcaseDemoWidget = Demo;
		GShowcaseDemoViewport = Viewport;
	}

	static void ToggleShowcaseDemo(const TArray<FString>& Args, UWorld* World)
	{
		if (GShowcaseDemoWidget.IsValid())
		{
			RemoveShowcaseDemo();
			return;
		}

		OpenShowcaseDemo(Args, World, ECBLGShowcaseTab::Glass, TEXT("CBLiquidGlass.ShowcaseDemo"));
	}

	static FAutoConsoleCommandWithWorldAndArgs GShowcaseToggleCmd(
		TEXT("CBLiquidGlass.ShowcaseDemo"),
		TEXT("Toggle the unified Liquid Glass component showcase (run during Play)."),
		FConsoleCommandWithWorldAndArgsDelegate::CreateStatic(&ToggleShowcaseDemo));

}

#undef LOCTEXT_NAMESPACE
