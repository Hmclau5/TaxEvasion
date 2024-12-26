#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "raylib.h"
#include "Ground.h"
#include "SubGround.h"




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

        ~Enemy();

        virtual Type GetType() override;
        
        Rectangle GetBounds();

        virtual void Update(vector<Entity*>& entities);
        

        virtual void Draw()override;
        virtual void Collide(Ground ground);
        virtual void MoveAndSlide();
        virtual void PlayerDetect(Rectangle player);

        
};


#endif // ENEMY_H
