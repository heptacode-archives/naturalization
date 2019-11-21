#include "stdafx.h"
#include "Bullet.h"
#include "TimeManager.h"
#include "Framework.h"
#define PI 3.141592f


Bullet::Bullet(const wchar_t* path,
	float speed, float speedRate,
	float angle, float angleRate,
	float damage)
	:GameObject(path),
	speed(speed), speedRate(speedRate),
	angle(angle), angleRate(angleRate),
	damage(damage)
{
	this->speed = speed;
	col = new CircleCollider(
		*transform, renderer->GetWidth()*0.5f);	//여기
}


Bullet::~Bullet()
{
}

void Bullet::Update()
{
	//매 프레임 실행될 함수
	Move();
	CheckOutOfScreen();
}

void Bullet::Move()
{
	//움직일 때 사용할 함수
	float rad = PI * angle* 2.0f;

	transform->position.x
		+= (speed*cosf(rad)
			*TimeManager::GetDeltaTime());
	transform->position.y
		+= (speed*sinf(rad)
			*TimeManager::GetDeltaTime());

	angle += angleRate;
	speed += speedRate;
}

void Bullet::Destroy()
{
	//삭제될 때 실행할 함수
}


bool Bullet::CheckOutOfScreen()
{
	int sw = Framework::GetInstance().GetWinApp().GetScreenWidth();
	int sh = Framework::GetInstance().GetWinApp().GetScreenHeight();
	int bw = renderer->GetWidth();
	int bh = renderer->GetHeight();
	Vector2 pos = transform->position;
	Vector2 scale = transform->scale;
	return pos.x<scale.x * bw * (-1.0f) ||
		pos.x>scale.x * bw + sw ||
		pos.y<scale.y * bh * (-1.0f) ||
		pos.y>scale.y * bh + sh;
}