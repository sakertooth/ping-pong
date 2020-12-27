#pragma once
#include <SFML/Graphics.hpp>

namespace Pong
{
	class Ball : public sf::CircleShape
	{
		int angle;
		int speed;
	public:
		Ball();
		void update(const float deltaTime, const sf::RectangleShape& leftPaddle, sf::Text& leftPaddleScore, const sf::RectangleShape& rightPaddle, sf::Text& rightPaddleScore);
	};
}