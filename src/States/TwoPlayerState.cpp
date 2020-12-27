#include	"Game.hpp"
#include	"States/MainMenuState.hpp"
#include	"States/TwoPlayerState.hpp"

#include	<iostream>
#include	<effolkronium/random.hpp>

using Random = effolkronium::random_static;

namespace Pong::States
{
	TwoPlayerState::TwoPlayerState() : tgui::Gui(Game::getInstance().getWindow()),
		leftPaddleScore(tgui::Label::create()),
		rightPaddleScore(tgui::Label::create()),
		paddleSpeed(500),
		ballSpeed(500),
		ballAngle(315),
		ballIsColliding(false)
	{
		const auto& window = Game::getInstance().getWindow();
		const auto paddleSize = sf::Vector2f(1, 64);
		const auto yCenter = (window.getSize().y - paddleSize.y) / 2;

		leftPaddle.setSize(paddleSize);
		leftPaddle.setPosition(16, yCenter);

		rightPaddle.setSize(paddleSize);
		rightPaddle.setPosition(window.getSize().x - rightPaddle.getLocalBounds().width - 16, yCenter);

		ball.setRadius(4);
		ball.setOrigin(ball.getRadius() / 2, ball.getRadius() / 2);

		leftPaddleScore->setPosition(window.getSize().x / 2 - 128, 0);
		leftPaddleScore->setTextSize(50);
		leftPaddleScore->setText("0");
		leftPaddleScore->getRenderer()->setFont("assets/font.ttf");
		leftPaddleScore->getRenderer()->setTextColor(tgui::Color::White);
		add(leftPaddleScore);

		rightPaddle.setPosition(static_cast<float>(window.getSize().x) - 16, yCenter);
		rightPaddleScore->setPosition(window.getSize().x / 2 + 128, 0);
		rightPaddleScore->setTextSize(50);
		rightPaddleScore->setText("0");
		rightPaddleScore->getRenderer()->setFont("assets/font.ttf");
		rightPaddleScore->getRenderer()->setTextColor(tgui::Color::White);
		add(rightPaddleScore);

		separator.setSize(sf::Vector2f(1, window.getSize().y));
		separator.setPosition(window.getSize().x / 2, 0);
	}

	void TwoPlayerState::draw(sf::RenderTarget& target)
	{
		tgui::Gui::draw();

		target.draw(leftPaddle);
		target.draw(rightPaddle);
		target.draw(ball);
		target.draw(separator);
	}

	void TwoPlayerState::handleEvent(const sf::Event& event)
	{
		tgui::Gui::handleEvent(event);
	}

	void TwoPlayerState::update(const float deltaTime)
	{
		updatePaddles(deltaTime);
		updateBall(deltaTime);
	}

