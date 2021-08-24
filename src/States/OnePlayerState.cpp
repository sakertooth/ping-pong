#include "OnePlayerState.hpp"
#include "MainMenuState.hpp"
#include "../Collision.hpp"
#include "../Game.hpp"
#include <cmath>
#include <iostream>

OnePlayerState::OnePlayerState() : score(0), gameOver(false) {
    auto windowSize = Game::getInstance().getWindow().getSize();
    paddle = Paddle{sf::Vector2f{static_cast<float>(windowSize.x / 2), 
                                    static_cast<float>(windowSize.y - 15.0f)}, Paddle::PaddleOrientation::DOWN};

    ball.setAngle(315);
    ball.setPosition(paddle.getPosition().x, paddle.getPosition().y - 10.0f);

    scoreboard.setFont(Game::getInstance().getFont());
    scoreboard.setCharacterSize(16);
    scoreboard.setString("Score: " + std::to_string(score));
    scoreboard.setPosition(15.0f, 15.0f);

    gameOverText.setFont(Game::getInstance().getFont());
    gameOverText.setCharacterSize(32);
    gameOverText.setString("    Game over with a score of " + std::to_string(score) + "!\nPress spacebar for the Main Menu");
    gameOverText.setOrigin(gameOverText.getLocalBounds().width / 2.0f, gameOverText.getLocalBounds().height / 2.0f);
    gameOverText.setPosition(static_cast<float>(windowSize.x / 2), 
                                static_cast<float>(windowSize.y / 2));
}

void OnePlayerState::update(const sf::Time &deltaTime) {
    if (!gameOver) {
        ball.update(deltaTime);

        auto paddleBounds = paddle.getGlobalBounds();
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
            && paddleBounds.left > 0.0f) {
            paddle.moveLeft(deltaTime);
        }  

        auto& window = Game::getInstance().getWindow();
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) 
            && paddleBounds.left + paddleBounds.width < window.getSize().x) {       
            paddle.moveRight(deltaTime);
        }

        if (Collision::ballCollidingWithWindow(ball, Collision::WindowBorder::LEFT) ||
            Collision::ballCollidingWithWindow(ball, Collision::WindowBorder::RIGHT)) {

            Collision::applyCollisionOffset(ball, Ball::VectorComponent::X);
            ball.invert(Ball::VectorComponent::X);
            Game::getInstance().playSound(SoundManager::SoundType::BEEP);
        }
        else if (Collision::ballCollidingWithWindow(ball, Collision::WindowBorder::TOP)) {
            Collision::applyCollisionOffset(ball, Ball::VectorComponent::Y);
            ball.invert(Ball::VectorComponent::Y);
            Game::getInstance().playSound(SoundManager::SoundType::BEEP);
        }

        auto ballPos = ball.getPosition();
        if (Collision::paddleCollidingWithBall(paddle, ball)) {
            Collision::applyCollisionOffset(ball, Ball::VectorComponent::Y);
            ball.invert(Ball::VectorComponent::Y);
            
            Game::getInstance().playSound(SoundManager::SoundType::PLOP);
            ++score;
            scoreboard.setString("Score: " + std::to_string(score));

            if (score % 5 == 0) {
                ball.accelerate();
            }
        }

        if (Collision::ballCollidingWithWindow(ball, Collision::WindowBorder::BOTTOM)) {
            gameOver = true;
            gameOverText.setString("    Game over with a score of " + std::to_string(score) + "!\nPress spacebar for the main menu");
            Game::getInstance().playSound(SoundManager::SoundType::PEEP);
        }
    }
    else {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
            auto mainMenuState = std::make_unique<MainMenuState>();
            Game::getInstance().clearAllStates();
            Game::getInstance().pushState(std::move(mainMenuState));
        }
    }
}

void OnePlayerState::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (!gameOver) {
        target.draw(paddle, states);
        target.draw(ball, states);
        target.draw(scoreboard, states);
    }
    else {
        target.draw(gameOverText, states);
    }
}