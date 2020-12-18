#include <Pong/Scenes/CreditsScene.hpp>

namespace Pong
{
	namespace Scenes
	{
		CreditsScene::CreditsScene(SceneManager& manager, sf::RenderTarget& target) : 
			tgui::Gui(target),
			m_goBackButton(tgui::Button::create("Go Back")),
			m_creditsLabel(tgui::Label::create("Saker, @sakeronthebeat on Twitter"))
		{
			m_creditsLabel->getRenderer()->setTextColor(tgui::Color::White);
			m_creditsLabel->setPosition("(&.size - size) / 2");
			m_creditsLabel->setTextSize(16);
			add(m_creditsLabel, "CreditsLabel");

			m_goBackButton->setPosition("(&.width - width) / 2", "(&.height - height) / 2 - 128");
			m_goBackButton->setSize(240, 48);
			m_goBackButton->connect("pressed", [&]()
			{
				manager.switchScene("MainMenu");
			});
			add(m_goBackButton, "GoBackButton");
		}

		void CreditsScene::draw()
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