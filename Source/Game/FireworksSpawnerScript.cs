using FlaxEngine;
using System;

namespace Game
{
    public class FireworksSpawnerScript : Script
    {
        public Prefab FireworkPrefab;
        public Color[] Colors;

        Random random;

        public override void OnStart()
        {
            random = new Random();
            if (!FireworkPrefab)
            {
                Debug.LogWarning("Fireworks prefab has not been defined!");
            }
        }

        public override void OnUpdate()
        {
            if (Input.GetAction("Space"))
            {
                Actor spawn = PrefabManager.SpawnPrefab(FireworkPrefab, Camera.MainCamera.Position);
                ParticleEffect fireworkFX = spawn.As<ParticleEffect>();

                Color selectedColor = Colors[random.Next(0, Colors.Length)];
                fireworkFX.SetParameterValue("Fireworks_Sphere", "Fireworks Color", selectedColor);
                fireworkFX.SetParameterValue("Fireworks_Inner", "Fireworks Color", selectedColor);

                Destroy(spawn, 12);
            }
        }
    }
}
