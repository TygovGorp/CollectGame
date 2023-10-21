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

		WillInst.setLoc(levelManager.getWillLoc());
		WillInst.init(screen);
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

		if (WillInst.getState() && levelNum != maxLevelNum)
		{
			levelNum++;
			Init();
			WillInst.resetState();
		}

		// clear the graphics window
		screen->Clear(0);


		levelManager.update();

		WillInst.update();

		Player.checkCollisionScreenBounds(ScreenHeight, ScreenWidth);
		Player.checkCollisionWall(levelManager.getWallVec());
		Player.update();

		if (Col.AABB(Player.getLoc(), WillInst.getLoc()))
		{
			std::cout << "pickup" << endl;
			WillInst.Interaction();
		}
	}
};