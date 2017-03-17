#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
// #include "PlayerClass.cpp"
// Player PlayerInstance;
// #include "EnemyClass.cpp"
// vector<Enemy> Enemies;
// #include "MapGeneration.cpp"

using namespace std;

/* Variables */
    int row=0;
    int col=0;
    const int enemnumb = 3;
    const int playnumb = 1;
    int playcount = 1;       // Counting how much players are left
    int enemcount = 3;       // Counting how much enemies are left
    int enemcordr[enemnumb]; // Enemy row number
    int enemcordc[enemnumb]; // Enemy column number
    int playcordr[playnumb]; // Player row number
    int playcordc[playnumb]; // Player column number

/* A function that find enemies. There is a while loop that serches in rows and columns.
   If it finds the letter 'e' saves the row and column number. Then substracts 1 from
   the enemy count in order to find how much are left. If there are no left enemies, the while
   loop stops. */

void findAllEnem(){
    bool found = false;
    while(!found){                                
        for(row=0;row<MapRowSize;row++){          
            for(col=0;col<MapColumnSize;col++){   
                if(arrCurrentMap[row][col]=='e'){ 
                    enemcordr[enemcount]=row;     
                    enemcordc[enemcount]=col;     
                    enemcount--;                  
                }
                if(enemcount==0){                 
                    found=true;                   
                }
                if(row==MapRowSize-1 && col==MapColumnSize-1){
                    found=true;
                }
            }
        }
    }
    found=false;
    enemcount=enemnumb;
}




/* A function that find player(s). There is a while loop that serches in rows and columns.
   If it finds the letter 'p' saves the row and column number. Then substracts 1 from
   the enemy count in order to find how much are left. If there are no left players, the while 
   loop stops. */

void findPlayer(){
    bool found = false;
    while(!found){                                
        for(row=0;row<MapRowSize;row++){           
            for(col=0;col<MapColumnSize;col++){   
                if(arrCurrentMap[row][col]=='p'){ 
                    playcordr[playcount]=row;     
                    playcordc[playcount]=col;     
                    playcount--;                  
                }
                if(playcount==0){                
                    found=true;                   
                }
            }
        }
    }
    found=false;
    playcount=playnumb;
}
/* A function to move enemy. It gets absolutely random number from 1 to 4 for each direction (left, right, up and down). 
   Then the function cheks if these directions are free */

