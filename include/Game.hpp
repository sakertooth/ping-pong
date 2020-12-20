#pragma once
#include "Scenes/Scene.hpp"
#include "Scenes/SceneWindow.hpp"
#include "Resources.hpp"

namespace Pong
{
	using namespace Scenes;

	class Game
	{
		SceneWindow sceneWindow;
		ResourceManager resourceManager;
	public:
		Game(const sf::VideoMode& mode, const sf::String& title);

		void draw();
		void update(float deltaTime);
		const bool& isRunning() const;
	};
}