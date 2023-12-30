#pragma once
#include "surface.h"
#include <string>
#include <vector>

namespace Tmpl8
{
	class animation
	{
	public:
		~animation() {Frames.clear();}

		//initializes the animation for use
		void init(int NumFrames, char* filename, int Xloc, int Yloc, Surface* ScreenSurface);

		//updates the animation
		void update(int FrameCounter, int w, int h, Surface* screen);
		//updates the animation with new location
		void update(int FrameCounter, int updatedX, int updatedY, int w, int h, Surface* screen);

		//converts string to char*
		char* StrToCharStar(char* filename, int i);

	private:
		int NumOfFrames = 1;
		int Xlocation = 0;
		int Ylocation = 0;
		std::vector<Sprite*> Frames;

	};
}