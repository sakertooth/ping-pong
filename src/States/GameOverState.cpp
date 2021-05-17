#include "States/GameOverState.hpp"
#include "States/MainMenuState.hpp"
#include "Game.hpp"

namespace Pong
{
	GameOverState::GameOverState(const std::string& message)
	{
		const auto& window = Game::getInstance().getWindow();

		this->message.setFont(Game::getInstance().getFont());
		this->message.setCharacterSize(24);
		this->message.setString(message);
		this->message.setOrigin(this->message.getGlobalBounds().left + this->message.getGlobalBounds().width / 2, this->message.getGlobalBounds().top + this->message.getGlobalBounds().height / 2);
		this->message.setPosition(static_cast<float>(window.getSize().x) / 2.0f, static_cast<float>(window.getSize().y) / 2.0f);
	}

	void GameOverState::draw(sf::RenderTarget& target)
	{
		target.draw(message);
	}

	void GameOverState::handleEvent(const sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
		{
			Game::getInstance().switchState(std::make_shared<MainMenuState>());
		}
	}
}