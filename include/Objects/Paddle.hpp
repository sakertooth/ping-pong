#pragma once
#include <SFML/Graphics.hpp>

namespace Pong::Objects
{
	class Paddle : public sf::RectangleShape
	{
	private:
		int points;
		sf::Keyboard::Key upKey;
		sf::Keyboard::Key downKey;
	public:
		static constexpr float speed = 500;
		Paddle(sf::Keyboard::Key upKey, sf::Keyboard::Key downKey);

		void update(const float deltaTime);
		void incrementPoint();
		const int& getPoints() const;
	};
}