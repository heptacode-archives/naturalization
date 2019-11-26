#pragma once
#include "Scene.h"
#include "GameManager.h"
class GameScene : public Scene {
public:
	GameScene();
	~GameScene();

	virtual void Initialize();
	GameObject* background;
	GameManager* gameManager;
};
