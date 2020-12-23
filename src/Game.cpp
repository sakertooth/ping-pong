#include "Game.hpp"
#include "ServiceLocator.hpp"
#include "Scenes/MainMenuScene.hpp"

namespace Pong
{
	Game::Game()
	{
		ServiceLocator::provide(&gameFont);
		gameFont.loadFromFile("pong.ttf");
	}

	void Game::draw(sf::RenderTarget &target)
	{
		sceneManager.getActiveScene()->draw(target);
	}

	void Game::update(const sf::Time& deltaTime)
	{
		sceneManager.getActiveScene()->update(deltaTime);
	}

	void Game::handleEvent(const sf::Event& event)
	{
		sceneManager.getActiveScene()->handleEvent(event);
	}
}