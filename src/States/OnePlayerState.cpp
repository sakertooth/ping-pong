#include "States/OnePlayerState.hpp"
#include "States/GameOverState.hpp"
#include "Game.hpp"
#include "random.hpp"

namespace Pong
{
	using Random = effolkronium::random_static;

	OnePlayerState::OnePlayerState(const Difficulty &difficulty) : TwoPlayerState(),
																   difficulty(difficulty),
																   probabilityOfHit(0.0f),
																   willHit(false),
																   willHitCalculated(false)
	{
		switch (difficulty)
		{
		case Difficulty::Easy:
			probabilityOfHit = 0.3f;
			break;
		case Difficulty::Medium:
			probabilityOfHit = 0.6f;
			break;
		case Difficulty::Hard:
			probabilityOfHit = 0.9f;
			break;
		}
	}

	void OnePlayerState::draw(sf::RenderTarget &target)
	{
		TwoPlayerState::draw(target);
	}

	void OnePlayerState::update(const float deltaTime)
	{
		const auto &window = Game::getInstance().getWindow();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && leftPaddle.getPosition().y - leftPaddle.getLocalBounds().height / 2 > 0.0f)
			leftPaddle.move(0.0f, -paddleSpeed * deltaTime);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && leftPaddle.getPosition().y + leftPaddle.getLocalBounds().height / 2 < window.getSize().y)
			leftPaddle.move(0.0f, paddleSpeed * deltaTime);

		if (rightPaddleScore.getString().toAnsiString() == "11")
			Game::getInstance().switchState(std::make_shared<GameOverState>("Player two has won! Press space to go to the main menu."));
		else if (leftPaddleScore.getString().toAnsiString() == "11")
			Game::getInstance().switchState(std::make_shared<GameOverState>("Player one has won! Press space to go to the main menu."));

		updateAI(deltaTime);
		ball.update(deltaTime, leftPaddle, leftPaddleScore, rightPaddle, rightPaddleScore);
	}

	void OnePlayerState::updateAI(const float deltaTime)
	{
		const auto &window = Game::getInstance().getWindow();

		if (std::cosf(ball.getAngle() * 0.0174532925f) > 0.0f)
		{
			if (!willHitCalculated)
			{
				willHit = Random::get<bool>(probabilityOfHit);
				willHitCalculated = true;
				return;
			}
			else if (willHit)
			{
				if (ball.getPosition().y + ball.getRadius() > rightPaddle.getPosition().y + rightPaddle.getGlobalBounds().height / 2)
					rightPaddle.move(0.0f, paddleSpeed * deltaTime);
				else if (ball.getPosition().y - ball.getRadius() < rightPaddle.getPosition().y - rightPaddle.getGlobalBounds().height / 2)
					rightPaddle.move(0.0f, -paddleSpeed * deltaTime);
			}
			else
			{
				const auto ballVelY = ball.getSpeed() * std::sin(ball.getAngle() * 0.0174532925f);
				if (ballVelY > 0.0f && rightPaddle.getPosition().y - rightPaddle.getGlobalBounds().height / 2 > 0.0f)
				{
					rightPaddle.move(0.0f, -paddleSpeed * deltaTime);
				}
				else if (ballVelY < 0.0f && rightPaddle.getPosition().y + rightPaddle.getGlobalBounds().height / 2 < window.getSize().y)
				{
					rightPaddle.move(0.0f, paddleSpeed * deltaTime);
				}
				else if (static_cast<int>(ballVelY) == 0)
				{
					willHit = true;
				}
			}

			auto rightPaddleDistX = rightPaddle.getPosition().x - rightPaddle.getSize().x / 2 - ball.getPosition().x;
			if (ball.getGlobalBounds().intersects(rightPaddle.getGlobalBounds()) && rightPaddleDistX < ball.getRadius() && rightPaddleDistX > 0.0f)
			{
				willHit = false;
				willHitCalculated = false;
			}
		}
	}
}