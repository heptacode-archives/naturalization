#pragma once
#include "GameObject.h"
#include "CircleCollider.h"
class Enemy:
	public GameObject
{
public:
	Enemy(const wchar_t* path);
	~Enemy();

	float hp;
	void Hit(float damage);
	CircleCollider *col;
};

