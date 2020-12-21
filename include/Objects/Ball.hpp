#pragma once
#include <SFML/Graphics.hpp>
#include "Objects/Paddle.hpp"

namespace Pong
{
	namespace Objects
	{
		class Ball : public sf::CircleShape
		{
		private:
			int angle;

			void resetPositionToCenter();
		public:
			float speed;
			Ball();

			void update(float deltaTime, Paddle& paddleOne, Paddle& paddleTwo);
			void setAngle(int newAngle);

			float getSpeed();
			float getAngle();
		};
	}
}