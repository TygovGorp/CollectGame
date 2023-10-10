#include "player.h"
namespace Tmpl8
{
	void player::moveWithInputs(int key)
	{
		//player movement with WASD and the arrow keys
		switch (key)
		{
		//w
		case 26:
			move(0, -10);
			break;
		//a
		case 4:
			move(-10, 0);
			break;
		//s
		case 22:
			move(0, 10);
			break;
		//d
		case 7:
			move(10, 0);
			break;
		//arrow keys
		//up
		case 82:
			move(0, -10);
			break;
		//left
		case 80:
			move(-10, 0);
			break;
		//down
		case 81:
			move(0, 10);
			break;
		//right
		case 79:
			move(10, 0);
			break;
		default:
			break;
		}
	}
}