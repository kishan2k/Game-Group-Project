#include "DatabaseClass.hpp"
#include <iostream>
#include <string>
//Use the mysql and mySQL++ files to be able to connect to the GameD1 database. see README.md for link to mysql++ website.
#include <mysql/mysql.h>
#include <mysql++.h>

using namespace mysqlpp;
using namespace std;

//Database Initialisation method to setup default class attributes.
DatabaseClass::DatabaseClass()
{
    _DatabaseName = "GameD1";
    _ComputerName = "localhost";
    _UserName = "root";
    _Password = "codio";
}

//Contains the methods to retrieve the details of the database attributes to connect to the database.
//char* means an array of characters and is required for the mysql++ module conncetion function.
const char* DatabaseClass::getDatabaseName() {
    return _DatabaseName;
}

const char* DatabaseClass::getComputerName() {
    return _ComputerName;
}

const char* DatabaseClass::getUserName() {
    return _UserName;
}

const char* DatabaseClass::getPassword() {
    return _Password;
}

string DatabaseClass::getLevelMap(int MapRequired)
{
    /*
    A function which takes a number of the level required as input and returns the map as a string.
    */

    try 
    {
        //Create an empty connection to use later on.
        Connection conn(false);

        //Give details of the database for the connection to connect to.
        if (conn.connect(getDatabaseName(),getComputerName(), getUserName(), getPassword()))
        {
            //Create a memory location of the query to be entered into. Write the required query and place the query into the query string.
            ostringstream QueryString;
            QueryString << "SELECT Map FROM Levels WHERE LevelNumber = " << MapRequired << ";";
            Query query = conn.query(QueryString.str());

            //Execute the query and store the reults in the results memory
            StoreQueryResult Reults = query.store();
            
            //Disconnect from the database as the data has been retrieved and the connection is no lnger needed
            conn.disconnect();
            
            //Get the first and only cell (on the first row and in the first column) and return the results
            ostringstream outstream;
            outstream << Reults[0][0];
            return outstream.str();
        }
        else
        {
            //Give a message to the user stating that the conncetion couldn't be created
            cerr << "Connection Failed. Program will now close" << endl;
            cout << conn.error() << endl;
            return "Connection Failed. Program will now close";
        }
    }
    //catch an error if the procedure fails.
    catch (Exception err){
        cerr << err.what() << endl;
        return "Unexected Error whilst communicating with the database"; 
    }
}