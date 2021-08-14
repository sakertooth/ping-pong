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

    backgroundPaddleLeft.init(sf::Vector2f(15, yPos), Paddle::PaddleOrientation::LEFT, &backgroundBall);
    backgroundPaddleRight.init(sf::Vector2f(window.getSize().x - 15.0f, yPos), Paddle::PaddleOrientation::RIGHT, &backgroundBall);

    if (!music.openFromFile("assets/artblock.ogg")) {
        std::cout << "could not load assets/artblock.ogg";
        Game::getInstance().stop();
    }

    music.setLoop(true);
    music.play();
}

void MainMenuState::update(const sf::Time& deltaTime) {
    onePlayerButton.update(deltaTime);
    twoPlayerButton.update(deltaTime);
    exitButton.update(deltaTime);
    backgroundBall.update(deltaTime);
    backgroundPaddleLeft.update(deltaTime);
    backgroundPaddleRight.update(deltaTime);

    const auto& window = Game::getInstance().getWindow();
    const auto ballTop = backgroundBall.getCircle().getPosition().y - backgroundBall.getCircle().getRadius();
    const auto ballBottom = backgroundBall.getCircle().getPosition().y + backgroundBall.getCircle().getRadius();
    const auto ballDirectionX = std::cos(backgroundBall.getAngle()) > 0 ? 1 : -1;
    const auto ballDirectionY = std::cos(backgroundBall.getAngle()) > 0 ? 1 : -1;

    const auto backgroundPaddleLeftTop = backgroundPaddleLeft.getRect().getPosition().y -
                                            backgroundPaddleLeft.getRect().getLocalBounds().height / 2.0f;

    const auto backgroundPaddleLeftBottom = backgroundPaddleLeft.getRect().getPosition().y +
                                                backgroundPaddleLeft.getRect().getLocalBounds().height / 2.0f;

    if (backgroundPaddleLeftBottom < ballBottom && ballDirectionX == -1) {
        backgroundPaddleLeft.moveDown(deltaTime);
    }
    else if (backgroundPaddleLeftTop > ballBottom && ballDirectionX == -1) {
        backgroundPaddleLeft.moveUp(deltaTime);
    }

    const auto backgroundPaddleRightTop = backgroundPaddleRight.getRect().getPosition().y -
                                            backgroundPaddleRight.getRect().getLocalBounds().height / 2.0f;

    const auto backgroundPaddleRightBottom = backgroundPaddleRight.getRect().getPosition().y +
                                                backgroundPaddleRight.getRect().getLocalBounds().height / 2.0f;

    if (backgroundPaddleRightBottom < ballBottom && ballDirectionX == 1) {
        backgroundPaddleRight.moveDown(deltaTime);
    }
    else if (backgroundPaddleRightTop > ballTop && ballDirectionX == 1) {
        backgroundPaddleRight.moveUp(deltaTime);
    }

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