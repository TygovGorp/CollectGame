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

        void setHitStateTrap(bool YN);
        bool getHitStateTrap();
    private:
        collision Col;
        vec2 lastChangeLoc;
        vec2 secondLastChangeLoc;
        bool hittingATrap = false;
    };
}

