#include "Player.h"

const float GRAVITY = 1.2;
const int screenWidth = 1920;
const int screenHeight = 1080;


Player::Player(float xIn, float yIn)
    : Entity({xIn, yIn, 96 , 96}), type_(Entity::Type::Player)
{
    
    
    xVel = 0;
    yVel = 0;
    friction = 2.0;
    moveSpeed = 3.0;
    jumpSpeed = 25.0;
    maxSpeed = 20.0;
    grounded = false;
    texture = LoadTexture("C:/Users/Haden/Desktop/NewTaxEvasion/assets/player.png");
    textureRec = {0,0,128,128};  
    camera = { 0 }; 
    camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;       
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

Camera2D Player::GetCamera()
{
    return camera;
}

Entity::Type Player::GetType()
{
    return type_;
}

void Player::Draw()
{

        
        if (xVel < 0)
            textureRec = {0,0,-128,128};
        else
            textureRec = {0,0,128,128};
        

        DrawTextureRec(texture, textureRec , {bounds.x -16 , bounds.y -32}, WHITE);



};


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

void Player::Update(vector<Entity*> entities)
{
    
    MoveInput();
    MoveAndSlide();

    camera.target = {(bounds.x + bounds.width/2) - xVel ,(bounds.y + bounds.height/2) - yVel};

    for(Entity* i : entities)
    {
        if(i->GetType() == Entity::Type::Ground)
        {
            Ground* ground = dynamic_cast<Ground*>(i);
            if (ground != nullptr) 
            {
                if(CheckCollisionRecs(bounds, ground->GetBounds()) && !grounded)
                {
                    Rectangle collision = GetCollisionRec(bounds, ground->GetBounds());
                    if(collision.width > collision.height && (collision.y > bounds.y))
                    {
                        bounds.y = ground->GetBounds().y - bounds.height;
                        yVel = 0;
                        grounded = true;
                        

                    }
                    if(collision.width > collision.height && (collision.y <= bounds.y))
                    {
                        bounds.y = ground->GetBounds().y + ground->GetBounds().height;
                        yVel = 0;
                    }
                    if(collision.height > collision.width && (collision.x <= bounds.x))
                    {
                        bounds.x = ground->GetBounds().x + ground->GetBounds().width;
                        xVel = 0;
                    }
                    if(collision.height > collision.width && (collision.x > bounds.x))
                    {
                        bounds.x = ground->GetBounds().x - bounds.width;
                        xVel = 0;
                    }
                }   
            }
            
        }

        else if(i->GetType()==Entity::Type::Enemy)
        {
            Enemy* enemy = dynamic_cast<Enemy*>(i);
            if (enemy != nullptr) 
            {
                if(CheckCollisionRecs(bounds, enemy->GetBounds()))
                {

                    bounds.x = 0;
                    bounds.y = 0;
                }
            }
        }

        else if(i->GetType() == Entity::Type::WinZone)
        {
            WinZone* winZone = dynamic_cast<WinZone*>(i);
            if (winZone != nullptr)
            {
                if(CheckCollisionRecs(bounds, winZone->GetBounds()))
                {

                    yVel -= 20; 
                }
            }
        }


    }
}



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

