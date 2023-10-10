#pragma once
#include "entity.h"
namespace Tmpl8
{
    class player : public entity
    {
    public:
        void moveWithInputs(int key);
    };
}

