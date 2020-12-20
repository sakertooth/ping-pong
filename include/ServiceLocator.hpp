#pragma once
#include <optional>
#include "Scenes/SceneManager.hpp"
#include "ResourceManager.hpp"

namespace Pong
{
    class ServiceLocator 
    {
        static Scenes::SceneManager* sceneManager;
        static ResourceManager* resourceManager;
    public:
        static void provide(Scenes::SceneManager* sceneManager);
        static void provide(ResourceManager* resourceManager);

        static Scenes::SceneManager* getSceneManager();
        static ResourceManager* getResourceManager();
    };
}
