#pragma once
#include <Pong/Scenes/Scene.hpp>
#include <SFML/Graphics.hpp>

namespace Pong
{
	namespace Scenes
	{
		class PlayScene : public Scene
		{
			sf::Text m_pressSpacebarText;
			sf::RectangleShape m_paddleOne;
			sf::RectangleShape m_paddleTwo;
		public:
			void draw();
			void update(float deltaTime);
			void handleEvent(sf::Event& event);
		};
	}
}