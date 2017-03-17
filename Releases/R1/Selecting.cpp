// ADD_LEVEL1.cpp : Creates a connection to gameD1 database in mysql and adds a level to the levels table.
#include <iostream>
#include <string>
//Use the mySQL++ files to be able to connect to the GameD1 database
#include <mysql/mysql.h>
#include <mysql++.h>
#define HOST "localhost" // you must keep the quotes on all four items,  
#define USER "root" // the function "mysql_real_connect" is looking for a char datatype,
#define PASSWD "codio" // without the quotes they're just an int.
#define DB "GameD1"

using namespace std;
using namespace mysqlpp;

string db1()
{
        Connection conn(false);
        conn.connect("GameD1", "localhost", "root", "codio");
        if (conn.connect("GameD1", "localhost", "root", "codio"))
        {
            ostringstream Querystring;
            Querystring << "SELECT * FROM Loot WHERE LootID = 11;";
            Query query = conn.query(Querystring.str());
            
            StoreQueryResult Results = query.store();
            
            conn.disconnect();
            
            ostringstream output;
            output << Results[0][0];
            output << " ";
            output << Results[0][1];
            output << " ";
            output << Results[0][2];
            output << " ";
            output << Results[0][3];
            output << " ";
            output << Results[0][4];
            output << " ";
            output << Results[0][5];
            return output.str();
        }
}

string db(){
    //Create an empty connection to use later on.
        Connection conn(false);

        //Give details of the database for the connection to connect to.
        if (conn.connect("GameD1", "localhost", "root", "codio"))
        {
            //Create a memory location of the query to be entered into. Write the required query and place the query into the query string.
            ostringstream QueryString;
            QueryString << "SELECT Wepon FROM Loot WHERE LootID = 11;";
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
}

int main()

    {
       cout<<db1()<<endl;

    return 0;
}