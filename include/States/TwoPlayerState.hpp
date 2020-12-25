 #pragma once
#include "State.hpp"
#include "Objects/Paddle.hpp"
#include "Objects/Ball.hpp"
#include <TGUI/TGUI.hpp>

namespace Pong::States
{
	class TwoPlayerState : public State, public tgui::Gui
	{
		tgui::Label::Ptr noteLabel;
		tgui::Label::Ptr leftPaddleScore;
		tgui::Label::Ptr rightPaddleScore;
		Objects::Paddle leftPaddle;
		Objects::Paddle rightPaddle;
		Objects::Ball ball;
		bool started;
		bool over;
	public:
		TwoPlayerState();

		void draw(sf::RenderTarget& target) override;
		void update(const float deltaTime) override;
		void handleEvent(const sf::Event& event) override;

		void updateScoreboard();
	};
}