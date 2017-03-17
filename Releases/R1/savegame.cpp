#include <mysql/mysql.h>
#include <mysql++.h>
#include <iostream>
#include <string>
#include <sstream>
#include "PlayerClass.cpp"

using namespace std;
using namespace mysqlpp;

int main()
{
    // Loads data for current player. 
	Player p1;

    // Create an empty connection to use later on.
    Connection conn(false);

    // Give details of the database for the connection to connect to.
    conn.connect("GameD1", "localhost", "root", "codio");

    // Create a memory location of the query to be entered into.
    Query query = conn.query();

	// Create the query to save the attributes to database
    ostringstream querystring;
    querystring << "INSERT INTO Save_Games VALUES (null, " << p1.getEntityID() << ",'#', "
                << p1.getXPos() << "," << p1.getYPos() << "," << p1.getScore() << ");";

    // Write the required query and place the query into.
    query << querystring.str();
    // Execute the query
    query.execute();

	// Output to terminal to say the Game has saved 
    cout << "Game Saved Successfully!" << endl;
    return 0;
}

//KISHAN