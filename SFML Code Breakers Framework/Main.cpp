//v 0.2.0

#include <iostream>

#include "GameCore\GameMain.h"

unsigned int	GAME_WITDH	= 800;
unsigned int	GAME_HEIGHT = 600;
int				GAME_TICK	= 60;
std::string		GAME_NAME	= "Game";

int main()
{
	//*
	Game game(GAME_WITDH, GAME_HEIGHT, GAME_NAME, GAME_TICK);
	game.Run();
	//*/

	return 0;
}