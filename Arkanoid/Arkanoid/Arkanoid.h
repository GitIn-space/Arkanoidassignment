#ifndef ARKANOID_H
#define ARKANOID_H
#include <SDL.h>
#include <iostream>

class Arkanoid
{
public:
	Arkanoid();
	void Start();

private:
	void CalcFrameRate();
	void EventHandler();
	void GameLogic();
	void Render();

	Uint64 prevTicks;
	float deltaTime;
	bool playing;
	bool left;
	bool right;
	SDL_Renderer* render;
	SDL_Rect paddle;
};

#endif