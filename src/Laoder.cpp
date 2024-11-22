#include "Loader.h"

Loader::Loader(string filename)
    {
    ifstream loader(filename);
    if (!loader.is_open())
        cout << "failed to open file\n";
    
   
    string line;

    while(getline(loader, line ))
    {

        vector<int> commas;
        for(long long unsigned int i = 0; i < line.length(); i++)
            {
            if(line[i] == ',')
                commas.push_back(i);
            }

        if(line.substr(0, commas[0]) == "PLAYER")
        {
            Player temp
            (
                stof(line.substr(commas[0]+1, commas[1]- commas[0]-1)),
                stof(line.substr(commas[1]+1, commas[2]- commas[1]-1))
            );
            players.push_back(temp);
        }
        if(line.substr(0, commas[0]) == "BADGER")
        {
            Badger temp
            (
                stof(line.substr(commas[0]+1, commas[1]- commas[0]-1)),
                stof(line.substr(commas[1]+1, commas[2]- commas[1]-1))
            );
            enemies.push_back(temp);
        }
        if(line.substr(0, commas[0]) == "GROUND")
        {
            Ground temp
            (
                stof(line.substr(commas[0]+1, commas[1]- commas[0]-1)),
                stof(line.substr(commas[1]+1, commas[2]- commas[1]-1))
            );
            grounds.push_back(temp);
        }
        if(line.substr(0, commas[0]) == "WINZONE")
        {
            WinZone temp
            (
                stof(line.substr(commas[0]+1, commas[1]- commas[0]-1)),
                stof(line.substr(commas[1]+1, commas[2]- commas[1]-1))
            );
            winners.push_back(temp);
        }
    }
        

    };

vector <Player> Loader::GetPlayers()
{
    return players;
}

vector <Ground> Loader::GetGrounds()
{
    return grounds;
}

vector <Enemy> Loader::GetEnemies()
{
    return enemies;
}

vector <WinZone> Loader::GetWinners()
{
    return winners;
}






