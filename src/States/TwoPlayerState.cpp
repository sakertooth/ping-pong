#include "Game.hpp"
#include "States/MainMenuState.hpp"
#include "States/TwoPlayerState.hpp"
#include "States/GameOverState.hpp"

namespace Pong
{
	TwoPlayerState::TwoPlayerState() : paddleSpeed(500)
	{
		const auto &window = Game::getInstance().getWindow();
		const auto paddleSize = sf::Vector2f(3, 64);

		leftPaddleScore.setFont(Game::getInstance().getFont());
		leftPaddleScore.setCharacterSize(50);
		leftPaddleScore.setString("0");
		leftPaddleScore.setPosition(128.0f, 0.0f);

		rightPaddleScore.setFont(Game::getInstance().getFont());
		rightPaddleScore.setCharacterSize(50);
		rightPaddleScore.setString("0");
		rightPaddleScore.setPosition(window.getSize().x - 128.0f, 0.0f);

		leftPaddle.setSize(paddleSize);
		leftPaddle.setOrigin(paddleSize / 2.0f);
		leftPaddle.setPosition(16.0f, window.getSize().y / 2.0f);

		rightPaddle.setSize(paddleSize);
		rightPaddle.setOrigin(paddleSize / 2.0f);
		rightPaddle.setPosition(window.getSize().x - 16.0f, window.getSize().y / 2.0f);

		ball.setRadius(4.0f);
		ball.setOrigin(ball.getRadius() / 2.0f, ball.getRadius() / 2.0f);
		ball.setPosition(ball.getOrigin().x + ball.getRadius(), ball.getOrigin().y + ball.getRadius());

		separator.setSize(sf::Vector2f(1.0f, static_cast<float>(window.getSize().y)));
		separator.setPosition(window.getSize().x / 2.0f, 0);
	}

	void TwoPlayerState::draw(sf::RenderTarget &target)
	{
		target.draw(leftPaddleScore);
		target.draw(rightPaddleScore);
		target.draw(leftPaddle);
		target.draw(rightPaddle);
		target.draw(ball);
		target.draw(separator);
	}

	void TwoPlayerState::update(const sf::Time& deltaTime)
	{
		const auto &window = Game::getInstance().getWindow();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && leftPaddle.getPosition().y - leftPaddle.getLocalBounds().height / 2 > 0.0f)
			leftPaddle.move(0, -paddleSpeed * deltaTime.asSeconds());
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && leftPaddle.getPosition().y + leftPaddle.getLocalBounds().height / 2 < window.getSize().y)
			leftPaddle.move(0, paddleSpeed * deltaTime.asSeconds());
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && rightPaddle.getPosition().y - rightPaddle.getLocalBounds().height / 2 > 0.0f)
			rightPaddle.move(0, -paddleSpeed * deltaTime.asSeconds());
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && rightPaddle.getPosition().y + rightPaddle.getLocalBounds().height / 2 < window.getSize().y)
			rightPaddle.move(0, paddleSpeed * deltaTime.asSeconds());

		ball.update(deltaTime, leftPaddle, leftPaddleScore, rightPaddle, rightPaddleScore);

		if (rightPaddleScore.getString().toAnsiString() == "11")
		{
			Game::getInstance().switchState(std::make_shared<GameOverState>("Player two has won! Press any key for the main menu."));
		}
		else if (leftPaddleScore.getString().toAnsiString() == "11")
		{
			Game::getInstance().switchState(std::make_shared<GameOverState>("Player one has won! Press any key for the main menu."));
		}
	}

}