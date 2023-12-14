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
        void update(Surface* surface, float deltaTime);
        void moveWithInputs(int key);
        void resetInputs(int key);
        void checkCollisionWall(std::vector<wall> wallVec, float deltaTime);
        void checkCollisionScreenBounds(int screenHight, int screenWidth, float deltaTime);

        void setHitStateTrap(bool YN, int trapNum);
        bool getHitStateTrap(int trapNum);

        void setSpotState(bool YN) { spotted = YN; };
        bool getSpotState() { return spotted; };
    private:
        collision Col;
        vec2 change = { 0, 0 };
        vec2 lastChangeLoc;
        vec2 secondLastChangeLoc;
        vector<bool> hittingATrap;
        bool spotted;
    };
}

