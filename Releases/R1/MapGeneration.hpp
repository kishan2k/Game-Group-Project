#ifndef MAPGENERATION_H
#define MAPGENERATION_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

void LoadMapIntoArray(string, Player&);
void PrintMap();
int GenerateLoadingMap(int);
void PopulateEnemiesVector();

#endif