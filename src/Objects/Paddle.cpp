#include "Objects/Paddle.hpp"
#include "ServiceLocator.hpp"

namespace Pong::Objects
{
	Paddle::Paddle(sf::Keyboard::Key upKey, sf::Keyboard::Key downKey) : points(0), upKey(upKey), downKey(downKey)
	{
		setSize(sf::Vector2f(4, 32));
	}

	void Paddle::update(const sf::Time& deltaTime)
	{
		auto window = ServiceLocator::getRenderWindow();
		if (sf::Keyboard::isKeyPressed(upKey) && getPosition().y > 0)
		{
			move(0, -speed * deltaTime.asSeconds());
		}
		
		if (sf::Keyboard::isKeyPressed(downKey) && getPosition().y + getLocalBounds().height < window->getSize().y)
		{
			move(0, speed * deltaTime.asSeconds());
		}
	}

	const int& Paddle::incrementPoint()
	{
		return ++points;
	}

	const int& Paddle::getPoints() const
	{
		return points;
	}
}