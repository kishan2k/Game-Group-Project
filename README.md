# Game Project - D1

Sprint sheet: https://docs.google.com/spreadsheets/d/15zmBvjYl_ikNeVGa43pKjJBd08npw8qt6O5hEaxSXOM/edit?usp=sharing

# MySQL++ Library

To connect to the MySQL database we will be using the following module: https://tangentsoft.net/mysql++/
The approriate libraries have been installed on codio.

To help with the understanding of how to communicate with the database, I have provided some example scripts in a folder called "C++ and mysql examples"
In my examples I have added comments to say what each lines does to make it clear.

# IMPORTANT: 
To compile a cpp file which uses the mysql++ file you must run the following line:
g++ -I/usr/include/mysql -I/usr/include/mysql++  -L/usr/lib FILENAME.cpp -o PROGRAMMENAME -lmysqlpp -lmysqlclient

This is due to the compiler not picking up the mysql++.h file automatically.
Please note that you must replace FILENAME and PROGRAMMENAME with the appropriate names.