#include "Scenes.hpp"
#include "ServiceLocator.hpp"

#include <iostream>

namespace Pong
{
	namespace Scenes
	{
		CreditsScene::CreditsScene() : tgui::Gui(*ServiceLocator::getSceneManager()),
			creditsLabel(tgui::Label::create("Saker, @sakeronthebeat on Twitter")),
			goBackButton(tgui::Button::create("Go Back"))
		{
			auto sceneManager = ServiceLocator::getSceneManager();
			creditsLabel->getRenderer()->setTextColor(tgui::Color::White);
			creditsLabel->setPosition("(&.size - size) / 2");
			creditsLabel->setTextSize(16);
			add(creditsLabel, "CreditsLabel");

			goBackButton->setPosition("(&.width - width) / 2", "(&.height - height) / 2 - 128");
			goBackButton->setSize(240, 48);
			goBackButton->connect("pressed", [sceneManager]()
			{
				sceneManager->switchScene("Main Menu");
			});
			add(goBackButton, "GoBackButton");
		}

		void CreditsScene::draw(sf::RenderTarget& target)
		{
			tgui::Gui::draw();
		}

		void CreditsScene::handleEvent(sf::Event& event)
		{
			tgui::Gui::handleEvent(event);
		}

		void CreditsScene::update(float deltaTime) {}
	}
}