#include "BearTrap.h"

BearTrap::BearTrap(float xIn, float yIn)
    : Enemy(xIn, yIn)
{
    bounds = {xIn + 128 , yIn , 0, 0 };

    texture = LoadTexture("C:/Users/Haden/Desktop/TaxEvasion/assets/bearTrap.png");

    textureRec = {0,0,256,64};

    grounded = false; 
}

void BearTrap::Update(vector<Entity*>& entities)
{


};


void BearTrap::Draw()
{
    DrawTextureRec(texture, textureRec, {bounds.x - 128, bounds.y} , WHITE);
}