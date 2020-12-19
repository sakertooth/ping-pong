#pragma once
#include <Pong/Scenes/Scene.hpp>
#include <Pong/Scenes/SceneManager.hpp>
#include <TGUI/TGUI.hpp>

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
			MainMenuScene(SceneManager& sceneManager, sf::RenderWindow& window);
			void draw(sf::RenderTarget& target);
			void update(float deltaTime);
			void handleEvent(sf::Event& event);
		};
	}
}