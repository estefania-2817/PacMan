#include "strawberry.h"
#include "MapBuilder.h"

ApplePowerUp::ApplePowerUp(int x, int y, int width, int height, ofImage spriteSheet) : Powerup(x, y, width, height){
   this->sprite.cropFrom(spriteSheet, 537,49,13,14 );
}