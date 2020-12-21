#include "Objects/Ball.hpp"
#include "ServiceLocator.hpp"

#include <iostream>
#include <iomanip>
namespace Pong
{
	namespace Objects
	{
		Ball::Ball() : speed(400), angle(45) {}

		void Ball::resetPositionToCenter()
		{
			auto sceneManager = ServiceLocator::getSceneManager();
			setPosition(sceneManager->getSize().x / 2, sceneManager->getSize().y / 2);
			speed = 400;
		}

		void Ball::update(float deltaTime, Paddle& paddleOne, Paddle& paddleTwo)
		{
			auto sceneManager = ServiceLocator::getSceneManager();		
			
			//When the ball passes through a paddle
			if (getPosition().x > sceneManager->getSize().x)
			{
				resetPositionToCenter();
				paddleOne.incrementPoint();
				angle = 180 - angle;
			}
			else if (getPosition().x < 0)
			{
				resetPositionToCenter();
				paddleTwo.incrementPoint();
				angle = 180 - angle;
			}

			//When the ball intersects with the first paddle
			auto ballLeftmostX = getGlobalBounds().left;
			auto paddleOneRightmostX = paddleOne.getGlobalBounds().left + paddleOne.getGlobalBounds().width;

			auto ballY = getGlobalBounds().top;
			auto paddleOneTopY = paddleOne.getGlobalBounds().top;
			auto paddleOneBottomY = paddleOne.getGlobalBounds().top + paddleOne.getGlobalBounds().height;

			if (ballY <= paddleOneBottomY && ballY >= paddleOneTopY)
			{
				if (std::abs(ballLeftmostX - paddleOneRightmostX) <= 1.0)
				{
					auto paddleOneMiddleY = paddleOneTopY + (paddleOne.getGlobalBounds().height / 2);
					if (ballY < paddleOneMiddleY || ballY > paddleOneMiddleY)
					{
						angle = 180 - angle;
					}
					else if (std::abs(ballY - paddleOneMiddleY) <= 1.0)
					{
						angle = 0;
					}

					if (speed <= 650)
					{
						speed += 50;
					}
				}
			}

			//When the ball intersects with the second paddle
			auto ballRightmostX = getGlobalBounds().left + getGlobalBounds().width;
			auto paddleTwoLeftmostX = paddleTwo.getGlobalBounds().left;

			auto paddleTwoTopY = paddleTwo.getGlobalBounds().top;
			auto paddleTwoBottomY = paddleTwo.getGlobalBounds().top + paddleTwo.getGlobalBounds().height;

			if (ballY <= paddleTwoBottomY && ballY >= paddleTwoTopY)
			{
				if (std::abs(ballLeftmostX - paddleTwoLeftmostX) < 1.0)
				{
					auto paddleTwoMiddleY = paddleTwoTopY + (paddleTwo.getGlobalBounds().height / 2);
					if (ballY <= paddleTwoMiddleY || ballY >= paddleTwoMiddleY)
					{
						angle = 180 - angle;
					}
					else if (std::abs(ballY - paddleTwoMiddleY) <= 1.0)
					{
						angle = 0;
					}

					if (speed <= 650)
					{
						speed += 50;
					}
				}
			}


			//When the ball hits the up or down part of the screen
			if (getPosition().y < 0 || getPosition().y > sceneManager->getSize().y)
			{
				angle = -angle;
			}

			move(speed * std::cos(angle * 0.0174532925) * deltaTime, speed * std::sin(angle * 0.0174532925) * deltaTime);
		}

		void Ball::setAngle(int newAngle)
		{
			angle = newAngle;
		}

		float Ball::getAngle()
		{
			return angle;
		}

	}
}