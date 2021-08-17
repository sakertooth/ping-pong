#include "OnePlayerState.hpp"
#include "MainMenuState.hpp"
#include "../Game.hpp"
#include <cmath>
#include <iostream>

OnePlayerState::OnePlayerState() : score(0), gameOver(false) {
    const auto& window = Game::getInstance().getWindow();
    paddle = Paddle(sf::Vector2f(static_cast<float>(window.getSize().x / 2), 
                                static_cast<float>(window.getSize().y - 15.0f)),
                sf::Vector2f(75, 5), 
                Paddle::PaddleOrientation::DOWN,
                &ball);

    ball.setAngle(315);
    ball.getCircle().setPosition(paddle.getRect().getPosition().x, paddle.getRect().getPosition().y - 10.0f);

    scoreboard.setFont(Game::getInstance().getFont());
    scoreboard.setCharacterSize(16);
    scoreboard.setString("Score: " + std::to_string(score));
    scoreboard.setPosition(15.0f, 15.0f);

    gameOverText.setFont(Game::getInstance().getFont());
    gameOverText.setCharacterSize(32);
    gameOverText.setString("    Game over with a score of " + std::to_string(score) + "!\nPress spacebar for the Main Menu");
    gameOverText.setOrigin(gameOverText.getLocalBounds().width / 2.0f, gameOverText.getLocalBounds().height / 2.0f);
    gameOverText.setPosition(static_cast<float>(window.getSize().x / 2), 
                                static_cast<float>(window.getSize().y / 2));
}

void OnePlayerState::update(const sf::Time &deltaTime) {
    if (!gameOver) {
        paddle.update(deltaTime);
        ball.update(deltaTime);

        const auto paddleBounds = paddle.getRect().getGlobalBounds();
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
            && paddleBounds.left > 0.0f) {

            paddle.moveLeft(deltaTime);
        }  

        const auto& window = Game::getInstance().getWindow();
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) 
            && paddleBounds.left + paddleBounds.width < window.getSize().x) {
            
            paddle.moveRight(deltaTime);
        }

        const auto ballPos = ball.getCircle().getPosition();
        const auto ballAngle = ball.getAngle();

        bool hitLeft = ballPos.x < 1.0f;
        bool hitRight = ballPos.x > window.getSize().x - 1.0f;

        if (hitLeft || hitRight) {
            ball.reflect(Ball::Axis::Y);
            ball.getCircle().setPosition(ball.getCircle().getPosition().x + (hitLeft ? 1.0f : -1.0f), ball.getCircle().getPosition().y);
            Game::getInstance().playSound(SoundManager::SoundType::BEEP);
        }
        else if (ballPos.y < 1.0f) {
            ball.reflect(Ball::Axis::X);
            ball.getCircle().setPosition(ball.getCircle().getPosition().x, ball.getCircle().getPosition().y + 1.0f);
            Game::getInstance().playSound(SoundManager::SoundType::BEEP);
        }

        auto intersections = paddle.getIntersectionRects();
        auto ballIntersectionRect = std::get<0>(intersections);
        auto paddleIntersectionRect = std::get<1>(intersections);

        if (paddleIntersectionRect.intersects(ballIntersectionRect)) {
            Game::getInstance().playSound(SoundManager::SoundType::PLOP);
            ++score;
            scoreboard.setString("Score: " + std::to_string(score));
        }

        if (ballPos.y > window.getSize().y) {
            gameOver = true;
            gameOverText.setString("    Game over with a score of " + std::to_string(score) + "!\nPress spacebar for the Main Menu");
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