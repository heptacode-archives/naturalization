#include "stdafx.h"
#include "Player.h"
#include "InputManager.h"


Player::Player(const wchar_t* path,
	BulletManager* bm)
:GameObject(path),bm(bm)
{
	moveSpeed = 3.0f;
	//this->bm = bm;
}
void Player::Shoot()
{
	Bullet* b = bm->PushBackPlayerBullet(
		new Bullet(L"bullet.png", 300.0f, 0.0f,
			0.75f, 0.00f, 1.0f)
	);
	b->transform->position
		= transform->position;
}

void Player::Update()
{
	if (InputManager::GetKeyState(VK_UP))
	{
		transform->position.y -= moveSpeed;
	}
	if (InputManager::GetKeyState(VK_DOWN))
		transform->position.y += moveSpeed;
	if (InputManager::GetKeyState(VK_RIGHT))
		transform->position.x += moveSpeed;
	if (InputManager::GetKeyState(VK_LEFT))
		transform->position.x -= moveSpeed;
	if (InputManager::GetKeyDown(VK_SPACE))
	{
		Shoot();
	}
}


Player::~Player()
{
}
