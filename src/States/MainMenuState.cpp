#include "States/MainMenuState.hpp"
#include "States/TwoPlayerState.hpp"
#include "Game.hpp"

namespace Pong::States
{
	MainMenuState::MainMenuState() : tgui::Gui(Game::getInstance().getWindow()),
		titleLabel(tgui::Label::create()),
		playButton(tgui::Button::create("Play")),
		exitButton(tgui::Button::create("Exit"))
	{
		auto loadButton = [&](tgui::Button::Ptr button, tgui::Layout x, tgui::Layout y)
		{
			button->setSize(240, 45);
			button->setTextSize(30);
			button->setPosition(x, y);
			button->getRenderer()->setFont("pong.ttf");
			button->getRenderer()->setBackgroundColor(tgui::Color::Black);
			button->getRenderer()->setTextColor(tgui::Color::White);
			button->getRenderer()->setBorderColor(tgui::Color::Transparent);
			button->getRenderer()->setBorderColorFocused(tgui::Color::Transparent);
			add(button);
		};

		titleLabel->setText("Ping Pong");
		titleLabel->setPosition("(&.width - width) / 2", "(&.height - height) / 2 - 128");
		titleLabel->getRenderer()->setFont("pong.ttf");
		titleLabel->getRenderer()->setTextColor(tgui::Color::White);
		titleLabel->setTextSize(45);
		add(titleLabel);

		loadButton(playButton, "(&.width - width) / 2", "(&.height - height) / 2 - 32");
		loadButton(exitButton, "(&.width - width) / 2", "(&.height - height) / 2 + 32");

		playButton->connect("pressed", []()
		{
			Game::getInstance().swtichState(std::make_shared<States::TwoPlayerState>());
		});

		exitButton->connect("pressed", []() { Game::getInstance().stop(); });
	}

	void MainMenuState::draw(sf::RenderTarget& target)
	{
		tgui::Gui::draw();
	}

	void MainMenuState::update(const float deltaTime) {}

	void MainMenuState::handleEvent(const sf::Event& event)
	{
		tgui::Gui::handleEvent(event);

		switch (event.type)
		{
		case sf::Event::Resized:
			tgui::Gui::setView(Game::getInstance().getWindow().getView());
			break;
		}
	}
}