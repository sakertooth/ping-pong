#include "Scenes/TwoPlayerScene.hpp"
#include "ServiceLocator.hpp"

namespace Pong::Scenes
{
	TwoPlayerScene::TwoPlayerScene() :
		tgui::Gui(*ServiceLocator::getRenderWindow()),
		noteLabel(tgui::Label::create()),
		leftPaddleScore(tgui::Label::create()),
		rightPaddleScore(tgui::Label::create()),
		leftPaddle(sf::Keyboard::Key::W, sf::Keyboard::Key::S),
		rightPaddle(sf::Keyboard::Key::Up, sf::Keyboard::Key::Down),
		started(false),
		over(false)
	{
		auto window = ServiceLocator::getRenderWindow();
		auto yCenter = (window->getSize().y - leftPaddle.getSize().y) / 2;

		leftPaddle.setPosition(16, yCenter);
		leftPaddleScore->setPosition(window->getSize().x / 2 - 128, 0);
		leftPaddleScore->setTextSize(50);
		leftPaddleScore->setText("0");
		leftPaddleScore->getRenderer()->setFont("pong.ttf");
		leftPaddleScore->getRenderer()->setTextColor(tgui::Color::White);
		leftPaddleScore->setVisible(false);
		add(leftPaddleScore);

		rightPaddle.setPosition(static_cast<float>(window->getSize().x) - 16, yCenter);
		rightPaddleScore->setPosition(window->getSize().x / 2 + 128, 0);
		rightPaddleScore->setTextSize(50);
		rightPaddleScore->setText("0");
		rightPaddleScore->getRenderer()->setFont("pong.ttf");
		rightPaddleScore->getRenderer()->setTextColor(tgui::Color::White);
		rightPaddleScore->setVisible(false);
		add(rightPaddleScore);

		ball.setRadius(4);
		ball.setPosition(window->getSize().x / 2, 16);

		noteLabel->setText("Press spacebar to start\n			First to 11 wins");
		noteLabel->setTextSize(30);
		noteLabel->setPosition("(&.size - size) / 2");
		noteLabel->getRenderer()->setFont("pong.ttf");
		noteLabel->getRenderer()->setTextColor(tgui::Color::White);
		add(noteLabel);
	}

	void TwoPlayerScene::draw(sf::RenderTarget& target)
	{
		tgui::Gui::draw();

		if (started)
		{
			target.draw(leftPaddle);
			target.draw(rightPaddle);
			target.draw(ball);
		}
	}

	void TwoPlayerScene::update(const sf::Time& deltaTime)
	{
		if (started && !over)
		{
			leftPaddle.update(deltaTime);
			rightPaddle.update(deltaTime);
			ball.update(deltaTime, leftPaddle, rightPaddle);

			updateScoreboard();
		}
	}

	void TwoPlayerScene::handleEvent(const sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Space)
		{
			if (!started)
			{
				started = true;
				noteLabel->setVisible(false);
				leftPaddleScore->setVisible(true);
				rightPaddleScore->setVisible(true);
			}
			else if (over)
			{
				auto sceneManager = ServiceLocator::getSceneManager();
				sceneManager->switchActiveScene(0);
			}
		}
	}

	void TwoPlayerScene::updateScoreboard()
	{
		auto leftPaddleScoreboard = std::stoi(leftPaddleScore->getText().toAnsiString());
		auto rightPaddleScoreboard = std::stoi(rightPaddleScore->getText().toAnsiString());

		if (leftPaddleScoreboard != leftPaddle.getPoints())
		{
			leftPaddleScore->setText(std::to_string(leftPaddle.getPoints()));
		}
		else if (rightPaddleScoreboard != rightPaddle.getPoints())
		{
			rightPaddleScore->setText(std::to_string(rightPaddle.getPoints()));
		}

		if (leftPaddleScoreboard == 11)
		{
			noteLabel->setText("		Player one has won the game!\n		Press space for the Main Menu");
			noteLabel->setTextSize(15);
			noteLabel->setVisible(true);
			over = true;
		}
		else if (rightPaddleScoreboard == 11)
		{
			noteLabel->setText("		Player two has won the game!\n		Press space for the Main Menu");
			noteLabel->setTextSize(15);
			noteLabel->setVisible(true);
			over = true;
		}
	}
}