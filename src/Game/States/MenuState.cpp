#include "MenuState.h"

MenuState::MenuState() {
	startButton = new Button(ofGetWidth()/2-32, ofGetHeight()/2, 64, 50, "Start");
	choosePlayerButton = new Button(ofGetWidth()/2-32, ofGetHeight()/2 + 40, 64, 50, "Choose a player");
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
void MenuState::tick() {
	startButton->tick();
	choosePlayerButton->tick();

	anim->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);
	}
	if(choosePlayerButton->wasPressed()){
		setNextState("chooseplayer");
		setFinished(true);
	}
}
void MenuState::render() {
	string title = "Pacman Project";
	ofDrawBitmapString(title, ofGetWidth()/2-4*title.size(), ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	anim->getCurrentFrame().draw(ofGetWidth()/2-50, ofGetHeight()/2-100, 100, 100);
	startButton->render();
	choosePlayerButton->render();


}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
	choosePlayerButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
	choosePlayerButton->reset();
}

MenuState::~MenuState(){
	delete startButton;
	delete choosePlayerButton;
	delete anim;
}