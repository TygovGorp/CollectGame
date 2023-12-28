#pragma once
#include "player.h"
#include "level.h"
#include "will.h"
#include "collision.h"
#include "UI.h"
#include "LOS.h"
#include "main_menu.h"
#include <iostream>

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
	void MouseUp(int button) {}
	void MouseDown(int button) 
	{ 
		int temp_level = levelNum;

		//checks if you if you hit a button on the main menu and if so preforms the action associated with the button
		MMinst.Button(levelNum, mainMenuStage, difficulty, mouseX, mouseY, button);

		//checks if your current level is different from the one in the previous frame to see if it needs to initialize a new level
		if (temp_level != levelNum) Init();
	}
	void MouseMove(int x, int y) 
	{ 
		mouseX = x;
		mouseY = y;
	}
	void KeyUp(int key) { Player.resetInputs(key); }
	void KeyDown(int key) { Player.moveWithInputs(key); MMinst.returnToPrevScreen(key, mainMenuStage); }
private:
	Surface* screen;
	player Player;
	level levelManager;
	will WillInst;
	vector<trap> trapVec;
	vector<enemy> enemyVec;
	collision Col;
	UI uiInst;
	LOS losInst;
	main_menu MMinst;

	animation gameOverScreen;
	animation gameWinScreen;
	animation gameSpottedScreen;

	int mouseX;
	int mouseY;

	bool gameOver = false;

	int levelNum = 0;
	int mainMenuStage = 1;
	int difficulty; //1 = easy 2 = medium 3 = hard
	const int maxLevelNum = 3;
	bool levelCleared[3] = { false };

	const int ScreenWidth = 800;
	const int ScreenHeight = 560;
};

}; // namespace Tmpl8