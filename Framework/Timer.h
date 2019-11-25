#pragma once
#include "Windows.h"
#include "GameObject.h"

class Timer : public GameObject {

public:
	Timer();
	~Timer();

	float time = 5.0;

	void Update();
};