#pragma once
#include "Scene.hpp"
#include "Objects/Paddle.hpp"
#include "Objects/Ball.hpp"
#include <TGUI/TGUI.hpp>

namespace Pong::Scenes
{
	class TwoPlayerScene : public Scene, public tgui::Gui
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
		TwoPlayerScene();

		virtual void draw(sf::RenderTarget& target) override;
		virtual void update(const sf::Time& deltaTime) override;
		virtual void handleEvent(const sf::Event& event) override;
		void updateScoreboard();
	};
}