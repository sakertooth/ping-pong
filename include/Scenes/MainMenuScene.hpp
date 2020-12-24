#pragma once
#include "Scenes/Scene.hpp"
#include <TGUI/TGUI.hpp>

namespace Pong::Scenes
{
	class MainMenuScene : public Scene, public tgui::Gui
	{
		tgui::Label::Ptr titleLabel;
		tgui::Button::Ptr playButton;
		tgui::Button::Ptr exitButton;
	public:
		MainMenuScene();

		virtual void update(const sf::Time& deltaTime) override {};
		virtual void draw(sf::RenderTarget& target) override;
		virtual void handleEvent(const sf::Event& event) override;
	};
}