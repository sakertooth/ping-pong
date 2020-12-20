#include "Game.hpp"
#include "Scenes.hpp"
#include "ServiceLocator.hpp"

namespace Pong
{
	Game::Game(const sf::VideoMode& mode, const sf::String& title) : sceneManager(mode, title)
	{
		ServiceLocator::provide(&sceneManager);
		ServiceLocator::provide(&resourceManager);

		sceneManager.addScene("Main Menu", std::make_shared<Scenes::MainMenuScene>());
		sceneManager.addScene("Play", std::make_shared<Scenes::PlayScene>());
		sceneManager.addScene("Credits", std::make_shared<Scenes::CreditsScene>());
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