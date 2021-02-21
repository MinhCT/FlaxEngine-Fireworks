
#pragma once

#include "Engine/Scripting/Script.h"
#include "Engine/Particles/ParticleEffect.h"

API_CLASS() class GAME_API ParticleManagement : public Script
{
DECLARE_SCRIPTING_TYPE(ParticleManagement);

    API_FIELD() float speed = 5;
    ParticleEffect* particleEffect;
    ParticleSystemInstance* instance;
    void* posPointer = nullptr;

    API_FIELD() Vector3 particlePos = { 0, 0, 0 };

    // [Script]
    void OnStart() override;
    void OnEnable() override;
    void OnDisable() override;
    void OnUpdate() override;
    void OnFixedUpdate() override;
    void GetPosition(ParticleEmitterInstance& data);
};
