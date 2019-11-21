#pragma once
#include "GameObject.h"
#include "CircleCollider.h"			//여기 추가
class Bullet : public GameObject {
public:
	Bullet(const wchar_t* path, float speed, float speedRate, float angle, float angleRate, float damage);
	~Bullet();
	float speed;
	float speedRate;
	float angle;
	float angleRate;
	float damage;

	bool CheckOutOfScreen();

	CircleCollider* col;			//여기도

	virtual void Update();
	virtual void Move();
	virtual void Destroy();
};
