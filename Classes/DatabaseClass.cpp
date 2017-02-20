#include <iostream>
#include <string>
//Use the mysql and mySQL++ files to be able to connect to the GameD1 database
#include <mysql/mysql.h>
#include <mysql++.h>

using namespace mysqlpp;
using namespace std;

class Database {
    /*
     Database Class that will acts as a conduit between the program and the database.
     Atrributes:
        DatabaseName - Holds the name of the database in a striung constant.
        ComputerName - Will hold the name of the database. in this case it will be localhost.
        UserName - Will hold the name of the user to gain access to the database.
        Password - Will hold the password of the user to gain access to the database.
    */ 
    
    private:
    //List of private attributes as described in the docstring for the database class
    char* _DatabaseName = "GameD1";
    char* _ComputerName = "localhost";
    char* _UserName = "root";
    char* _Password = "codio";
    
    //Contains the methods to retrieve the details of the database to connect to.
    //char* means an array of characters and is required for the mysql++ conncetion.
    char* getDatabaseName() {
        return _DatabaseName;
    }
    
    char* getComputerName() {
        return _ComputerName;
    }
    
    char* getUserName() {
        return _UserName;
    }
    
    char* getPassword() {
        return _Password;
    }
        
    //Contains the public methods to access the database
    public:   
    string GetLevelMap(int MapRequired)
    {
        /*
        A function which takes a number of the level required as input and returns the map as a string
        */
        
        try {
            //Create an empty connection to use later on.
            Connection conn(false);
            
            //Give details of the database for the connection to connect to.
            conn.connect(getDatabaseName(),getComputerName(), getUserName(), getPassword());
            
            //Create a memory location of the query to be entered into. Write the required query and place the query into the query string.
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
        
        //catch an error if the procedure fails.
        catch (exception &err){
            cerr << err.what() << endl;
        }
    }
};

int main()
{
   Database db;
   db.GetLevelMap(1);
   return 0;
}