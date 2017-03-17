#include <iostream>
#include <string>
#include <vector>

#include "UserInput.cpp"
#include "PlayerClass.cpp"
Player PlayerInstance;
#include "EnemyClass.cpp"
vector<Enemy> Enemies;
#include "MapGeneration.cpp"
//#include "Astar.cpp"
#include "PlayerMovement.cpp"
//#include "Pathfinding.cpp"

//Use the mysql and mySQL++ files to be able to connect to the GameD1 database. The mysql++ is a third party module and can be found at this website: https://tangentsoft.net/mysql++/ 
#include <mysql/mysql.h>
#include <mysql++.h>

using namespace mysqlpp;
using namespace std;

string Level1Map = "#################################                       #e     ##      #                #      ##      #                #      ##      #                #      ##      #                #      ##      #                #      ##      #                #      ######  ###########      #      ##                #      #      ##                #      #      ##             #  #      #      ##             #  #      #      ##             #  #      #      ############  ##                ##            ####################             #                ##             #                ##             #   p            ##           e #                ##  ############                ##       #                      ##    #        #             e  #################################";



void TestGeneratingMap ()
{
     if (db.getLevelMap(1) == Level1Map)
     {
         cout << "Test -- get level 1 map PASSED" << endl;
     }
    
     if (db.getLevelMap(1) == "Connection Failed. Program will now close")
     {
         cout << "Test -- Check than the program closes if it could not retieve the map from the database -- PASSED" << endl;
     }
}

void TestLoadMapIntoArray()
{
    LoadMapIntoArray(Level1Map, PlayerInstance);
    int CharNum = 0;
    
    for (int column=0; column<MapColumnSize; column++)
    {
        for(int row=0; row<MapRowSize; row++)
        {
            //add character to the appropriate array position
            if (arrCurrentMap[row][column] != Level1Map.at(CharNum))
                {
                    cout << "Test -- Map array matches map given as string -- FAILED" << endl;
                }
            
            //move to next character ins string
            CharNum += 1;
        }
    }
    if (CharNum == 768)
    {
        cout << "Test -- Map array matches map given as string -- PASSED" << endl;
    }
}

void TestPopulateEnemiesVector()
{
    PopulateEnemiesVector();
    if (Enemies.size() == 3)
    {
        cout << "Test -- PopulateEnemiesVector correctly populated the enemies vector for level1 -- PASSED" << endl;
    }
    else
    {
        cout << "Test -- PopulateEnemiesVector incorrectly populated the enemies vector for level1 -- FAILED" << endl;
    }
}

void MapGenerationTests()
{
    cout << "***********************MapGeneration Automated Tests*****************" << endl;
    TestGeneratingMap();
    TestLoadMapIntoArray();
    TestPopulateEnemiesVector();
    cout << "*********************************************************************" << endl;
}

void TestCanPlayerMove()
{
    string letters = "abcdefghijklmnopqrstuvwxyz36'~";
    
    for(char letter : letters)
    {
        if (letter == 'a' || letter == 'd' || letter == 's' || letter == 'w')
        {
            if (CanPlayerMove(&letter, PlayerInstance) == false)
            {
                cout << "Test -- User input " << letter << " was accepted and should have been -- PASSED" << endl;
            }
            else
            {
                 cout << "Test -- User input " << letter << " was accepted and should NOT have been -- FAILED" << endl;
            }
        }
        else
        {
            if (CanPlayerMove(&letter, PlayerInstance) == false)
            {
                cout << "Test -- User input " << letter << " was NOT accepted and should NOT have been -- PASSED" << endl;
            }
            else
            {
                 cout << "Test -- User input " << letter << " was accepted and should NOT have been -- FAILED" << endl;
            }
        }
    
    } 
}

void TestMovePlayer()
{
    int OriginalXPos = PlayerInstance.getXPos();
    int OriginalYPos = PlayerInstance.getYPos();
    
    MovePlayer("w", PlayerInstance);
    if (PlayerInstance.getXPos() == OriginalXPos && PlayerInstance.getYPos() == OriginalYPos - 1)
    {
        cout << "Test -- Player can move up -- PASSED" << endl;
    }
    else
    {
        cout << "Test -- Player can move up -- FAILED" << endl;
    }
    
    OriginalXPos = PlayerInstance.getXPos();
    OriginalYPos = PlayerInstance.getYPos();
    
    MovePlayer("s", PlayerInstance);
    if (PlayerInstance.getXPos() == OriginalXPos && PlayerInstance.getYPos() == OriginalYPos + 1)
    {
        cout << "Test -- Player can move down -- PASSED" << endl;
    }
    else
    {
        cout << "Test -- Player can move down -- FAILED" << endl;
    }
    
    OriginalXPos = PlayerInstance.getXPos();
    OriginalYPos = PlayerInstance.getYPos();
    
    MovePlayer("a", PlayerInstance);
    if (PlayerInstance.getXPos() == OriginalXPos-1 && PlayerInstance.getYPos() == OriginalYPos)
    {
        cout << "Test -- Player can move left -- PASSED" << endl;
    }
    else
    {
        cout << "Test -- Player can move left -- FAILED" << endl;
    }
    
    OriginalXPos = PlayerInstance.getXPos();
    OriginalYPos = PlayerInstance.getYPos();
    
    MovePlayer("d", PlayerInstance);
    if (PlayerInstance.getXPos() == OriginalXPos+1 && PlayerInstance.getYPos() == OriginalYPos)
    {
        cout << "Test -- Player can move right -- PASSED" << endl;
    }
    else
    {
        cout << "Test -- Player can move right -- FAILED" << endl;
    }
}

void PlayerMovementTests()
{
    cout << "***********************PlayerMovement Automated Tests*****************" << endl;
    TestCanPlayerMove();
    TestMovePlayer();
    cout << "*********************************************************************" << endl;
}

int main()
{
    MapGenerationTests();
    PlayerMovementTests();
}