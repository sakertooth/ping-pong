#pragma once
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <unordered_map>

namespace Pong::Scenes
{
	class Scene
	{
	public:
		virtual void draw(sf::RenderTarget& target) = 0;
		virtual void update(const sf::Time& deltaTime) = 0;
		virtual void handleEvent(const sf::Event& event) = 0;
	};
}