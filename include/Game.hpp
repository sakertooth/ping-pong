#pragma once
#include "Scenes/SceneManager.hpp"

namespace Pong
{
	class Game
	{
		Scenes::SceneManager sceneManager;
	public:
		void draw(sf::RenderTarget &target);
		void update(const sf::Time& deltaTime);
		void handleEvent(const sf::Event& event);
	};
}