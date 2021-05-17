#include "States/SpacebarToPlayState.hpp"
#include "States/OnePlayerState.hpp"
#include "States/TwoPlayerState.hpp"
#include "Game.hpp"

namespace Pong
{
	SpacebarToStartState::SpacebarToStartState() : tgui::Gui(Game::getInstance().getWindow()),
		spacebarLabel(tgui::Label::create())
	{
		spacebarLabel->setText("		Press spacebar to start\n		First to 11 points wins");
		spacebarLabel->setTextSize(30);
		spacebarLabel->setPosition("(&.size - size) / 2");
		spacebarLabel->getRenderer()->setFont("assets/font.ttf");
		spacebarLabel->getRenderer()->setTextColor(tgui::Color::White);
		add(spacebarLabel);
	}

	SpacebarToStartState::SpacebarToStartState(const Difficulty& difficulty) : SpacebarToStartState::SpacebarToStartState()
	{
		onePlayerDifficulty = difficulty;
	}

	void SpacebarToStartState::draw(sf::RenderTarget& target)
	{
		tgui::Gui::draw();
	}

	void SpacebarToStartState::handleEvent(const sf::Event& event)
	{
		tgui::Gui::handleEvent(event);

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Space)
		{
			if (onePlayerDifficulty.has_value())
				Game::getInstance().switchState(std::make_shared<OnePlayerState>(onePlayerDifficulty.value()));
			else
				Game::getInstance().switchState(std::make_shared<TwoPlayerState>());
		}
	}
}