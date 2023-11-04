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
		std::vector<Sprite*> Frames;

	public:
		~animation() {Frames.clear();}

		void init(int NumFrames, char* filename, int Xloc, int Yloc, Surface* ScreenSurface);

		void update(int FrameCounter, int w, int h, Surface* screen);
		void update(int FrameCounter, int updatedX, int updatedY, int w, int h, Surface* screen);

		char* StrToCharStar(char* filename, int i);
	};
}