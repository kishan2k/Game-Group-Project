// Delete_Levels.cpp : Creates a connection to gameD1 database in mysql and deletes everything from Levels table.
// For creating a connection I have followed thh example at this url:
// https://rameshchalla.wordpress.com/tag/connecting-to-mysql-with-c-in-ubuntu/

//Use the mySQL++ files to be able to connect to the GameD1 database
#include <mysql/mysql.h>
#include <mysql++.h>

using namespace std;
using namespace mysqlpp;

int main()
{
    //Create an empty connection to use later on.
    Connection conn(false);
    
    //Give details of the database for the connection to connect to.
    conn.connect("GameD1", "localhost", "root", "codio");
    
    //Create a memory location of the query to be entered into.
    Query query = conn.query();

    //Write the required query and place the query into.
    query << "DELETE FROM Levels;";
    
    //Execute the query
    query.execute();

    return 0;
}