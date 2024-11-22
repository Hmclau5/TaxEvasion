
#include "Ground.h"

Ground::Ground(float xIn, float yIn)
{
    bounds = {(float)xIn, (float)yIn, 96, 96};
    textureRec = {0,0,96,96};
    texture = LoadTexture("C:/Users/Haden/Desktop/NewTaxEvasion/assets/ground.png");
    
};


Rectangle Ground::GetBounds()
{
    return bounds;
};

void Ground::DrawGround()
{
    DrawTextureRec(texture, textureRec , {bounds.x, bounds.y}, WHITE);
};