#include <Pong/Scenes/MainMenuScene.hpp>
#include <Pong/Scenes/SceneManager.hpp>
#include <Pong/Game.hpp>

namespace Pong
{
	namespace Scenes
	{
		MainMenuScene::MainMenuScene() : 
			tgui::Gui(Game::getInstance().getWindow()),
			m_titleLabel(tgui::Label::create("Saker's Ping Pong")),
			m_playButton(tgui::Button::create("Play")),
			m_creditsButton(tgui::Button::create("Credits")),
			m_exitButton(tgui::Button::create("Exit"))
		{
			auto& sceneManager = Game::getInstance().getSceneManager();

			m_titleLabel->setPosition("(&.width - width) / 2", "(&.height - height) / 2 - 188");
			m_titleLabel->getRenderer()->setTextColor(tgui::Color::White);
			m_titleLabel->setTextSize(20);
			add(m_titleLabel, "TitleLabel");

			m_playButton->setPosition("(&.width - width) / 2", "(&.height - height) / 2 - 128");
			m_playButton->setSize(240, 48);
			m_playButton->connect("pressed", [&]()
			{
				sceneManager.switchScene("Play");
			});
			add(m_playButton, "PlayButton");

			m_creditsButton->setPosition("(&.width - width) / 2", "(&.height - height) / 2");
			m_creditsButton->setSize(240, 48);
			m_creditsButton->connect("pressed", [&]()
			{
				sceneManager.switchScene("Credits");
			});
			add(m_creditsButton, "CreditsButton");

			m_exitButton->setPosition("(&.width - width) / 2", "(&.height - height) / 2 + 128");
			m_exitButton->setSize(240, 48);
			m_exitButton->connect("pressed", [&]()
			{
				std::exit(0);
			});
			add(m_exitButton, "ExitButton");
		}

		void MainMenuScene::draw()
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