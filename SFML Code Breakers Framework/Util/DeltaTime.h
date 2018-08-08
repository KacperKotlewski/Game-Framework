#pragma once

#include <SFML\Graphics.hpp>

class DeltaTime
{
public:
	DeltaTime();
	~DeltaTime();

	void Update();
	bool CheckDelay(float second);
	sf::Clock Get();

private:
	sf::Clock m_delayTimer;
};

