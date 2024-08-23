#pragma once

#include "State.h"
#include "Button.h"
#include "Animation.h" 

class WinState: public State{
    private:
        Button *playAgainButton;
        Button *quitButton;
        ofImage img1;
	    Animation* anim;
        int finalScore = 0;
        bool winS;

    public:
        WinState();
        ~WinState();
        void tick();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void reset();
        void setFinalScore(int);
        bool getWinS() {return winS;}
};