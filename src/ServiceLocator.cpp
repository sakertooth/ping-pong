#include "ServiceLocator.hpp"

namespace Pong
{
	Scenes::SceneManager* ServiceLocator::sceneManager = NULL;
	ResourceManager* ServiceLocator::resourceManager = NULL;

	void ServiceLocator::provide(Scenes::SceneManager* sceneManager)
	{
		ServiceLocator::sceneManager = sceneManager;
	}

	void ServiceLocator::provide(ResourceManager* resourceManager)
	{
		ServiceLocator::resourceManager = resourceManager;
	}

	Scenes::SceneManager* ServiceLocator::getSceneManager()
	{
		return sceneManager;
	}

	ResourceManager* ServiceLocator::getResourceManager()
	{
		return resourceManager;
	}
}