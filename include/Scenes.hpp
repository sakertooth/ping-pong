#pragma once
#include <TGUI/TGUI.hpp>
#include "Scenes/Scene.hpp"

namespace Pong
{
	namespace Scenes
	{
		class MainMenuScene : public Scene, public tgui::Gui
		{
			tgui::Label::Ptr titleLabel;
			tgui::Button::Ptr playButton;
			tgui::Button::Ptr creditsButton;
			tgui::Button::Ptr exitButton;
		public:
			MainMenuScene();

			virtual void draw(sf::RenderTarget& target) override;
			virtual void update(float deltaTime) override;
			virtual void handleEvent(sf::Event& event) override;
		};

		class CreditsScene : public Scene, public tgui::Gui
		{
			tgui::Label::Ptr creditsLabel;
			tgui::Button::Ptr goBackButton;
		public:
			CreditsScene();

			virtual void draw(sf::RenderTarget& target) override;
			virtual void update(float deltaTime) override;
			virtual void handleEvent(sf::Event& event) override;
		};

		class PlayScene : public Scene
		{
			sf::Text pressSpacebarText;
			sf::RectangleShape paddleOne;
			sf::RectangleShape paddleTwo;
			bool started;
		public:
			PlayScene();

			virtual void draw(sf::RenderTarget& target) override;
			virtual void update(float deltaTime) override;
			virtual void handleEvent(sf::Event& event) override;
		};
	}
}