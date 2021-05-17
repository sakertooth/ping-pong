#include "SoundManager.hpp"

namespace Pong
{
  SoundManager::SoundManager(const std::string &beepFilename,
                             const std::string &peepFilename,
                             const std::string plopFilename)
  {
    beepBuffer.loadFromFile(beepFilename);
    beep.setBuffer(beepBuffer);

    peepBuffer.loadFromFile(peepFilename);
    peep.setBuffer(peepBuffer);

    plopBuffer.loadFromFile(plopFilename);
    plop.setBuffer(plopBuffer);
  }

  sf::Sound &SoundManager::getBeepSound() { return beep; }

  sf::Sound &SoundManager::getPeepSound() { return peep; }

  sf::Sound &SoundManager::getPlopSound() { return plop; }
} // namespace Pong