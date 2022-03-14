#ifndef PADDLE_H
#define PADDLE_H
#include "GameObject.h"

class Paddle : public GameObject
{
public:
	Paddle() = delete;
	Paddle(Uint8, Uint8, Uint8);
	void MoveX(int);
};

#endif