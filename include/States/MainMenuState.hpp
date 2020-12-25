#include "State.hpp"
#include <TGUI/TGUI.hpp>

namespace Pong::States
{
	class MainMenuState : public State, public tgui::Gui
	{
		tgui::Label::Ptr titleLabel;
		tgui::Button::Ptr playButton;
		tgui::Button::Ptr exitButton;
	public:
		MainMenuState();

		void draw(sf::RenderTarget& target) override;
		void update(const float deltaTime) override;
		void handleEvent(const sf::Event& event) override;
	};
}