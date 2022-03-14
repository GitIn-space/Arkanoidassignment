#ifndef ARKANOID_H
#define ARKANOID_H
#include <SDL.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "GameObject.h"
#include "Ball.h"
#include "Paddle.h"
#include "Block.h"

class Arkanoid
{
#define WIDTH 800
#define HEIGHT 600
#define MOVESPEED 500

public:
	Arkanoid();
	void Start();
	void Remove(GameObject*);

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
	Paddle* paddle;
	GameObject* ball;
	GameObject* leftWall;
	GameObject* rightWall;
	std::vector<GameObject*> renderQueue;
	std::vector<GameObject*> updateQueue;
	std::vector<GameObject*> physicsQueue;
};

#endif