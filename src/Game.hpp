#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <stack>
#include "Updatable.hpp"
#include "SoundManager.hpp"

class Game 
{
public:
    Game();
    ~Game();
    
    void handleEvent();
    void update(const sf::Time& deltaTime);
    void draw();
    void stop();

    void pushState(std::unique_ptr<Updatable> state);
    void popState();
    void clearAllStates();
    void playSound(SoundManager::SoundType soundType);

    const bool isRunning();

    static Game& getInstance();
    const sf::RenderWindow& getWindow();
    const sf::Font& getFont();
    
private:
    sf::RenderWindow window;
    sf::Font font;
    SoundManager soundManager;
    std::stack<std::unique_ptr<Updatable>> states;
};
