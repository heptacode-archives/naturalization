#include "stdafx.h"
#include "ImageManager.h"
#include "Scene.h"
#include "InputManager.h"
ImageManager::ImageManager() {}

ImageManager::~ImageManager() {}

Image* ImageManager::PushBackImage(Image* e) {
	Scene::GetCurrentScene().PushBackGameObject(e);
	imageList.push_back(e);
	return e;
}

void ImageManager::ReplaceImage(int stage) {
	if (stage != 0) {
		Remove();
	}
	switch (stage) {
	case 0:
		PushBackImage(new Image(L"resources/background.jpg", Vector2(360.0f, 360.0f)));
	case 1:
		PushBackImage(new Image(L"resources/img/feather.png", Vector2(120.0f, 120.0f)));
		PushBackImage(new Image(L"resources/img/candle.jpg", Vector2(360.0f, 120.0f)));
		PushBackImage(new Image(L"resources/img/chandelier.jpg", Vector2(600.0f, 120.0f)));
		PushBackImage(new Image(L"resources/img/halogen.jpg", Vector2(120.0f, 360.0f)));
		PushBackImage(new Image(L"resources/img/lamp.jpg", Vector2(360.0f, 360.0f)));
		PushBackImage(new Image(L"resources/img/lightapp.jpg", Vector2(600.0f, 360.0f)));
		PushBackImage(new Image(L"resources/img/led.jpg", Vector2(120.0f, 600.0f)));
		PushBackImage(new Image(L"resources/img/discord.png", Vector2(360.0f, 600.0f)));
		PushBackImage(new Image(L"resources/img/lightbulb.jpg", Vector2(600.0f, 600.0f)));
		break;
	case 2:
		PushBackImage(new Image(L"resources/img/candle.jpg", Vector2(120.0f, 120.0f)));
		PushBackImage(new Image(L"resources/img/chandelier.jpg", Vector2(360.0f, 120.0f)));
		PushBackImage(new Image(L"resources/img/lightapp.jpg", Vector2(600.0f, 120.0f)));
		PushBackImage(new Image(L"resources/img/discord.png", Vector2(120.0f, 360.0f)));
		PushBackImage(new Image(L"resources/img/led.jpg", Vector2(360.0f, 360.0f)));
		PushBackImage(new Image(L"resources/img/feather.png", Vector2(600.0f, 360.0f)));
		PushBackImage(new Image(L"resources/img/lamp.jpg", Vector2(120.0f, 600.0f)));
		PushBackImage(new Image(L"resources/img/lightbulb.jpg", Vector2(360.0f, 600.0f)));
		PushBackImage(new Image(L"resources/img/halogen.jpg", Vector2(600.0f, 600.0f)));
		break;
	case 3:
		renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/img/lamp.jpg", 0, 0));
		break;
	}
}

void ImageManager::Destroy(Image* e) {
	destroyed.push_back(e);
}

void ImageManager::Update() {
	if (InputManager::GetKeyDown(VK_LBUTTON)) {
		int mX = InputManager::GetMouseX();
		int mY = InputManager::GetMouseY();
		if (mX >= 20 && mY >= 20 && mX <= 220 && mY <= 220) { // (20, 20) ~ (220, 220)
			std::cout << "1";
		}
		else if (mX >= 260 && mY >= 20 && mX <= 460 && mY <= 220) { // (260, 20) ~ (460, 220)
			std::cout << "2";
		}
		else if (mX >= 500 && mY >= 20 && mX <= 700 && mY <= 220) { // (500, 20) ~ (700, 220)
			std::cout << "3";
		}
		//
		else if (mX >= 20 && mY >= 260 && mX <= 220 && mY <= 460) { // (20, 260) ~ (220, 460)
			std::cout << "4";
		}
		else if (mX >= 260 && mY >= 260 && mX <= 460 && mY <= 460) { // (260, 260) ~ (460, 460)
			std::cout << "5";
		}
		else if (mX >= 500 && mY >= 260 && mX <= 700 && mY <= 460) { // (500, 260) ~ (700, 460)
			std::cout << "6";
		}
		//
		else if (mX >= 20 && mY >= 500 && mX <= 220 && mY <= 700) { // (20, 500) ~ (220, 700)
			std::cout << "7";
		}
		else if (mX >= 260 && mY >= 500 && mX <= 460 && mY <= 700) { // (260, 500) ~ (460, 700)
			std::cout << "8";
		}
		else if (mX >= 500 && mY >= 500 && mX <= 700 && mY <= 700) { // (500, 500) ~ (700, 700)
			std::cout << "9";
		}
		ReplaceImage(2);
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