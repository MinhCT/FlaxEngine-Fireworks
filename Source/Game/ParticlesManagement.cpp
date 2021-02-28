#include "ParticlesManagement.h"
#include "Engine/Core/Log.h"

ParticlesManagement::ParticlesManagement(const SpawnParams& params)
	: Script(params)
{
	// Enable ticking OnUpdate function
	_tickUpdate = true;
}

void ParticlesManagement::Initialize(ParticleEffect* particleEffectPtr)
{
	if (!particleEffectPtr)
	{
		LOG(Warning, "Method does not accept NULL Particle Effect pointer!");
		return;
	}

	this->particleEffectPtr = particleEffectPtr;
	instancePtr = &particleEffectPtr->Instance;

	if (!instancePtr)
	{
		LOG(Warning, "No Particle System instance found within the Actor!");
	}
}

Vector3 ParticlesManagement::GetParticlePosition(int emitterIndex)
{
	auto buffer = GetParticleBuffer(emitterIndex);
	if (buffer)
	{
		byte* positionPtr = buffer->CPU.Buffer.Get();
		if (positionPtr)
		{
			Vector3 pos = *(Vector3*)positionPtr;
			return pos;
		}
	}
	
	return Vector3().Zero;
}

ParticleBuffer* ParticlesManagement::GetParticleBuffer(int emitterIndex)
{
	if (instancePtr->Emitters.IsEmpty())
	{
		return nullptr;
	}
	ParticleEmitterInstance& data = instancePtr->Emitters[emitterIndex];
	return data.Buffer;
}

