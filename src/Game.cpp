#include "Game.hpp"
#include "States/MainMenuState.hpp"
#include <SFML/Graphics.hpp>

namespace Pong
{
	Game::Game() :
		window(sf::VideoMode(640, 480), "Ping Pong", sf::Style::Titlebar | sf::Style::Close),
		currentState(nullptr),  
		soundManager("assets/sounds/beep.ogg", "assets/sounds/peep.ogg", "assets/sounds/plop.ogg")
	{
		sf::Image icon;
		icon.loadFromFile("assets/icon.png");
		window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	}

	Game::~Game()
	{
		stop();
	}

	void Game::init()
	{
		
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

	void Game::update()
	{
		currentState->update(deltaTime.asSeconds());
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
			}
			currentState->handleEvent(event);
		}
	}
	
	void Game::switchState(const std::shared_ptr<States::State> state)
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

	const sf::Time& Game::getDeltaTime()
	{
		return deltaTime;
	}
	
	sf::RenderWindow& Game::getWindow()
	{
		return window;
	}

	SoundManager& Game::getSoundManager()
	{
		return soundManager;
	}

	void Game::setDeltaTime(const sf::Time& deltaTime)
	{
		this->deltaTime = deltaTime;
	}
}