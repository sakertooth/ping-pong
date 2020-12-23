#include "Game.hpp"
#include "ServiceLocator.hpp"

#include <iostream>

int main()
{
	auto window = sf::RenderWindow(sf::VideoMode(640, 480), "Ping Pong");
	Pong::ServiceLocator::provide(&window);

	auto game = Pong::Game();

	sf::Image icon;
	icon.loadFromFile("icon.png");

	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	sf::Clock deltaClock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
			game.handleEvent(event);
		}

		window.clear();
		game.draw(window);
		window.display();

		game.update(deltaClock.getElapsedTime());
		deltaClock.restart();
	}
}