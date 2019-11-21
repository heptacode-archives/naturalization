#include "stdafx.h"
#include "GameScene.h"
#include "PhysicsManager.h"

GameScene::GameScene() {}

GameScene::~GameScene() {}

void GameScene::Initialize() {
	background = PushBackGameObject(new GameObject(L"resources/background.jpg"));

	BulletManager* bm = (BulletManager*)PushBackGameObject(new BulletManager());	//여기

	player = (Player*)PushBackGameObject(new Player(L"resources/player/Player.png", bm)); //여기
	player->transform->SetPosition(300.0f, 300.0f);

	EnemyManager* em = (EnemyManager*)PushBackGameObject(new EnemyManager());
	PhysicsManager* pm = (PhysicsManager*)PushBackGameObject(new PhysicsManager(player, em, bm));

	Enemy* test = em->PushBackEnemy(new Enemy(L"b.png"));
	test->transform->SetPosition(300.0f, 100.0f);
}