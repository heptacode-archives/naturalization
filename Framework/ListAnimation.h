#pragma once
#include "Animation.h"

class ListAnimation
	:public Animation
{
public:
	ListAnimation(const int state, float fps); //초기화 단계에서 PushBackSprite로 list 완성
	virtual ~ListAnimation();
public:
	std::list<Sprite*> sprites;
	std::list<Sprite*>::iterator iter;			//현재 Sprite값

public:
	virtual void SetSourceRect(D2D1_RECT_F& outRect) {}
	virtual Sprite* UpdateAnim(); 
	virtual Sprite* GetCurrentSprite();
	virtual Vector2 GetAnimationSize();
	virtual void Reset();
	void PushBackSprite(Sprite* sprite);
	void PushBackSprite(const wchar_t* path);
};
