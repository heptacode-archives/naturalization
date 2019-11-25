#include "stdafx.h"
#include "Timer.h"
#include "Scene.h"
#include "TimeManager.h"

Timer::Timer() {}

Timer::~Timer() {}

void Timer::Update() {
	time += TimeManager::GetDeltaTime();
	std::cout << time << std::endl;
}