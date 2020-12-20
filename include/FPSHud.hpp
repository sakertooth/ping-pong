#pragma once
#include <SFML/Graphics.hpp>

namespace Pong
{
	class FPSHud : public sf::Text
	{
		sf::Clock clock;
		bool toggled;
	public:
		FPSHud();

		void draw(sf::RenderTarget& target);
		void update(float deltaTime);
		void setToggled(bool toggled);
		const bool& getToggled();
	};
}