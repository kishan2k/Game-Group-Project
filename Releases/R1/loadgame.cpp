// Use the mySQL++ files to be able to connect to the GameD1 database
#include <mysql/mysql.h>
#include <mysql++.h>
#include <iostream>
#include <string>
#include <sstream>
#include "PlayerClass.cpp"

using namespace std;
using namespace mysqlpp;

string loadgame(int savedGameID)
{
    try
    {
        // Create an empty connection to use later on.
        Connection conn(false);

        // Give details of the database for the connection to connect to.
        conn.connect("GameD1", "localhost", "root", "codio");

        // Create a memory location of the query to be entered into.
        Query query = conn.query();

        // Write Query
        ostringstream querystring;
        querystring << "SELECT * FROM Save_Games WHERE savedGamesID = " << savedGameID << ";";

        // Write the required query and place the query into.
        query << querystring.str();
        // Execute the query
        query.execute();


        StoreQueryResult Results = query.store(); // Store query results raw

        conn.disconnect(); // Disconnect from datbase

        ostringstream output;
        output << Results;
        return output.str(); // Convert Raw results to string.
    }
    catch (exception& err) // Catch any errors if it fails
    {
        cerr << err.what() << endl; // inform user what the error was
    }
}

int main()
{
    loadgame(2); // Automatic testing to check if the loadgame function works
    cout << loadgame << endl;
}

//KISHAN