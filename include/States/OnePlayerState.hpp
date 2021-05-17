#pragma once
#include "States/State.hpp"
#include "States/TwoPlayerState.hpp"
#include "States/ChooseDifficultyState.hpp"
#include <TGUI/TGUI.hpp>

namespace Pong
{
	class OnePlayerState : public TwoPlayerState
	{
		Difficulty		difficulty;
		float			probabilityOfHit;
		bool			willHit;
		bool			willHitCalculated;
	public:
		OnePlayerState(const Difficulty& difficulty);

		virtual void	draw(sf::RenderTarget& target) override;
		virtual void	update(const float deltaTime) override;
		void			updateAI(const float deltaTime);
	};
}