#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL.h>

class GameObject
{
public:
	GameObject() = delete;
	GameObject(Uint8, Uint8, Uint8);
	SDL_Rect* GetRect();
	virtual void Render(SDL_Renderer*);
	virtual void Update();
	virtual GameObject* InitialMove(int, int);
	virtual GameObject* InitialDimensions(int, int);
	virtual void Collision(GameObject*);
	
	void MoveX(int);

protected:
	Uint8 r;
	Uint8 g;
	Uint8 b;
	SDL_Rect go;
};

#endif