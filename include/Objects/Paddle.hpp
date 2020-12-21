#pragma once
#include <SFML/Graphics.hpp>

namespace Pong
{
	namespace Objects
	{
		class Paddle : public sf::RectangleShape
		{
		private:
			int points;
			sf::Keyboard::Key upKey;
			sf::Keyboard::Key downKey;
		public:
			static constexpr float speed = 500;
			Paddle(const sf::Vector2f& startingPosition, sf::Keyboard::Key upKey, sf::Keyboard::Key downKey);
			
			void update(float deltaTime);
			const int& incrementPoint();
			const int& getPoints();
		};
	}
}