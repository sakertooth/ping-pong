#include "Scenes/SceneManager.hpp"
#include "Scenes/MainMenuScene.hpp"
#include "Scenes/TwoPlayerScene.hpp"
#include "ServiceLocator.hpp"

namespace Pong::Scenes
{
	SceneManager::SceneManager()
	{
		ServiceLocator::provide(this);
		addScene(0, std::make_shared<Scenes::MainMenuScene>());
		addScene(2, std::make_shared<Scenes::TwoPlayerScene>());
		switchActiveScene(0);
	}

	void SceneManager::addScene(int id, std::shared_ptr<Scene> scene)
	{
		if (scene == nullptr)
		{
			return;
		}
		scenes[id] = scene;
	}

	void SceneManager::switchActiveScene(int id)
	{
		activeScene = scenes[id];
	}

	std::shared_ptr<Scene> SceneManager::getActiveScene() const
	{
		return activeScene;
	}
}