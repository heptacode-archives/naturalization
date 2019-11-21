#pragma once
#include "stdafx.h"
#include "Renderer.h"

class GameObject
{
public:
	GameObject(Vector2 position = Vector2(), float angle = 0.0f, Vector2 scale = Vector2());
	GameObject(const wchar_t* imagePath, Vector2 position = Vector2(), float angle = 0.0f, Vector2 scale = Vector2(1.0f,1.0f));
	GameObject(Renderer* renderer, Vector2 position = Vector2(), float angle = 0.0f, Vector2 scale = Vector2(1.0f, 1.0f));
	virtual ~GameObject();
private:
	bool isActive;
public:
	std::string name;
	Transform* transform;
	Renderer* renderer;

public:
	virtual void Start() {}				//오브젝트가 처음 만들었을 때 호출
	virtual void Update() {}			//매 프레임마다 호출
	virtual void LateUpdate() {}		//Update가 호출된 이후 호출
	virtual void OnDestroy() {}			//오브젝트가 삭제될 때 호출

public:
	bool GetActive();
};

