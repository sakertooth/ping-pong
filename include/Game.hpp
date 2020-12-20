#pragma once
#include "Scenes/Scene.hpp"
#include "Scenes/SceneManager.hpp"
#include "ResourceManager.hpp"

namespace Pong
{
	using namespace Scenes;

	class Game
	{
		SceneManager sceneManager;
		ResourceManager resourceManager;
	public:
		Game(const sf::VideoMode& mode, const sf::String& title);

		void draw();
		void update(float deltaTime);
		const bool isRunning() const;
	};
}