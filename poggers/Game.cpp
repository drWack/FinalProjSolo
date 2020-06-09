#include "Game.h"
#include <iostream>

SDL_Surface* tempSurface;
SDL_Texture* AsterTex;

bool loadMedia();
Game::Game()
{
	isActive = false;
}

Game::~Game()
{
}

void Game::init(const char* title, int xpos, int ypos, int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) //if not initialized, initialize
	{
		std::cout << "subsystems initialized" << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, false);
		std::cout << "window created" << std::endl;
		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
		std::cout << "renderer created" << std::endl;

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		std::cout << "window drawn" << std::endl;

		isActive = true;
	}
	else { isActive = false; }
	const char* titl ="assets\asteroid.png";
	loadMedia();
	AsterTex = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	SDL_BlitSurface(curr, NULL, tempSurface,NULL);
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isActive = false; std::cout << "user has quit"<<std::endl;
		break;

	default:
		break;
	}
}

void Game::update()
{
}

void Game::render()// use this to draw each thing in order
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer,AsterTex,NULL,NULL);
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	tempSurface = SDL_LoadBMP("assets\asteroid.png");
	if (tempSurface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
		success = false;
	}

	return success;
}