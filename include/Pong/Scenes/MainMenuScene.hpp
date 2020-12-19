#pragma once
#include <Pong/Scenes/Scene.hpp>
#include <TGUI/TGUI.hpp>

namespace Pong
{
	namespace Scenes
	{
		class MainMenuScene : public Scene, public tgui::Gui
		{
			tgui::Label::Ptr m_titleLabel;
			tgui::Button::Ptr m_playButton;
			tgui::Button::Ptr m_creditsButton;
			tgui::Button::Ptr m_exitButton;
		public:
			MainMenuScene();
			void draw();
			void update(float deltaTime);
			void handleEvent(sf::Event& event);
		};
	}
}