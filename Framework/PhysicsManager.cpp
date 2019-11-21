#include "stdafx.h"
#include "PhysicsManager.h"

PhysicsManager::PhysicsManager(Player * p, EnemyManager * em, BulletManager * bm) : p(p), em(em), bm(bm)
{
}

void PhysicsManager::LateUpdate()
{
	if (!bm || !em || !p)
		return;
	for (auto& i : bm->playerBullets) {
		for (auto& j : em->enemyList) {
			if (i->col->Intersected(*j->col)) {
				em->Hit(j, i->damage);
				bm->Destroy(i);
			}
		}
	}
}

PhysicsManager::~PhysicsManager()
{
}