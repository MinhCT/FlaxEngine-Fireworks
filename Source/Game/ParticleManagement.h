
#pragma once

#include "Engine/Scripting/Script.h"
#include "Engine/Particles/ParticleEffect.h"

API_CLASS() class GAME_API ParticleManagement : public Script
{
DECLARE_SCRIPTING_TYPE(ParticleManagement);

    ParticleEffect* particleEffect;
    ParticleSystemInstance* instance;

    // [Script]
    void OnStart() override;
    void OnEnable() override;
    void OnDisable() override;
    void OnUpdate() override;
    void GetPosition(ParticleEmitterInstance& data);
};
