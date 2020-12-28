#pragma once
#include "ChooseDifficultyState.hpp"
#include <optional>
#include <TGUI/TGUI.hpp>

namespace Pong::States
{
	class SpacebarToStartState : public State, public tgui::Gui
	{
		std::optional<Difficulty>	onePlayerDifficulty;
		tgui::Label::Ptr			spacebarLabel;
	public:
		SpacebarToStartState();
		SpacebarToStartState(const Difficulty& difficulty);

		virtual void draw(sf::RenderTarget& target) override;
		virtual void update(const float deltaTime) override {}
		virtual void handleEvent(const sf::Event& event) override;
	};
}