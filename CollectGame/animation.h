#pragma once
#include "surface.h"
#include <string>
#include <vector>

namespace Tmpl8
{
	class animation
	{
	private:
		int NumOfFrames;
		int Xlocation, Ylocation;
		Surface* Screen;
		std::vector <Sprite*> Frames;

	public:
		~animation() {Frames.clear();}

		void init(int NumFrames, char* filename, int Xloc, int Yloc, Surface* ScreenSurface);
		void update(int FrameCounter);
		char* StrToCharStar(char* filename, int i);
	};
}