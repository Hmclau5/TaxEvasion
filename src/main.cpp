#include <raylib.h>
#include <vector>
#include <iostream> 
#include <fstream>
 
#include "Loader.h"




const int screenWidth = 1920;
const int screenHeight = 1080;

using namespace std;

int main()
{

    
    InitWindow(screenWidth, screenHeight, "TaxEvasion");
    
    SetTargetFPS(60);
 
    Loader load("C:/Users/Haden/Desktop/NewTaxEvasion/src/DevLevel.csv");

    vector<Player>  players = load.GetPlayers();
    vector<Ground*>  grounds = load.GetGrounds();
    vector<Enemy*>   enemies = load.GetEnemies();
    vector<WinZone> winners = load.GetWinners();

    //vector<vector<Badger>> = load.GetEnemies;
    
    
    Camera2D camera = { 0 };
    camera.target = {players[0].GetBounds().x,players[0].GetBounds().y};
    camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    


    while (!WindowShouldClose())
    {



        camera.target = {(players[0].GetBounds().x + players[0].GetBounds().width/2) - players[0].GetxVel() ,players[0].GetBounds().y + players[0].GetBounds().height/2};
        
        players[0].MoveInput();
        players[0].MoveAndSlide();
  

        for(long long unsigned int i = 0; i < enemies.size(); i ++)
        {
            enemies[i]->MoveAndSlide();
            players[0].Collide(*enemies[i]);
        }


        for (Ground* i : grounds)
        {
            players[0].Collide(*i);
            for(long long unsigned int j = 0; j < enemies.size(); j ++)
            {
                enemies[j]->Collide(*i);
            }

        }


        players[0].Collide(winners[0]);

        



        
        BeginDrawing();
            ClearBackground(BLUE);
            BeginMode2D(camera);

            for (Player i : players)
            {
                i.DrawPlayer();
            }
            
            for (Ground* i : grounds)
            {
                i->DrawGround();
            }

            for (Enemy* i : enemies)
            {
                i->DrawEnemy();
            }

            for (WinZone i : winners)
            {
                i.DrawWinZone();
            }
            


            EndMode2D();
        EndDrawing();
    }

    CloseWindow();







    return 0;

}