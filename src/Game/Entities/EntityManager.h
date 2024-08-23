#pragma once

#include "BoundBlock.h"

class EntityManager {

public:
	~EntityManager();
	std::vector<Entity*> entities;
	std::vector<BoundBlock*> boundBlocks;
	std::vector<Entity*> ghosts;
	void tick();
	void render();
	void setKillable(bool);
	bool getHasWon(){return hasWon;}
	void setHasWon(){}
private:
	bool hasWon = false;
	bool killable = false;
	int killableCounter;
};