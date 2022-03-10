#ifndef ARKANOID_H
#define ARKANOID_H
#include <SDL.h>
#include <iostream>
#include <vector>
#include "GameObject.h"
#include "Ball.h"

class Arkanoid
{
#define MOVESPEED 500

public:
	Arkanoid();
	void Start();

private:
	void CalcFrameRate();
	void EventHandler();
	void GameLogic();
	void Physics();
	void Update();
	void Render();

	Uint64 prevTicks;
	float deltaTime;
	bool playing;
	bool left;
	bool right;
	SDL_Renderer* render;
	GameObject* paddle;
	GameObject* ball;
	std::vector<GameObject*> renderQueue;
	std::vector<GameObject*> updateQueue;
	std::vector<GameObject*> physicsQueue;
};

#endif