#pragma once
#include "stdafx.h"

struct Sprite {
	const wchar_t* uri;
	ID2D1Bitmap* bitmap;	//비트맵이 저장되어있는 포인터
};


//같은 이미지를 여러번 로드하는 것을 방지하기 위한 객체.
class ResourceManager
{
public:
	~ResourceManager();
public:
	std::list<Sprite*> spriteList;		//이미지를 저장할 리스트
	Sprite* LoadBitmapFromFile(PCWSTR uri, UINT destinationWidth, UINT destinationHeight);
};

