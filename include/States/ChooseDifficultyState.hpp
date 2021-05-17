#pragma once
#include "States/State.hpp"
#include "States/TwoPlayerState.hpp"
#include <TGUI/TGUI.hpp>

namespace Pong
{
	enum class Difficulty
	{
		Easy,
		Medium,
		Hard
	};

	class ChooseDifficultyState : public State, public tgui::Gui
	{
		Difficulty			difficultyChosen;
		tgui::Label::Ptr	chooseDifficultyLabel;
		tgui::Label::Ptr	difficultyLabel;
		tgui::Button::Ptr	forwardButton;
		tgui::Button::Ptr	backwardButton;
		tgui::Button::Ptr	goBackButton;
		tgui::Button::Ptr	playButton;
	public:
		ChooseDifficultyState();

		void draw(sf::RenderTarget& target);
		void handleEvent(const sf::Event& event);
		void update(const float deltaTime) {}
	};
}