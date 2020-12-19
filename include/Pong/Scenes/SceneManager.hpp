#pragma once
#include <Pong/Scenes/Scene.hpp>
#include <unordered_map>

namespace Pong
{
	namespace Scenes
	{
		class SceneManager
		{
			std::unordered_map<std::string, std::shared_ptr<Scene>> m_scenes;
			std::shared_ptr<Scene> m_activeScene;
		public:
			void SceneManager::addScene(const std::string& name, const std::shared_ptr<Scene> scene);

			void switchScene(const std::string &name);

			std::shared_ptr<Scene> getActiveScene();
		};
	}
}