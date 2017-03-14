#include <iostream>
#include <string>
#include <vector>

#include "PlayerClass.cpp"
Player PlayerInstance;
#include "EnemyClass.cpp"
vector<Enemy> Enemies;
#include "MapGeneration.cpp"
#include "Astar.cpp"
#include "PlayerMovement.cpp"

//Use the mysql and mySQL++ files to be able to connect to the GameD1 database
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
        PrintMap();
        PlayerProcedures();
    }
    
    return 0;
}