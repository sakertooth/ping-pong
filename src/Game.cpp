#include "Game.hpp"
#include "States/MainMenuState.hpp"
#include <SFML/Graphics.hpp>

namespace Pong
{
	Game::Game() : window(sf::VideoMode(640, 480), "Ping Pong", sf::Style::Titlebar | sf::Style::Close),
				   currentState(nullptr)
	{
		gameFont.loadFromFile("assets/font.ttf");

		sf::Image icon;
		icon.loadFromFile("assets/icon.png");
		window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

		registerSound("beep", "assets/sounds/beep.ogg");
		registerSound("peep", "assets/sounds/peep.ogg");
		registerSound("plop", "assets/sounds/plop.ogg");
	}

	Game::~Game()
	{
		stop();
	}

	void Game::init()
	{
		currentState = std::make_shared<MainMenuState>();
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

	void Game::update(const sf::Time& deltaTime)
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
			}
			currentState->handleEvent(event);
		}
	}

	void Game::registerSound(const std::string &id, const std::string &soundFileName)
	{
		sounds.emplace(id, std::make_pair(sf::SoundBuffer(), sf::Sound()));

		auto &[buffer, sound] = sounds.at(id);
		buffer.loadFromFile(soundFileName);
		sound.setBuffer(buffer);
	}

	void Game::switchState(const std::shared_ptr<State> state)
	{
		currentState = state;
	}

	bool Game::isRunning()
	{
		return window.isOpen();
	}

	Game &Game::getInstance()
	{
		static Game game;
		return game;
	}

	const sf::Font &Game::getFont()
	{
		return gameFont;
	}

	sf::RenderWindow &Game::getWindow()
	{
		return window;
	}

	sf::Sound &Game::getSound(const std::string &id)
	{
		return sounds.at(id).second;
	}
}