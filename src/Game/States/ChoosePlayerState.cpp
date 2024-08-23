#include "ChoosePlayerState.h"

ChoosePlayerState::ChoosePlayerState() {
	pacmanButton = new Button(ofGetWidth()/2-130, ofGetHeight()/2, 64, 50, "Pacman");
    marioButton = new Button(ofGetWidth()/2+70, ofGetHeight()/2, 64, 50, "Mario");
	// img1.load("images/pacman.png");
	// vector<ofImage> rightAnimframes;
    // ofImage temp;
	// for(int i=0; i<3; i++){
    //     temp.cropFrom(img1, i*16, 0, 16, 16);
    //     rightAnimframes.push_back(temp);
    // }
	// anim = new Animation(10,rightAnimframes);
	img1.load("images/mario.png");
	vector<ofImage> rightAnimframes;
	ofImage temp1;
	ofImage temp2;
	ofImage temp3;
	temp1.cropFrom(img1, 9, 4, 27, 29);
	temp2.cropFrom(img1, 50, 4, 24, 26);
	temp3.cropFrom(img1, 92, 3, 22, 30);
	rightAnimframes.push_back(temp1);
	rightAnimframes.push_back(temp2);
	rightAnimframes.push_back(temp3);
	anim = new Animation(10,rightAnimframes);
}
void ChoosePlayerState::tick() {
	pacmanButton->tick();
    marioButton->tick();
	anim->tick();
	if(pacmanButton->wasPressed()){
		choseMario = false;
		setFinished(true);
		setNextState("Menu");
	}
    if(marioButton->wasPressed()){
		choseMario = true;
		setFinished(true);
		setNextState("Menu");
	}
}
void ChoosePlayerState::render() {
	string title = "Choose a player";
	ofDrawBitmapString(title, ofGetWidth()/2-4*title.size(), ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	anim->getCurrentFrame().draw(ofGetWidth()/2-50, ofGetHeight()/2-100, 100, 100);
	pacmanButton->render();
    marioButton->render();


}

void ChoosePlayerState::keyPressed(int key){
	
}

void ChoosePlayerState::mousePressed(int x, int y, int button){
	pacmanButton->mousePressed(x, y);
    marioButton->mousePressed(x, y);
}

void ChoosePlayerState::reset(){
	setFinished(false);
	setNextState("");
	pacmanButton->reset();
    marioButton->reset();
}

ChoosePlayerState::~ChoosePlayerState(){
	delete pacmanButton;
    delete marioButton;
	delete anim;
}