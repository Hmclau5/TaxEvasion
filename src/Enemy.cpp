#include "Enemy.h"
#include<iostream>



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
            textureRec.width = abs(textureRec.width);
        else
            textureRec.width = -abs(textureRec.width);


        DrawTextureRec(texture, textureRec , {bounds.x -16 , bounds.y}, WHITE);
}

void Enemy::Collide(Ground ground){}
void Enemy::MoveAndSlide(){}
void Enemy::PlayerDetect(Rectangle player){}

