#include "Game.hpp"
#include "States/MainMenuState.hpp"
#include <iostream>

Game::Game() {
    window.create(sf::VideoMode(640, 480), "Ping Pong", sf::Style::Titlebar | sf::Style::Close);
    if (!font.loadFromFile("assets/font.ttf")) {
        std::cout << "Game font could not be loaded.\n";
    }
    
    currentState = std::make_shared<MainMenuState>();
}

void Game::init() {
    currentState->init();
}

Game::~Game() {
    stop();
}

Game& Game::getInstance() {
    static Game instance;
    return instance;
}

void Game::update(const sf::Time& deltaTime) {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                stop();
            default:
                break;
        }
    }
    
    currentState->update(deltaTime);
}

void Game::draw() {
    window.clear(sf::Color::Black);
    window.draw(*currentState);
    window.display();
}

void Game::stop() {
    window.close();
}

const bool Game::isRunning() {
    return window.isOpen();
}

void Game::switchState(std::shared_ptr<State> newState) {
    currentState = newState;
}

sf::RenderWindow& Game::getWindow() {
    return window;
}

const sf::Font& Game::getFont() {
    return font;
}