#pragma once
#include <Pong/Scenes/Scene.hpp>
#include <Pong/Scenes/SceneManager.hpp>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

namespace Pong
{
	namespace Scenes
	{
		class PlayScene : public Scene, public tgui::Gui
		{
			tgui::Label::Ptr pressSpacebarLabel;
			sf::RectangleShape paddleOne;
			sf::RectangleShape paddleTwo;
			bool started;
		public:
			PlayScene(SceneManager& sceneManager, sf::RenderWindow& window);
			void draw(sf::RenderTarget& target);
			void update(float deltaTime);
			void handleEvent(sf::Event& event);
		};
	}
}