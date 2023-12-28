#pragma once
#include "animation.h"
#include "template.h"
#include <vector>

using namespace std;

namespace Tmpl8
{
	class UI
	{
	public:
		//preforms all private init functions
		void init(Surface* surface, int levelNum, int hp);
		//preforms all private update functions
		void update(Surface* surface, int levelNum, int hp);

	private:
		//initializes the texts "level"
		void initLevelTxt(Surface* surface);
		//initializes the level number
		void initLevelCounter(Surface* surface, int levelNum);

		//updates the level number
		void updateLevelCounter(Surface* surface, int levelNum);

		//initializes the hearts and location
		void initHpCounter(Surface* surface, int hp);
		//updates the hearts
		void updateHpCounter(int hp, Surface* surface);

		int currentLevelNum;

		animation levelCounterAnimation;
		vec2 levelCounterLoc{ 131, 1 };
		animation levelTxtAnimation;
		vec2 levelTxtLoc{ 1, 1 };

		vector<animation*> heartAnimVec;
		vec2 heartLoc{ 770, 1 };
	};
}

