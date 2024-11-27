#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "raylib.h"
#include "Ground.h"




class Enemy : public Entity
{
     protected:
        Rectangle textureRec;
        float xVel, yVel;  
        Texture2D texture;
        Rectangle Target;
        Type type_;
        

    public:
        Enemy(float x, float y);

        virtual Type getType() override;
        
        Rectangle GetBounds();

        virtual void DrawEnemy();
        virtual void Collide(Ground ground);
        virtual void MoveAndSlide();
        virtual void PlayerDetect(Rectangle player);

        //TODO ~Enemy()
};


#endif // ENEMY_H
