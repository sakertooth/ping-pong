#include "Scenes/SceneWindow.hpp"

namespace Pong
{
	namespace Scenes
	{
		void SceneWindow::draw()
		{
			if (activeScene != nullptr)
			{
				clear();
				activeScene->draw(*this);
				fpsHud.draw(*this);
				display();
			}
		}

		void SceneWindow::update(float deltaTime)
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
					case sf::Event::KeyPressed:
						if (event.key.code == sf::Keyboard::F)
						{
							fpsHud.setToggled(!fpsHud.getToggled());
						}
						break;
					default:
						break;
					}
					activeScene->handleEvent(event);
				}

				activeScene->update(deltaTime);
				fpsHud.update(deltaTime);
			}
		}

		void SceneWindow::addScene(const std::string& id, const std::shared_ptr<Scene>& scene)
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
		
		void SceneWindow::switchScene(const std::string& id)
		{
			activeScene = scenes.at(id);
		}
	}
}