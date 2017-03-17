#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Pathfinding.cpp"


using namespace std;

/* Variables */
    int rowtest; 
    int coltest; 
    const int enemnumbtest = 3;
    const int playnumbtest = 1;
    int playcounttest = 1;
    int enemcounttest = 3;
    int enemcordrtest[enemnumbtest];
    int enemcordctest[enemnumbtest];
    int playcordrtest[playnumbtest];
    int playcordctest[playnumbtest];


void TestfindAllEnem(){
    bool found = false;
    while(!found){                                
        for(rowtest=0;rowtest<MapRowSize;rowtest++){          
            for(coltest=0;coltest<MapColumnSize;coltest++){   
                if(arrCurrentMap[rowtest][coltest]=='e'){ 
                    enemcordrtest[enemcounttest]=rowtest;     
                    enemcordctest[enemcounttest]=coltest;     
                    enemcounttest--;                  
                }
                if(enemcounttest==0){                 
                    found=true;                   
                }
                if(rowtest==MapRowSize-1 && coltest==MapColumnSize-1){
                    found=true;
                }
            }
        }
    }
    found=false;
    enemcounttest=enemnumbtest;
}




/* A function that find player(s). There is a while loop that serches in rows and columns.
   If it finds the letter 'p' saves the row and column number. Then substracts 1 from
   the enemy count in order to find how much are left. If there are no left players, the while 
   loop stops. */

void TestfindPlayer(){
    bool found = false;
    while(!found){                                
        for(rowtest=0;rowtest<MapRowSize;rowtest++){           
            for(coltest=0;coltest<MapColumnSize;coltest++){   
                if(arrCurrentMap[rowtest][coltest]=='p'){ 
                    playcordrtest[playcounttest]=rowtest;     
                    playcordctest[playcounttest]=coltest;     
                    playcounttest--;                  
                }
                if(playcounttest==0){                
                    found=true;                   
                }
            }
        }
    }
    found=false;
    playcounttest=playnumbtest;
}

int main (){
    for(int i=3;i>0;i--){
        if(enemcordrtest[i] == enemcordr[i] && enemcordctest[i] == enemcordc[i]){
            cout<<"Test - Find enemy "<<i<<" - PASSED"<<endl;
        }
        else{
            cout<<"Test - Find enemy "<<i<<" - FAILED"<<endl;
        }
    }
    if(playcordrtest[1] == playcordr[1] && playcordctest[1] == playcordr[1]){
        cout<<"Test - Find player "<<1<<" - PASSED"<<endl;
    }
    else{
        cout<<"Test - Find player "<<1<<" - FAILED"<<endl;
    }
    return 0;
}