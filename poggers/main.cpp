// C++ Implementation for drawing line
#include "SDL.h"
#include <stdio.h>
#include "Game.h"
// driver code 


Game* myGame = nullptr;
int main(int argc, char *argv[])
{
	myGame = new Game;
	const char* title = "asteriods";
	myGame->init(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600);
	while (myGame->Active())
	{
		myGame->handleEvents();
		myGame->update();
		myGame->render();

	}
	myGame->clean();
	return 0;
	
}