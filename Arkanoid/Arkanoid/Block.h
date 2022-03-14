#ifndef BLOCK_H
#define BLOCK_H
#include <type_traits>
#include "GameObject.h"
#include "Ball.h"
#include "Arkanoid.h"

class Block : public GameObject
{
public:
	Block() = delete;
	Block(Uint8, Uint8, Uint8);
	void Collision(GameObject*) override;
	Block* InitialHP(int);

private:
	int hp;
};

#endif