void enemMovement() {
    srand(time(NULL)); // absolutely random
    
    /* Variables for the function */
    bool legit = false;
    const int possible = 1500;
    int possmov = 1;
    int bestmove;
    int min[enemnumb];
    for(int i=enemnumb;i>0;i--){
        min[i]=possible;       // Minimum distance
    }
    int countMove[possible][enemnumb];// Counts how many moves have been made with road
    int moveR[possible][enemnumb];    // Gets virtual row without moving the enemy
    int moveC[possible][enemnumb];    // Gets virtual column without moving the enemy
    int firstR[possible][enemnumb];
    int firstC[possible][enemnumb];
    
    for (playcount = playnumb; playcount > 0; playcount--) { // For every player
      for (enemcount = enemnumb; enemcount > 0; enemcount--){ //For the three enemies 
          if(enemcordr[enemcount]>0 && enemcordc[enemcount]>0){
            for (possmov = 0; possmov < possible; possmov++) {  // Possible directions
              moveR[possmov][enemcount] = enemcordr[enemcount];
              moveC[possmov][enemcount] = enemcordc[enemcount];
              if(arrCurrentMap[moveR[possmov][enemcount]][moveC[possmov][enemcount] + 1] == 'p' || arrCurrentMap[moveR[possmov][enemcount]][moveC[possmov][enemcount] - 1] == 'p'
                || arrCurrentMap[moveR[possmov][enemcount] + 1][moveC[possmov][enemcount]] == 'p' || arrCurrentMap[moveR[possmov][enemcount] - 1][moveC[possmov][enemcount]] == 'p'){
                  break;
              }
              while (legit != true) {
                int nRand = rand()%(4-0)+1;  //4 possible directions  
                if (nRand == 1) { //Moveove right
                  if (arrCurrentMap[moveR[possmov][enemcount]][moveC[possmov][enemcount] + 1] != '#') {
                      if (arrCurrentMap[moveR[possmov][enemcount]][moveC[possmov][enemcount] + 1] == 'p') {
                        if(countMove[possmov][enemcount]<min[enemcount]){
                          min[enemcount]=countMove[possmov][enemcount];
                          bestmove = possmov;
                        }
                        legit=true;
                      }
                      moveC[possmov][enemcount]++;
                      countMove[possmov][enemcount]++;
                      if(countMove[possmov][enemcount]==1){ // if it is the first move it will save the coordinates
                        firstR[possmov][enemcount]=enemcordr[enemcount];
                        firstC[possmov][enemcount]=moveC[possmov][enemcount];
                      }
                    }
                  }
                  if (nRand == 2) // Move left
                  {
                    if (arrCurrentMap[moveR[possmov][enemcount]][moveC[possmov][enemcount] - 1] != '#') {
                      if (arrCurrentMap[moveR[possmov][enemcount]][moveC[possmov][enemcount] - 1] == 'p') {
                        if(countMove[possmov][enemcount]<min[enemcount]){
                          min[enemcount]=countMove[possmov][enemcount];
                          bestmove = possmov;
                        }
                        legit=true;
                      }
                      moveC[possmov][enemcount]--;
                      countMove[possmov][enemcount]++;
                      if(countMove[possmov][enemcount]==1){ // if it is the first move it will save the coordinates
                        firstR[possmov][enemcount]=enemcordr[enemcount];
                        firstC[possmov][enemcount]=moveC[possmov][enemcount];
                      }
                    }
                  }
                  if (nRand == 3) // Move up
                  {
                    if (arrCurrentMap[moveR[possmov][enemcount] - 1][moveC[possmov][enemcount]] != '#') {
                      if (arrCurrentMap[moveR[possmov][enemcount] - 1][moveC[possmov][enemcount]]== 'p') {
                        if(countMove[possmov][enemcount]<min[enemcount]){
                          min[enemcount]=countMove[possmov][enemcount];
                          bestmove = possmov;
                        }
                        legit=true;
                      }
                      moveR[possmov][enemcount]--;
                      countMove[possmov][enemcount]++;
                      if(countMove[possmov][enemcount]==1){ // if it is the first move it will save the coordinates
                        firstR[possmov][enemcount]=moveR[possmov][enemcount];
                        firstC[possmov][enemcount]=enemcordc[enemcount];
                      }
                    }
                  }
                  if (nRand == 4) // Move down
                  {
                    if (arrCurrentMap[moveR[possmov][enemcount] + 1][moveC[possmov][enemcount]] != '#') {
                      if (arrCurrentMap[moveR[possmov][enemcount] + 1][moveC[possmov][enemcount]]== 'p') {
                        if(countMove[possmov][enemcount]<min[enemcount]){
                          min[enemcount]=countMove[possmov][enemcount];
                          bestmove = possmov;
                        }
                        legit=true;
                      }
                      moveR[possmov][enemcount]++;
                      countMove[possmov][enemcount]++;
                      if(countMove[possmov][enemcount]==1){ // if it is the first move it will save the coordinates
                        firstR[possmov][enemcount]=moveR[possmov][enemcount];
                        firstC[possmov][enemcount]=enemcordc[enemcount];
                      }
                    }
                  }
                }
                legit=false; // Returns the value of legit to false for next movement route
              }
              if(arrCurrentMap[firstR[bestmove][enemcount]][firstC[bestmove][enemcount]]=' '){
                  arrCurrentMap[enemcordr[enemcount]][enemcordc[enemcount]]=' '; // set previous location to empty
                  arrCurrentMap[firstR[bestmove][enemcount]][firstC[bestmove][enemcount]]='e'; // movement of enemy
              }
           }
        }
       
      }
      for(int j = 1; j <= enemnumb; j++){
         for(int i = 1; i <= possible; i++){  
            countMove[i][j] = 0;
         }
      }
      enemcount = enemnumb;
      playcount = playnumb;
      possmov = 1;
}

void EnemyMovement(){
    findPlayer();          // Finds players
    findAllEnem();         // Find enemies
    enemMovement();        // Enemy movement
}

/* Main function */

/*
int main (){
    // remove
    GenerateLoadingMap(1); // Generate map
    
    
    while (true)
    {
        EnemyMovement();
        PrintMap();
    }
    
    // remove
    return 0;
}
*/
