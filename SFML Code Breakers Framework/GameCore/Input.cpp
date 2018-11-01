#include "Input.h"



Input::Input()
{
}


Input::~Input()
{
}

bool Input::isKeyPressed(sf::Keyboard::Key key)
{
	return keyboard.isKeyPressed(key);
}

bool Input::toggleKey(sf::Keyboard::Key key)
{
	if ((key != m_key) || m_delayTimer.CheckDelay(0.2f))
	{
		m_key = key;
		if (sf::Keyboard::isKeyPressed(key))
		{
			m_delayTimer.Update();
			return true;
		}
	}
	return false;
}

bool Input::isButtonPressed(sf::Mouse::Button button)
{
	return mouse.isButtonPressed(button);
}

int Input::getMouseX()
{
	return int(mouse.getPosition().x);
}
int Input::getMouseY()
{
	return int(mouse.getPosition().y);
}
