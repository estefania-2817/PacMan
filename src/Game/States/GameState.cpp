#include "GameState.h"
#include "Entity.h"

GameState::GameState() {
	music.load("music/pacman_chomp.wav");
	mapImage.load("images/map2.png");
	map = MapBuilder().createMap(mapImage);
}
void GameState::tick() {
	if(!music.isPlaying()){
			music.play();
	}
	map->tick();
	if(map->getPlayer()->getHealth() == 0){
		setFinished(true);
		setNextState("over");
		map->getPlayer()->setHealth(3);
		finalScore = map->getPlayer()->getScore();
		map->getPlayer()->setScore(0);
	}
	if(map->Won()){  
		setFinished(true);
		setNextState("win");
		finalScore = map->getPlayer()->getScore();
	}
}
void GameState::render() {
	map->render();
}

void GameState::keyPressed(int key){
	if (key == 'p') {
        setNextState("pause");  
        setFinished(true);  
    } else {
        map->keyPressed(key);
    }

	if (key == 'y') {
        setNextState("win");  
        setFinished(true);  
		finalScore = map->getPlayer()->getScore();  
    } else {
        map->keyPressed(key);
    }
}

void GameState::mousePressed(int x, int y, int button){
	map->mousePressed(x, y, button);
}

void GameState::keyReleased(int key){
	map->keyReleased(key);
}
void GameState::setPauseR(bool b) {
	pauseR = b;
}
void GameState::setWinS(bool b) {
	winS = b;
}
// void GameState::setIsMario(bool mar) {
// 	isMario = mar; 
// }


void GameState::reset(){
	setFinished(false);
	setNextState("");
	if(pauseR == true) {
		mapImage.load("images/map2.png");
		map = MapBuilder().createMap(mapImage);
	}
	if(winS == true) {
		mapImage.load("images/map2.png");
		map = MapBuilder().createMap(mapImage);
	}
}

int GameState::getFinalScore(){
	return finalScore;
}

GameState::~GameState(){
	delete map;
}