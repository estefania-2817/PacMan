#pragma once

#include "State.h"
#include "Button.h"
#include "Animation.h" 
#include "MapBuilder.h"
#include "EntityManager.h"

class MenuState : public State {
private:
	ofImage img1;
	Button *startButton;
	Button *choosePlayerButton;
	Animation* anim;
	ofImage mapImage;
	Map* map;

public:
	MenuState();
	~MenuState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
};
