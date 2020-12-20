#include "Scenes/SceneManager.hpp"

#include <iostream>
namespace Pong
{
	namespace Scenes
	{
		void SceneManager::draw()
		{
			if (activeScene != nullptr)
			{
				clear();
				activeScene->draw(*this);
				display();
			}
		}

		void SceneManager::update(float deltaTime)
		{
			if (activeScene != nullptr)
			{
				sf::Event event;
				while (pollEvent(event))
				{
					switch (event.type)
					{
					case sf::Event::Closed:
						close();
						break;
					default:
						break;
					}
					activeScene->handleEvent(event);
				}
				activeScene->update(deltaTime);
			}
		}

		void SceneManager::addScene(const std::string& id, const std::shared_ptr<Scene>& scene)
		{
			if (scene != nullptr)
			{
				if (scenes.empty())
				{
					activeScene = scene;
				}
				scenes[id] = scene;
			}

		}

		void SceneManager::switchScene(const std::string& id)
		{
			activeScene = scenes.at(id);
		}
	}
}