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
		void update(const float deltaTime, Paddle& leftPaddle, Paddle& rightPaddle);
	};
}