#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofSetWindowTitle("C++ Game Box");
	//States
	menuState = new MenuState();
	gameState = new GameState();
	gameOverState = new GameOverState();
	pauseState = new PauseState();
	winState = new WinState();
	choosePlayerState = new ChoosePlayerState();
	// Initial State
	currentState = menuState;
}

//--------------------------------------------------------------
void ofApp::update(){

	if (currentState != nullptr){
		currentState->tick();
		if(currentState->hasFinished()){
			if(currentState->getNextState() == "Menu"){
				currentState = menuState;
				currentState->reset();
			}else if(currentState->getNextState() == "Game"){
				gameState->setPauseR(pauseState->getPauseR());
				gameState->setWinS(winState->getWinS());
				// gameState->setIsMario(choosePlayerState->getChoseMario());
				// if(gameState->getIsMario() == false) {
				// 	map2->setPlayer(map->PacMan);
				// } else {
				// 	map2->setAltPlayer(map->Mario);
				// }
				currentState = gameState;
				currentState->reset();
			}else if(currentState->getNextState() == "over"){
				gameOverState->setScore(gameState->getFinalScore());
				currentState = gameOverState;
				currentState->reset();
			}else if(currentState->getNextState() == "pause"){
				currentState = pauseState;
				currentState->reset();
			}else if(currentState->getNextState() == "win"){
				winState->setFinalScore(gameState->getFinalScore());
				currentState = winState;
				currentState->reset();
			}else if(currentState->getNextState() == "chooseplayer"){
				currentState = choosePlayerState;
				currentState->reset();
			}
		}
	}		
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (currentState != nullptr)
		currentState->render();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (currentState != nullptr) {
        currentState->keyPressed(key);
        if (key == 'p') {
            pauseState->reset(); 
            currentState = pauseState;
        }
	}
	//Turn Volume Down (Mute)	
	if( key == '-' ){
		ofSoundSetVolume(0);
	}
	
	//Turn Volume Back Up
	if( key == '=' ){
		ofSoundSetVolume(1);
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (currentState != nullptr)
			currentState->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	if (currentState != nullptr)
		currentState->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
	if (currentState != nullptr)
			currentState->mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
	if (currentState != nullptr)
		currentState->mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	if (currentState != nullptr)
			currentState->windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	if (currentState != nullptr)
		currentState->gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	if (currentState != nullptr)
		currentState->dragEvent(dragInfo);
}
