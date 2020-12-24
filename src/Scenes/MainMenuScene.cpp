#include "Scenes/MainMenuScene.hpp"
#include "Scenes/TwoPlayerScene.hpp"
#include "ServiceLocator.hpp"

namespace Pong::Scenes
{
	MainMenuScene::MainMenuScene() : 
		tgui::Gui(*ServiceLocator::getRenderWindow()),
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

		auto sceneManager = ServiceLocator::getSceneManager();

		playButton->connect("pressed", [=]() 
		{
			sceneManager->addScene(1, std::make_shared<Scenes::TwoPlayerScene>());
			sceneManager->switchActiveScene(1);
		});

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