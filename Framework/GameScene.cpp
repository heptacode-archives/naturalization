#include "stdafx.h"
#include "GameScene.h"
#include "PhysicsManager.h"
#include "Image.h"

GameScene::GameScene() {}

GameScene::~GameScene() {}

void GameScene::Initialize() {
	//background = PushBackGameObject(new GameObject(L"resources/background.jpg"));

	//BulletManager* bm = (BulletManager*)PushBackGameObject(new BulletManager());	//여기

	//player = (Player*)PushBackGameObject(new Player(L"resources/player/Player.png", bm)); //여기
	//player->transform->SetPosition(300.0f, 300.0f);

	//EnemyManager* em = (EnemyManager*)PushBackGameObject(new EnemyManager());
	//PhysicsManager* pm = (PhysicsManager*)PushBackGameObject(new PhysicsManager(player, em, bm));
	imageManager = (ImageManager*)PushBackGameObject(new ImageManager());

	//Enemy* test = em->PushBackEnemy(new Enemy(L"b.png"));
	//test->transform->SetPosition(300.0f, 100.0f);

	imageManager->PushBackImage(new Image(L"resources/background.jpg", Vector2(360.0f, 360.0f)));
	imageManager->PushBackImage(new Image(L"resources/img/feather.png", Vector2(120.0f, 120.0f)));
	imageManager->PushBackImage(new Image(L"resources/img/candle.jpg", Vector2(360.0f, 120.0f)));
	imageManager->PushBackImage(new Image(L"resources/img/chandelier.jpg", Vector2(600.0f, 120.0f)));
	imageManager->PushBackImage(new Image(L"resources/img/halogen.jpg", Vector2(120.0f, 360.0f)));
	imageManager->PushBackImage(new Image(L"resources/img/lamp.jpg", Vector2(360.0f, 360.0f)));
	imageManager->PushBackImage(new Image(L"resources/img/lightapp.jpg", Vector2(600.0f, 360.0f)));
	imageManager->PushBackImage(new Image(L"resources/img/led.jpg", Vector2(120.0f, 600.0f)));
	imageManager->PushBackImage(new Image(L"resources/img/discord.png", Vector2(360.0f, 600.0f)));
	imageManager->PushBackImage(new Image(L"resources/img/lightbulb.jpg", Vector2(600.0f, 600.0f)));

	imageManager->ReplaceImage(1);
	/*for (int i = 0; i < 3; ++i)
	{
		for (int t = 0; t < 3; ++t)
		{
			imageManager->PushBackImage(new Image());
			new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/img/feather.png", 0, 0));
		}

	}*/
}