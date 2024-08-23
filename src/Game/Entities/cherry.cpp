#include "cherry.h"
#include "MapBuilder.h"

CherryPowerUp::CherryPowerUp(int x, int y, int width, int height, ofImage spriteSheet) : Powerup(x, y, width, height){
   this->sprite.cropFrom(spriteSheet, 489,50,14,14 );
}
