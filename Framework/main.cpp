#include "stdafx.h"
#include "Framework.h"
#include "GameScene.h"
#include "Math.h"

int main() {
	Framework& f = Framework::GetInstance();
	f.Run(new GameScene(), L"Game", 720, 720, false);

	return 0;
}