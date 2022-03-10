#ifndef BALL_H
#define BALL_H
#include "GameObject.h"

class Ball : public GameObject
{
public:
	Ball() = delete;
	Ball(Uint8, Uint8, Uint8);
	void Update() override;
	void Collision(GameObject*) override;

private:
	int dirX;
	int dirY;
};

#endif