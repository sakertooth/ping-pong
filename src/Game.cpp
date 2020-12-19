#include <Pong/Game.hpp>
#include <Pong/Scenes/MainMenuScene.hpp>
#include <Pong/Scenes/PlayScene.hpp>
#include <Pong/Scenes/CreditsScene.hpp>

namespace Pong
{
	Game::Game() : m_running(true), m_window(sf::RenderWindow{ sf::VideoMode(640, 480), "Saker's Ping Pong" })
	{
		/*m_sceneManager.addScene("Main Menu", std::make_shared<Scenes::MainMenuScene>());
		m_sceneManager.addScene("Play", std::make_shared<Scenes::PlayScene>());
		m_sceneManager.addScene("Credits", std::make_shared<Scenes::CreditsScene>());*/
	}

	void Game::draw()
	{
		m_sceneManager.getActiveScene()->draw();
	}

	void Game::update(float deltaTime)
	{
		m_sceneManager.getActiveScene()->update(deltaTime);
	}

	void Game::handleEvents(sf::Event& event)
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			stop();
			break;
		default:
			break;
		}
	}

	void Game::stop()
	{
		m_running = false;
	}

	Game& Game::getInstance()
	{
		static Game game;
		return game;
	}

	Scenes::SceneManager& Game::getSceneManager()
	{
		return m_sceneManager;
	}

	sf::RenderWindow& Game::getWindow()
	{
		return m_window;
	}

	const bool& Game::isRunning()
	{
		return m_running;
	}
}