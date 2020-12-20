#pragma once
#include <SFML/Graphics.hpp>

namespace Pong
{
	class ResourceManager
	{
		inline static sf::Font gameFont;
		inline static bool loadedGameFont;
	public:
		static const sf::Font& getGameFont();
	};
}