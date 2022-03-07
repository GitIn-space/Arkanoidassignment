#include "Arkanoid.h"

Arkanoid::Arkanoid()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* wnd = SDL_CreateWindow("Arkanoid-look-alike", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
	render = SDL_CreateRenderer(wnd, -1, SDL_RENDERER_ACCELERATED);

	prevTicks = SDL_GetPerformanceCounter();
	deltaTime = 0.0f;
	playing = false;
	left = false;
	right = false;

	paddle = { 350, 550, 64, 16 };
}

void Arkanoid::CalcFrameRate()
{
	Uint64 ticks = SDL_GetPerformanceCounter();

	deltaTime = (float) (ticks - prevTicks) / SDL_GetPerformanceFrequency();

	prevTicks = ticks;
}

void Arkanoid::EventHandler()
{
	SDL_Event event;
	int scancode;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			playing = false;
			break;

		case SDL_KEYDOWN:
		{
			scancode = event.key.keysym.scancode;

			if (scancode == SDL_SCANCODE_ESCAPE)
				playing = false;

			if (scancode == SDL_SCANCODE_A)
				left = true;
			if (scancode == SDL_SCANCODE_D)
				right = true;

			break;
		}

		case SDL_KEYUP:
		{
			scancode = event.key.keysym.scancode;

			if (scancode == SDL_SCANCODE_A)
				left = false;
			if (scancode == SDL_SCANCODE_D)
				right = false;

			break;
		}
		}
	}
}

void Arkanoid::GameLogic()
{
	if (left)
		paddle.x -= (500 * deltaTime);

	if (right)
		paddle.x += (500 * deltaTime);
}

void Arkanoid::Render()
{
	SDL_SetRenderDrawColor(render, 25, 25, 40, 255);
	SDL_RenderClear(render);

	SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
	SDL_RenderFillRect(render, &paddle);

	SDL_RenderPresent(render);

	SDL_Delay(16);
}

void Arkanoid::Start()
{
	playing = true;
	while (playing)
	{
		CalcFrameRate();
		EventHandler();
		GameLogic();
		Render();
	}
}