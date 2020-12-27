#pragma once
#include "State.hpp"
#include <TGUI/TGUI.hpp>

namespace Pong::States
{
	class TwoPlayerState : public State, public tgui::Gui
	{
		tgui::Label::Ptr	leftPaddleScore;
		tgui::Label::Ptr	rightPaddleScore;
		sf::RectangleShape	separator;
		
		sf::RectangleShape	leftPaddle;
		sf::RectangleShape	rightPaddle;
		float				paddleSpeed;
		
		sf::CircleShape		ball;
		float				ballSpeed;
		int					ballAngle;
		bool				ballIsColliding;
	public:
		TwoPlayerState();

		void				draw(sf::RenderTarget& target) override;
		void				handleEvent(const sf::Event& event) override;
		void				update(const float deltaTime) override;
		void				updatePaddles(const float deltaTime);
		void				updateBall(const float deltaTime);
	};
}