#pragma once
#include "GameObject.h"
#include "Image.h"
#include "TimeManager.h"
class GameManager :
	public GameObject
{
public:
	GameManager();
	~GameManager();

	int stage;
	static int ans[10000];
	int tile;
	float time;

	std::list<Image*> imageList;

	Image* PushBackImage(Image* i);
	void PrintImage();
	void Timeout();
	void GameOver();
	void initTimer();
	void stopTimer();
	void Destroy(Image* i);
	virtual void Update();
	virtual void LateUpdate();

private:
	std::list<Image*> destroyed;
	void Remove();
};
