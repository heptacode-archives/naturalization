#include "stdafx.h"
#include "GameScene.h"
#include "PhysicsManager.h"
#include "Image.h"

GameScene::GameScene() {}

GameScene::~GameScene() {}

void GameScene::Initialize() {
	imageManager = (ImageManager*)PushBackGameObject(new ImageManager());
	imageManager->PrintImage();

	timer = new Timer;
	PushBackGameObject(timer);
}