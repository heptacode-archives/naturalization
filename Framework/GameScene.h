#pragma once
#include "Scene.h"
#include "ImageManager.h"
#include "Timer.h"
class GameScene : public Scene {
public:
	GameScene();
	~GameScene();

	virtual void Initialize();
	GameObject* background;
	Timer* timer;
	ImageManager* imageManager;
};