	void TwoPlayerState::updatePaddles(const float deltaTime)
	{
		const auto& window = Game::getInstance().getWindow();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && leftPaddle.getPosition().y > 0.0f)
			leftPaddle.move(0, -paddleSpeed * deltaTime);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && leftPaddle.getPosition().y < window.getSize().y - leftPaddle.getLocalBounds().height)
			leftPaddle.move(0, paddleSpeed * deltaTime);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && rightPaddle.getPosition().y > 0.0f)
			rightPaddle.move(0, -paddleSpeed * deltaTime);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && rightPaddle.getPosition().y < window.getSize().y - rightPaddle.getLocalBounds().height)
			rightPaddle.move(0, paddleSpeed * deltaTime);		
	}

	void TwoPlayerState::updateBall(const float deltaTime)
	{
		const auto& window = Game::getInstance().getWindow();

		//Upper Window Collision
		if (ball.getPosition().y - ball.getRadius() < 0.0f)
		{
			ballAngle = (360 - ballAngle) % 360;
			ball.setPosition(ball.getPosition().x, ball.getRadius() + 0.1f);
			Game::getInstance().getSoundManager().getBeepSound().play();
		}

		//Lower Window Collision
		if (ball.getPosition().y + ball.getRadius() > window.getSize().y)
		{
			ballAngle = (360 - ballAngle) % 360;
			ball.setPosition(ball.getPosition().x, window.getSize().y - ball.getRadius() - 0.1f);
			Game::getInstance().getSoundManager().getBeepSound().play();
		}

		const auto rightPaddleLeft = rightPaddle.getGlobalBounds().left;
		const auto rightPaddleTop = rightPaddle.getGlobalBounds().top;

		//Left Window Collision
		if (ball.getPosition().x - ball.getRadius() < 0.0f)
		{
			rightPaddleScore->setText(std::to_string(std::stoi(rightPaddleScore->getText().toAnsiString()) + 1));
			ball.setPosition(rightPaddleLeft - 10, rightPaddleTop + rightPaddle.getLocalBounds().height / 2);
			ballAngle = 180;
			Game::getInstance().getSoundManager().getPeepSound().play();
		}

		const auto leftPaddleRight = leftPaddle.getGlobalBounds().left + leftPaddle.getGlobalBounds().width;
		const auto leftPaddleTop = leftPaddle.getGlobalBounds().top;

		//Right Window Collision
		if (ball.getPosition().x + ball.getRadius() > window.getSize().x)
		{
			leftPaddleScore->setText(std::to_string(std::stoi(leftPaddleScore->getText().toAnsiString()) + 1));
			ball.setPosition(leftPaddleRight + 10, leftPaddleTop + leftPaddle.getLocalBounds().height / 2);
			ballAngle = 0;
			Game::getInstance().getSoundManager().getPeepSound().play();
		}

		//Paddle Collision
		if (ball.getPosition().x + ball.getRadius() < leftPaddle.getPosition().x)
		{
			ballAngle = (180 - ballAngle) % 360;

			if (ballAngle > 0 && ballAngle < 90)
			{
				ballAngle -= Random::get(45, ballAngle);
			}
			else if (ballAngle > 90 && ballAngle < 180)
			{
				ballAngle += Random::get(45, 180 - ballAngle);
			}
			else if (ballAngle > 180 && ballAngle < 270)
			{
				ballAngle -= Random::get(45, ballAngle - 180);
			}
			else if (ballAngle > 270 && ballAngle > 360)
			{
				ballAngle += Random::get(45, 360 - ballAngle);
			}
			else if (ballAngle == 0 || ballAngle == 180)
			{
				auto randAngle = Random::get(0, 180);
				ballAngle = Random::get<bool>() ? randAngle : -randAngle;
			}

			ballAngle %= 360;
			ballIsColliding = true;
			Game::getInstance().getSoundManager().getPlopSound().play();
		}

		ball.move(ballSpeed * std::cos(ballAngle * 0.0174532925f) * deltaTime, -ballSpeed * std::sin(ballAngle * 0.0174532925f) * deltaTime);
	}

	//void TwoPlayerState::checkIfGameOver()
	//{

	//	/*auto leftPaddleScoreboard = std::stoi(leftPaddleScore->getText().toAnsiString());
	//	auto rightPaddleScoreboard = std::stoi(rightPaddleScore->getText().toAnsiString());

	//	if (leftPaddleScoreboard != leftPaddle.getPoints())
	//	{
	//		leftPaddleScore->setText(std::to_string(leftPaddle.getPoints()));
	//	}
	//	else if (rightPaddleScoreboard != rightPaddle.getPoints())
	//	{
	//		rightPaddleScore->setText(std::to_string(rightPaddle.getPoints()));
	//	}

	//	if (leftPaddleScoreboard == 11)
	//	{
	//		noteLabel->setText("			Player one has won the game!\n		Press space for the Main Menu");
	//		noteLabel->setTextSize(20);
	//		noteLabel->setVisible(true);
	//		over = true;
	//	}
	//	else if (rightPaddleScoreboard == 11)
	//	{
	//		noteLabel->setText("			Player two has won the game!\n		Press space for the Main Menu");
	//		noteLabel->setTextSize(20);
	//		noteLabel->setVisible(true);
	//		over = true;
	//	}*/
	//}
}