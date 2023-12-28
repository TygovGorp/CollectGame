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
        //initializes hittingATrap 
        void init(int numOfTraps);
        //initializes all animations
        void buildAnimation(Surface* surface);
        //updates the location and orientation
        void update(Surface* surface, float deltaTime);
        //player movement with WASD and the arrow keys
        void moveWithInputs(int key);
        //reset according to inputs
        void resetInputs(int key);
        //checks if the player collides with a wall and respond accordingly
        void checkCollisionWall(std::vector<wall> wallVec, float deltaTime);
        //checks if the player collides with a screen border and respond accordingly
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
        int facingDirection = 0; //0 = idle, 1 = down, 2 = forward, 3 = left, 4 = right
        animation playerAnim[5]; //0 = idle, 1 = down, 2 = forward, 3 = left, 4 = right

        bool keyPressed[4];//0 = down, 1 = forward, 2 = left, 3 = right

    };
}

