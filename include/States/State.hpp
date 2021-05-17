#pragma once
#include <SFML/Graphics.hpp>

namespace Pong
{
	class State
	{
	public:
		virtual void draw(sf::RenderTarget &target) = 0;
		virtual void update(const sf::Time& deltaTime) = 0;
		virtual void handleEvent(const sf::Event &event) = 0;
	};
}