#include "States/ChooseDifficultyState.hpp"
#include "States/MainMenuState.hpp"
#include "States/SpacebarToPlayState.hpp"
#include "Game.hpp"

namespace Pong
{
	ChooseDifficultyState::ChooseDifficultyState() : tgui::Gui(Game::getInstance().getWindow()),
													 difficultyChosen(Difficulty::Easy),
													 chooseDifficultyLabel(tgui::Label::create("Choose Difficulty")),
													 difficultyLabel(tgui::Label::create("Easy")),
													 forwardButton(tgui::Button::create(">")),
													 backwardButton(tgui::Button::create("<")),
													 goBackButton(tgui::Button::create("Go Back")),
													 playButton(tgui::Button::create("Play"))
	{
		chooseDifficultyLabel->setPosition("(&.width - width) / 2", "(&.height - height) / 2 - 128");
		chooseDifficultyLabel->getRenderer()->setFont("assets/font.ttf");
		chooseDifficultyLabel->getRenderer()->setTextColor(tgui::Color::White);
		chooseDifficultyLabel->setTextSize(45);
		add(chooseDifficultyLabel);

		difficultyLabel->setPosition("(&.width - width) / 2", "(&.height - height) / 2");
		difficultyLabel->getRenderer()->setFont("assets/font.ttf");
		difficultyLabel->getRenderer()->setTextColor(tgui::Color::White);
		difficultyLabel->setTextSize(45);
		add(difficultyLabel);

		forwardButton->setSize(48, 48);
		forwardButton->setTextSize(30);
		forwardButton->setPosition("(&.width - width) / 2 + 256", "(&.height - height) / 2");
		forwardButton->getRenderer()->setFont("assets/font.ttf");
		forwardButton->getRenderer()->setBackgroundColor(tgui::Color::Black);
		forwardButton->getRenderer()->setTextColor(tgui::Color::White);
		forwardButton->getRenderer()->setBorderColor(tgui::Color::Transparent);
		forwardButton->getRenderer()->setBorderColorFocused(tgui::Color::Transparent);
		forwardButton->connect("pressed", [&]
							   {
								   if (difficultyLabel->getText() == "Easy")
								   {
									   difficultyLabel->setText("Medium");
									   backwardButton->setVisible(true);
									   difficultyChosen = Difficulty::Medium;
								   }
								   else if (difficultyLabel->getText() == "Medium")
								   {
									   difficultyLabel->setText("Hard");
									   forwardButton->setVisible(false);
									   difficultyChosen = Difficulty::Hard;
								   }
							   });
		add(forwardButton);

		backwardButton->setSize(48, 48);
		backwardButton->setTextSize(30);
		backwardButton->setPosition("(&.width - width) / 2 - 256", "(&.height - height) / 2");
		backwardButton->getRenderer()->setFont("assets/font.ttf");
		backwardButton->getRenderer()->setBackgroundColor(tgui::Color::Black);
		backwardButton->getRenderer()->setTextColor(tgui::Color::White);
		backwardButton->getRenderer()->setBorderColor(tgui::Color::Transparent);
		backwardButton->getRenderer()->setBorderColorFocused(tgui::Color::Transparent);
		backwardButton->setVisible(false);
		backwardButton->connect("pressed", [&]
								{
									if (difficultyLabel->getText() == "Hard")
									{
										difficultyLabel->setText("Medium");
										forwardButton->setVisible(true);
										difficultyChosen = Difficulty::Medium;
									}
									else if (difficultyLabel->getText() == "Medium")
									{
										difficultyLabel->setText("Easy");
										backwardButton->setVisible(false);
										difficultyChosen = Difficulty::Easy;
									}
								});
		add(backwardButton);

		goBackButton->setSize(240, 45);
		goBackButton->setTextSize(30);
		goBackButton->setPosition("(&.width - width) / 2 - 128", "(&.height - height) / 2 + 128");
		goBackButton->getRenderer()->setFont("assets/font.ttf");
		goBackButton->getRenderer()->setBackgroundColor(tgui::Color::Black);
		goBackButton->getRenderer()->setTextColor(tgui::Color::White);
		goBackButton->getRenderer()->setBorderColor(tgui::Color::Transparent);
		goBackButton->getRenderer()->setBorderColorFocused(tgui::Color::Transparent);
		goBackButton->connect("pressed", []
							  { Game::getInstance().switchState(std::make_shared<MainMenuState>()); });
		add(goBackButton);

		playButton->setSize(240, 45);
		playButton->setTextSize(30);
		playButton->setPosition("(&.width - width) / 2 + 128", "(&.height - height) / 2 + 128");
		playButton->getRenderer()->setFont("assets/font.ttf");
		playButton->getRenderer()->setBackgroundColor(tgui::Color::Black);
		playButton->getRenderer()->setTextColor(tgui::Color::White);
		playButton->getRenderer()->setBorderColor(tgui::Color::Transparent);
		playButton->getRenderer()->setBorderColorFocused(tgui::Color::Transparent);
		playButton->connect("pressed", [&]
							{ Game::getInstance().switchState(std::make_shared<SpacebarToStartState>(difficultyChosen)); });
		add(playButton);
	}

	void ChooseDifficultyState::draw(sf::RenderTarget &target)
	{
		tgui::Gui::draw();
	}

	void ChooseDifficultyState::handleEvent(const sf::Event &event)
	{
		tgui::Gui::handleEvent(event);
	}
}