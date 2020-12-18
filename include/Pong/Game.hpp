#pragma once
#include <Pong/Scenes/SceneManager.hpp>
#include <Pong/Scenes/Scene.hpp>
#include <Pong/Scenes/MainMenuScene.hpp>
#include <Pong/Scenes/PlayScene.hpp>
#include <Pong/Scenes/CreditsScene.hpp>
#include <SFML/Graphics.hpp>

namespace Pong
{
	class Game
	{
	private:
		Scenes::SceneManager m_sceneManager;
		bool m_running;
	public:
		Game(sf::RenderWindow &window);

		void draw();

		void update(float deltaTime);

		void handleEvents(sf::Event& event);

		void stop();

		const bool& isRunning();
	};
}