#pragma once
#include "Game.hpp"
#include <effolkronium/random.hpp>

namespace Pong::Objects
{
	using Random = effolkronium::random_static;

	Ball::Ball() : angle(45), speed(450)
	{
		const auto& view = Game::getInstance().getWindow().getView();
		setRadius(4);
		setPosition(0, 0);
	}

	void Ball::update(const float deltaTime, Paddle& leftPaddle, Paddle& rightPaddle)
	{
		const auto& view = Game::getInstance().getWindow();

		const auto ballLeft = getGlobalBounds().left;
		const auto ballRight = ballLeft + getGlobalBounds().width;
		const auto ballTop = getGlobalBounds().top;
		const auto ballBottom = ballTop + getGlobalBounds().height;

		const auto leftPaddleLeft = leftPaddle.getGlobalBounds().left;
		const auto leftPaddleRight = leftPaddleLeft + leftPaddle.getGlobalBounds().width;
		const auto leftPaddleTop = leftPaddle.getGlobalBounds().top;
		const auto leftPaddleBottom = leftPaddleTop + leftPaddle.getGlobalBounds().height;

		const auto rightPaddleLeft = rightPaddle.getGlobalBounds().left;
		const auto rightPaddleRight = rightPaddleLeft + rightPaddle.getGlobalBounds().width;
		const auto rightPaddleTop = rightPaddle.getGlobalBounds().top;
		const auto rightPaddleBottom = rightPaddleTop + rightPaddle.getGlobalBounds().height;

		if (ballTop < 0 || ballBottom > view.getSize().y)
		{
			angle = 360 - angle;
			Game::getInstance().getSoundManager().getBeepSound().play();
		}
		
		if (ballLeft < 0)
		{
			rightPaddle.incrementPoint();
			angle = 180;
			speed = 440;
			setPosition(rightPaddleLeft - 10, rightPaddleBottom - ((rightPaddleBottom - rightPaddleTop) / 2));
			Game::getInstance().getSoundManager().getPeepSound().play();
		}
		
		if (ballRight > view.getSize().x)
		{
			leftPaddle.incrementPoint();
			angle = 0;
			speed = 440;
			setPosition(leftPaddleRight + 10, leftPaddleBottom - ((leftPaddleBottom - leftPaddleTop) / 2));
			Game::getInstance().getSoundManager().getPeepSound().play();
		}
		
		if (leftPaddle.getGlobalBounds().contains(ballLeft, ballTop) || leftPaddle.getGlobalBounds().contains(ballLeft, ballBottom) || 
			(rightPaddle.getGlobalBounds().contains(ballRight, ballTop) || rightPaddle.getGlobalBounds().contains(ballRight, ballBottom)))
		{
			angle = 180 - angle;
			Game::getInstance().getSoundManager().getPlopSound().play();
		}

		move(speed * std::cos(angle * 0.0174532925f) * deltaTime, speed * std::sin(angle * 0.0174532925f) * deltaTime);
	}
	
}