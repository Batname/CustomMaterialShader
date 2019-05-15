// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class CustomMaterialShaderEditorTarget : TargetRules
{
	public CustomMaterialShaderEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "CustomMaterialShader" } );
	}
}
