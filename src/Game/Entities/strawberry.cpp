#include "strawberry.h"
#include "MapBuilder.h"

StrawberryPowerUp::StrawberryPowerUp(int x, int y, int width, int height, ofImage spriteSheet) : Powerup(x, y, width, height){
   this->sprite.cropFrom(spriteSheet, 504,49,14,13 );
}