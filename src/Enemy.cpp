#include "Enemy.h"




Enemy::Enemy(float xIn, float yIn)
{
    bounds = {xIn,yIn,256,128};

}


Rectangle Enemy::GetBounds()
{
    return bounds;
}


void Enemy::DrawEnemy()
{
    if (xVel < 0)
            textureRec = {0,0,256,128};
        else
            textureRec = {0,0,-256,128};


        DrawTextureRec(texture, textureRec , {bounds.x -16 , bounds.y}, WHITE);
}

void Enemy::Collide(Ground ground){}
void Enemy::MoveAndSlide(){}

