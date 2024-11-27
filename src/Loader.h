#ifndef LOADER_H
#define LOADER_H


#include "raylib.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "Ground.h"
#include "Player.h"
#include "Enemy.h"
#include "Badger.h"
#include "Surface.h"
#include "SubGround.h"
#include "KillBox.h"
#include "Wolf.h"

using namespace std;
/*
class Loader
{

    private:



        vector <Player> players;
        vector <Ground*> grounds;
        vector <Enemy*> enemies;
        vector <WinZone> winners;





    public:



        Loader(string filename);

        vector <Player> GetPlayers();
        vector <Ground*> GetGrounds();
        vector <Enemy*> GetEnemies();
        vector <WinZone> GetWinners();



        




};
*/

class Loader
{
    private:
        vector<Entity*> entities;
    public:
        Loader(string filename);
        vector<Entity*> GetEntities();

};

#endif // LOADER_H