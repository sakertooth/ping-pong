#pragma once
#include <Pong/Scenes/SceneManager.hpp>
#include <Pong/Scenes/Scene.hpp>

namespace Pong
{
	namespace Scenes
	{
		class PlayScene : public Scene
		{
		public:
			PlayScene(SceneManager& manager, sf::RenderTarget& target);
			void draw();
			void update(float deltaTime);
			void handleEvent(sf::Event& event);
		};
	}
}