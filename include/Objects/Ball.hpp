#pragma once
#include <SFML/Graphics.hpp>
#include "Objects/Paddle.hpp"

namespace Pong::Objects
{
	class Ball : public sf::CircleShape
	{
		int angle;
		bool reset;
		sf::Clock cooldown;
	public:
		Ball();

		static constexpr int speed = 510;
		void update(const sf::Time& deltaTime, Paddle& paddleOne, Paddle& paddleTwo);
		void resetBall();
	};
}