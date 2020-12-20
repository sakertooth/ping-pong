#include "Game.hpp"

int main()
{
	auto game = Pong::Game(sf::VideoMode(640, 480), "Ping Pong");

	sf::Clock deltaClock;
	while (game.isRunning())
	{
		deltaClock.restart();
		game.draw();
		game.update(deltaClock.getElapsedTime().asSeconds());
	}
}