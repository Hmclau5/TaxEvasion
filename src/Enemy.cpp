#include "Enemy.h"

const float GRAVITY = 1.2;


Enemy::Enemy(Rectangle inbounds, Color incolor, bool infixed)
{
    bounds = inbounds;
    color = incolor;
    fixed = infixed;
    timeCount = 0;
    xVel = 5;
    yVel = 0;
}


Rectangle Enemy::GetBounds()
{
    return bounds;
}


void Enemy::DrawEnemy()
{
    DrawRectangleRec(bounds, color);
}

void Enemy::Collide(Ground ground)
{
    
    
    
    if(CheckCollisionRecs(bounds, ground.GetBounds()) && !grounded)
    {
        Rectangle collision = GetCollisionRec(bounds, ground.GetBounds());
        if(collision.width > collision.height && (collision.y > bounds.y))
        {
            bounds.y = ground.GetBounds().y - bounds.height;
            yVel = 0;
            grounded = true;
            

        }
        if(collision.width > collision.height && (collision.y <= bounds.y))
        {
            bounds.y = ground.GetBounds().y + ground.GetBounds().height;
            yVel = 0;
        }
        if(collision.height > collision.width && (collision.x <= bounds.x))
        {
            bounds.x = ground.GetBounds().x + ground.GetBounds().width;
            xVel = 0;
        }
        if(collision.height > collision.width && (collision.x > bounds.x))
        {
            bounds.x = ground.GetBounds().x - bounds.width;
            xVel = 0;
        }

        
        
    }



        
        
    

}



void Enemy::MoveAndSlide()
{
    if(!fixed)
    {
        bounds.x += xVel;
        bounds.y += yVel;
        timeCount ++;
        if(timeCount == 100)
        {
            xVel = - xVel;
            timeCount = 0;
        }

        yVel += GRAVITY;
        

        grounded = false;

    }



}