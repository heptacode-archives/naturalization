#pragma once
#include "Math.h"
class InputManager
{
private:
	static POINT mousePosition;

public:
	static int GetMouseX();
	static int GetMouseY();

private:
	static bool lkey[256], rkey[256];

public:
	static void UpdateKeyState();
	static int GetKeyState(int vk);
	static bool GetKeyDown(int vk);
	static bool GetKeyPressed(int vk);
	static bool GetKeyUp(int vk);
};

