#pragma once
#include "State.hpp"
#include <TGUI/TGUI.hpp>

namespace Pong
{
	class GameOverState : public State
	{
		sf::Text message;

	public:
		GameOverState(const std::string &message);

		virtual void draw(sf::RenderTarget &target) override;
		virtual void update(const float deltaTime) override {}
		virtual void handleEvent(const sf::Event &event) override;
	};
}
