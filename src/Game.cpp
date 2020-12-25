#include "Game.hpp"
#include "States/MainMenuState.hpp"
#include <SFML/Graphics.hpp>

namespace Pong
{
	void Game::init()
	{
		window.create(sf::VideoMode(640, 480), "Ping Pong");

		sf::Image icon;
		icon.loadFromFile("icon.png");
		window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

		currentState = std::make_shared<States::MainMenuState>();
	}

	void Game::stop()
	{
		window.close();
	}

	void Game::draw()
	{
		window.clear();
		currentState->draw(window);
		window.display();
	}

	void Game::update(const float deltaTime)
	{
		currentState->update(deltaTime);
	}

	void Game::handleEvent()
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				stop();
				break;
			case sf::Event::Resized:
				sf::View view;

				auto gameWidth = window.getSize().x;
				auto gameHeight = window.getSize().y;

				view.setSize(gameWidth, gameHeight);
				view.setCenter(gameWidth / 2.0f, gameHeight / 2.0f);
				window.setView(view);
				break;
			}
			currentState->handleEvent(event);
		}
	}

	void Game::swtichState(const std::shared_ptr<States::State> state)
	{
		currentState = state;
	}

	bool Game::isRunning()
	{
		return window.isOpen();
	}

	Game& Game::getInstance()
	{
		static Game game;
		return game;
	}

	sf::RenderWindow& Game::getWindow()
	{
		return window;
	}

	Game::~Game()
	{
		stop();
	}
}