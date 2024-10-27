#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "Ground.h"


class Enemy
{
    private:
        Rectangle bounds;
        Color color;
        float xVel, yVel, friction, moveSpeed;
        int timeCount;
        bool grounded, fixed;
        Texture2D texture;  
        Rectangle textureRec;      

    public:
        Enemy(Rectangle inbounds, Color incolor, bool infixed);

        Rectangle GetBounds();

        void DrawEnemy();
        void Collide(Ground ground);
        void MoveAndSlide();


};


#endif // ENEMY_H
