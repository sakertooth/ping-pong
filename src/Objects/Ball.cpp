#include "Objects/Ball.hpp"
#include "ServiceLocator.hpp"

#include <iostream>
#include <random>

namespace Pong::Objects
{
	Ball::Ball() : angle(45), speed(440) {
		auto window = ServiceLocator::getRenderWindow();

		std::random_device rd;
		std::default_random_engine e1(rd());
		std::uniform_int_distribution<int> uniform_dist(0, window->getSize().x);
		setPosition(uniform_dist(e1), 1);
	}

	void Ball::update(const sf::Time& deltaTime, Paddle& leftPaddle, Paddle& rightPaddle)
	{
		auto window = ServiceLocator::getRenderWindow();
		auto windowX = static_cast<int>(window->getSize().x);
		auto windowY = static_cast<int>(window->getSize().y);

		auto ballLeft = static_cast<int>(getGlobalBounds().left);
		auto ballRight = static_cast<int>(ballLeft + getGlobalBounds().width);
		auto ballTop = static_cast<int>(getGlobalBounds().top);
		auto ballBottom = static_cast<int>(ballTop + getGlobalBounds().height);

		auto leftPaddleLeft = static_cast<int>(leftPaddle.getGlobalBounds().left);
		auto leftPaddleRight = static_cast<int>(leftPaddleLeft + leftPaddle.getGlobalBounds().width);
		auto leftPaddleTop = static_cast<int>(leftPaddle.getGlobalBounds().top);
		auto leftPaddleBottom = static_cast<int>(leftPaddleTop + leftPaddle.getGlobalBounds().height);

		auto rightPaddleLeft = static_cast<int>(rightPaddle.getGlobalBounds().left);
		auto rightPaddleRight = static_cast<int>(rightPaddleLeft + rightPaddle.getGlobalBounds().width);
		auto rightPaddleTop = static_cast<int>(rightPaddle.getGlobalBounds().top);
		auto rightPaddleBottom = static_cast<int>(rightPaddleTop + rightPaddle.getGlobalBounds().height);

		if (ballTop < 0 || ballBottom > windowY)
		{
			angle = 360 - angle;
		}

		if (ballLeft < 0)
		{
			rightPaddle.incrementPoint();
			setPosition(rightPaddle.getPosition().x - 16, rightPaddleBottom - (rightPaddle.getGlobalBounds().height / 2));
			angle = 180;
			speed = 440;
		}
		else if (ballRight > windowX)
		{
			leftPaddle.incrementPoint();
			setPosition(leftPaddle.getPosition().x + 16, leftPaddleBottom - (leftPaddle.getGlobalBounds().height / 2));
			angle = 0;
			speed = 440;
		}

		if ((ballBottom <= rightPaddleBottom && ballTop >= rightPaddleTop && ballRight == rightPaddleLeft) ||
			(ballBottom <= leftPaddleBottom && ballTop >= leftPaddleTop && ballLeft == leftPaddleRight))
		{
			std::random_device rd;
			std::default_random_engine e1(rd());
			std::uniform_int_distribution<int> uniform_dist(0, 45);
			
			auto angleVariability = uniform_dist(e1);
			angle = (angle + angleVariability + 90) % 360;
			speed += 2;
		}

		auto deltaTimeSeconds = deltaTime.asSeconds();
		move(speed * std::cos(angle * 0.0174532925f) * deltaTimeSeconds, speed * std::sin(angle * 0.0174532925f) * deltaTimeSeconds);
	}
}