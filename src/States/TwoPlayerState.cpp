#include "TwoPlayerState.hpp"
#include "MainMenuState.hpp"
#include "../Game.hpp"

TwoPlayerState::TwoPlayerState() : paddleLeftScore(0), paddleRightScore(0), gameOver(false) {
    const auto& window = Game::getInstance().getWindow();
    const auto xPos = window.getSize().x / 2.0f;
    const auto yPos = window.getSize().y / 2.0f;

    paddleLeft = Paddle(sf::Vector2f(15, yPos),
                                sf::Vector2f(5, 75), 
                                Paddle::PaddleOrientation::LEFT, 
                                &ball);

    paddleRight = Paddle(sf::Vector2f(window.getSize().x - 15.0f, yPos), 
                                sf::Vector2f(5, 75), 
                                Paddle::PaddleOrientation::RIGHT, 
                                &ball);

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

    net.setSize(sf::Vector2f(2, window.getSize().y));
    net.setOrigin(net.getLocalBounds().width / 2.0f, net.getLocalBounds().height / 2.0f);
    net.setFillColor(sf::Color::White);
    net.setPosition(xPos, yPos);
}

void TwoPlayerState::update(const sf::Time& deltaTime) {
    if (!gameOver) {
        paddleLeft.update(deltaTime);
        paddleRight.update(deltaTime);
        ball.update(deltaTime);

        const auto& window = Game::getInstance().getWindow();
        const auto paddleLeftBounds = paddleLeft.getGlobalBounds();
        const auto paddleRightBounds = paddleRight.getGlobalBounds();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) &&
            paddleLeftBounds.top > 1.0f) {
                paddleLeft.moveUp(deltaTime);
            }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) &&
            paddleLeftBounds.top + paddleLeftBounds.height < window.getSize().y - 1.0f) {
                paddleLeft.moveDown(deltaTime);
            }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) &&
            paddleRightBounds.top > 1.0f) {
                paddleRight.moveUp(deltaTime);
            }
        

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) &&
            paddleRightBounds.top + paddleRightBounds.height < window.getSize().y - 1.0f) {
                paddleRight.moveDown(deltaTime);
            }

        const auto ballPos = ball.getPosition();
        const int ballAngle = ball.getAngle();
        const int offsetY = 0;

        const bool hitUp = ballPos.y < 1.0f;
        const bool hitBottom = ballPos.y > window.getSize().y - 1.0f;

        if (hitUp || hitBottom) {
            ball.reflect(Ball::VectorComponent::Y);
            ball.setPosition(ball.getPosition().x, ball.getPosition().y + (hitUp ? 1.0f : -1.0f));
            Game::getInstance().playSound(SoundManager::SoundType::BEEP);
        }

        auto paddleLeftIntersections = paddleLeft.getIntersectionRects();
        auto paddleRightIntersections = paddleRight.getIntersectionRects();
        if (paddleLeftIntersections.first.intersects(paddleLeftIntersections.second) ||
            paddleRightIntersections.first.intersects(paddleRightIntersections.second)) {
            Game::getInstance().playSound(SoundManager::SoundType::PLOP);
        }

        if (ballPos.x < 1.0f) {
            Game::getInstance().playSound(SoundManager::SoundType::PEEP);
            paddleRightScoreText.setString(std::to_string(++paddleRightScore));

            ball.reflect(Ball::VectorComponent::X);
            ball.setPosition(paddleLeft.getPosition().x + ball.getRadius(), paddleLeft.getPosition().y);
        }
        else if (ballPos.x > window.getSize().x - 1.0f) {
            Game::getInstance().playSound(SoundManager::SoundType::PEEP);
            paddleLeftScoreText.setString(std::to_string(++paddleLeftScore));

            ball.reflect(Ball::VectorComponent::X);
            ball.setPosition(paddleRight.getPosition().x - ball.getRadius(), paddleRight.getPosition().y);
            ball.setSpeed(500);
        }

        if (paddleLeftScore == 11 || paddleRightScore == 11) {
            gameOver = true;
            gameOverText.setString(std::string("            Player ") + (paddleLeftScore == 11 ? "one" : "two") + " has won!\nPress spacebar for the main menu");
            ball.setSpeed(500);
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
