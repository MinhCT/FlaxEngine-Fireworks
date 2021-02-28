using FlaxEngine;

namespace Game
{
    public class FireworksScript : Script
    {
        ParticleEffect particleEffect;
        ParticlesManagement particlesManagement;

        public override void OnStart()
        {
            particleEffect = Actor.As<ParticleEffect>();
            particlesManagement = new ParticlesManagement();
            particlesManagement.Initialize(particleEffect);
        }
        
        public override void OnUpdate()
        {
            Vector3 leadPos = particlesManagement.GetParticlePosition(0);
            particleEffect.SetParameterValue("Fireworks_Tail", "Position", leadPos);
            particleEffect.SetParameterValue("Fireworks_Sphere", "Position", leadPos);
            particleEffect.SetParameterValue("Fireworks_Inner", "Position", leadPos);
        }
    }
}
