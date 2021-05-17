#pragma once
#include "States/State.hpp"
#include "SoundManager.hpp"

namespace Pong
{
	class Game
	{
		sf::RenderWindow window;
		sf::Time deltaTime;
		sf::Font gameFont;
		std::shared_ptr<State> currentState;
		std::map<std::string, std::pair<sf::SoundBuffer, sf::Sound>> sounds;
	public:
		Game();
		~Game();

		void init();
		void stop();
		void draw();
		void update(const sf::Time& deltaTime);
		void handleEvent();
		void switchState(const std::shared_ptr<State> state);
		bool isRunning();
		void registerSound(const std::string &id, const std::string &file);

		static Game &getInstance();
		const sf::Font &getFont();
		const sf::RenderWindow &getWindow();
		const sf::Sound &getSound(const std::string& id);
	};
}