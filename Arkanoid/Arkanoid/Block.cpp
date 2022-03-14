#include "Block.h"

Block::Block(Uint8 r, Uint8 g, Uint8 b) : GameObject::GameObject(r, g, b)
{
	hp = 0;
}

void Block::Collision(GameObject* collider)
{
	if (dynamic_cast<Ball*>(collider))
	{
		hp--;
		if (hp <= 0)
			delete this;
	}
}

Block* Block::InitialHP(int hp)
{
	this->hp = hp;

	return this;
}