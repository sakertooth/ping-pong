#pragma once
#include <SFML/Graphics.hpp>
#include "States/State.hpp"

class Game 
{
public:
    Game();
    ~Game();
    
    static Game& getInstance();
    
    void update(const sf::Time& deltaTime);
    void draw();
    void stop();

    const bool isRunning();
    const sf::RenderWindow& getWindow();
    void switchState(std::shared_ptr<State> newState);

private:
    sf::RenderWindow window;
    std::shared_ptr<State> currentState;
};

