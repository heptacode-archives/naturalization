#include "stdafx.h"
#include "Image.h"
#include "Scene.h"

Image::Image(const wchar_t* path, Vector2 pos) : GameObject(path, pos) {
	col = new AABBCollider(*transform, Vector2(transform->position.x, transform->position.y));
}

Image::~Image()
{
	SAFE_DELETE(col);
}

void Image::Update()
{
}