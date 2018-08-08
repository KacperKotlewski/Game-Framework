#pragma once

#include <SFML/Graphics.hpp>

#include "DeltaTime.h"

class Input
{
public:
	Input();
	~Input();

	bool isKeyPressed(sf::Keyboard::Key key);
	bool toggleKey(sf::Keyboard::Key key);
	bool isButtonPressed(sf::Mouse::Button button);
	int getMouseX();
	int getMouseY();

	//object
	sf::Keyboard keyboard;
	sf::Mouse mouse;

private:
	DeltaTime m_delayTimer;
	sf::Keyboard::Key m_key;
};

