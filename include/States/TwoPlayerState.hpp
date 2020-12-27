#pragma once
#include "State.hpp"
#include "Ball.hpp"
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

namespace Pong::States
{
	class TwoPlayerState : public State
	{
		sf::Font			scoreFont;

		sf::Text			leftPaddleScore;
		sf::Text			rightPaddleScore;
		
		sf::RectangleShape	leftPaddle;
		sf::RectangleShape	rightPaddle;
		Ball ball;

		sf::RectangleShape	separator;

		int					ballAngle;
		float				paddleSpeed;
		float				ballSpeed;
	public:
		TwoPlayerState();

		void				draw(sf::RenderTarget& target) override;
		void				handleEvent(const sf::Event& event) override {}
		void				update(const float deltaTime) override;
		void				updatePaddles(const float deltaTime);
		void				updateBall(const float deltaTime);
	};
}