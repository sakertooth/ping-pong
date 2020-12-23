#include "Objects/Ball.hpp"
#include "ServiceLocator.hpp"

#include <iostream>
#include <random>

namespace Pong::Objects
{
	Ball::Ball() : angle(45), reset(false)
	{

	}

	void Ball::update(const sf::Time& deltaTime, Paddle& paddleOne, Paddle& paddleTwo)
	{
		auto window = ServiceLocator::getRenderWindow();

		if (!reset)
		{
			auto ballTopY = getGlobalBounds().top;
			auto ballBottomY = ballTopY + getGlobalBounds().height;

			//Window Boundaries
			if (ballTopY < 0 || ballBottomY > static_cast<int>(window->getSize().y))
			{
				angle = -angle;
			}

			//Paddle One
			auto ballLeftX = static_cast<int>(getGlobalBounds().left);
			auto paddleOneRightX = static_cast<int>(paddleOne.getGlobalBounds().left + paddleOne.getGlobalBounds().width);

			auto paddleOneTopY = paddleOne.getGlobalBounds().top;
			auto paddleOneBottomY = paddleOneTopY + paddleOne.getGlobalBounds().height;

			if (ballBottomY < paddleOneBottomY && ballTopY > paddleOneTopY && ballLeftX == paddleOneRightX)
			{
				angle = 180 - angle;
			}

			//Paddle Two
			auto ballRightX = static_cast<int>(ballLeftX + getGlobalBounds().width);
			auto paddleTwoLeftX = static_cast<int>(paddleTwo.getGlobalBounds().left);

			auto paddleTwoTopY = paddleTwo.getGlobalBounds().top;
			auto paddleTwoBottomY = paddleTwoTopY + paddleTwo.getGlobalBounds().height;

			if (ballBottomY < paddleTwoBottomY && ballTopY > paddleTwoTopY && ballRightX == paddleTwoLeftX + paddleTwo.getGlobalBounds().width)
			{
				angle = 180 - angle;
			}

			//If it goes beyond any of the two paddles
			if (ballLeftX < 0)
			{
				paddleTwo.incrementPoint();
				resetBall();
			}
			else if (ballRightX > static_cast<int>(window->getSize().x))
			{
				paddleOne.incrementPoint();
				resetBall();
			}

			auto deltaTimeSeconds = deltaTime.asSeconds();
			move(speed * std::cos(angle * 0.0174532925f) * deltaTimeSeconds, speed * std::sin(angle * 0.0174532925f) * deltaTimeSeconds);
		}
		else
		{
			if (cooldown.getElapsedTime().asSeconds() >= 3)
			{
				setPosition(window->getSize().x / 2, window->getSize().y / 2);
				setFillColor(sf::Color::White);
				reset = false;
			}
		}
	}

	void Ball::resetBall()
	{
		auto window = ServiceLocator::getRenderWindow();

		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_int_distribution<int> uni(0, window->getSize().y);
		setFillColor(sf::Color::Black);
		setPosition(window->getSize().x / 2, uni(rng));
		cooldown.restart();
		reset = true;
	}
}