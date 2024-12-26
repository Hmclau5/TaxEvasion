#include <raylib.h>
#include <vector>
#include <iostream>
#include <fstream>

#include "Loader.h"

const int screenWidth = 1920;
const int screenHeight = 1080;

using namespace std;



int main() {
    InitWindow(screenWidth, screenHeight, "TaxEvasion");
    SetTargetFPS(60);

    Loader load("C:/Users/Haden/Desktop/TaxEvasion/src/DevLevel.csv");
    vector<Entity*> entities = load.GetEntities();

    while (!WindowShouldClose()) {
        for (auto entity : entities) {
            entity->Update(entities);
        }

        BeginDrawing();
            ClearBackground(BLUE);
            BeginMode2D(dynamic_cast<Player*>(entities[0])->GetCamera());

            for (auto entity : entities) {
                entity->Draw();
            }

            EndMode2D();
        EndDrawing();
    }

    // Clean up
    for (Entity* entity : entities) {
        delete entity;
    }
    entities.clear();
    
    CloseWindow();
    return 0;
}