#include <iostream>
#include <sstream> 

//Use the mysql and mySQL++ files to be able to connect to the GameD1 database
#include <mysql/mysql.h>
#include <mysql++.h>

using namespace std;
using namespace mysqlpp;

/*
Setup the global variable and constants of the map whcih will be required
to be kept in memory whilst the program is running but also will be needed for functions
that move the player, check to see if there is a wall in the direction the 
player needs to move in, etc.
*/
const int MapRowSize = 24;
const int MapColumnSize = 32;
char arrCurrentMap[MapRowSize][MapColumnSize];

string GetLevelMap(int MapRequired)
{
    /*
    A function which takes a number of the level required as input and returns the map as a string
    */
    
    //Create an empty connection to use later on.
    Connection conn(false);

    //Give details of the database for the connection to connect to.
    conn.connect("GameD1", "localhost", "root", "codio");

    //Create a memory location of the query to be entered into. Write the required query and place the query into.
    ostringstream QueryString;
    QueryString << "SELECT Map FROM Levels WHERE LevelNumber = " << MapRequired << ";";
    Query query = conn.query(QueryString.str());

    //execute the query and store the reults in the results memory
    StoreQueryResult Reults = query.store();
    
    //Get the first and only cell (on the first row and in  the first column) and return the results
    if (Reults && Reults.num_rows())
    {
        ostringstream outstream;
        outstream << Reults[0][0];
        return outstream.str();
    }
}

int LoadMapIntoArray(string InsertMapIntoArray)
{
    /* A function that takes the map as a string input and places the appropriate characters inth the global map array */
    int CharNum = 0;
    
    for (int row=0; row<MapRowSize; row++)
    {
        for(int column=0; column<MapColumnSize; column++)
        {
            //add character to the appropriate array position
            arrCurrentMap[row][column] = InsertMapIntoArray.at(CharNum);
            
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
    
    //iterate through each letter in the map array
    for (int row=0; row<MapRowSize; row++)
    {
        for (int col=0; col<MapColumnSize; col++)
        {
            cout << arrCurrentMap[row][col];
        }
        cout << endl;
    }
    return 0;
    
}


int GenerateLoadingMap(int MapToGenerate)
{
    /* 
    A funciton that takes the map that needs to be generated as an integer and 
    prints the map to the screen. It also places the map into an array to be used for
    other tasks such as pathfinding, attacking near by enemies, etc. This is to be 
    used when the user click starts new game or load a saved game between levels.
    */
    
    //Call the GetLevelMap funciton to retrieve the map as a string.
    string Map = GetLevelMap(1);
    
    //Load the map into an array to be used for other uses (e.g. pathfinding, etc)
    LoadMapIntoArray(Map);
    
    //Print the map to the screen for the user to see.
    PrintMap();
       
    return 0;
}

int main()
{
   GenerateLoadingMap(1);
   return 0;
}

