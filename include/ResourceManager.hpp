#pragma once
#include <SFML/Graphics.hpp>

namespace Pong
{
	class ResourceManager
	{
		sf::Font gameFont;
	public:
		ResourceManager();
		const sf::Font& getGameFont();
	};
}