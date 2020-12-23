#include "Scenes/TwoPlayerScene.hpp"
#include "ServiceLocator.hpp"

namespace Pong::Scenes
{
	TwoPlayerScene::TwoPlayerScene() :
		tgui::Gui(*ServiceLocator::getRenderWindow()),
		noteLabel(tgui::Label::create()),
		playerOneScore(tgui::Label::create()),
		playerTwoScore(tgui::Label::create()),
		playerOne(sf::Keyboard::Key::W, sf::Keyboard::Key::S),
		playerTwo(sf::Keyboard::Key::Up, sf::Keyboard::Key::Down),
		started(false),
		over(false)
	{
		auto window = ServiceLocator::getRenderWindow();
		auto yCenter = (window->getSize().y - playerOne.getSize().y) / 2;

		playerOne.setPosition(16, yCenter);
		playerOneScore->setPosition(window->getSize().x / 2 - 128, 0);
		playerOneScore->setTextSize(50);
		playerOneScore->setText("0");
		playerOneScore->getRenderer()->setFont("pong.ttf");
		playerOneScore->getRenderer()->setTextColor(tgui::Color::White);
		playerOneScore->setVisible(false);
		add(playerOneScore);

		playerTwo.setPosition(static_cast<float>(window->getSize().x) - 16, yCenter);
		playerTwoScore->setPosition(window->getSize().x / 2 + 128, 0);
		playerTwoScore->setTextSize(50);
		playerTwoScore->setText("0");
		playerTwoScore->getRenderer()->setFont("pong.ttf");
		playerTwoScore->getRenderer()->setTextColor(tgui::Color::White);
		playerTwoScore->setVisible(false);
		add(playerTwoScore);

		ball.setRadius(4);

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
			target.draw(playerOne);
			target.draw(playerTwo);
			target.draw(ball);
		}
	}

	void TwoPlayerScene::update(const sf::Time& deltaTime)
	{
		if (started)
		{
			playerOne.update(deltaTime);
			playerTwo.update(deltaTime);
			ball.update(deltaTime, playerOne, playerTwo);

			updateScoreboard();
		}
	}

	void TwoPlayerScene::handleEvent(const sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Space && !started)
		{
			started = true;
			noteLabel->setVisible(false);
			playerOneScore->setVisible(true);
			playerTwoScore->setVisible(true);
		}
	}

	void TwoPlayerScene::updateScoreboard()
	{
		if (std::stoi(playerOneScore->getText().toAnsiString()) != playerOne.getPoints())
		{
			playerOneScore->setText(std::to_string(playerOne.getPoints()));
		}

		if (std::stoi(playerTwoScore->getText().toAnsiString()) != playerTwo.getPoints())
		{
			playerTwoScore->setText(std::to_string(playerTwo.getPoints()));
		}
	}
}