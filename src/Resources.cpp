#pragma once
#include "Resources.hpp"

namespace Pong
{
	const sf::Font& ResourceManager::getGameFont()
	{
		if (!loadedGameFont)
		{
			gameFont.loadFromFile("bit5x3.ttf");
			loadedGameFont = true;
		}
		return gameFont;
	}

}