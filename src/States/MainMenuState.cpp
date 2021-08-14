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
    exitButton.onClick([]() { Game::getInstance().stop(); });
    exitButton.setPosition(xPos, yPos + 50.0f);

    backgroundPaddleLeft.setSize({5, 75});
    backgroundPaddleLeft.setOrigin(backgroundPaddleLeft.getLocalBounds().width / 2.0f, backgroundPaddleLeft.getLocalBounds().height / 2.0f);
    backgroundPaddleLeft.setPosition(15, yPos);
    backgroundPaddleLeft.setFillColor(sf::Color::White);

    backgroundPaddleRight.setSize(backgroundPaddleLeft.getSize());
    backgroundPaddleRight.setOrigin(backgroundPaddleLeft.getOrigin());
    backgroundPaddleRight.setPosition(window.getSize().x - 15.0f, yPos);
    backgroundPaddleRight.setFillColor(sf::Color::White);
    
    if (!music.openFromFile("assets/artblock.ogg")) {
        std::cout << "could not load assets/artblock.ogg";
        Game::getInstance().stop();
    }

    music.play();
}

void MainMenuState::update(const sf::Time& deltaTime) {
    onePlayerButton.update(deltaTime);
    twoPlayerButton.update(deltaTime);
    exitButton.update(deltaTime);
    
    const auto &window = Game::getInstance().getWindow();
    const auto ballAngle = backgroundBall.getAngle();
    const auto ballSpeed = backgroundBall.getSpeed();
    const auto ballComponentX = std::cos(ballAngle);
    const auto ballComponentY = std::sin(backgroundBall.getAngle());

    if (backgroundPaddleLeft.getPosition().y + backgroundPaddleLeft.getLocalBounds().height / 2.0f < window.getSize().y &&
        backgroundPaddleLeft.getPosition().y - backgroundPaddleLeft.getLocalBounds().height / 2.0f > 0 &&
        ballComponentX < 0) {

    }

    const auto backgroundPaddleRightBottom = std::round(backgroundPaddleRight.getPosition().y + backgroundPaddleRight.getLocalBounds().height / 2.0f);
    const auto backgroundPaddleRightTop = std::round(backgroundPaddleRight.getPosition().y - backgroundPaddleRight.getLocalBounds().height / 2.0f);
    if (backgroundPaddleRightBottom < window.getSize().y && backgroundPaddleRightTop > 0) {
        const auto directionY = ballComponentY > 0 ? 1 : -1;

        std::cout << backgroundBall.getAngle() << '\n';
        backgroundPaddleRight.move(0, directionY * ballSpeed * deltaTime.asSeconds());
    }

    backgroundBall.update(deltaTime);
}

void MainMenuState::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(onePlayerButton, states);
    target.draw(twoPlayerButton, states);
    target.draw(exitButton, states);
    target.draw(title, states);

    target.draw(backgroundPaddleLeft, states);
    target.draw(backgroundPaddleRight, states);
    target.draw(backgroundBall, states);
}