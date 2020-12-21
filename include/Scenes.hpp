#pragma once
#include <TGUI/TGUI.hpp>
#include "Scenes/Scene.hpp"
#include "Objects/Paddle.hpp"
#include "Objects/Ball.hpp"

namespace Pong
{
	namespace Scenes
	{
		class MainMenuScene : public Scene, public tgui::Gui
		{
			tgui::Label::Ptr titleLabel;
			tgui::Button::Ptr playButton;
			tgui::Button::Ptr creditsButton;
			tgui::Button::Ptr exitButton;
		public:
			MainMenuScene();

			virtual void draw(sf::RenderTarget& target) override;
			virtual void update(float deltaTime) override;
			virtual void handleEvent(sf::Event& event) override;
		};

		class PlayScene : public Scene
		{
			Objects::Paddle paddleOne;
			Objects::Paddle paddleTwo;
			Objects::Ball ball;

			sf::Text paddleOneScore;
			sf::Text paddleTwoScore;

			sf::RectangleShape separatorLine;

			sf::Text noteText;
			bool started;
			bool over;
		public:
			PlayScene();

			virtual void draw(sf::RenderTarget& target) override;
			virtual void update(float deltaTime) override;
			virtual void handleEvent(sf::Event& event) override;
		};
	}
}