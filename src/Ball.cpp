#include "Ball.hpp"
#include "Game.hpp"
#include <effolkronium/random.hpp>

namespace Pong
{
	using Random = effolkronium::random_static;
	
	Ball::Ball() : angle(315), speed(500) {}

	void Ball::update(const float deltaTime, const sf::RectangleShape& leftPaddle, sf::Text& leftPaddleScore, const sf::RectangleShape& rightPaddle, sf::Text& rightPaddleScore)
	{
		const auto& window = Game::getInstance().getWindow();

		if (getPosition().y - getRadius() < 0.0f)
		{
			angle = (360 - angle) % 360;
			setPosition(getPosition().x, getRadius() + 0.1f);
			Game::getInstance().getSoundManager().getBeepSound().play();
		}
		else if (getPosition().y + getRadius() > window.getSize().y)
		{
			angle = (360 - angle) % 360;
			setPosition(getPosition().x, window.getSize().y - getRadius() - 0.1f);
			Game::getInstance().getSoundManager().getBeepSound().play();
		}
		else if (getPosition().x - getRadius() < 0.0f)
		{
			angle = 180;
			setPosition(rightPaddle.getPosition().x - rightPaddle.getSize().x / 2 - 10, rightPaddle.getPosition().y);
			rightPaddleScore.setString(std::to_string(std::stoi(rightPaddleScore.getString().toAnsiString()) + 1));
			Game::getInstance().getSoundManager().getPeepSound().play();
		}
		else if (getPosition().x + getRadius() > window.getSize().x)
		{
			angle = 0;
			setPosition(leftPaddle.getPosition().x + leftPaddle.getSize().x / 2 + 10, leftPaddle.getPosition().y);
			leftPaddleScore.setString(std::to_string(std::stoi(leftPaddleScore.getString().toAnsiString()) + 1));
			Game::getInstance().getSoundManager().getPeepSound().play();
		}

		auto rightPaddleDistX = rightPaddle.getPosition().x - rightPaddle.getSize().x / 2 - getPosition().x;
		if (getGlobalBounds().intersects(rightPaddle.getGlobalBounds()) && rightPaddleDistX < getRadius() && rightPaddleDistX > 0.0f)
		{
			angle = static_cast<int>(std::atan2f(Random::get(-0.9f, 0.9f), Random::get(-0.9f, -0.2f)) * 57.2957795f);
			setPosition(getPosition().x - 0.1f, getPosition().y);
			Game::getInstance().getSoundManager().getPlopSound().play();
		}

		auto leftPaddleDistX = getPosition().x - leftPaddle.getPosition().x - leftPaddle.getSize().x / 2;
		if (getGlobalBounds().intersects(leftPaddle.getGlobalBounds()) && leftPaddleDistX < getRadius() && leftPaddleDistX > 0.0f)
		{
			angle = static_cast<int>(std::atan2f(Random::get(-0.9f, 0.9f), Random::get(0.2f, 0.9f)) * 57.2957795f);
			setPosition(getPosition().x + 0.1f, getPosition().y);
			Game::getInstance().getSoundManager().getPlopSound().play();
		}

		move(speed * std::cos(angle * 0.0174532925f) * deltaTime, -speed * std::sin(angle * 0.0174532925f) * deltaTime);
	}

	int Ball::getAngle()
	{
		return angle;
	}

	int Ball::getSpeed()
	{
		return speed;
	}
}