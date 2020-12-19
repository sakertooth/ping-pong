#include <Pong/Scenes/CreditsScene.hpp>
#include <Pong/Game.hpp>

namespace Pong
{
	namespace Scenes
	{
		CreditsScene::CreditsScene(SceneManager& sceneManager, sf::RenderWindow &window) : 
			tgui::Gui(window),
			goBackButton(tgui::Button::create("Go Back")),
			creditsLabel(tgui::Label::create("Saker, @sakeronthebeat on Twitter"))
		{			
			creditsLabel->getRenderer()->setTextColor(tgui::Color::White);
			creditsLabel->setPosition("(&.size - size) / 2");
			creditsLabel->setTextSize(16);
			add(creditsLabel, "CreditsLabel");

			goBackButton->setPosition("(&.width - width) / 2", "(&.height - height) / 2 - 128");
			goBackButton->setSize(240, 48);
			goBackButton->connect("pressed", [&]()
			{
				sceneManager.switchScene("Main Menu");
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