#include "Game.hpp"
#include "Updatable.hpp"
#include <iostream>

Game::Game() {
    window.create(sf::VideoMode(640, 480), "Ping Pong", sf::Style::Titlebar | sf::Style::Close);
    if (!font.loadFromFile("assets/font.ttf")) {
        std::cout << "Game font could not be loaded.\n";
        return;
    }    
}

Game::~Game() {
    stop();
}

Game& Game::getInstance() {
    static Game instance;
    return instance;
}

void Game::handleEvent() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                stop();
            default:
                break;
        }
    }
}

void Game::update(const sf::Time& deltaTime) {
    if (states.size() > 0) {
        auto& currentState = states.top();
        currentState->update(deltaTime);
    }
}

void Game::draw() {
    window.clear(sf::Color::Black);
    if (states.size() > 0) {
        auto& currentState = states.top();
        window.draw(*currentState);
    }
    window.display();
}

void Game::stop() {
    window.close();
}

void Game::pushState(std::unique_ptr<Updatable> state) {
    states.push(std::move(state));
}

void Game::popState() {
    states.pop();
}

const bool Game::isRunning() {
    return window.isOpen();
}

const sf::RenderWindow& Game::getWindow() {
    return window;
}

const sf::Font& Game::getFont() {
    return font;
}