#pragma once
#include <SFML/Graphics.hpp>

namespace Pong
{
	namespace Scenes
	{
		class Scene
		{
		public:
			virtual void draw(sf::RenderTarget& target) = 0;
			virtual void update(float deltaTime) = 0;
			virtual void handleEvent(sf::Event& event) = 0;
		};
	}
}