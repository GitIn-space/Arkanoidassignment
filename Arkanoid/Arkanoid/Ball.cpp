#include "Ball.h"

Ball::Ball(Uint8 r, Uint8 g, Uint8 b) : GameObject::GameObject(r, g, b)
{
	dirX = 1;
	dirY = 1;
}

void Ball::Update()
{
	go.x += dirX;
	go.y += dirY;
}

void Ball::Collision(GameObject* collider)
{
	dirX += dirY;
	dirY = dirX - dirY;
	dirX -= dirY;
	dirX *= -1;

	collider->Collision(this);
}