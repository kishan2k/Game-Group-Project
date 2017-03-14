#include "MapGeneration.hpp"
#include "DatabaseClass.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace mysqlpp;
using namespace std;

/*
Setup the global variable and constants of the map whcih will be required
to be kept in memory whilst the program is running but also will be needed for functions
that move the player, check to see if there is a wall in the direction the 
player needs to move in, etc.
*/

const int MapRowSize = 32;
const int MapColumnSize = 24;
char arrCurrentMap[MapRowSize][MapColumnSize];
DatabaseClass db{};

int GenerateLoadingMap(int MapToGenerate)
{
    /* 
    A funciton that takes the map that needs to be generated as an integer and 
    prints the map to the screen. It also places the map into an array to be used for
    other tasks such as pathfinding, attacking near by enemies, etc. This is to be 
    used when the user click starts new game or load a map between levels.
    */
    
    //Call the GetLevelMap funciton to retrieve the map as a string.
    string Map = db.getLevelMap(MapToGenerate);
    
    //Load the map into an array to be used for other uses (e.g. pathfinding, etc)
    LoadMapIntoArray(Map, PlayerInstance);
    
    //Print the map to the screen for the user to see.
    PrintMap();
    
    //Populate Enemies
    PopulateEnemiesVector();
       
    return 0;
}

int LoadMapIntoArray(string InsertMapIntoArray, Player& UserPlayer)
{
    /* A function that takes the map as a string input and places the appropriate characters inth the global map array */
    int CharNum = 0;
    
    for (int column=0; column<MapColumnSize; column++)
    {
        for(int row=0; row<MapRowSize; row++)
        {
            //add character to the appropriate array position
            arrCurrentMap[row][column] = InsertMapIntoArray.at(CharNum);
            
            if (InsertMapIntoArray.at(CharNum) == 'p')
            {
                UserPlayer.setXPos(column);
                UserPlayer.setYPos(row);
            }
            //move to next character ins string
            CharNum += 1;
        }
        
    }
    return 0;
}

int PrintMap()
{
    /*
    A function that prints the given map as a string to the screen
    */
    
    //clear screen and places cursor at row 1 column 1
    cout << "\033[2J\033[1;1H";
    
    //iterate through each letter in the map array
    for (int col=0; col<MapColumnSize; col++)
    {
        for (int row=0; row<MapRowSize; row++)
        {
            cout << arrCurrentMap[row][col];
        }
        cout << endl;
    }
    return 0;
    
}

void PopulateEnemiesVector()
{
    Enemies.clear();
    
    //iterate through each letter in the map array
    for (int col=0; col<MapColumnSize; col++)
    {
        for (int row=0; row<MapRowSize; row++)
        {
            if (arrCurrentMap[row][col] == 'e')
            {
                Enemy NewEnemy;
                NewEnemy.setXPos(row);
                NewEnemy.setYPos(col);
                Enemies.push_back(NewEnemy);
            }
        }
    }
}