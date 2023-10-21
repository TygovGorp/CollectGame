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
		Player.build(10, 5, vec2(10, 10));
		levelManager.init(1, screen);

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
		// clear the graphics window
		screen->Clear(0);

		levelManager.update();

		if (Col.AABB(Player.getLoc(), WillInst.getLoc()))
		{
			std::cout << "pickup" << endl;
			WillInst.Interaction();
		}
		WillInst.update();

		Player.checkCollisionScreenBounds(ScreenHeight, ScreenWidth);
		Player.checkCollisionWall(levelManager.getWallVec());
		Player.update();
	}
};