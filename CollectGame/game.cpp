#include "game.h"
#include "surface.h"

namespace Tmpl8
{

	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{
		Player.buildAnimation(screen);

		Reset();

		//initializing the different state screens
		gameOverScreen.init(1, "assets/game_over_screen.png", 1, 1, screen);
		gameWinScreen.init(1, "assets/game_win_screen.png", 1, 1, screen);
		gameSpottedScreen.init(1, "assets/spotted_screen.png", 1, 1, screen);
	}

	void Game::Reset()
	{
		//checks if you are in the main menu or not
		if (levelNum != 0)
		{
			//reads the level_x.txt and loads level
			levelManager.init(levelNum, difficulty, screen);

			//initializes the player
			Player.init(levelManager.getPlayerStartLoc().x, levelManager.getPlayerStartLoc().y);
			Player.init(levelManager.getTrapVec().size());

			//initializes the line of sight system
			losInst.init(Player.getLoc() + 30);

			//set the location of the will and loads it
			WillInst.setLoc(levelManager.getWillLoc());
			WillInst.init(screen);

			uiInst.init(screen, levelNum, Player.getHP());

			//gets all traps and enemy's from the levelmanager for further use
			trapVec = levelManager.getTrapVec();
			enemyVec = levelManager.getEnemyVec();
		}
		else
		{
			//loads main the menu screen
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
		//conversion to seconds
		deltaTime /= 1000;

		// clear the graphics window
		screen->Clear(0);

		//checks if it needs to load the main menu or a level
		if (levelNum != 0)
		{
			//updates the light part of the line of sight system
			//losInst.update_light(screen, Player.getLoc());

			//updates the enemy, trap, walls
			levelManager.update(screen, Player, deltaTime);
			
			//updates the will
			WillInst.update(screen);

			//checks for collisions between the screen and player and moves it back to a valid location if they collide
			Player.checkCollisionScreenBounds(ScreenHeight, ScreenWidth, deltaTime);
			//checks for collisions between the walls and player and moves it back to a valid location if they collide
			Player.checkCollisionWall(levelManager.getWallVec(), deltaTime);
			//updates the player sprite and location
			Player.update(screen, deltaTime);

			//updates the dark part of the line of sight system
			//losInst.update_darkness(screen, Player.getLoc(), levelManager.getWallVec());

			//update the UI (level tracker and health)
			uiInst.update(screen, levelNum, Player.getHP());

			//set will collection state to true when colliding with it
			if (Col.AABB(Player.getLoc() + 7 , Player.getLoc() + 52, WillInst.getLoc() + 21, WillInst.getLoc() + 41) && !gameOver)
			{
				WillInst.Interaction();
			}

			//checks if the player collides or is colliding with a trap and decreases the health if it does
			for (int i = 0; i < trapVec.size(); i++)
			{
				//checks for collision between the player and trap with id i
				bool collisionYN = Col.AABB(Player.getLoc() + 7, Player.getLoc().x + 52, trapVec[i].getLoc(), trapVec[i].getPointB());

				//checks if the player collides for the first time or not, so it only decreases health once
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
			//updates the main menu
			MMinst.update(levelNum, mainMenuStage, screen);
		}
	}
};