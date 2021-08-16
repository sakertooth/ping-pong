#include "SpacebarState.hpp"
#include <cmath>

SpacebarState::SpacebarState(std::shared_ptr<State> nextState) {
    this->nextState = nextState;
    spacebarContinueText.setFont(Game::getInstance().getFont());
    spacebarContinueText.setString("Press spacebar to continue");
    spacebarContinueText.setOrigin(std::round(spacebarContinueText.getLocalBounds().width / 2.0f),
                                    std::round(spacebarContinueText.getLocalBounds().height / 2.0f));
    
    const auto& window = Game::getInstance().getWindow();
    spacebarContinueText.setPosition(window.getSize().x / 2, window.getSize().y / 2);
}

void SpacebarState::init() {}

void SpacebarState::update(const sf::Time& deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        nextState->init();
        Game::getInstance().switchState(nextState);
    }
}

void SpacebarState::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(spacebarContinueText, states);
}