#include "stdafx.h"
#include "ImageManager.h"
#include "Scene.h"
#include "InputManager.h"
#include "Timer.h"

int stage = 0;
int ImageManager::ans[11] = { -1, 8, 4, 2, 7, 1, 3, 4, 9, 7, 3 };
int tile = -1;

ImageManager::ImageManager() {}

ImageManager::~ImageManager() {}

Image* ImageManager::PushBackImage(Image* e) {
	Scene::GetCurrentScene().PushBackGameObject(e);
	imageList.push_back(e);
	return e;
}

void ImageManager::PrintImage() {
	Remove();
	switch (stage) {
	case -2:
		PushBackImage(new Image(L"resources/GameOver.png", Vector2(360.0f, 360.0f)));
		break;
	case -1:
		PushBackImage(new Image(L"resources/Timeout.png", Vector2(360.0f, 360.0f)));
		break;
	case 0:
		PushBackImage(new Image(L"resources/background.jpg", Vector2(360.0f, 360.0f)));
		break;
	case 1:
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
		PushBackImage(new Image(L"resources/stage02/glasses01.jpg", Vector2(120.0f, 120.0f)));	// 1
		PushBackImage(new Image(L"resources/stage02/glasses02.jpg", Vector2(360.0f, 120.0f)));	// 2
		PushBackImage(new Image(L"resources/stage02/glasses03.jpg", Vector2(600.0f, 120.0f)));	// 3
		PushBackImage(new Image(L"resources/stage02/glasses_ans.jpg", Vector2(120.0f, 360.0f)));// 4 $
		PushBackImage(new Image(L"resources/stage02/glasses04.jpg", Vector2(360.0f, 360.0f)));	// 5
		PushBackImage(new Image(L"resources/stage02/glasses05.png", Vector2(600.0f, 360.0f)));	// 6
		PushBackImage(new Image(L"resources/stage02/glasses06.png", Vector2(120.0f, 600.0f)));	// 7
		PushBackImage(new Image(L"resources/stage02/glasses07.png", Vector2(360.0f, 600.0f)));	// 8
		PushBackImage(new Image(L"resources/stage02/glasses08.jpg", Vector2(600.0f, 600.0f)));	// 9
		break;
	case 3:
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
	}
}


void ImageManager::Timeout() {
	std::cout << "시간 초과\n\n";
	stage = -1;
	PrintImage();
}

void ImageManager::GameOver() {
	std::cout << "GAME OVER\n\n";
	stage = -2;
	PrintImage();
}


void ImageManager::Destroy(Image* e) {
	destroyed.push_back(e);
}

void ImageManager::Update() {
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

		if (tile == ans[stage]) {
			stage++;
			PrintImage();
			std::cout << "stage : " << stage << " tile:" << tile << " ans\n";
			Timer::Timer(1);
			//timer->reset();
			// 타이머 리셋되어야 함
		}
		else if(tile != ans[stage] && stage >= 1) {
			std::cout << "stage : " << stage << " tile:" << tile << " wrong\n" << "right ans : " << ans[stage] << "\n\n";
			GameOver();
		}
		else if (stage == 0) {
			stage++;
			std::cout << "Now Stage " << stage << std::endl;
			PrintImage();
			Timer::Timer(1);
			//timer->reset();
			// 타이머 리셋되어야 함
		}
	}
}

void ImageManager::LateUpdate() {
	Remove();
}

void ImageManager::Remove() {
	for (auto& i : destroyed) {
		imageList.remove(i);
		Scene::GetCurrentScene().Destroy(i);
	}
	destroyed.clear();
}