#include "Game.hpp"
#include <iostream>

int main()
{
	auto& game		= Pong::Game::getInstance();
	auto deltaClock	= sf::Clock::Clock();
	game.init();

	while (game.isRunning())
	{
		game.handleEvent();
		game.draw();
		game.setDeltaTime(deltaClock.getElapsedTime());
		game.update();
		deltaClock.restart();
	}
}