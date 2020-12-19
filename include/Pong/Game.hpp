#pragma once
#include <SFML/Graphics.hpp>
#include <Pong/Scenes/Scene.hpp>
#include <Pong/Scenes/SceneManager.hpp>

namespace Pong
{
	class Game
	{
	private:
		sf::RenderWindow window;
		sf::Clock deltaClock;
		Scenes::SceneManager sceneManager;
	public:
		Game();

		void run();
		void stop();
		void draw(sf::RenderTarget& target);
		void update(float deltaTime);
		
		const sf::RenderWindow& getWindow();
		const Scenes::SceneManager& getSceneManager();
		const bool& isRunning();
	};
}