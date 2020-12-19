#pragma once
#include <SFML/Graphics.hpp>
#include <Pong/Scenes/Scene.hpp>
#include <Pong/Scenes/SceneManager.hpp>

namespace Pong
{
	class Game
	{
	private:
		Game::Game();

		Scenes::SceneManager m_sceneManager;
		sf::RenderWindow m_window;
		bool m_running;
	public:
		Game(const Game&) = delete;
		Game& operator=(const Game&) = delete;

		void draw();
		void update(float deltaTime);
		void handleEvents(sf::Event& event);
		void stop();

		static Game& getInstance();
		sf::RenderWindow& getWindow();
		Scenes::SceneManager& getSceneManager();
		const bool& isRunning();
	};
}