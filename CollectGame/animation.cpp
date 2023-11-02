#include "animation.h"

namespace Tmpl8
{
	void animation::init(int NumFrames, char* filename, int Xloc, int Yloc, Surface* ScreenSurface)
	{
		//clear frames just to be sure that the vector is empty
		Frames.clear();

		//assigning the values
		Xlocation = Xloc;
		Ylocation = Yloc;
		Screen = ScreenSurface;
		NumOfFrames = NumFrames;

		//storing the frames in the Frames vector
		if (NumFrames > 1) //if the number of frames is above 1 it will automatically add the last part of the name of the file
		{
			for (int i = 0; i < NumOfFrames; i++)
			{
				Frames.push_back(new Sprite(new Surface(StrToCharStar(filename, i)), 1));
			}
		}
		else //leaving the addition to the name out because it isn't necessary here
		{
			for (int i = 0; i < NumOfFrames; i++)
			{
				Frames.push_back(new Sprite(new Surface(filename), 1));
			}
		}
	}

	void animation::update(int FrameCounter, int w, int h)
	{
		//drawing the frames (do minus to the FrameCounter because you don't have frame 0 but start at 1)
		Frames[FrameCounter - 1]->DrawScaled(Xlocation, Ylocation, w, h, Screen);
	}
	
	void animation::update(int FrameCounter, int updatedX, int updatedY, int w, int h)
	{
		Xlocation = updatedX;
		Ylocation = updatedY;
		update(FrameCounter, w, h);
	}

	//adding the extension to the end of the filename for full animations (automation)
	char* animation::StrToCharStar(char* filename, int i)
	{
		std::string FileNameString = (filename + std::to_string(i + 1) + ".png");
		char* charPtr = new char[FileNameString.length() + 1];
		std::strcpy(charPtr, FileNameString.c_str());
		return charPtr;
		delete[] charPtr;
	}
}