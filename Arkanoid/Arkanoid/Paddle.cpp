#include "Paddle.h"

Paddle::Paddle(Uint8 r, Uint8 g, Uint8 b) : GameObject::GameObject(r, g, b)
{
	
}

void Paddle::MoveX(int x)
{
	go.x += x;
}