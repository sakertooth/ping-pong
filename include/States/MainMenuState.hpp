#pragma once
#include "State.hpp"
#include <TGUI/TGUI.hpp>

namespace Pong
{
	class MainMenuState : public State, public tgui::Gui
	{
		tgui::Label::Ptr titleLabel;
		tgui::Button::Ptr onePlayerButton;
		tgui::Button::Ptr twoPlayerButton;
		tgui::Button::Ptr exitButton;

	public:
		MainMenuState();

		void draw(sf::RenderTarget &target) override;
		void handleEvent(const sf::Event &event) override;
		void update(const sf::Time& deltaTime) override {}
	};
}