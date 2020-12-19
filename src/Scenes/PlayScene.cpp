#include <Pong/Scenes/PlayScene.hpp>
#include <iostream>

namespace Pong
{
	namespace Scenes
	{
		const float paddleSpeed = 500;

		PlayScene::PlayScene(SceneManager& sceneManager, sf::RenderWindow& window) : 
			tgui::Gui(window), 
			started(false), 
			pressSpacebarLabel(tgui::Label::create("Press spacebar to start"))
		{
			auto yCenter = (window.getSize().y - 96) / 2;
			paddleOne.setSize(sf::Vector2f(4, 96));
			paddleOne.setPosition(16, yCenter);

			paddleTwo.setSize(sf::Vector2f(4, 96));
			paddleTwo.setPosition(window.getSize().x - 16, yCenter);

			pressSpacebarLabel->getRenderer()->setTextColor(tgui::Color::White);
			pressSpacebarLabel->setPosition("(&.size - size) / 2");
			pressSpacebarLabel->setTextSize(16);
			add(pressSpacebarLabel, "SpacebarLabel");
		}

		void PlayScene::draw(sf::RenderTarget &target)
		{
			if (!started)
			{
				tgui::Gui::draw();
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

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && paddleOne.getPosition().y < getTarget()->getSize().y - paddleOne.getLocalBounds().height)
				{
					paddleOne.move(0, paddleSpeed * deltaTime);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && paddleTwo.getPosition().y > 0)
				{
					paddleTwo.move(0, -paddleSpeed * deltaTime);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && paddleTwo.getPosition().y < getTarget()->getSize().y - paddleTwo.getLocalBounds().height)
				{
					paddleTwo.move(0, paddleSpeed * deltaTime);
				}

				return;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
			{
				started = true;
			}
		}

		void PlayScene::handleEvent(sf::Event& event) {}
	}
}