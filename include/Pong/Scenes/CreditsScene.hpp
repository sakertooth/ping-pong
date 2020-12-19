#pragma once
#include <Pong/Scenes/Scene.hpp>
#include <TGUI/TGUI.hpp>

namespace Pong
{
	namespace Scenes
	{
		class CreditsScene : public Scene, public tgui::Gui
		{
			tgui::Label::Ptr m_creditsLabel;
			tgui::Button::Ptr m_goBackButton;
		public:
			CreditsScene();
			void draw();
			void update(float deltaTime);
			void handleEvent(sf::Event& event);
		};
	}
}