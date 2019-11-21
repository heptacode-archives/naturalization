#pragma once
#include "GameObject.h"
#include "Player.h"
#include "EnemyManager.h"
class PhysicsManager : public GameObject {
public:
	PhysicsManager(Player* p, EnemyManager* em, BulletManager* bm);
	~PhysicsManager();

	Player* p;
	EnemyManager* em;
	BulletManager* bm;
	virtual void LateUpdate();
};