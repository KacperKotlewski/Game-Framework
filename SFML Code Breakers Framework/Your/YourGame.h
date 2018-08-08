#pragma once

#include <SFML\Graphics.hpp>

#include "..\GameCore\Input.h"
#include "..\ResourceManager\ResourceHolder.h"

class Game;

class YourGame
{
public:
	YourGame();
	~YourGame();
	
	void m_LogicUpdate(sf::Time deltaTime);
	void m_FixedUpdate(sf::Time deltaTime);
	void m_FrameUpdate(sf::RenderWindow & render);

private:
	ResourceHolder res
};

