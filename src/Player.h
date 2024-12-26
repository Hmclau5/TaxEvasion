#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "Entity.h"
#include "Ground.h"

#include "WinZone.h"
#include "Enemy.h"


class Player : public Entity
{
    private:
        
        float xVel, yVel, friction, moveSpeed, jumpSpeed, maxSpeed;
        
        bool grounded;

        Type type_;

        Camera2D camera;
       

        Texture2D texture;
        Rectangle textureRec;
    
    public:
        Player(float xIn, float yIn);

        virtual Type GetType() override;

        Rectangle GetBounds();

        Camera2D GetCamera();

        float GetxVel();

        float GetyVel();

        void Update(vector<Entity*>& entities  )override;

        

        void MoveInput();

        void Draw()override;

        void MoveAndSlide();

        void Collide(Ground ground);

        void Collide(Enemy enemy);

        void Collide(WinZone winZone);
};



#endif // PLAYER_H