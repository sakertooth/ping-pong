#include "TwoPlayerState.hpp"
#include "MainMenuState.hpp"
#include "../Collision.hpp"
#include "../Game.hpp"

TwoPlayerState::TwoPlayerState() : paddleLeftScore(0), paddleRightScore(0), gameOver(false) {
    auto& window = Game::getInstance().getWindow();
    float xPos = window.getSize().x / 2.0f;
    float yPos = window.getSize().y / 2.0f;

    paddleLeft = Paddle{sf::Vector2f{15, yPos}, Paddle::PaddleOrientation::LEFT};
    paddleRight = Paddle{sf::Vector2f{window.getSize().x - 15.0f, yPos}, Paddle::PaddleOrientation::RIGHT};

    ball.setAngle(45);
    ball.setPosition(100, yPos);

    paddleLeftScoreText.setFont(Game::getInstance().getFont());
    paddleLeftScoreText.setString(std::to_string(paddleLeftScore));
    paddleLeftScoreText.setCharacterSize(32);
    paddleLeftScoreText.setPosition(64.0f, 30.0f);

    paddleRightScoreText.setFont(Game::getInstance().getFont());
    paddleRightScoreText.setString(std::to_string(paddleRightScore));
    paddleRightScoreText.setCharacterSize(32);
    paddleRightScoreText.setPosition(window.getSize().x - 64.0f, 30.0f);

    gameOverText.setFont(Game::getInstance().getFont());
    gameOverText.setCharacterSize(32);
    gameOverText.setString("Player ... has won!\nPress spacebar for the main menu");
    gameOverText.setOrigin(gameOverText.getLocalBounds().width / 2.0f, gameOverText.getLocalBounds().height / 2.0f);
    gameOverText.setPosition(xPos, yPos);

    net.setSize(sf::Vector2f{2.0f, static_cast<float>(window.getSize().y)});
    net.setOrigin(net.getLocalBounds().width / 2.0f, net.getLocalBounds().height / 2.0f);
    net.setFillColor(sf::Color::White);
    net.setPosition(xPos, yPos);
}

void TwoPlayerState::update(const sf::Time& deltaTime) {
    if (!gameOver) {
        ball.update(deltaTime);

        auto& window = Game::getInstance().getWindow();
        auto paddleLeftBounds = paddleLeft.getGlobalBounds();
        auto paddleRightBounds = paddleRight.getGlobalBounds();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && paddleLeftBounds.top > 1.0f) {
            paddleLeft.moveUp(deltaTime);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && paddleLeftBounds.top + paddleLeftBounds.height < window.getSize().y - 1.0f) {
            paddleLeft.moveDown(deltaTime);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && paddleRightBounds.top > 1.0f) {
            paddleRight.moveUp(deltaTime);
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && paddleRightBounds.top + paddleRightBounds.height < window.getSize().y - 1.0f) {
            paddleRight.moveDown(deltaTime);
        }
        
        if (Collision::ballCollidingWithWindow(ball, Collision::WindowBorder::TOP) ||
            Collision::ballCollidingWithWindow(ball, Collision::WindowBorder::BOTTOM)) {
            
            Collision::applyCollisionOffset(ball, Ball::VectorComponent::Y);
            ball.invert(Ball::VectorComponent::Y);
            Game::getInstance().playSound(SoundManager::SoundType::BEEP);
        }

        if (Collision::paddleCollidingWithBall(paddleLeft, ball) || Collision::paddleCollidingWithBall(paddleRight, ball)) {
            Collision::applyCollisionOffset(ball, Ball::VectorComponent::X);
            ball.invert(Ball::VectorComponent::X);
            Game::getInstance().playSound(SoundManager::SoundType::PLOP);
        }

        if (Collision::ballCollidingWithWindow(ball, Collision::WindowBorder::LEFT)) {
            ball.setPosition(paddleLeft.getPosition().x + ball.getRadius() * 2, paddleLeft.getPosition().y);
            ball.invert(Ball::VectorComponent::X);
            ball.resetSpeed();

            Game::getInstance().playSound(SoundManager::SoundType::PEEP);
            paddleRightScoreText.setString(std::to_string(++paddleRightScore));
        }
        else if (Collision::ballCollidingWithWindow(ball, Collision::WindowBorder::RIGHT)) {
            ball.setPosition(paddleRight.getPosition().x - ball.getRadius() * 2, paddleRight.getPosition().y);
            ball.invert(Ball::VectorComponent::X);
            ball.resetSpeed();
            
            Game::getInstance().playSound(SoundManager::SoundType::PEEP);
            paddleLeftScoreText.setString(std::to_string(++paddleLeftScore));
        }

        if (paddleLeftScore == 11 || paddleRightScore == 11) {
            gameOver = true;
            gameOverText.setString(std::string{"            Player "} + (paddleLeftScore == 11 ? "one" : "two") + " has won!\nPress spacebar for the main menu");
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

void TwoPlayerState::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (!gameOver) {
        target.draw(paddleLeft, states);
        target.draw(paddleRight, states);
        target.draw(paddleLeftScoreText, states);
        target.draw(paddleRightScoreText, states);
        target.draw(net, states);
        target.draw(ball, states);
    }
    else {
        target.draw(gameOverText, states);
    }
}
