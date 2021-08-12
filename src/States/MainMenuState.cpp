#include "MainMenuState.hpp"

void MainMenuState::update(const sf::Time& deltaTime) {
    twoPlayerButton.update(deltaTime);
}

void MainMenuState::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    twoPlayerButton.draw(target, states);
}