#pragma once
#include <SFML/Audio.hpp>
#include <map>

class SoundManager {
public:
    enum class SoundType {
        BEEP,
        PEEP,
        PLOP
    };

    SoundManager();
    void playSound(SoundType soundType);
private:
    std::map<SoundType, std::pair<sf::Sound, sf::SoundBuffer>> sounds;
};