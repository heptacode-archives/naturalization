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
		PushBackImage(new Image(L"resources/stage01/feather.png", Vector2(120.0f, 120.0f)));	// 1
		PushBackImage(new Image(L"resources/stage01/candle.jpg", Vector2(360.0f, 120.0f)));		// 2
		PushBackImage(new Image(L"resources/stage01/chandelier.jpg", Vector2(600.0f, 120.0f)));	// 3
		PushBackImage(new Image(L"resources/stage01/halogen.jpg", Vector2(120.0f, 360.0f)));	// 4
		PushBackImage(new Image(L"resources/stage01/lamp.jpg", Vector2(360.0f, 360.0f)));		// 5
		PushBackImage(new Image(L"resources/stage01/lightapp.jpg", Vector2(600.0f, 360.0f)));	// 6
		PushBackImage(new Image(L"resources/stage01/led.jpg", Vector2(120.0f, 600.0f)));		// 7
		PushBackImage(new Image(L"resources/stage01/discord.png", Vector2(360.0f, 600.0f)));	// 8 $
		PushBackImage(new Image(L"resources/stage01/lightbulb.jpg", Vector2(600.0f, 600.0f)));	// 9
		break;
	case 2:
		PushBackImage(new Image(L"resources/stage01/candle.jpg", Vector2(120.0f, 120.0f)));		// 1
		PushBackImage(new Image(L"resources/stage01/chandelier.jpg", Vector2(360.0f, 120.0f)));	// 2
		PushBackImage(new Image(L"resources/stage01/lightapp.jpg", Vector2(600.0f, 120.0f)));	// 3
		PushBackImage(new Image(L"resources/stage01/discord.png", Vector2(120.0f, 360.0f)));	// 4 $
		PushBackImage(new Image(L"resources/stage01/led.jpg", Vector2(360.0f, 360.0f)));		// 5
		PushBackImage(new Image(L"resources/stage01/feather.png", Vector2(600.0f, 360.0f)));	// 6
		PushBackImage(new Image(L"resources/stage01/lamp.jpg", Vector2(120.0f, 600.0f)));		// 7
		PushBackImage(new Image(L"resources/stage01/lightbulb.jpg", Vector2(360.0f, 600.0f)));	// 8
		PushBackImage(new Image(L"resources/stage01/halogen.jpg", Vector2(600.0f, 600.0f)));	// 9
		break;
	case 3:
		PushBackImage(new Image(L"resources/stage01/feather.png", Vector2(120.0f, 120.0f)));	// 1
		PushBackImage(new Image(L"resources/stage01/candle.jpg", Vector2(360.0f, 120.0f)));		// 2 $
		PushBackImage(new Image(L"resources/stage01/chandelier.jpg", Vector2(600.0f, 120.0f)));	// 3
		PushBackImage(new Image(L"resources/stage01/halogen.jpg", Vector2(120.0f, 360.0f)));	// 4
		PushBackImage(new Image(L"resources/stage01/lamp.jpg", Vector2(360.0f, 360.0f)));		// 5
		PushBackImage(new Image(L"resources/stage01/lightapp.jpg", Vector2(600.0f, 360.0f)));	// 6
		PushBackImage(new Image(L"resources/stage01/led.jpg", Vector2(120.0f, 600.0f)));		// 7
		PushBackImage(new Image(L"resources/stage01/discord.png", Vector2(360.0f, 600.0f)));	// 8
		PushBackImage(new Image(L"resources/stage01/lightbulb.jpg", Vector2(600.0f, 600.0f)));	// 9
		break;
	case 4:
		PushBackImage(new Image(L"resources/stage01/feather.png", Vector2(120.0f, 120.0f)));	// 1
		PushBackImage(new Image(L"resources/stage01/candle.jpg", Vector2(360.0f, 120.0f)));		// 2
		PushBackImage(new Image(L"resources/stage01/chandelier.jpg", Vector2(600.0f, 120.0f)));	// 3
		PushBackImage(new Image(L"resources/stage01/halogen.jpg", Vector2(120.0f, 360.0f)));	// 4
		PushBackImage(new Image(L"resources/stage01/lamp.jpg", Vector2(360.0f, 360.0f)));		// 5
		PushBackImage(new Image(L"resources/stage01/lightapp.jpg", Vector2(600.0f, 360.0f)));	// 6
		PushBackImage(new Image(L"resources/stage01/led.jpg", Vector2(120.0f, 600.0f)));		// 7 $
		PushBackImage(new Image(L"resources/stage01/discord.png", Vector2(360.0f, 600.0f)));	// 8
		PushBackImage(new Image(L"resources/stage01/lightbulb.jpg", Vector2(600.0f, 600.0f)));	// 9
		break;
	case 5:
		PushBackImage(new Image(L"resources/stage01/feather.png", Vector2(120.0f, 120.0f)));	// 1 $
		PushBackImage(new Image(L"resources/stage01/candle.jpg", Vector2(360.0f, 120.0f)));		// 2
		PushBackImage(new Image(L"resources/stage01/chandelier.jpg", Vector2(600.0f, 120.0f)));	// 3
		PushBackImage(new Image(L"resources/stage01/halogen.jpg", Vector2(120.0f, 360.0f)));	// 4
		PushBackImage(new Image(L"resources/stage01/lamp.jpg", Vector2(360.0f, 360.0f)));		// 5
		PushBackImage(new Image(L"resources/stage01/lightapp.jpg", Vector2(600.0f, 360.0f)));	// 6
		PushBackImage(new Image(L"resources/stage01/led.jpg", Vector2(120.0f, 600.0f)));		// 7
		PushBackImage(new Image(L"resources/stage01/discord.png", Vector2(360.0f, 600.0f)));	// 8
		PushBackImage(new Image(L"resources/stage01/lightbulb.jpg", Vector2(600.0f, 600.0f)));	// 9
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