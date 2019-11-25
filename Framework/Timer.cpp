#include "stdafx.h"
#include "Timer.h"
#include "Scene.h"
#include "ImageManager.h"

Timer::Timer() {}

Timer::Timer(int i) {
	time = 5.0;
}

Timer::~Timer() {}

void Timer::Update() {
	time -= TimeManager::GetDeltaTime();
	std::cout << time << std::endl;
	if (time <= 0) {
		imageManager->Timeout();
		stop();
	}
}

void Timer::reset() {
	time = 5.0;
}

void Timer::stop() {
	time = 3.402823466e+38F;
}