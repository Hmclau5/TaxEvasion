#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "Ground.h"


class Enemy
{
     protected:
        Rectangle bounds, textureRec;
        float xVel, yVel;  
        Texture2D texture;

    public:
        Enemy(float x, float y);

        Rectangle GetBounds();

        virtual void DrawEnemy();
        virtual void Collide(Ground ground);
        virtual void MoveAndSlide();


};


#endif // ENEMY_H
