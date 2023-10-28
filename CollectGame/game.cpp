#include "game.h"
#include "surface.h"

namespace Tmpl8
{

	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{
		Player.buildAnimation(screen, 1, "assets/temp_Player.png");

		Reset();

		gameOverScreen.init(1, "assets/game_over_screen.png", 1, 1);
		gameWinScreen.init(1, "assets/game_win_screen.png", 1, 1);
	}

	void Game::Reset()
	{
		levelManager.init(levelNum, screen);

		Player.init(levelManager.getPlayerStartLoc().x, levelManager.getPlayerStartLoc().y);

		losInst.init(levelManager.getWallVec(), Player);

		WillInst.setLoc(levelManager.getWillLoc());
		WillInst.init();

		uiInst.init(screen, levelNum, Player.getHP());
	}
	
	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown()
	{

	}

	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{
		// clear the graphics window
		screen->Clear(0);

		levelManager.update(screen);

		losInst.update(screen, Player.getLoc(), levelManager.getWallVec());

		WillInst.update(screen);

		Player.checkCollisionScreenBounds(ScreenHeight, ScreenWidth);
		Player.checkCollisionWall(levelManager.getWallVec());
		Player.update(screen);

		uiInst.update(screen, levelNum, Player.getHP());

		if (Col.AABB(Player.getLoc(), WillInst.getLoc()) && !gameOver)
		{
			WillInst.Interaction();
		}

		vector<trap> tempTrapVec = levelManager.getTrapVec();
		for (int i = 0; i < tempTrapVec.size(); i++)
		{
			bool collisionYN = Col.AABB(Player.getLoc(), vec2(Player.getLoc().x + 60, Player.getLoc().y + 60), tempTrapVec[i].getLoc(), tempTrapVec[i].getPointB());

			if (collisionYN && !Player.getHitStateTrap())
			{
				Player.setHitStateTrap(true);
				Player.setHP(Player.getHP() - tempTrapVec[i].getDMG());
				cout << "hit" << endl;
			}
			else if (!collisionYN && Player.getHitStateTrap())
			{
				Player.setHitStateTrap(false);
			}
		}

		if (Player.getHP() <= 0)
		{
			gameOverScreen.update(1, ScreenWidth, ScreenHeight, screen);
			gameOver = true;
		}

		if (WillInst.getState() && levelNum != maxLevelNum)
		{
			levelNum++;
			screen->Clear(0);
			Reset();
			WillInst.resetState();
		}

		if (levelNum == maxLevelNum && WillInst.getState())
		{
			gameWinScreen.update(1, ScreenWidth, ScreenHeight,screen);
		}
	}
};