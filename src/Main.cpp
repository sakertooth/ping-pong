#include <iostream>
#include "Game.hpp"

int main() {
    auto &game = Game::getInstance();
    auto clock = sf::Clock::Clock();

    while (game.isRunning()) {
        game.update(clock.getElapsedTime());
        game.draw();
    }
}
