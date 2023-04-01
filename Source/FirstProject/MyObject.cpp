// Fill out your copyright notice in the Description page of Project Settings.


#include "MyObject.h"


/// <summary>
/// Class constructor
/// </summary>
UMyObject::UMyObject()
{
  myFloat = 0.0f;
}

/// <summary>
/// Dummy Function
/// </summary>
void UMyObject::MyFunction()
{
  UE_LOG(LogTemp, Warning, TEXT("This is our warning text!"));
}
