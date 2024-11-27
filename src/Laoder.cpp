#include "Loader.h"


/*
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

            enemies.push_back
            (new Badger
                (
                    stof(line.substr(commas[0]+1, commas[1]- commas[0]-1)),
                    stof(line.substr(commas[1]+1, commas[2]- commas[1]-1))
                )
            );
        }
        if(line.substr(0, commas[0]) == "WOLF")
        {

            enemies.push_back
            (new Wolf
                (
                    stof(line.substr(commas[0]+1, commas[1]- commas[0]-1)),
                    stof(line.substr(commas[1]+1, commas[2]- commas[1]-1))
                )
            );
        }
        if(line.substr(0, commas[0]) == "KILLBOX")
        {

            enemies.push_back
            (new KillBox
                (
                    stof(line.substr(commas[0]+1, commas[1]- commas[0]-1)),
                    stof(line.substr(commas[1]+1, commas[2]- commas[1]-1)),
                    stof(line.substr(commas[2]+1, commas[3]- commas[2]-1)),
                    stof(line.substr(commas[3]+1, commas[4]- commas[3]-1))
                )
            );
        }
        if(line.substr(0, commas[0]) == "SURFACE")
        {
            grounds.push_back
            (new Surface
                (
                    stof(line.substr(commas[0]+1, commas[1]- commas[0]-1)),
                    stof(line.substr(commas[1]+1, commas[2]- commas[1]-1)),
                    stof(line.substr(commas[2]+1, commas[3]- commas[2]-1)),
                    stof(line.substr(commas[3]+1, commas[4]- commas[3]-1))
                )
            );
        
        }
        if(line.substr(0, commas[0]) == "SUBGROUND")
        {
            grounds.push_back
            (new SubGround
                (
                    stof(line.substr(commas[0]+1, commas[1]- commas[0]-1)),
                    stof(line.substr(commas[1]+1, commas[2]- commas[1]-1)),
                    stof(line.substr(commas[2]+1, commas[3]- commas[2]-1)),
                    stof(line.substr(commas[3]+1, commas[4]- commas[3]-1))
                    
                )
            );
        
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

vector <Ground*> Loader::GetGrounds()
{
    return grounds;
}

vector <Enemy*> Loader::GetEnemies()
{
    return enemies;
}

vector <WinZone> Loader::GetWinners()
{
    return winners;
}
*/

std::vector<Entity*> Loader::GetEntities()
{
    return entities;
}

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

        if(commas.size() == 3)
        {
            if(line.substr(0, commas[0]) == "PLAYER")
            {

                entities.push_back
                (new Player
                    (
                        stof(line.substr(commas[0]+1, commas[1]- commas[0]-1)),
                        stof(line.substr(commas[1]+1, commas[2]- commas[1]-1))
                    )
                );
                
            }

            if(line.substr(0, commas[0]) == "BADGER")
            {

                entities.push_back
                (new Badger
                    (
                        stof(line.substr(commas[0]+1, commas[1]- commas[0]-1)),
                        stof(line.substr(commas[1]+1, commas[2]- commas[1]-1))
                    )
                );
                
            }
            if(line.substr(0, commas[0]) == "WOLF")
            {

                entities.push_back
                (new Wolf
                    (
                        stof(line.substr(commas[0]+1, commas[1]- commas[0]-1)),
                        stof(line.substr(commas[1]+1, commas[2]- commas[1]-1))
                    )
                );
                
            }

            if(line.substr(0, commas[0]) == "WINZONE")
            {

                entities.push_back
                (new WinZone
                    (
                        stof(line.substr(commas[0]+1, commas[1]- commas[0]-1)),
                        stof(line.substr(commas[1]+1, commas[2]- commas[1]-1))
                    )
                );
                
            }

            

        }

        if(commas.size() == 4)
        {
            if(line.substr(0, commas[0]) == "SURFACE")
            {
                entities.push_back
                (new Surface
                    (
                        stof(line.substr(commas[0]+1, commas[1]- commas[0]-1)),
                        stof(line.substr(commas[1]+1, commas[2]- commas[1]-1)),
                        stof(line.substr(commas[2]+1, commas[3]- commas[2]-1)),
                        stof(line.substr(commas[3]+1, commas[4]- commas[3]-1))
                    )
                );
            }

            if(line.substr(0, commas[0]) == "SUBGROUND")
            {
                entities.push_back
                (new SubGround
                    (
                        stof(line.substr(commas[0]+1, commas[1]- commas[0]-1)),
                        stof(line.substr(commas[1]+1, commas[2]- commas[1]-1)),
                        stof(line.substr(commas[2]+1, commas[3]- commas[2]-1)),
                        stof(line.substr(commas[3]+1, commas[4]- commas[3]-1))
                    )
                );
            }
            /*
            if(line.substr(0, commas[0]) == "KILLBOX")
            {

                entities.push_back
                (new KillBox
                    (
                        stof(line.substr(commas[0]+1, commas[1]- commas[0]-1)),
                        stof(line.substr(commas[1]+1, commas[2]- commas[1]-1)),
                        stof(line.substr(commas[2]+1, commas[3]- commas[2]-1)),
                        stof(line.substr(commas[3]+1, commas[4]- commas[3]-1))
                    )
                );
            }
            */
        }
    }


}



