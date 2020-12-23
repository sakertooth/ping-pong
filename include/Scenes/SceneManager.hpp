#pragma once
#include "Scenes/Scene.hpp"
#include <unordered_map>

namespace Pong::Scenes
{
	class SceneManager
	{
		std::unordered_map<int, std::shared_ptr<Scene>> scenes;
		std::shared_ptr<Scene> activeScene;
	public:
		SceneManager();

		void addScene(int id, std::shared_ptr<Scene> scene);
		void switchActiveScene(int id);
		std::shared_ptr<Scene> getActiveScene() const;
	};
}