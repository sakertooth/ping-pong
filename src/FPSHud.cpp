#include "FPSHud.hpp"
#include "Resources.hpp"

#include <iostream>

namespace Pong
{
	FPSHud::FPSHud() : toggled(false)
	{
		setFont(ResourceManager::getGameFont());
		setPosition(10, 10);
		
	}

	void FPSHud::draw(sf::RenderTarget& target)
	{
		if (toggled)
		{
			target.draw(*this);
		}
	}

	void FPSHud::update(float deltaTime)
	{
		if (toggled && clock.getElapsedTime().asSeconds() >= 0.2)
		{
			setString("FPS: " + std::to_string(static_cast<int>(1 / deltaTime)));
			clock.restart();
		}
	}

	void FPSHud::setToggled(bool toggled)
	{
		this->toggled = toggled;
	}

	const bool& FPSHud::getToggled()
	{
		return toggled;
	}
}