#include "Ticks.h"



Ticks::Ticks(int tickRate)
	:
	m_tick(tickRate)
{
	m_tickPerUpdate = sf::seconds(1.0f / m_tick);

	m_timer.restart();

	m_lastTick = sf::Time::Zero;

	m_deltatime = sf::Time::Zero;
}

Ticks::~Ticks()
{
}

void Ticks::Update()
{
	m_elapsed = m_timer.getElapsedTime() - m_lastTick;
	m_deltatime += m_elapsed;

	m_lastTick = m_timer.getElapsedTime();

	while (m_deltatime > m_tickPerUpdate)
	{
		tickCount++;
		m_deltatime -= m_tickPerUpdate;
	}
}

