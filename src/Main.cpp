#include "Game.hpp"
#include <iostream>

int main()
{
	auto &game = Pong::Game::getInstance();
	auto deltaClock = sf::Clock::Clock();
	game.init();

	while (game.isRunning())
	{
		game.handleEvent();
		game.update(deltaClock.restart());
		game.draw();
	}
}