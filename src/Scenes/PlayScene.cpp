#include "Scenes.hpp"
#include "ServiceLocator.hpp"
#include <iostream>

namespace Pong
{
	namespace Scenes
	{
		PlayScene::PlayScene() : started(false), over(false),
			paddleOne(sf::Vector2f(16, (ServiceLocator::getSceneManager()->getSize().y - 96) / 2), sf::Keyboard::W, sf::Keyboard::S),
			paddleTwo(sf::Vector2f(ServiceLocator::getSceneManager()->getSize().x - 16, (ServiceLocator::getSceneManager()->getSize().y - 96) / 2), sf::Keyboard::Up, sf::Keyboard::Down)
		{
			auto sceneManager = ServiceLocator::getSceneManager();

			ball.setRadius(3);
			ball.setPosition(sceneManager->getSize().x / 2, sceneManager->getSize().y / 2);

			paddleOneScore.setFont(ServiceLocator::getResourceManager()->getGameFont());
			paddleOneScore.setString(std::to_string(paddleOne.getPoints()));
			paddleOneScore.setCharacterSize(48);
			paddleOneScore.setPosition(static_cast<int>((sceneManager->getSize().x - paddleOneScore.getLocalBounds().width) / 2) - 96, 5);

			paddleTwoScore.setFont(ServiceLocator::getResourceManager()->getGameFont());
			paddleTwoScore.setString(std::to_string(paddleTwo.getPoints()));
			paddleTwoScore.setCharacterSize(48);
			paddleTwoScore.setPosition(static_cast<int>((sceneManager->getSize().x - paddleOneScore.getLocalBounds().width) / 2) + 96, 5);

			separatorLine.setPosition(sceneManager->getSize().x / 2, 0);
			separatorLine.setSize(sf::Vector2f(2, sceneManager->getSize().y));

			noteText.setFont(ServiceLocator::getResourceManager()->getGameFont());
			noteText.setString("Press spacebar to start");
			noteText.setCharacterSize(24);
			noteText.setPosition(static_cast<int>((sceneManager->getSize().x - noteText.getLocalBounds().width) / 2),
				static_cast<int>((sceneManager->getSize().y - noteText.getLocalBounds().height) / 2));
		}

		void PlayScene::draw(sf::RenderTarget& target)
		{
			if (started && !over)
			{
				target.draw(paddleOne);
				target.draw(paddleTwo);

				target.draw(paddleOneScore);
				target.draw(paddleTwoScore);

				target.draw(separatorLine);
				target.draw(ball);
			}
			else if (!started || over)
			{
				target.draw(noteText);
			}
		}

		void PlayScene::update(float deltaTime)
		{
			if (started && !over)
			{
				paddleOne.update(deltaTime);
				paddleTwo.update(deltaTime);
				ball.update(deltaTime, paddleOne, paddleTwo);

				if (std::stoi(paddleOneScore.getString().toAnsiString()) != paddleOne.getPoints())
				{
					paddleOneScore.setString(std::to_string(paddleOne.getPoints()));
				}
				
				if (std::stoi(paddleTwoScore.getString().toAnsiString()) != paddleTwo.getPoints())
				{
					paddleTwoScore.setString(std::to_string(paddleTwo.getPoints()));
				}

				over = paddleOne.getPoints() == 11 || paddleTwo.getPoints() == 11;
				if (paddleOne.getPoints() == 11)
				{
					noteText.setString("Player One has won the game");
				}
				else if (paddleOne.getPoints() == 11)
				{
					noteText.setString("Player Two has won the game");
				}
			}
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
			{
				if (!started && !over)
				{
					noteText.setString("");
					started = true;
				}
				else if (over)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && over)
					{
						auto sceneManager = ServiceLocator::getSceneManager();
						sceneManager->switchScene("Main Menu");
					}
				}
			}
		}

		void PlayScene::handleEvent(sf::Event& event) {}
	}
}