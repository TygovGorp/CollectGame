#pragma once
#include "player.h"
#include <iostream>

namespace Tmpl8 {
class Surface;
class Game
{
public:
	void SetTarget( Surface* surface ) { screen = surface; }
	void Init();
	void Shutdown();
	void Tick( float deltaTime );
	void MouseUp( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseDown( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseMove( int x, int y ) { /* implement if you want to detect mouse movement */ }
	void KeyUp( int key ) { /* implement if you want to handle keys */ }
	void KeyDown(int key) { 
		//7 = e
		if (key == 7)
		{
			//check for will if player is on the will collect will and go to next level
		}

		Player.moveWithInputs(key); 
	}
private:
	Surface* screen;
	player Player;
};

}; // namespace Tmpl8