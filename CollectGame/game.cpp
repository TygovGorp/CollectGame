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

		levelManager.init(levelNum, screen);
		
		Player.init(levelManager.getPlayerStartLoc().x, levelManager.getPlayerStartLoc().y);

		losInst.init();

		WillInst.setLoc(levelManager.getWillLoc());
		WillInst.init(screen);

		uiInst.init(screen, levelNum, Player.getHP());

		gameOverScreen.init(1, "assets/game_over_screen.png", 1, 1, screen);
		gameWinScreen.init(1, "assets/game_win_screen.png", 1, 1, screen);
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

		levelManager.update();

		losInst.update(screen, Player.getLoc(), levelManager.getWallVec());

		WillInst.update();

		Player.checkCollisionScreenBounds(ScreenHeight, ScreenWidth);
		Player.checkCollisionWall(levelManager.getWallVec());
		Player.update();

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
			gameOverScreen.update(1, ScreenWidth, ScreenHeight);
			gameOver = true;
		}

		if (WillInst.getState() && levelNum != maxLevelNum)
		{
			levelNum++;
			Init();
			WillInst.resetState();
		}

		if (levelNum == maxLevelNum && WillInst.getState())
		{
			gameWinScreen.update(1, ScreenWidth, ScreenHeight);
		}
	}
};