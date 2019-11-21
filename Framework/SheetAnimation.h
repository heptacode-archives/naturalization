#pragma once
#include "Animation.h"

class SheetAnimation
	:public Animation
{
public:
	SheetAnimation(const int state, float fps, const wchar_t* sheetPath, int pixelWidth, int pixelHeight, int length);	//pixelWidth,Height: 한 프레임의 가로,세로크기
	SheetAnimation(const int state, float fps, const wchar_t* sheetPath, int row,  int length);	//row: 가로에 저장된 애니메이션의 개수
public:
	Sprite* sheet;
	int width, height;	//애니메이션을 자를 단위
	int rowCount;
	virtual void SetSourceRect(D2D1_RECT_F& outRect);
	virtual Sprite* GetCurrentSprite();
	virtual Vector2 GetAnimationSize();
	virtual Sprite* UpdateAnim();
	std::vector<D2D1_RECT_F> sourceRects;

};