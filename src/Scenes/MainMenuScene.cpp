#include "Scenes/MainMenuScene.hpp"
#include "ServiceLocator.hpp"

namespace Pong::Scenes
{
	MainMenuScene::MainMenuScene() : 
		tgui::Gui(*ServiceLocator::getRenderWindow()),
		titleLabel(tgui::Label::create()),
		onePlayerButton(tgui::Button::create("One Player")),
		twoPlayerButton(tgui::Button::create("Two Player")),
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

		loadButton(onePlayerButton, "(&.width - width) / 2", "(&.height - height) / 2 - 32");
		loadButton(twoPlayerButton, "(&.width - width) / 2", "(&.height - height) / 2 + 32");
		loadButton(exitButton, "(&.width - width) / 2", "(&.height - height) / 2 + 128");

		onePlayerButton->connect("pressed", []() { ServiceLocator::getSceneManager()->switchActiveScene(1); });
		twoPlayerButton->connect("pressed", []() { ServiceLocator::getSceneManager()->switchActiveScene(2); });
		exitButton->connect("pressed", []() { ServiceLocator::getRenderWindow()->close(); });
	}

	void MainMenuScene::draw(sf::RenderTarget& target)
	{
		tgui::Gui::draw();
	}

	void MainMenuScene::handleEvent(const sf::Event& event) 
	{
		tgui::Gui::handleEvent(event);
	}
}