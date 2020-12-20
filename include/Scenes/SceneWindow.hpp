#pragma once
#include "Scenes/Scene.hpp"
#include "FPSHud.hpp"
#include <unordered_map>

namespace Pong
{
	namespace Scenes
	{
		class SceneWindow : public sf::RenderWindow
		{
		private:
			FPSHud fpsHud;
			std::unordered_map<std::string, std::shared_ptr<Scene>> scenes;
			std::shared_ptr<Scene> activeScene;
		public:
			using sf::RenderWindow::RenderWindow;

			void draw();
			void update(float deltaTime);

			void addScene(const std::string &id, const std::shared_ptr<Scene>& scene);
			void switchScene(const std::string& id);
		};
	}
}