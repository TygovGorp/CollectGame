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
		void init(Surface* surface, int levelNum, int hp);
		void update(Surface* surface, int levelNum, int hp);

	private:
		void initLevelTxt(Surface* surface);
		void initLevelCounter(Surface* surface, int levelNum);
		void updateLevelCounter(Surface* surface, int levelNum);

		void initHpCounter(Surface* surface, int hp);
		void updateHpCounter(int hp);

		int currentLevelNum;

		animation levelCounterAnimation;
		vec2 levelCounterLoc{ 131, 1 };
		animation levelTxtAnimation;
		vec2 levelTxtLoc{ 1, 1 };

		vector<animation*> heartAnimVec;
		vec2 heartLoc{ 770, 1 };
	};
}

