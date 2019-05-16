// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "CustomShader.h"
#include "Engine.h"
#include "SceneViewExtension.h"

#define LOCTEXT_NAMESPACE "FCustomShaderModule"

class FCSRendererViewExtension : public FSceneViewExtensionBase
{
public:
	FCSRendererViewExtension(const FAutoRegister& AutoRegister)
		: FSceneViewExtensionBase(AutoRegister) {}
	~FCSRendererViewExtension(){}

	virtual void SetupViewFamily(FSceneViewFamily& InViewFamily) {}
	virtual void SetupView(FSceneViewFamily& InViewFamily, FSceneView& InView) {}
	virtual void BeginRenderViewFamily(FSceneViewFamily& InViewFamily) {}
	virtual void PreRenderViewFamily_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneViewFamily& InViewFamily) {}
	virtual void PreRenderView_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneView& InView) {}
	virtual void PostRenderView_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneView& InView)
	{
		UE_LOG(LogTemp, Warning, TEXT("PostRenderView_RenderThread"));
	}
};

void FCustomShaderModule::StartupModule()
{
	FCoreDelegates::OnPostEngineInit.AddRaw(this, &FCustomShaderModule::OnPostEngineInit);
}

void FCustomShaderModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

void FCustomShaderModule::OnPostEngineInit()
{
	CSRendererViewExtension = FSceneViewExtensions::NewExtension<FCSRendererViewExtension>();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCustomShaderModule, CustomShader)