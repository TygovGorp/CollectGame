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
		levelManager.init(1);
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
		Player.update();
		
	}
};