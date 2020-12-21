#include "Objects/Paddle.hpp"
#include "ServiceLocator.hpp"

namespace Pong
{
	namespace Objects
	{
		Paddle::Paddle(const sf::Vector2f& startingPosition, sf::Keyboard::Key upKey, sf::Keyboard::Key downKey) : upKey(upKey), downKey(downKey), points(0)
		{
			setPosition(startingPosition);
			setSize(sf::Vector2f(4, 48));
		}

		void Paddle::update(float deltaTime)
		{
			if (sf::Keyboard::isKeyPressed(upKey) && getPosition().y > 0)
			{
				move(0, -Paddle::speed * deltaTime);
			}

			auto sceneManger = ServiceLocator::getSceneManager();
			if (sf::Keyboard::isKeyPressed(downKey) && getPosition().y < sceneManger->getSize().y - getLocalBounds().height)
			{
				move(0, Paddle::speed * deltaTime);
			}
		}

		const int& Paddle::incrementPoint()
		{
			return ++points;
		}

		const int& Paddle::getPoints()
		{
			return points;
		}
	}
}