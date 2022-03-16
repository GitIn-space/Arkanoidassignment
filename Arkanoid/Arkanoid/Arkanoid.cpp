#include "Arkanoid.h"

Arkanoid::Arkanoid()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* wnd = SDL_CreateWindow("Arkanoid-look-alike", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
	render = SDL_CreateRenderer(wnd, -1, SDL_RENDERER_ACCELERATED);

	prevTicks = SDL_GetPerformanceCounter();
	deltaTime = 0.0f;
	playing = false;
	left = false;
	right = false;

	paddle = new Paddle(0, 0, 255);
	renderQueue.push_back(paddle);
	physicsQueue.push_back(paddle);

	renderQueue.push_back((new GameObject(232, 0, 254))->InitialMove(0, 0)->InitialDimensions(800, 16));
	physicsQueue.push_back(renderQueue.back());

	renderQueue.push_back((new GameObject(232, 0, 254))->InitialMove(0, 0)->InitialDimensions(16, 600));
	physicsQueue.push_back(renderQueue.back());
	leftWall = renderQueue.back();

	renderQueue.push_back((new GameObject(232, 0, 254))->InitialMove(784, 0)->InitialDimensions(16, 600));
	physicsQueue.push_back(renderQueue.back());
	rightWall = renderQueue.back();

	ball = (new Ball(0, 255, 255))->InitialMove(350, 500)->InitialDimensions(16, 16);
	renderQueue.push_back(ball);
	updateQueue.push_back(ball);

	renderQueue.push_back((new Block(255, 255, 0))->InitialHP(1)->InitialMove(32, HEIGHT / 2)->InitialDimensions(64, 16));
	physicsQueue.push_back(renderQueue.back());

	renderQueue.push_back((new Block(255, 255, 0))->InitialHP(1)->InitialMove(128, HEIGHT / 2)->InitialDimensions(64, 16));
	physicsQueue.push_back(renderQueue.back());
}

Arkanoid& Arkanoid::getInstance()
{
	static Arkanoid instance;
	return instance;
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
	if (left && !SDL_HasIntersection(paddle->GetRect(), leftWall->GetRect()))
		paddle->MoveX(-(MOVESPEED * deltaTime));

	if (right && !SDL_HasIntersection(paddle->GetRect(), rightWall->GetRect()))
		paddle->MoveX((MOVESPEED * deltaTime));

	if (ball->GetRect()->y >= 600)
		playing = false;
}

void Arkanoid::Physics()
{
	for (GameObject* each : physicsQueue)
		if (SDL_HasIntersection(ball->GetRect(), each->GetRect()))
			ball->Collision(each);
}

void Arkanoid::Update()
{
	for (GameObject* each : updateQueue)
		each->Update();
}

void Arkanoid::Render()
{
	SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
	SDL_RenderClear(render);

	for (GameObject* each : renderQueue)
		each->Render(render);

	SDL_RenderPresent(render);

	SDL_Delay(4);
}

void Arkanoid::Remove(GameObject* go)
{
	if (std::find(renderQueue.begin(), renderQueue.end(), go) != renderQueue.end())
		renderQueue.erase(std::remove(renderQueue.begin(), renderQueue.end(), go));
	if (std::find(updateQueue.begin(), updateQueue.end(), go) != updateQueue.end())
		updateQueue.erase(std::remove(updateQueue.begin(), updateQueue.end(), go));
	if (std::find(physicsQueue.begin(), physicsQueue.end(), go) != physicsQueue.end())
		physicsQueue.erase(std::remove(physicsQueue.begin(), physicsQueue.end(), go));
}

void Arkanoid::Start()
{
	playing = true;
	while (playing)
	{
		CalcFrameRate();
		EventHandler();
		GameLogic();
		Physics();
		Update();
		Render();
	}
}