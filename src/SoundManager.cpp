#include "SoundManager.hpp"
#include <iostream>

SoundManager::SoundManager() {
    std::map<SoundType, std::string> unloadedSounds;
    unloadedSounds.emplace(SoundType::BEEP, "assets/beep.ogg");
    unloadedSounds.emplace(SoundType::PEEP, "assets/peep.ogg");
    unloadedSounds.emplace(SoundType::PLOP, "assets/plop.ogg");

    for (const auto& unloadedSound : unloadedSounds) {
        auto& soundType = std::get<0>(unloadedSound);
        sounds.emplace(soundType, std::make_pair(sf::Sound(), sf::SoundBuffer()));

        auto& soundBuffer = std::get<1>(sounds[soundType]);
        if (!soundBuffer.loadFromFile(unloadedSounds[soundType])) {
            continue;
        }

        auto& sound = std::get<0>(sounds[soundType]);
        sound.setBuffer(soundBuffer);
    }
}

void SoundManager::playSound(SoundType soundType) {
    auto& sound = std::get<0>(sounds[soundType]);
    sound.play();
}