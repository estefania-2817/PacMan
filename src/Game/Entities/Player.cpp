#include "Player.h"
#include "EntityManager.h"
#include "Dot.h"
#include "BigDot.h"
#include "Ghost.h"
#include "cherry.h"
#include "strawberry.h"
#include "apple.h"

Player::Player(int x, int y, int width, int height, EntityManager* em /*, bool useMario */) : Entity(x, y, width, height){
    spawnX = x;
    spawnY = y;

    // if(useMario == false){
    //     sprite.load("images/pacman.png");
    //     down.cropFrom(sprite, 0, 48, 16, 16);
    //     up.cropFrom(sprite, 0, 32, 16, 16);
    //     left.cropFrom(sprite, 0, 16, 16, 16);
    //     right.cropFrom(sprite, 0, 0, 16, 16);
        
    //     vector<ofImage> downAnimframes;
    //     vector<ofImage> upAnimframes;
    //     vector<ofImage> leftAnimframes;
    //     vector<ofImage> rightAnimframes;
    //     ofImage temp;
    //     for(int i=0; i<3; i++){
    //         temp.cropFrom(sprite, i*16, 48, 16, 16);
    //         downAnimframes.push_back(temp);
    //     }
    //     for(int i=0; i<3; i++){
    //         temp.cropFrom(sprite, i*16, 32, 16, 16);
    //         upAnimframes.push_back(temp);
    //     }
    //     for(int i=0; i<3; i++){
    //         temp.cropFrom(sprite, i*16, 16, 16, 16);
    //         leftAnimframes.push_back(temp);
    //     }
    //     for(int i=0; i<3; i++){
    //         temp.cropFrom(sprite, i*16, 0, 16, 16);
    //         rightAnimframes.push_back(temp);
    //     }
    //     walkDown = new Animation(1,downAnimframes);
    //     walkUp = new Animation(1,upAnimframes);
    //     walkLeft = new Animation(1,leftAnimframes);
    //     walkRight = new Animation(1,rightAnimframes);

    //     this->em = em;

    //     moving = MLEFT;
    // }
    // if(useMario == true) {
        sprite.load("images/mario.png");
        down.cropFrom(sprite, 13, 283, 19, 27);
        up.cropFrom(sprite, 54, 283, 18, 28);
        left.cropFrom(sprite, 174, 243, 17, 28);
        right.cropFrom(sprite, 215, 243, 16, 28);                             
        
        vector<ofImage> downmoving;
        vector<ofImage> upmoving;
        vector<ofImage> leftmoving;
        vector<ofImage> rightmoving;
        ofImage picture;
        picture.cropFrom(sprite, 13, 283, 19, 27);
        downmoving.push_back(picture);               //down
        picture.cropFrom(sprite, 54, 283, 18, 28);
        upmoving.push_back(picture);                 //up
        picture.cropFrom(sprite, 174, 243, 17, 28);
        leftmoving.push_back(picture);               //left
        picture.cropFrom(sprite, 135, 243, 16, 29);
        leftmoving.push_back(picture);               //left
        picture.cropFrom(sprite, 215, 243, 16, 28);
        rightmoving.push_back(picture);              //right
        picture.cropFrom(sprite, 255, 243, 16, 28);
        rightmoving.push_back(picture);              //right

        vector<ofImage> downAnimframes;
        vector<ofImage> upAnimframes;
        vector<ofImage> leftAnimframes;
        vector<ofImage> rightAnimframes; 

        for(int i = 0; i < downmoving.size(); i++) {
            downAnimframes.push_back(downmoving[i]);
        }
        for(int i = 0; i < upmoving.size(); i++) {
            upAnimframes.push_back(upmoving[i]);
        }
        for(int i = 0; i < leftmoving.size(); i++) {
            leftAnimframes.push_back(leftmoving[i]);
        }
        for(int i = 0; i < rightmoving.size(); i++) {
            rightAnimframes.push_back(rightmoving[i]);
        }
        walkDown = new Animation(1,downAnimframes);
        walkUp = new Animation(1,upAnimframes);
        walkLeft = new Animation(1,leftAnimframes);
        walkRight = new Animation(1,rightAnimframes);

        this->em = em;

        moving = MLEFT;
    //}
}
// void Player::setUseMario(bool use) {
//         useMario = use;
// }
void Player::tick(){

    //apple powerup
    if(faster) {
        setSpeed(6);
        fasterCounter--;
        if(fasterCounter == 0){
            setSpeed(4);
            faster = false;
        }
    } 

    checkCollisions();

    if (moving == MUP && canMoveUp) 
        facing = UP;
    else if (moving == MDOWN && canMoveDown) 
        facing = DOWN;
    else if (moving == MLEFT && canMoveLeft) 
        facing = LEFT;
    else if (moving == MRIGHT && canMoveRight)
        facing = RIGHT;

    if(facing == UP && canMoveUp){
        y-= speed;
        walkUp->tick();
    }else if(facing == DOWN && canMoveDown){
        y+=speed;
        walkDown->tick();
    }else if(facing == LEFT && canMoveLeft){
        x-=speed;
        walkLeft->tick();
    }else if(facing == RIGHT && canMoveRight){
        x+=speed;
        walkRight->tick();
    }
    if(isInvencible){
        invisibleT++;
        if(invisibleT >= invisibleDuration* 60 ){
            setInvencible(false);
           setInvisible(false);
            invisibleT = 0;
        }
    }
}

