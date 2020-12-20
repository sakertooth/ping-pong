#include "Scenes.hpp"
#include "Resources.hpp"
#include <iostream>

namespace Pong
{
	namespace Scenes
	{
		const float paddleSpeed = 500;

		PlayScene::PlayScene(SceneWindow& sceneWindow) : 
			started(false),
			sceneWindow(sceneWindow)
		{
			auto yCenter = (sceneWindow.getSize().y - 96) / 2;
			paddleOne.setSize(sf::Vector2f(4, 96));

			paddleOne.setPosition(16, yCenter);

			paddleTwo.setSize(sf::Vector2f(4, 96));
			paddleTwo.setPosition(sceneWindow.getSize().x - 16, yCenter);

			pressSpacebarText.setFont(ResourceManager::getGameFont());
			pressSpacebarText.setString("Press spacebar to start");
			pressSpacebarText.setPosition((sceneWindow.getPosition().x - pressSpacebarText.getPosition().x) / 2, (sceneWindow.getPosition().y - pressSpacebarText.getPosition().y) / 2);
			pressSpacebarText.setCharacterSize(16);
		}

		void PlayScene::draw(sf::RenderTarget& target)
		{
			if (!started)
			{
				target.draw(pressSpacebarText);
				return;
			}

			target.draw(paddleOne);
			target.draw(paddleTwo);
		}

		void PlayScene::update(float deltaTime)
		{
			if (started)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && paddleOne.getPosition().y > 0)
				{
					paddleOne.move(0, -paddleSpeed * deltaTime);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && paddleOne.getPosition().y < sceneWindow.getSize().y - paddleOne.getLocalBounds().height)
				{
					paddleOne.move(0, paddleSpeed * deltaTime);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && paddleTwo.getPosition().y > 0)
				{
					paddleTwo.move(0, -paddleSpeed * deltaTime);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && paddleTwo.getPosition().y < sceneWindow.getSize().y - paddleTwo.getLocalBounds().height)
				{
					paddleTwo.move(0, paddleSpeed * deltaTime);
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !started)
			{
				started = true;
			}
		}

		void PlayScene::handleEvent(sf::Event& event) {}
	}
}