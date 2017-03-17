#include <iostream>
#include <string>
#include <vector>

#include "UserInput.cpp"
#include "PlayerClass.cpp"
Player PlayerInstance;
#include "EnemyClass.cpp"
vector<Enemy> Enemies;
#include "MapGeneration.cpp"
#include "PlayerMovement.cpp"
#include "Pathfinding.cpp"

//Use the mysql and mySQL++ files to be able to connect to the GameD1 database. The mysql++ is a third party module and can be found at this website: https://tangentsoft.net/mysql++/ 
#include <mysql/mysql.h>
#include <mysql++.h>

using namespace mysqlpp;
using namespace std;

int main()
{
    bool GameExit = false;
    GenerateLoadingMap(1);
  
    while (GameExit == false)
    {
        PlayerInstance.setEnergyLevel(5);
        PrintMap();
        PlayerProcedures();
        EnemyMovement();
    }
    
    return 0;
}