#include "Game.hpp"
#include "States/MainMenuState.hpp"

int main() {
    auto &game = Game::getInstance();
    auto clock = sf::Clock();

    game.pushState(std::make_unique<MainMenuState>());
    while (game.isRunning()) {
        game.handleEvent();
        game.update(clock.restart());
        game.draw();
    }
}
