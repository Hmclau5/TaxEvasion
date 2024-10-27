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
            ({
                stoi(line.substr(commas[0]+1, commas[1]- commas[0]-1)),
                stoi(line.substr(commas[1]+1, commas[2]- commas[1]-1)),
                stoi(line.substr(commas[2]+1, commas[3]- commas[2]-1)),
                stoi(line.substr(commas[3]+1, commas[4]- commas[3]-1)),
            }, BLUE);
            players.push_back(temp);
        }
        if(line.substr(0, commas[0]) == "ENEMY")
        {
            Enemy temp
            ({
                stoi(line.substr(commas[0]+1, commas[1]- commas[0]-1)),
                stoi(line.substr(commas[1]+1, commas[2]- commas[1]-1)),
                stoi(line.substr(commas[2]+1, commas[3]- commas[2]-1)),
                stoi(line.substr(commas[3]+1, commas[4]- commas[3]-1)),
            }, RED, false);
            enemies.push_back(temp);
        }
        if(line.substr(0, commas[0]) == "GROUND")
        {
            Ground temp
            ({
                stoi(line.substr(commas[0]+1, commas[1]- commas[0]-1)),
                stoi(line.substr(commas[1]+1, commas[2]- commas[1]-1)),
                stoi(line.substr(commas[2]+1, commas[3]- commas[2]-1)),
                stoi(line.substr(commas[3]+1, commas[4]- commas[3]-1)),
            }, BROWN);
            grounds.push_back(temp);
        }
        if(line.substr(0, commas[0]) == "WINZONE")
        {
            WinZone temp
            ({
                stoi(line.substr(commas[0]+1, commas[1]- commas[0]-1)),
                stoi(line.substr(commas[1]+1, commas[2]- commas[1]-1)),
                stoi(line.substr(commas[2]+1, commas[3]- commas[2]-1)),
                stoi(line.substr(commas[3]+1, commas[4]- commas[3]-1)),
            }, GREEN);
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






