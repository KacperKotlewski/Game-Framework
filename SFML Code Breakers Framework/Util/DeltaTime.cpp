#include "DeltaTime.h"



DeltaTime::DeltaTime()
{
	Update();
}


DeltaTime::~DeltaTime()
{
}

void DeltaTime::Update()
{
	m_delayTimer.restart();
}

bool DeltaTime::CheckDelay(float second)
{
	if (m_delayTimer.getElapsedTime().asSeconds() > second)
	{
		return true;
		Update();
	}
	return false;
}

sf::Clock DeltaTime::Get()
{
	return m_delayTimer;
}
