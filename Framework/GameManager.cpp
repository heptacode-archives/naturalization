#include "stdafx.h"
#include "GameManager.h"
#include "Scene.h"
#include "InputManager.h"

int GameManager::ans[10000] = { -1, 8, 4, 2, 7, 1 };

GameManager::GameManager() {
	stage = 0;
	time = 3.402823466e+38F;
	tile = -1;
}

GameManager::~GameManager() {}

Image* GameManager::PushBackImage(Image* e) {
	Scene::GetCurrentScene().PushBackGameObject(e);
	imageList.push_back(e);
	return e;
}

void GameManager::PrintImage() {
	Remove();
	switch (stage) {
	case -2:
		PushBackImage(new Image(L"resources/GameOver.png", Vector2(360.0f, 360.0f)));
		break;
	case -1:
		PushBackImage(new Image(L"resources/Timeout.png", Vector2(360.0f, 360.0f)));
		break;
	case 0:
		PushBackImage(new Image(L"resources/background.png", Vector2(360.0f, 360.0f)));
		break;
	case 1:
		PushBackImage(new Image(L"resources/stage01/background.png", Vector2(360.0f, 360.0f)));
		PushBackImage(new Image(L"resources/stage01/light01.jpg", Vector2(120.0f, 120.0f)));	// 1
		PushBackImage(new Image(L"resources/stage01/light02.jpg", Vector2(360.0f, 120.0f)));	// 2
		PushBackImage(new Image(L"resources/stage01/light03.jpg", Vector2(600.0f, 120.0f)));	// 3
		PushBackImage(new Image(L"resources/stage01/light04.png", Vector2(120.0f, 360.0f)));	// 4
		PushBackImage(new Image(L"resources/stage01/light05.jpg", Vector2(360.0f, 360.0f)));	// 5
		PushBackImage(new Image(L"resources/stage01/light06.jpg", Vector2(600.0f, 360.0f)));	// 6
		PushBackImage(new Image(L"resources/stage01/light07.jpg", Vector2(120.0f, 600.0f)));	// 7
		PushBackImage(new Image(L"resources/stage01/light_ans.jpg", Vector2(360.0f, 600.0f)));	// 8 $
		PushBackImage(new Image(L"resources/stage01/light08.jpg", Vector2(600.0f, 600.0f)));	// 9
		break;
	case 2:
		PushBackImage(new Image(L"resources/stage02/background.png", Vector2(360.0f, 360.0f)));
		PushBackImage(new Image(L"resources/stage02/glasses01.jpg", Vector2(120.0f, 120.0f)));	// 1
		PushBackImage(new Image(L"resources/stage02/glasses02.jpg", Vector2(360.0f, 120.0f)));	// 2
		PushBackImage(new Image(L"resources/stage02/glasses03.jpg", Vector2(600.0f, 120.0f)));	// 3
		PushBackImage(new Image(L"resources/stage02/glasses_ans.jpg", Vector2(120.0f, 360.0f)));// 4 $
		PushBackImage(new Image(L"resources/stage02/glasses04.jpg", Vector2(360.0f, 360.0f)));	// 5
		PushBackImage(new Image(L"resources/stage02/glasses05.jpg", Vector2(600.0f, 360.0f)));	// 6
		PushBackImage(new Image(L"resources/stage02/glasses06.png", Vector2(120.0f, 600.0f)));	// 7
		PushBackImage(new Image(L"resources/stage02/glasses07.png", Vector2(360.0f, 600.0f)));	// 8
		PushBackImage(new Image(L"resources/stage02/glasses08.jpg", Vector2(600.0f, 600.0f)));	// 9
		break;
	case 3:
		PushBackImage(new Image(L"resources/stage03/background.png", Vector2(360.0f, 360.0f)));
		PushBackImage(new Image(L"resources/stage03/circle01.jpg", Vector2(120.0f, 120.0f)));	// 1
		PushBackImage(new Image(L"resources/stage03/circle_ans.jpg", Vector2(360.0f, 120.0f)));	// 2 $
		PushBackImage(new Image(L"resources/stage03/circle02.png", Vector2(600.0f, 120.0f)));	// 3
		PushBackImage(new Image(L"resources/stage03/circle03.png", Vector2(120.0f, 360.0f)));	// 4
		PushBackImage(new Image(L"resources/stage03/circle04.jpg", Vector2(360.0f, 360.0f)));	// 5
		PushBackImage(new Image(L"resources/stage03/circle05.png", Vector2(600.0f, 360.0f)));	// 6
		PushBackImage(new Image(L"resources/stage03/circle06.png", Vector2(120.0f, 600.0f)));	// 7
		PushBackImage(new Image(L"resources/stage03/circle07.jpg", Vector2(360.0f, 600.0f)));	// 8
		PushBackImage(new Image(L"resources/stage03/circle08.png", Vector2(600.0f, 600.0f)));	// 9
		break;
	case 4:
		PushBackImage(new Image(L"resources/stage04/background.png", Vector2(360.0f, 360.0f)));
		PushBackImage(new Image(L"resources/stage04/check01.JPG", Vector2(120.0f, 120.0f)));	// 1
		PushBackImage(new Image(L"resources/stage04/check02.png", Vector2(360.0f, 120.0f)));	// 2
		PushBackImage(new Image(L"resources/stage04/check03.jpg", Vector2(600.0f, 120.0f)));	// 3
		PushBackImage(new Image(L"resources/stage04/check04.jpg", Vector2(120.0f, 360.0f)));	// 4
		PushBackImage(new Image(L"resources/stage04/check05.jpg", Vector2(360.0f, 360.0f)));	// 5
		PushBackImage(new Image(L"resources/stage04/check06.jpg", Vector2(600.0f, 360.0f)));	// 6
		PushBackImage(new Image(L"resources/stage04/check_ans.jpg", Vector2(120.0f, 600.0f)));	// 7 $
		PushBackImage(new Image(L"resources/stage04/check07.jpg", Vector2(360.0f, 600.0f)));	// 8
		PushBackImage(new Image(L"resources/stage04/check08.jpg", Vector2(600.0f, 600.0f)));	// 9
		break;
	case 5:
		PushBackImage(new Image(L"resources/stage05/background.png", Vector2(360.0f, 360.0f)));
		PushBackImage(new Image(L"resources/stage05/bow_ans.jpg", Vector2(120.0f, 120.0f)));	// 1 $
		PushBackImage(new Image(L"resources/stage05/bow01.jpg", Vector2(360.0f, 120.0f)));		// 2
		PushBackImage(new Image(L"resources/stage05/bow02.jpg", Vector2(600.0f, 120.0f)));		// 3
		PushBackImage(new Image(L"resources/stage05/bow03.jpg", Vector2(120.0f, 360.0f)));		// 4
		PushBackImage(new Image(L"resources/stage05/bow04.png", Vector2(360.0f, 360.0f)));		// 5
		PushBackImage(new Image(L"resources/stage05/bow05.jpg", Vector2(600.0f, 360.0f)));		// 6
		PushBackImage(new Image(L"resources/stage05/bow06.png", Vector2(120.0f, 600.0f)));		// 7
		PushBackImage(new Image(L"resources/stage05/bow07.jpg", Vector2(360.0f, 600.0f)));		// 8
		PushBackImage(new Image(L"resources/stage05/bow08.jpg", Vector2(600.0f, 600.0f)));		// 9
		break;
	default:
		stopTimer();
		PushBackImage(new Image(L"resources/GameClear.png", Vector2(360.0f, 360.0f)));
		isGameEnded = true;
	}
}


