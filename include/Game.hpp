#pragma once
#include "States/State.hpp"

namespace Pong
{
	class Game
	{
		sf::RenderWindow window;
		std::shared_ptr<States::State> currentState;
	public:
		void init();

		void stop();

		void draw();

		void update(const float deltaTime);

		void handleEvent();

		void swtichState(const std::shared_ptr<States::State> state);

		bool isRunning();

		static Game& getInstance();

		sf::RenderWindow& getWindow();

		~Game();
	};
}