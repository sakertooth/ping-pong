#include "Game.hpp"
#include "Scenes.hpp"

namespace Pong
{
	Game::Game(const sf::VideoMode& mode, const sf::String& title) : sceneWindow(mode, title)
	{
		sceneWindow.addScene("Main Menu", std::make_shared<Scenes::MainMenuScene>(sceneWindow));
		sceneWindow.addScene("Play", std::make_shared<Scenes::PlayScene>(sceneWindow));
		sceneWindow.addScene("Credits", std::make_shared<Scenes::CreditsScene>(sceneWindow));
	}

	void Game::draw()
	{
		sceneWindow.draw();
	}

	void Game::update(float deltaTime)
	{
		sceneWindow.update(deltaTime);
	}

	const bool& Game::isRunning() const
	{
		return sceneWindow.isOpen();
	}
}