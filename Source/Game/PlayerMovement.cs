using FlaxEngine;

namespace Game
{
    public class PlayerMovement : Script
    {
        CharacterController characterController;
        Vector3 velocity;
        ParticleEffect particleEffect;

        public override void OnStart()
        {
            characterController = Actor.As<CharacterController>();
        }

        public override void OnUpdate()
        {
            velocity.Y = 1;
            characterController.Move(velocity * Time.DeltaTime);
        }

        public override void OnFixedUpdate()
        {
            //base.OnFixedUpdate();   

            //velocity.Y = 1;
            //characterController.Move(velocity * Time.DeltaTime);
        }
    }
}
