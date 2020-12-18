#pragma once
#include <Pong/Scenes/Scene.hpp>
#include <Pong/Scenes/SceneManager.hpp>
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
			MainMenuScene(SceneManager& manager, sf::RenderTarget& target);
			void draw();
			void update(float deltaTime);
			void handleEvent(sf::Event& event);
		};
	}
}