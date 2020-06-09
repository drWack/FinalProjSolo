#ifndef GameHeader
#define GameHeader

#include "SDL.h"
#include <stdio.h> 
#include <vector>
#include "SDL_image.h"
class Game
{ 
public:
	Game();
	~Game();
	void init(const char* title, int xpos, int ypos, int width, int height);
	bool Active() { return isActive; }
	void handleEvents();
	void update();
	void render();
	void clean(); 
private:
	bool isActive;
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::vector<SDL_Surface*> entities;
	SDL_Surface* curr;
};
#endif