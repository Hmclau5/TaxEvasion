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


    vector<Entity*> entities = load.GetEntities();
    /*
    
    Camera2D camera = { 0 };
    camera.target = {players[0]*->GetBounds().x,players[0].GetBounds().y};
    camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    */
    cout<<endl<<entities.size()<<endl;

    while (!WindowShouldClose())
    {



        //camera.target = {(players[0].GetBounds().x + players[0].GetBounds().width/2) - players[0].GetxVel() ,players[0].GetBounds().y + players[0].GetBounds().height/2};
        
        for (Entity* i : entities)
        {
            i->Update(entities);
        }
  

        

        
        BeginDrawing();
            ClearBackground(BLUE);
            BeginMode2D(dynamic_cast<Player*>(entities[0])->GetCamera());

            for (Entity* i : entities)
            {
                i->Draw();
            }
            
            


            EndMode2D();
        EndDrawing();
    }

    CloseWindow();





    

    return 0;

}