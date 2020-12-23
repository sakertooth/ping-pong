#pragma once
#include "ServiceLocator.hpp"

namespace Pong
{
	Scenes::SceneManager* ServiceLocator::sceneManager = nullptr;
	sf::RenderWindow* ServiceLocator::renderWindow = nullptr;
	sf::Font* ServiceLocator::gameFont = nullptr;

	void ServiceLocator::provide(Scenes::SceneManager* sceneManager)
	{
		ServiceLocator::sceneManager = sceneManager;
	}

	Scenes::SceneManager* ServiceLocator::getSceneManager()
	{
		return sceneManager;
	}

	void ServiceLocator::provide(sf::RenderWindow* renderWindow)
	{
		ServiceLocator::renderWindow = renderWindow;
	}

	sf::RenderWindow* ServiceLocator::getRenderWindow()
	{
		return renderWindow;
	}

	void ServiceLocator::provide(sf::Font* gameFont)
	{
		ServiceLocator::gameFont = gameFont;
	}

	sf::Font* ServiceLocator::getGameFont()
	{
		return gameFont;
	}
}