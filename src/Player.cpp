#include "Player.h"

const float GRAVITY = 1.2;



Player::Player(Rectangle InBounds, Color InColor)
{
    bounds = InBounds;
    color = InColor;
    xVel = 0;
    yVel = 0;
    friction = 2.0;
    moveSpeed = 3.0;
    jumpSpeed = 25.0;
    maxSpeed = 20.0;
    grounded = false;
            
};

float Player::GetxVel()
{
    return xVel;
}

float Player::GetyVel()
{
    return yVel;
}

Rectangle Player::GetBounds()
{
    return bounds;
}

Color Player::GetColor()
{
    return color;
}


void Player::MoveInput()
{
     if(IsKeyDown(KEY_A))
    {
        xVel -= moveSpeed;
    }
    if(IsKeyDown(KEY_D))
    {
        xVel += moveSpeed;
    }

    if(IsKeyDown(KEY_SPACE)  && grounded)
    {
        yVel -= jumpSpeed;
    }

    if(IsKeyPressed(KEY_R))
    {
        bounds.x = 0;
        bounds.y = 0;
    }
}



void Player::DrawPlayer()
{
    DrawRectangleRec(bounds, color);
};

void Player::MoveAndSlide()
{
    bounds.x += xVel;
    bounds.y += yVel;
    if (grounded)
    {
        if(xVel > 0)
        {
            xVel -= friction;
            if (xVel < 0) xVel = 0;
        }
        else if(xVel < 0 )
        {
            xVel += friction;
            if (xVel > 0) xVel = 0;
        }
    }

    yVel += GRAVITY;

    if(xVel > maxSpeed){xVel = maxSpeed;}
    if(xVel < -maxSpeed){xVel = -maxSpeed;}
    grounded = false;

};

void Player::Collide(Ground ground)
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



};

void Player::Collide(Enemy enemy)
{
    if(CheckCollisionRecs(bounds, enemy.GetBounds()))
    {
        color = RED; 
        bounds.x = 0;
        bounds.y = 0;
    }
};


void Player::Collide(WinZone winZone)
{
    if(CheckCollisionRecs(bounds, winZone.GetBounds()))
    {
        color = GREEN;
        yVel -= 20; 
    }
}