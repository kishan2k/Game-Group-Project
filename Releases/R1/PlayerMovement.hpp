#ifndef PLAYERMOVEMENT_H
#define PLAYERMOVEMENT_H

#include <string>
#include <iostream>

using namespace std;

string WhereToMove();
void PrintEnemiesStats();
bool CanPlayerMove(string, Player&);
int getPlayerXPos();
int getPlayerYPos();
void MovePlayer(string, Player&);
void AttackEnemy(string);
void PlayerAttackEnemy(Player&, Enemy&, int);

#endif