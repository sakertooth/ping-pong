#include <Pong/Game.hpp>

namespace Pong
{

	Game::Game(sf::RenderWindow& window) :
		m_running(true)
	{
		m_sceneManager.addScene("MainMenu", std::make_shared<Scenes::MainMenuScene>(m_sceneManager, window));
		m_sceneManager.addScene("Play", std::make_shared<Scenes::PlayScene>(m_sceneManager, window));
		m_sceneManager.addScene("Credits", std::make_shared<Scenes::CreditsScene>(m_sceneManager, window));
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
		}
		m_sceneManager.getActiveScene()->handleEvent(event);
	}
	
	void Game::stop()
	{
		m_running = false;
	}

	const bool& Game::isRunning()
	{
		return m_running;
	}
}