#pragma once
#include "player.h"
#include "level.h"
#include "will.h"
#include "collision.h"
#include "UI.h"
#include "LOS.h"
#include<iostream>

namespace Tmpl8 {
class Surface;
class Game
{
public:
	void SetTarget(Surface* surface) { screen = surface; }
	void Init();
	void Reset();
	void Shutdown();
	void Tick(float deltaTime);
	void MouseUp(int button) { /* implement if you want to detect mouse button presses */ }
	void MouseDown(int button) { /* implement if you want to detect mouse button presses */ }
	void MouseMove(int x, int y) { /* implement if you want to detect mouse movement */ }
	void KeyUp(int key) { /* implement if you want to handle keys */ }
	void KeyDown(int key) {
		Player.moveWithInputs(key);
	}
private:
	Surface* screen;
	player Player;
	level levelManager;
	will WillInst;
	collision Col;
	UI uiInst;
	LOS losInst;

	animation gameOverScreen;
	animation gameWinScreen;

	bool gameOver = false;

	int levelNum = 1;
	int maxLevelNum = 3;

	const int ScreenWidth = 800;
	const int ScreenHeight = 560;
};

}; // namespace Tmpl8