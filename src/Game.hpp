#pragma once
#include <SFML/Graphics.hpp>
#include "States/State.hpp"
#include <memory>

class Game 
{
public:
    Game();
    ~Game();
    
    static Game& getInstance();
    
    void update(const sf::Time& deltaTime);
    void init();
    void draw();
    void stop();

    const bool isRunning();
    void switchState(std::shared_ptr<State> newState);
    
    sf::RenderWindow& getWindow();
    const sf::Font& getFont();

private:
    sf::RenderWindow window;
    std::shared_ptr<State> currentState;
    sf::Font font;
};

