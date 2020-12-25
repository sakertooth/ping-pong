#include "Game.hpp"
#include "Objects/Paddle.hpp"

namespace Pong::Objects
{
	Paddle::Paddle(sf::Keyboard::Key upKey, sf::Keyboard::Key downKey) : points(0), upKey(upKey), downKey(downKey)
	{
		setSize(sf::Vector2f(1, 64));
	}

	void Paddle::update(const float deltaTime)
	{
		if (sf::Keyboard::isKeyPressed(upKey) && getPosition().y > 0)
		{
			move(0, -speed * deltaTime);
		}
		
		const auto& view = Game::getInstance().getWindow().getView();
		if (sf::Keyboard::isKeyPressed(downKey) && getPosition().y + getLocalBounds().height < view.getSize().y)
		{
			move(0, speed * deltaTime);
		}
	}

	void Paddle::incrementPoint()
	{
		++points;
	}

	const int& Paddle::getPoints() const
	{
		return points;
	}
}