#pragma once
#include "State.hpp"
#include "Ball.hpp"
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

namespace Pong::States
{
	class TwoPlayerState : public State
	{
	protected:
		sf::Text			leftPaddleScore;
		sf::Text			rightPaddleScore;
		sf::RectangleShape	leftPaddle;
		sf::RectangleShape	rightPaddle;
		Ball ball;
		sf::RectangleShape	separator;
		float				paddleSpeed;
	public:
		TwoPlayerState();

		virtual void		draw(sf::RenderTarget& target) override;
		virtual void		handleEvent(const sf::Event& event) override {}
		virtual void		update(const float deltaTime) override;
	};
}