#include "Game.hpp"
#include "Resources.hpp"

int main()
{
	auto game = Pong::Game(sf::VideoMode(640, 480), "Ping Pong");

	sf::Clock deltaClock;
	while (game.isRunning())
	{
		game.update(deltaClock.getElapsedTime().asSeconds());
		deltaClock.restart();
		game.draw();
	}
}