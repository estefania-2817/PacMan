#pragma once

#include "Animation.h"
#include "EntityManager.h"

enum MOVING {
	MUP,
	MDOWN,
	MLEFT,
	MRIGHT,
};
class Player: public Entity{

    private:
        int spawnX, spawnY;
        unsigned int health=3;
        int score=0;
        bool canMoveUp, canMoveDown, canMoveRight, canMoveLeft;
        int speed = 4;
        bool walking = false;
        bool useMario;
        MOVING moving;
        FACING facing = DOWN;
        ofImage up, down, left, right;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        EntityManager* em;
        bool faster = false;
	    int fasterCounter;

    public:
        Player(int, int, int , int, EntityManager* /*, bool */);
        ~Player();
        int getHealth();
        int getScore();
        FACING getFacing();
        void setHealth(int);
        void setScore(int);
        void setFacing(FACING facing);
        void tick();
        void render();
        void keyPressed(int);
        void keyReleased(int);
        void damage(Entity* damageSource);
        void mousePressed(int, int, int);
        void reset();
        void checkCollisions();
        void die();
        vector <string> Save;
        bool invencible = false; 
        bool invisible  = false; 
        vector<int> locationofX;
        vector<int> locationofY;
        bool getInvencible() {return invencible;}
        bool setInvencible(bool k){invencible = k;}
        bool getInvisible() { return invisible;}
        void setInvisible(bool i ){invisible = 1;}
        int getX(){return x;}
        int getY(){return y;}
        void setX(int newX){this->x = newX;}
        void setY(int newY){this -> y = newY;}
        int invisibleT; 
        int invisibleDuration = 5;
        bool isInvencible;
        void setSpeed(int);
        void setFaster(bool);


        //void setUseMario(bool);
};