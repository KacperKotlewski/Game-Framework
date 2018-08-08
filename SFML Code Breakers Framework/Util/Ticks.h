#pragma once

#include <SFML\Graphics.hpp>

class Ticks
{
public:
	Ticks(int tickRate);

	void Update();
	sf::Time getElapsed() { return m_elapsed; }
	int tickCount = 0;

	~Ticks();
private:
	int m_tick;
	sf::Time m_tickPerUpdate;
	sf::Time m_lastTick;
	sf::Time m_deltatime;
	sf::Clock m_timer;
	sf::Time m_elapsed;
};

