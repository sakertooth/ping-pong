#include "Game.hpp"
#include "States/MainMenuState.hpp"

Game::Game() {
    window.create(sf::VideoMode(640, 480), "Ping Pong", sf::Style::Titlebar | sf::Style::Close);
    currentState = std::make_shared<MainMenuState>();
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

const sf::RenderWindow& Game::getWindow() {
    return window;
}

void Game::switchState(std::shared_ptr<State> newState) {
    currentState = newState;
}