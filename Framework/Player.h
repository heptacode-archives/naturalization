#pragma once
#include "GameObject.h"
#include "BulletManager.h"			//여기
class Player : public GameObject {
public:
	Player(const wchar_t* path, BulletManager* bm);			//여기
	~Player();

	float moveSpeed;	//이동 속도
	virtual void Update();	//업데이트 처리

	BulletManager* bm;				//여기
	void Shoot();					//여기
};