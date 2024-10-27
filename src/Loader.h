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

using namespace std;

class Loader
{

    private:



        vector <Player> players;
        vector <Ground> grounds;
        vector <Enemy> enemies;
        vector <WinZone> winners;





    public:



        Loader(string filename);

        vector <Player> GetPlayers();
        vector <Ground> GetGrounds();
        vector <Enemy> GetEnemies();
        vector <WinZone> GetWinners();



        




};

#endif // LOADER_H