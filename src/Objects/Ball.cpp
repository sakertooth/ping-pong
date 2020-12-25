#include "Objects/Ball.hpp"
#include "Objects/Paddle.hpp"
#include "Game.hpp"

#include <random>
#include <iostream>

namespace Pong::Objects
{
	Ball::Ball() : angle(315), speed(470) {
		const auto& view = Game::getInstance().getWindow().getView();

		std::random_device rd;
		std::default_random_engine e1(rd());
		std::uniform_int_distribution<int> uniform_dist(0, view.getSize().x);
		setPosition(uniform_dist(e1), 1);
	}

	void Ball::update(const float deltaTime, Paddle& leftPaddle, Paddle& rightPaddle)
	{
		const auto& view = Game::getInstance().getWindow().getView();

		const auto ballTop = static_cast<int>(getGlobalBounds().top);
		const auto ballBottom = static_cast<int>(ballTop + getGlobalBounds().height);
		const auto ballLeft = static_cast<int>(getGlobalBounds().left);
		const auto ballRight = static_cast<int>(ballLeft + getGlobalBounds().width);

		const auto leftPaddleTop = static_cast<int>(leftPaddle.getGlobalBounds().top);
		const auto leftPaddleBottom = static_cast<int>(leftPaddleTop + leftPaddle.getGlobalBounds().height);
		const auto leftPaddleLeft = static_cast<int>(leftPaddle.getGlobalBounds().left);
		const auto leftPaddleRight = static_cast<int>(leftPaddleLeft + leftPaddle.getGlobalBounds().width);

		const auto rightPaddleTop = static_cast<int>(rightPaddle.getGlobalBounds().top);
		const auto rightPaddleBottom = static_cast<int>(rightPaddleTop + rightPaddle.getGlobalBounds().height);
		const auto rightPaddleLeft = static_cast<int>(rightPaddle.getGlobalBounds().left);
		const auto rightPaddleRight = static_cast<int>(rightPaddleLeft + rightPaddle.getGlobalBounds().width);

		if (ballTop <= 0 || ballBottom >= view.getSize().y)
		{
			angle = 360 - angle;
		}
		
		if (ballLeft <= 0)
		{
			rightPaddle.incrementPoint();
			setPosition(rightPaddleLeft - 5, rightPaddleBottom - ((rightPaddleBottom - rightPaddleTop) / 2));
			angle = 180;
		}
		else if (ballRight >= view.getSize().x)
		{
			leftPaddle.incrementPoint();
			setPosition(leftPaddleRight + 5, leftPaddleBottom - ((leftPaddleBottom - leftPaddleTop) / 2));
			angle = 0;
		}

		if ((ballTop >= rightPaddleTop && ballBottom <= rightPaddleBottom && ballRight == rightPaddleLeft) ||
			(ballTop >= leftPaddleTop && ballBottom <= leftPaddleBottom && ballLeft == leftPaddleRight))
		{
			std::random_device rd;
			std::default_random_engine e1(rd());
			std::uniform_int_distribution<int> uniform_dist(0, 10);

			angle += 90 + uniform_dist(e1);
		}

		move(speed * std::cos(angle * 0.0174532925f) * deltaTime, speed * std::sin(angle * 0.0174532925f) * deltaTime);
	}
}