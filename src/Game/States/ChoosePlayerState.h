#pragma once

#include "State.h"
#include "Button.h"
#include "Animation.h" 
#include "Player.h"


class ChoosePlayerState: public State{
    private:
        Button *pacmanButton;
        Button *marioButton;
        ofImage img1;
	    Animation* anim;
        bool choseMario;

    public:
        ChoosePlayerState();
        ~ChoosePlayerState();
        void tick();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void reset();
        bool getChoseMario() { return choseMario; }
    
};