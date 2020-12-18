#include <Pong/Game.hpp>

int main()
{
	sf::RenderWindow window{ sf::VideoMode(640, 480), "Saker's Ping Pong" };
	Pong::Game game{ window };

	sf::Clock deltaClock;
	while (game.isRunning())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			game.handleEvents(event);
		}

		window.clear();
		game.draw();
		window.display();

		game.update(deltaClock.getElapsedTime().asSeconds());
		deltaClock.restart();
	}

	window.close();
}