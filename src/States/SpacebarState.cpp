#include "SpacebarState.hpp"
#include "OnePlayerState.hpp"
#include "../Updatable.hpp"
#include "../Game.hpp"
#include <cmath>

SpacebarState::SpacebarState(std::unique_ptr<Updatable> nextState) {
    this->nextState = std::move(nextState);

    spacebarContinueText.setFont(Game::getInstance().getFont());
    spacebarContinueText.setCharacterSize(32);
    spacebarContinueText.setString("Press spacebar to begin");
    spacebarContinueText.setOrigin(std::round(spacebarContinueText.getLocalBounds().width / 2.0f),
                                    std::round(spacebarContinueText.getLocalBounds().height / 2.0f));

    const auto& window = Game::getInstance().getWindow();
    spacebarContinueText.setPosition(static_cast<float>(window.getSize().x / 2), 
                                    static_cast<float>(window.getSize().y / 2));
}

void SpacebarState::update(const sf::Time& deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && nextState) {
        Game::getInstance().pushState(std::make_unique<OnePlayerState>());
    }
}

void SpacebarState::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(spacebarContinueText, states);
}