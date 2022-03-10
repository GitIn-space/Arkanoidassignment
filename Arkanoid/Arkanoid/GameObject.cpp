#include "GameObject.h"

GameObject::GameObject(Uint8 r, Uint8 g, Uint8 b)
{
	this->r = r;
	this->g = g;
	this->b = b;

	go = { 350, 550, 64, 16 };
}

void GameObject::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderFillRect(renderer, &go);
}

SDL_Rect* GameObject::GetRect()
{
	return &go;
}

void GameObject::Update()
{
	
}

GameObject* GameObject::InitialMove(int x, int y)
{
	go.x = x;
	go.y = y;

	return this;
}

GameObject* GameObject::InitialDimensions(int w, int h)
{
	go.w = w;
	go.h = h;

	return this;
}

void GameObject::Collision(GameObject* collider)
{

}

void GameObject::MoveX(int x)
{
	go.x += x;
}