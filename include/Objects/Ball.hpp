#pragma once
#include <SFML/Graphics.hpp>
#include "Objects/Paddle.hpp"

namespace Pong::Objects
{
	class Ball : public sf::CircleShape
	{
		int angle;
		int speed;
	public:
		Ball();

		void update(const sf::Time& deltaTime, Paddle& paddleOne, Paddle& paddleTwo);
	};
}