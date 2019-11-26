#include "stdafx.h"
#include "GameScene.h"
#include "Image.h"

GameScene::GameScene() {}

GameScene::~GameScene() {}

void GameScene::Initialize() {
	gameManager = (GameManager*)PushBackGameObject(new GameManager());
	gameManager->PrintImage();
}