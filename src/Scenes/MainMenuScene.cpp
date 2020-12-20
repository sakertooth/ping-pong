#include "Scenes.hpp"
#include "ServiceLocator.hpp"
#include <iostream>

namespace Pong
{
	namespace Scenes
	{
		MainMenuScene::MainMenuScene() : tgui::Gui(*ServiceLocator::getSceneManager()),
			titleLabel(tgui::Label::create("Saker's Ping Pong")),
			playButton(tgui::Button::create("Play")),
			creditsButton(tgui::Button::create("Credits")),
			exitButton(tgui::Button::create("Exit"))
		{
			auto sceneManager = ServiceLocator::getSceneManager();
			titleLabel->setPosition("(&.width - width) / 2", "(&.height - height) / 2 - 188");
			titleLabel->getRenderer()->setTextColor(tgui::Color::White);
			titleLabel->setTextSize(20);
			add(titleLabel, "TitleLabel");

			playButton->setPosition("(&.width - width) / 2", "(&.height - height) / 2 - 128");
			playButton->setSize(240, 48);
			playButton->connect("pressed", [sceneManager]()
			{
				sceneManager->switchScene("Play");
			});
			add(playButton, "PlayButton");

			creditsButton->setPosition("(&.width - width) / 2", "(&.height - height) / 2");
			creditsButton->setSize(240, 48);
			creditsButton->connect("pressed", [sceneManager]()
			{
				sceneManager->switchScene("Credits");
			});
			add(creditsButton, "CreditsButton");

			exitButton->setPosition("(&.width - width) / 2", "(&.height - height) / 2 + 128");
			exitButton->setSize(240, 48);
			exitButton->connect("pressed", [sceneManager]()
			{
				sceneManager->close();
			});
			add(exitButton, "ExitButton");
		}

		void MainMenuScene::draw(sf::RenderTarget& target)
		{
			tgui::Gui::draw();
		}

		void MainMenuScene::handleEvent(sf::Event& event)
		{
			tgui::Gui::handleEvent(event);
		}

		void MainMenuScene::update(float deltaTime) {}
	}
}