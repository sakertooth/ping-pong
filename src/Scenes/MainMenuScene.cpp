#include "Scenes.hpp"
#include "ServiceLocator.hpp"
#include <iostream>

namespace Pong
{
	namespace Scenes
	{
		MainMenuScene::MainMenuScene() : tgui::Gui(*ServiceLocator::getSceneManager()),
			titleLabel(tgui::Label::create("Ping Pong")),
			playButton(tgui::Button::create("Play")),
			exitButton(tgui::Button::create("Exit"))
		{
			auto sceneManager = ServiceLocator::getSceneManager();
			titleLabel->setPosition("(&.width - width) / 2", "(&.height - height) / 2 - 148");
			titleLabel->getRenderer()->setTextColor(tgui::Color::White);
			titleLabel->getRenderer()->setFont(ServiceLocator::getResourceManager()->getGameFont());
			titleLabel->setTextSize(70);
			add(titleLabel, "TitleLabel");

			playButton->setPosition("(&.width - width) / 2", "(&.height - height) / 2 - 64");
			playButton->getRenderer()->setFont(ServiceLocator::getResourceManager()->getGameFont());
			playButton->setSize(240, 48);
			playButton->connect("pressed", [sceneManager]()
			{
				sceneManager->switchScene("Play");
			});
			add(playButton, "PlayButton");

			exitButton->setPosition("(&.width - width) / 2", "(&.height - height) / 2");
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