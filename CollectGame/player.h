#pragma once
#include "entity.h"
#include "wall.h"
#include "collision.h"
#include <vector>
namespace Tmpl8
{
    class player : public entity
    {
    public:
        void moveWithInputs(int key);
        void checkCollisionWall(std::vector<wall> wallVec);
        void checkCollisionScreenBounds(int screenHight, int screenWidth);
    private:
        collision Col;
        bool collideYN = false;
        vec2 lastChangeLoc;
        vec2 secondLastChangeLoc;
    };
}

