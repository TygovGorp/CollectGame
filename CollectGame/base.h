#pragma once
#include "template.h"
namespace Tmpl8
{
	class base
	{
	public:
		//sets location
		base();
		base(vec2 LOC);
		base(int x, int y);

		void init(int x, int y);

	protected:
		vec2 loc;
	};
}

