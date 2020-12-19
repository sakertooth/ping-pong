#include <Pong/Game.hpp>
#include <Pong/Scenes/MainMenuScene.hpp>
#include <Pong/Scenes/PlayScene.hpp>
#include <Pong/Scenes/CreditsScene.hpp>

namespace Pong
{
	Game::Game() : window(sf::RenderWindow(sf::VideoMode(640, 480), "Saker's Ping Pong"))
	{
		sceneManager.addScene("Main Menu", std::make_shared<Scenes::MainMenuScene>(sceneManager, window));
		sceneManager.addScene("Play", std::make_shared<Scenes::PlayScene>(sceneManager, window));
		sceneManager.addScene("Credits", std::make_shared<Scenes::CreditsScene>(sceneManager, window));
	}

	void Game::run()
	{
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
					return;
				}
				sceneManager.getActiveScene()->handleEvent(event);
			}

			window.clear();
			draw(window);
			window.display();

			update(deltaClock.getElapsedTime().asSeconds());
			deltaClock.restart();
		}
	}

	void Game::stop()
	{
		window.close();
	}

	void Game::draw(sf::RenderTarget &target)
	{
		sceneManager.getActiveScene()->draw(target);
	}

	void Game::update(float deltaTime)
	{
		sceneManager.getActiveScene()->update(deltaTime);
	}

	const sf::RenderWindow& Game::getWindow()
	{
		return window;
	}

	const Scenes::SceneManager& Game::getSceneManager()
	{
		return sceneManager;
	}

	const bool& Game::isRunning()
	{
		return window.isOpen();
	}
}