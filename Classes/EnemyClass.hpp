#ifndef ENEMYCLASS_H
#define ENEMYCLASS_H
#include <iostream>
#ifndef ENTITYCLASS_H
#include "EntityClass.hpp"
#include "EntityClass.cpp"
#endif

using namespace std;

class Enemy : public Entity {
    /*
     A child class of Entity which inherits all of its methods and attributes.
     It has an additional attribute lootType which represents the type of loot that the enemy drops upon its death.
     The lootType attribute has get and set functions.
     */
    private:
    int _lootType;
    
    public: 
    Enemy();
    int getLoot();
    void setLoot(int);
};

#endif