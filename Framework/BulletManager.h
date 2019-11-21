#pragma once
#include "GameObject.h"
#include "Bullet.h"
class BulletManager :
	public GameObject
{
public:
	BulletManager();
	~BulletManager();

	std::list<Bullet*> playerBullets;
	Bullet* PushBackPlayerBullet(Bullet* b);
	void Destroy(Bullet* b);
	virtual void LateUpdate();

private:
	std::list<Bullet*> destroyed;
	void Remove();
};

