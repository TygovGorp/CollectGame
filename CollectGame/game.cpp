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

		gameOverScreen.init(1, "assets/game_over_screen.png", 1, 1, screen);
		gameWinScreen.init(1, "assets/game_win_screen.png", 1, 1, screen);
		gameSpottedScreen.init(1, "assets/spotted_screen.png", 1, 1, screen);
	}

	void Game::Reset()
	{
		if (levelNum != 0)
		{
			levelManager.init(levelNum, difficulty, screen);

			Player.init(levelManager.getPlayerStartLoc().x, levelManager.getPlayerStartLoc().y);
			Player.init(levelManager.getTrapVec().size());

			losInst.init(Player.getLoc() + 30);

			WillInst.setLoc(levelManager.getWillLoc());
			WillInst.init(screen);

			uiInst.init(screen, levelNum, Player.getHP());

			trapVec = levelManager.getTrapVec();
			enemyVec = levelManager.getEnemyVec();
		}
		else
		{
			MMinst.init(screen, ScreenWidth, ScreenHeight);
		}
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

		if (levelNum != 0)
		{
			losInst.update_light(screen, Player.getLoc());

			levelManager.update(screen, Player);
			
			WillInst.update(screen);
			Player.checkCollisionScreenBounds(ScreenHeight, ScreenWidth);
			Player.checkCollisionWall(levelManager.getWallVec());
			Player.update(screen);

			losInst.update_darkness(screen, Player.getLoc(), levelManager.getWallVec());

			uiInst.update(screen, levelNum, Player.getHP());

			//set will collection state to true when colliding with it
			if (Col.AABB(Player.getLoc(), WillInst.getLoc()) && !gameOver)
			{
				WillInst.Interaction();
			}

			for (int i = 0; i < trapVec.size(); i++)
			{
				bool collisionYN = Col.AABB(Player.getLoc(), vec2(Player.getLoc().x + 60, Player.getLoc().y + 60), trapVec[i].getLoc(), trapVec[i].getPointB());

				//std::cout << "hitstate: " << Player.getHitStateTrap() << " collision: " << collisionYN << endl;
				if (collisionYN && !Player.getHitStateTrap(i))
				{
					Player.setHitStateTrap(true, i);
					Player.setHP(Player.getHP() - trapVec[i].getDMG());
				}
				else if (!collisionYN && Player.getHitStateTrap(i))
				{
					Player.setHitStateTrap(false, i);
				}
			}

			//game over if player is spotted
			if (Player.getSpotState() == true)
			{
				gameSpottedScreen.update(1, ScreenWidth, ScreenHeight, screen);
				gameOver = true;
			}

			//game over if player heath reaches 0
			if (Player.getHP() <= 0)
			{
				gameOverScreen.update(1, ScreenWidth, ScreenHeight, screen);
				gameOver = true;
			}

			//load next level when will is collected
			if (WillInst.getState() && levelNum != maxLevelNum)
			{
				levelCleared[levelNum] = true;
				levelNum++;
				Init();
				WillInst.resetState();
			}

			//game win screen when will is collected in the last level
			if (levelNum == maxLevelNum && WillInst.getState())
			{
				gameWinScreen.update(1, ScreenWidth, ScreenHeight, screen);
			}
		}
		else
		{
			MMinst.update(levelNum, mainMenuStage, screen);
		}
	}
};