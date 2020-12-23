#pragma once
#include "Scenes/SceneManager.hpp"

namespace Pong
{
	class ServiceLocator
	{
		static Scenes::SceneManager* sceneManager;
		static sf::RenderWindow* renderWindow;
		static sf::Font* gameFont;
	public:
		static void provide(Scenes::SceneManager* sceneManager);
		static Scenes::SceneManager* getSceneManager();

		static void provide(sf::RenderWindow* renderWindow);
		static sf::RenderWindow* getRenderWindow();

		static void provide(sf::Font* gameFont);
		static sf::Font* getGameFont();
	};
}