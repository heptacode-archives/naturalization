#include "stdafx.h"
#include "ImageManager.h"
#include "Scene.h"
#include "InputManager.h"
ImageManager::ImageManager()
{
}

ImageManager::~ImageManager()
{
}

Image* ImageManager::PushBackImage(Image* e)
{
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

void ImageManager::Destroy(Image* e)
{
	destroyed.push_back(e);
}

void ImageManager::Update()
{
	if (InputManager::GetKeyDown(VK_SPACE))
		ReplaceImage(2);
}

void ImageManager::LateUpdate()
{
	Remove();
}

void ImageManager::Remove()
{
	for (auto& i : destroyed)
	{
		imageList.remove(i);
		Scene::GetCurrentScene().Destroy(i);
	}
	destroyed.clear();
}