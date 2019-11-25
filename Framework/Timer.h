#pragma once
#include "GameObject.h"
#include "TimeManager.h"
#include "ImageManager.h"

class Timer : public GameObject {

public:
	Timer();
	Timer(int i);
	~Timer();

	float time = 3.402823466e+38F;

	void Update();
	void reset();
	void stop();

	ImageManager* imageManager;
};