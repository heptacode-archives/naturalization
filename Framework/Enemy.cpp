#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy(const wchar_t* path) :GameObject(path), hp(100.0f) {
	col = new CircleCollider(*transform, renderer->GetWidth() * 0.5f);
}

Enemy::~Enemy() {
	SAFE_DELETE(col);
}

void Enemy::Hit(float damage) {
	hp -= damage;
	std::cout << "hp°¡" << hp << "³²À½\n";
}