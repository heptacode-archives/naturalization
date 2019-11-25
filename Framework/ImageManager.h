#pragma once
#include "GameObject.h"
#include "Image.h"

class ImageManager :
	public GameObject
{
public:
	ImageManager();
	~ImageManager();

	std::list<Image*> imageList;

	Image* PushBackImage(Image* i);
	void ReplaceImage(int stage);
	void Destroy(Image* i);
	virtual void Update();
	virtual void LateUpdate();

private:
	std::list<Image*> destroyed;
	void Remove();
};

