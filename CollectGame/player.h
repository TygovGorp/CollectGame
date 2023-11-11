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
        using entity::init;
        void init(int numOfTraps);
        void moveWithInputs(int key);
        void checkCollisionWall(std::vector<wall> wallVec);
        void checkCollisionScreenBounds(int screenHight, int screenWidth);

        void setHitStateTrap(bool YN, int trapNum);
        bool getHitStateTrap(int trapNum);
    private:
        collision Col;
        vec2 lastChangeLoc;
        vec2 secondLastChangeLoc;
        vector<bool> hittingATrap;
    };
}

