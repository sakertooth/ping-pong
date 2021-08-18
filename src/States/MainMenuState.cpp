#define _USE_MATH_DEFINES

#include "MainMenuState.hpp"
#include "SpacebarState.hpp"
#include "OnePlayerState.hpp"
#include "TwoPlayerState.hpp"
#include "../Game.hpp"
#include <iostream>
#include <cmath>

MainMenuState::MainMenuState() {
    const auto& window = Game::getInstance().getWindow();
    const auto xPos = window.getSize().x / 2.0f;
    const auto yPos = window.getSize().y / 2.0f;

    title.setFont(Game::getInstance().getFont());
    title.setCharacterSize(64);
    title.setString("Ping Pong");
    title.setOrigin(std::round(title.getLocalBounds().width / 2.0f), std::round(title.getLocalBounds().height / 2.0f));
    title.setPosition(xPos, yPos - 150.0f);

    onePlayerButton.setText("One Player");
    onePlayerButton.onClick([&]() {
        music.stop();

        auto onePlayerState = std::make_unique<OnePlayerState>();
        auto spacebarState = std::make_unique<SpacebarState>(std::move(onePlayerState));
        Game::getInstance().pushState(std::move(spacebarState));
    });
    onePlayerButton.setPosition(xPos, yPos - 50.0f);

    twoPlayerButton.setText("Two Player");
    twoPlayerButton.onClick([&]() {
        music.stop();

        auto twoPlayerState = std::make_unique<TwoPlayerState>();
        auto spacebarState = std::make_unique<SpacebarState>(std::move(twoPlayerState));
        Game::getInstance().pushState(std::move(spacebarState));    
    });
    twoPlayerButton.setPosition(xPos, yPos);

    exitButton.setText("Exit");
    exitButton.onClick([]() { Game::getInstance().stop(); });
    exitButton.setPosition(xPos, yPos + 50.0f);

    backgroundPaddleLeft = Paddle(sf::Vector2f(15, yPos),
                                sf::Vector2f(5, 75), 
                                Paddle::PaddleOrientation::LEFT, 
                                &backgroundBall);

    backgroundPaddleRight = Paddle(sf::Vector2f(window.getSize().x - 15.0f, yPos), 
                                sf::Vector2f(5, 75), 
                                Paddle::PaddleOrientation::RIGHT, 
                                &backgroundBall);

    backgroundBall.setAngle(45);
    backgroundBall.setPosition(100, yPos);

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
    backgroundPaddleRight.update(deltaTime);
    backgroundPaddleLeft.update(deltaTime);

    const auto& window = Game::getInstance().getWindow();
    const auto ballTop = backgroundBall.getPosition().y - backgroundBall.getRadius();
    const auto ballBottom = backgroundBall.getPosition().y + backgroundBall.getRadius();
    const auto ballDirectionX = std::cos(backgroundBall.getAngle() * M_PI/180) > 0 ? 1 : -1;

    //Move paddles accordingly
    const auto paddleLeftTop = backgroundPaddleLeft.getPosition().y -
                                            backgroundPaddleLeft.getLocalBounds().height / 2.0f;

    const auto paddleLeftBottom = backgroundPaddleLeft.getPosition().y +
                                                backgroundPaddleLeft.getLocalBounds().height / 2.0f;

    if (paddleLeftTop > ballTop && paddleLeftTop > 0.0f && ballDirectionX == -1) {
        backgroundPaddleLeft.moveUp(deltaTime);
    }
    
    if (paddleLeftBottom < ballBottom && paddleLeftBottom < window.getSize().y && ballDirectionX == -1) {
        backgroundPaddleLeft.moveDown(deltaTime);
    }

    const auto paddleRightTop = backgroundPaddleRight.getPosition().y -
                                            backgroundPaddleRight.getLocalBounds().height / 2.0f;

    const auto paddleRightBottom = backgroundPaddleRight.getPosition().y +
                                                backgroundPaddleRight.getLocalBounds().height / 2.0f;

    if (paddleRightTop > ballTop && paddleRightTop > 0.0f && ballDirectionX == 1) {     
        backgroundPaddleRight.moveUp(deltaTime);
    }
    else if (paddleRightBottom < ballBottom && paddleRightBottom < window.getSize().y && ballDirectionX == 1) {
        backgroundPaddleRight.moveDown(deltaTime);
    }

    //Handle collision with the ball and the window
    bool hitTop = ballTop < 1.0f;
    bool hitBottom = ballBottom > static_cast<float>(window.getSize().y) - 1.0f;
    if (hitTop || hitBottom) {
        backgroundBall.reflect(Ball::VectorComponent::Y);
        backgroundBall.setPosition(backgroundBall.getPosition().x,
                                                backgroundBall.getPosition().y + (hitTop ? 1.0f : -1.0f));
    }

    //Bring ball back if out of bounds
    const auto ballPos = backgroundBall.getPosition();
    if (ballPos.x > static_cast<float>(window.getSize().x)) {
        const auto paddleRightPos = backgroundPaddleRight.getPosition();
        backgroundBall.setPosition(paddleRightPos.x - 10.0f, paddleRightPos.y);
    }
    else if (ballPos.x < 0.0f) {
        const auto paddleLeftPos = backgroundPaddleLeft.getPosition();
        backgroundBall.setPosition(paddleLeftPos.x + 10.0f, paddleLeftPos.y);
    }
}

void MainMenuState::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(backgroundPaddleLeft, states);
    target.draw(backgroundPaddleRight, states);
    target.draw(backgroundBall, states);
    target.draw(onePlayerButton, states);
    target.draw(twoPlayerButton, states);
    target.draw(exitButton, states);
    target.draw(title, states);
}