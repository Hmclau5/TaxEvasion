#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "Ground.h"
#include "Enemy.h"
#include "WinZone.h"


class Player
{
    private:
        Rectangle bounds;
        float xVel, yVel, friction, moveSpeed, jumpSpeed, maxSpeed;
        
        bool grounded;
       

        Texture2D texture;
        Rectangle textureRec;
    
    public:
        Player(float xIn, float yIn);


        Rectangle GetBounds();

        float GetxVel();

        float GetyVel();

        

        void MoveInput();

        void DrawPlayer();

        void MoveAndSlide();

        void Collide(Ground ground);

        void Collide(Enemy enemy);

        void Collide(WinZone winZone);
};



#endif // PLAYER_H