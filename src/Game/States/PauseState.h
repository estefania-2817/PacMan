#pragma once

#include "State.h"
#include "Button.h"
#include "Animation.h" 

class PauseState: public State{
    private:
        Button *resumeButton;
        Button *quitButton;
        ofImage img1;
	    Animation* anim;
        bool pauseR;

    public:
        PauseState();
        ~PauseState();
        void tick();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void reset();
        bool getPauseR() {return pauseR;}
};