void GameManager::Timeout() {
	stopTimer();
	stage = -1;
	PrintImage();
}

void GameManager::GameOver() {
	stopTimer();
	stage = -2;
	PrintImage();
}

void GameManager::initTimer() {
	time = 5.0f;
}

void GameManager::stopTimer() {
	time = 3.402823466e+38F;
}


void GameManager::Destroy(Image* e) {
	destroyed.push_back(e);
}

void GameManager::Update() {
	if (InputManager::GetKeyDown(VK_LBUTTON)) {
		int mX = InputManager::GetMouseX();
		int mY = InputManager::GetMouseY();
		if (mX >= 20 && mY >= 20 && mX <= 220 && mY <= 220) // (20, 20) ~ (220, 220)
			tile = 1;
		else if (mX >= 260 && mY >= 20 && mX <= 460 && mY <= 220) // (260, 20) ~ (460, 220)
			tile = 2;
		else if (mX >= 500 && mY >= 20 && mX <= 700 && mY <= 220) // (500, 20) ~ (700, 220)
			tile = 3;
		//
		else if (mX >= 20 && mY >= 260 && mX <= 220 && mY <= 460) // (20, 260) ~ (220, 460)
			tile = 4;
		else if (mX >= 260 && mY >= 260 && mX <= 460 && mY <= 460) // (260, 260) ~ (460, 460)
			tile = 5;
		else if (mX >= 500 && mY >= 260 && mX <= 700 && mY <= 460) // (500, 260) ~ (700, 460)
			tile = 6;
		//
		else if (mX >= 20 && mY >= 500 && mX <= 220 && mY <= 700) // (20, 500) ~ (220, 700)
			tile = 7;
		else if (mX >= 260 && mY >= 500 && mX <= 460 && mY <= 700) // (260, 500) ~ (460, 700)
			tile = 8;
		else if (mX >= 500 && mY >= 500 && mX <= 700 && mY <= 700) // (500, 500) ~ (700, 700)
			tile = 9;

		if (tile == ans[stage]) { // 정답
			stage++;
			PrintImage();
			initTimer();
		}
		else if(tile != ans[stage] && stage >= 1 && !isGameEnded) { // 오답
			GameOver();
		}
		else if (stage == 0) { // 게임 시작
			stage++;
			PrintImage();
			initTimer();
		}
	}

	time -= TimeManager::GetDeltaTime();

	if (time <= 0 && !isGameEnded) {
		Timeout();
	}

}

void GameManager::LateUpdate() {
	Remove();
}

void GameManager::Remove() {
	for (auto& i : destroyed) {
		imageList.remove(i);
		Scene::GetCurrentScene().Destroy(i);
	}
	destroyed.clear();
}