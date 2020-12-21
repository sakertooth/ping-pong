#include "ResourceManager.hpp"

namespace Pong
{
	ResourceManager::ResourceManager()
	{
		gameFont.loadFromFile("bit9x9.ttf");
	}

	const sf::Font& ResourceManager::getGameFont()
	{
		return gameFont;
	}
}