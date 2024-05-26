// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "MSTypes.generated.h"

/**
 * 
 */

UENUM()
enum class EProductType: uint8{
	Tea,
	Coffee,
	Juice,
	Smoothie,
	Bao,
	Takoyaki,
	Ramen,
	Rice
};
