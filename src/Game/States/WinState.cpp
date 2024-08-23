#include "WinState.h"

WinState::WinState() {
    playAgainButton = new Button(ofGetWidth()/2-32, ofGetHeight()/3+250, 64, 50, "Play Again");
    quitButton = new Button(ofGetWidth()/2-32, ofGetHeight()/3+300, 64, 50, "Quit");
	img1.load("images/Confetti.png");
	vector<ofImage> rightAnimframes;
    ofImage temp;
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++) {
			temp.cropFrom(img1, i*512, j*512, 512, 512);
			rightAnimframes.push_back(temp);
		}
    }
	anim = new Animation(10,rightAnimframes);
}


void WinState::tick() {
	playAgainButton->tick();
    quitButton->tick();
	anim->tick();
	if(playAgainButton->wasPressed()){
		winS = true;
		setNextState("Game");
		setFinished(true);

	}
    if(quitButton->wasPressed()){
		winS = true;
		setNextState("Menu");
		setFinished(true);

	}
}

void WinState::render() {
	string title = "Pacman Project";
	ofDrawBitmapString(title, ofGetWidth()/2-4*title.size(), ofGetHeight()/2-300, 50);
	ofDrawBitmapString("Final Score: " + to_string(finalScore), ofGetWidth()/2-55, ofGetHeight()/3+350, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	anim->getCurrentFrame().draw(ofGetWidth()/2-256, ofGetHeight()/2-280, 500, 500);
	playAgainButton->render();
    quitButton->render();

}

void WinState::keyPressed(int key){	
}

void WinState::mousePressed(int x, int y, int button){
	playAgainButton->mousePressed(x, y);
    quitButton->mousePressed(x, y);
}
void WinState::setFinalScore(int sc){
    finalScore = sc;
}
void WinState::reset(){
	setFinished(false);
	setNextState("");
	playAgainButton->reset();
    quitButton->reset();
}

WinState::~WinState(){
    delete playAgainButton;
    delete quitButton;
	delete anim;
}