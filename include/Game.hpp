#pragma once
#include "States/State.hpp"
#include "SoundManager.hpp"

namespace Pong
{
	class Game
	{
		sf::RenderWindow				window;
		sf::Time						deltaTime;
		sf::Font						gameFont;
		std::shared_ptr<States::State>	currentState;
		SoundManager					soundManager;
	public:
		Game();
		~Game();

		void				init();
		void				stop();
		void				draw();
		void				update();
		void				handleEvent();
		void				switchState(const std::shared_ptr<States::State> state);
		bool				isRunning();

		static Game&		getInstance();
		const sf::Time&		getDeltaTime();
		sf::Font&			getFont();
		sf::RenderWindow&	getWindow();
		SoundManager&		getSoundManager();

		void				setDeltaTime(const sf::Time& time);
	};
}