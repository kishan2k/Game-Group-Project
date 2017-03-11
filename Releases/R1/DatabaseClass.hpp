#ifndef DATABASECLASS_H
#define DATABASECLASS_H
#include <string>
#include <iostream>
//Use the mysql and mySQL++ files to be able to connect to the GameD1 database. See README.md for link to mysql++ website.
#include <mysql/mysql.h>
#include <mysql++.h>

using namespace mysqlpp;
using namespace std;

class DatabaseClass
{
    /*
     Database Class that will acts as a conduit between the program and the database.
     
     Private Atrributes:
        _DatabaseName - Holds the name of the database in an array of characters.
        _ComputerName - Holds the name of the computer the database is running on. In this case it will be localhost.
        _UserName - Will hold the name of the user to gain access to the database.
        _Password - Will hold the password of the user to gain access to the database.
        
     Public Methods:
        getDatabaseName - returns the private attribute _DatabaseName
        getComputerName - returns the private attribute _ComputerName
        getComputerName - returns the private attribute _UserName
        getPassword - returns the private attribute _Password
     
     Public Methods:
        getLevelMap - returns a map as a string for the associated level given as a parameter.
    */ 
    public:
        //Public instantiation method for the database class.
        DatabaseClass();
    
        //Declares the private methods to retrieve the private attributes listed above.
        const char* getDatabaseName();
        const char* getComputerName();
        const char* getUserName();
        const char* getPassword();
    
        //Public method to retrieve a map for a given level according to the level number given as a parameter.
        string getLevelMap(int);

    private:
        //Declares the private attributes for the database class to connect to the database.
        const char* _DatabaseName;
        const char* _ComputerName;
        const char* _UserName;
        const char* _Password;
    
};

#endif // DATABASECLASS_H