#include "Ball.h"

Ball::Ball(Uint8 r, Uint8 g, Uint8 b) : GameObject::GameObject(r, g, b)
{
	dirX = 0;
	dirY = -1;
}

void Ball::Update()
{
	go.x += dirX;
	go.y += dirY;
}

void Ball::Collision(GameObject* collider)
{
	SDL_Rect* col = collider->GetRect();
}