#pragma once
#include "ResourceManager.h"

class Animation
{
public:
	Animation(const int state, float fps);
public:
	const int state;		//애니메이션의 state number
	int currentFrame;			//현재 frame number
	float frameTime;		//현재 애니메이션의 시간
	int length;				//애니메이션의 프레임 개수
protected:
	float fps;				//애니메이션을 실행할 fps
	float reciprocalFPS;	//1/fps

public:
	void SetFPS(float fps);
	float GetFPS(float fps);
public:
	virtual void SetSourceRect(D2D1_RECT_F& outRect)=0;
	virtual Sprite* UpdateAnim() = 0;
	virtual Sprite* GetCurrentSprite() = 0;
	virtual Vector2 GetAnimationSize() = 0;
	virtual void Reset();
};