void Player::render(){
    if(!getInvencible()){
        ofSetColor(256,256,256);
    

    // ofDrawRectangle(getBounds());

    if(facing == UP)
        walkUp->getCurrentFrame().draw(x, y, width, height);
    else if(facing == DOWN)
        walkDown->getCurrentFrame().draw(x, y, width, height);
    else if(facing == LEFT)
        walkLeft->getCurrentFrame().draw(x, y, width, height);
    else if(facing == RIGHT)
        walkRight->getCurrentFrame().draw(x, y, width, height);
    }
    ofSetColor(256, 0, 0);
    ofDrawBitmapString("Health: ", ofGetWidth()/2+165, 50);

    for(unsigned int i=0; i<health; i++){
        ofDrawCircle(ofGetWidth()/2 + 25*i +250, 50, 10);
    }
    ofDrawBitmapString("Score:"  + to_string(score), ofGetWidth()/2-300, 50);

    if(!Save.empty()) {
        ofDrawBitmapString("Next PowerUp: " + Save[0], ofGetWidth()/2-100, 50);
    }
}

void Player::keyPressed(int key){
    switch(key){
        case 'w':
            moving = MUP;
            break;
        case 's':
            moving = MDOWN;
            break;
        case 'a':
            moving = MLEFT;;
            break;
        case 'd':
            moving = MRIGHT;;
            break;
        case 'n':
            die();
            break;
        case 'm':
        if (health < 3){
            health++;
        }
        case ' ':

        if(!Save.empty()){
            if(Save[0] == "Cherry"){
                int i = (int)ofRandom(0, locationofX.size()-1);
                int index = locationofX[i];
                int indexx = locationofY[i];
                setX(index);
                setY(indexx);
                Save.erase(Save.begin());
            } 
            else if (Save[0] == "Strawberry"){
                isInvencible = true;
                invisibleT = 0;
                setInvencible(true);
                setInvisible(true);
                Save.erase(Save.begin());
            }
            else if (Save[0] == "Apple") {
                setFaster(true);
                Save.erase(Save.begin());
            }
        }

      /*  else if(!Save[0]== "Strawberry"){
            
            setInvencible(true);
            setInvisible(true);
        }*/
            break;
    }
}

void Player::keyReleased(int key){
    if(key == 'w' || key =='s' || key == 'a' || key == 'd'){
        walking = false;
    }
}
void Player::mousePressed(int x, int y, int button){

}

int Player::getHealth(){ return health; }
int Player::getScore(){ return score; }
FACING Player::getFacing(){ return facing; }
void Player::setHealth(int h){ health = h; }
void Player::setFacing(FACING facing){ this->facing = facing; }
void Player::setScore(int h){ score = h; }

void Player::setSpeed(int num) {speed = num;}

void Player::setFaster(bool k){
    faster = k;
    fasterCounter=5*ofGetFrameRate();
}

void Player::checkCollisions(){
    canMoveUp = true;
    canMoveDown = true;
    canMoveLeft = true;
    canMoveRight = true;

    for(BoundBlock* boundBlock: em->boundBlocks){
        if(this->getBounds(x, y-speed).intersects(boundBlock->getBounds()))
            canMoveUp = false;
        if(this->getBounds(x, y+speed).intersects(boundBlock->getBounds()))
            canMoveDown = false;
        if(this->getBounds(x-speed, y).intersects(boundBlock->getBounds()))
            canMoveLeft = false;
        if(this->getBounds(x+speed, y).intersects(boundBlock->getBounds()))
            canMoveRight = false;
    }
    for(Entity* entity:em->entities){
        if(collides(entity)){
            if(dynamic_cast<Dot*>(entity) || dynamic_cast<BigDot*>(entity)){
                locationofX.push_back(entity->getX());
                locationofY.push_back(entity->getY());
                entity->remove = true;
                score += 10;
            }
            if(dynamic_cast<BigDot*>(entity)){
                score +=20;
                em->setKillable(true);
            }
            if (dynamic_cast<CherryPowerUp*>(entity)){
                if(Save.size() <3){
                    Save.push_back("Cherry");
                }
                entity->remove = true;
            }
            if (dynamic_cast<StrawberryPowerUp*>(entity)){
                if(Save.size() <3){
                    Save.push_back("Strawberry");
                }
                entity->remove = true;
            }
            if (dynamic_cast<ApplePowerUp*>(entity)){
                if(Save.size() < 3){
                    Save.push_back("Apple");
                }
                entity->remove = true;
            }

        }
    }
    for(Entity* entity:em->ghosts){
        if(collides(entity)){
            Ghost* ghost = dynamic_cast<Ghost*>(entity);
            if(ghost->getKillable())
                ghost->remove = true;
            else if(!getInvencible()){
                die();
            }
                
        }
    }

    
}

void Player::die(){
    health--;
    x = spawnX;
    y = spawnY;

}

Player::~Player(){
    delete walkUp;
    delete walkDown;
    delete walkLeft;
    delete walkRight;
}