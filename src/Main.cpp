#include <iostream>
#include "Game.hpp"

int main() {
    auto &game = Game::getInstance();
    auto clock = sf::Clock();

    game.init();
    while (game.isRunning()) {
        game.update(clock.restart());
        game.draw();
    }
}
