#pragma once

#include "Engine/Scripting/Script.h"
#include "Engine/Particles/ParticleEffect.h"

API_CLASS() class GAME_API ParticlesManagement : public Script
{
	DECLARE_SCRIPTING_TYPE(ParticlesManagement);

	ParticleEffect* particleEffectPtr;
	ParticleSystemInstance* instancePtr;

	// [Script]
	API_FUNCTION() void Initialize(ParticleEffect* particleEffectPtr);
	API_FUNCTION() Vector3 GetParticlePosition(int emitterIndex);

private:
	ParticleBuffer* GetParticleBuffer(int emitterIndex);
};
