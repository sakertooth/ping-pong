#pragma once
#include <Pong/Scenes/Scene.hpp>
#include <Pong/Scenes/SceneManager.hpp>
#include <TGUI/TGUI.hpp>

namespace Pong
{
	namespace Scenes
	{
		class CreditsScene : public Scene, public tgui::Gui
		{
			tgui::Label::Ptr creditsLabel;
			tgui::Button::Ptr goBackButton;
		public:
			CreditsScene(SceneManager& sceneManager, sf::RenderWindow& window);
			void draw(sf::RenderTarget& target);
			void update(float deltaTime);
			void handleEvent(sf::Event& event);
		};
	}
}