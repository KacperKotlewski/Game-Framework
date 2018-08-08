#pragma once
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "FPScounter.h"
#include "Input.h"
#include "Ticks.h"
#include "..\Your\YourGame.h"

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

