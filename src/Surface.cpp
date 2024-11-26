#include "Surface.h"

Surface::Surface(float xIn,float yIn, float widthIn, float heightIn) 
    : Ground(xIn, yIn, widthIn, heightIn)
{
    textureRec = {0,0,widthIn, heightIn};
    texture = LoadTexture("C:/Users/Haden/Desktop/NewTaxEvasion/assets/ground.png");
}