#include <Pong/Scenes/SceneManager.hpp>

namespace Pong
{
	namespace Scenes
	{
		void SceneManager::addScene(const std::string& name, const std::shared_ptr<Scene> scene)
		{
			m_scenes.insert(std::make_pair(name, scene));
			if (m_scenes.size() == 1)
			{
				m_activeScene = m_scenes.at(name);
			}
		}

		void SceneManager::switchScene(const std::string& name)
		{
			m_activeScene = m_scenes.at(name);
		}

		std::shared_ptr<Scene> SceneManager::getActiveScene()
		{
			return m_activeScene;
		}
	}
}