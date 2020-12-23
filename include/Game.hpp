#pragma once
#include "Scenes/SceneManager.hpp"

namespace Pong
{
	class Game
	{
		Scenes::SceneManager sceneManager;
		sf::Font gameFont;
	public:
		Game();

		void draw(sf::RenderTarget &target);
		void update(const sf::Time& deltaTime);
		void handleEvent(const sf::Event& event);
	};
}