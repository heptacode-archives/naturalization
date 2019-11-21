#pragma once
#include "Scene.h"
#include "Player.h"
class GameScene :
	public Scene
{
public:
	GameScene();
	~GameScene();

	virtual void Initialize();
	Player* player;
	GameObject* background;
};

