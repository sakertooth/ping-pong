#include "Game.hpp"
#include <iostream>

int main()
{
	auto& game = Pong::Game::getInstance();
	game.init();

	sf::Clock deltaClock;
	while (game.isRunning())
	{
		game.handleEvent();
		game.draw();
		game.update(deltaClock.getElapsedTime().asSeconds());

		deltaClock.restart();
	}
}