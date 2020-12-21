#include "Game.hpp"
#include "Scenes.hpp"
#include "ServiceLocator.hpp"

namespace Pong
{
	Game::Game(const sf::VideoMode& mode, const sf::String& title) : sceneManager(mode, title, sf::Style::Titlebar | sf::Style::Close)
	{
		ServiceLocator::provide(&sceneManager);
		ServiceLocator::provide(&resourceManager);

		sceneManager.addScene("Main Menu", std::make_shared<Scenes::MainMenuScene>());
		sceneManager.addScene("Play", std::make_shared<Scenes::PlayScene>());
	}

	void Game::draw()
	{
		sceneManager.draw();
	}

	void Game::update(float deltaTime)
	{
		sceneManager.update(deltaTime);
	}

	const bool Game::isRunning() const
	{
		return sceneManager.isOpen();
	}
}