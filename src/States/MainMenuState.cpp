#include "MainMenuState.hpp"
#include "../Game.hpp"
#include <iostream>
#include <cmath>

void MainMenuState::init() {
    const auto& window = Game::getInstance().getWindow();
    const auto xPos = window.getSize().x / 2.0f;
    const auto yPos = window.getSize().y / 2.0f;

    title.setFont(Game::getInstance().getFont());
    title.setCharacterSize(45);
    title.setString("Ping Pong");
    title.setOrigin(std::round(title.getLocalBounds().width / 2.0f), std::round(title.getLocalBounds().height / 2.0f));
    title.setPosition(xPos, yPos - 150.0f);

    onePlayerButton.init();
    onePlayerButton.setText("One Player");
    onePlayerButton.onClick([]() { std::cout << "clicked\n"; });
    onePlayerButton.setPosition(xPos, yPos - 50.0f);

    twoPlayerButton.init();
    twoPlayerButton.setText("Two Player");
    twoPlayerButton.onClick([]() { std::cout << "clicked\n"; });
    twoPlayerButton.setPosition(xPos, yPos);

    exitButton.init();
    exitButton.setText("Exit");
    exitButton.onClick([]() { std::exit(0); });
    exitButton.setPosition(xPos, yPos + 50.0f);
}

void MainMenuState::update(const sf::Time& deltaTime) {
    onePlayerButton.update(deltaTime);
    twoPlayerButton.update(deltaTime);
    exitButton.update(deltaTime);
}

void MainMenuState::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(onePlayerButton, states);
    target.draw(twoPlayerButton, states);
    target.draw(exitButton, states);
    target.draw(title, states);
}