#pragma once
#include "GameObject.h"
#include "Image.h"
class ImageManager :
	public GameObject
{
public:
	ImageManager();
	~ImageManager();

	int stage;
	static int ans[11];
	int tile;

	std::list<Image*> imageList;

	Image* PushBackImage(Image* i);
	void PrintImage();
	void Timeout();
	void GameOver();
	void Destroy(Image* i);
	virtual void Update();
	virtual void LateUpdate();

private:
	std::list<Image*> destroyed;
	void Remove();
};
