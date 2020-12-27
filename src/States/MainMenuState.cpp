#include "States/MainMenuState.hpp"
#include "States/TwoPlayerState.hpp"
#include "States/ChooseDifficultyState.hpp"
#include "States/SpacebarToPlayState.hpp"
#include "Game.hpp"

namespace Pong::States
{
	MainMenuState::MainMenuState() : tgui::Gui(Game::getInstance().getWindow()),
		titleLabel(tgui::Label::create()),
		onePlayerButton(tgui::Button::create("One Player")),
		twoPlayerButton(tgui::Button::create("Two Players")),
		exitButton(tgui::Button::create("Exit"))
	{
		auto loadButton = [&](tgui::Button::Ptr button, tgui::Layout x, tgui::Layout y)
		{
			button->setSize(240, 45);
			button->setTextSize(30);
			button->setPosition(x, y);
			button->getRenderer()->setFont("assets/font.ttf");
			button->getRenderer()->setBackgroundColor(tgui::Color::Black);
			button->getRenderer()->setTextColor(tgui::Color::White);
			button->getRenderer()->setBorderColor(tgui::Color::Transparent);
			button->getRenderer()->setBorderColorFocused(tgui::Color::Transparent);
			add(button);
		};

		titleLabel->setText("Ping Pong");
		titleLabel->setPosition("(&.width - width) / 2", "(&.height - height) / 2 - 128");
		titleLabel->getRenderer()->setFont("assets/font.ttf");
		titleLabel->getRenderer()->setTextColor(tgui::Color::White);
		titleLabel->setTextSize(45);
		add(titleLabel);

		loadButton(onePlayerButton, "(&.width - width) / 2", "(&.height - height) / 2");
		loadButton(twoPlayerButton, "(&.width - width) / 2", "(&.height - height) / 2 + 64");
		loadButton(exitButton, "(&.width - width) / 2", "(&.height - height) / 2 + 128");

		onePlayerButton->connect("pressed", []
		{
			Game::getInstance().switchState(std::make_shared<ChooseDifficultyState>());
		});

		twoPlayerButton->connect("pressed", []
		{
			Game::getInstance().switchState(std::make_shared<SpacebarToStartState>());
		});

		exitButton->connect("pressed", [] { Game::getInstance().stop(); });
	}

	void MainMenuState::draw(sf::RenderTarget& target)
	{
		tgui::Gui::draw();
	}

	void MainMenuState::handleEvent(const sf::Event& event)
	{
		tgui::Gui::handleEvent(event);
	}
}