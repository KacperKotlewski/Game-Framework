#pragma once
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Util\FPScounter.h"
#include "Util\Input.h"
#include "Util\Ticks.h"
#include "YourGame.h"

class Game
{
public:
	//functions
	Game(unsigned int witdh, unsigned int height, std::string windowName, int tick);
	~Game();

	void Run();

	int GetFPS() { return m_FPScounter.GetValue(); }

private:
	//class object
	sf::RenderWindow m_wnd;
	FPScounter m_FPScounter = FPScounter();
	Input m_input;
	Ticks m_tick;
	YourGame m_ygame = YourGame();
};

