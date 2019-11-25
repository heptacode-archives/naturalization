#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
class Image :
	public GameObject
{
public:
	Image(const wchar_t* path, Vector2 pos);
	//void ReplaceImage(int p);
	~Image();
	AABBCollider* col;

	virtual void Update();
};

