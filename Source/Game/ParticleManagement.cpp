#include "ParticleManagement.h"
#include "Engine/Core/Log.h"

ParticleManagement::ParticleManagement(const SpawnParams& params)
	: Script(params)
{
	// Enable ticking OnUpdate function
	_tickUpdate = true;
}

void ParticleManagement::OnStart()
{
	particleEffect = Cast<ParticleEffect>(GetActor());
	instance = &particleEffect->Instance;
}

void ParticleManagement::OnEnable()
{
}

void ParticleManagement::OnDisable()
{
}

void ParticleManagement::OnUpdate()
{
	if (!instance->Emitters.Get())
		return;
	GetPosition(*instance->Emitters.Get());
}

void ParticleManagement::OnFixedUpdate()
{
}


void ParticleManagement::GetPosition(ParticleEmitterInstance& data)
{
	auto buffer = data.Buffer;
	if (buffer)
	{
		byte* positionPtr = buffer->CPU.Buffer.Get();
		if (positionPtr)
		{
			Vector3 pos = *(Vector3*)positionPtr;
			LOG(Info, "{}", pos);
			Variant variant(pos);
			particleEffect->SetParameterValue(String("Fireworks_Trail"), String("Position"), variant);
			particleEffect->SetParameterValue(String("Fireworks_Sphere"), String("Position"), variant);
			particleEffect->SetParameterValue(String("Fireworks_Inner"), String("Position"), variant);
		}
	}
	else
	{
		buffer = data.Buffer;
	}
}
