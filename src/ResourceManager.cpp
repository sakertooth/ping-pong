#include "ResourceManager.hpp"

namespace Pong
{
	ResourceManager::ResourceManager()
	{
		gameFont.loadFromFile("bit5x3.ttf");
	}

	const sf::Font& ResourceManager::getGameFont()
	{
		return gameFont;
	}
}