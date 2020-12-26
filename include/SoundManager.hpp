#pragma once
#include <SFML/Audio.hpp>
#include <unordered_map>

namespace Pong
{
	class SoundManager
	{
		sf::SoundBuffer beepBuffer;
		sf::Sound beep;

		sf::SoundBuffer peepBuffer;
		sf::Sound peep;
		
		sf::SoundBuffer plopBuffer;
		sf::Sound plop;
	public:
		SoundManager() {}
		SoundManager(const std::string& beepFilename, const std::string& peepFilename, const std::string plopFilename);

		sf::Sound& getBeepSound();
		sf::Sound& getPeepSound();
		sf::Sound& getPlopSound();
	};
}