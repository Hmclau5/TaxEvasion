#include "Surface.h"

Surface::Surface(float xIn,float yIn) 
    : Ground(xIn, yIn)
{
    textureRec = {0,0,96,96};
    texture = LoadTexture("C:/Users/Haden/Desktop/NewTaxEvasion/assets/ground.png");
}