#ifndef MAPGENERATION_H
#define MAPGENERATION_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int LoadMapIntoArray(string, Player&);
int PrintMap();
int GenerateLoadingMap(int);
void PopulateEnemiesVector();

#endif