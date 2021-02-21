// This code was auto-generated. Do not modify it.

#include "Engine/Scripting/BinaryModule.h"
#include "Game.Gen.h"

StaticallyLinkedBinaryModuleInitializer StaticallyLinkedBinaryModuleGame(GetBinaryModuleGame);

extern "C" NativeBinaryModule* GetBinaryModuleGame()
{
    static NativeBinaryModule module("Game", MAssemblyOptions());
    return &module;
}
