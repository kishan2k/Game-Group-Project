#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H
#include <iostream>
#ifndef ENTITYCLASS_H
#include "EntityClass.hpp"
#include "EntityClass.cpp"
#endif

using namespace std;

class Player : public Entity {
    /*
     A child class of Entity which inherits all of its methods and attributes.
     It has additional attributes currentScore and name.
     Both of these attributes have get and set methods.
     */
    private:
    int _currentScore;
    string _name;
    
    public:
    Player();
    int getScore();
    void setScore(int);
    
    string getName();
    void setName(string);
};

#endif