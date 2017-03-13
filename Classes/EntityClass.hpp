#ifndef ENTITYCLASS_H
#define ENTITYCLASS_H
#include <iostream>

using namespace std;

class Entity
{
    /*
     A parent class for the Player and Enemy Classes.
     Class atrributes:
     callNo - used to assign Entity IDs.
     
     Object attributes:
     entityID - used to identify each entity.
     health - The amount of damage that can be dealt to an entity before it dies.
     strength - Used to calculate the damage an entity does.
     energyLevel - The amount of actions an entity can perform each turn.
     xPos & yPos - Used to deterine the position of the entity on the map.
     isAlive - Used to determine whether the entity is alive and therefore if it should be shown on screen.
     
     Constructor function:
     This is called when an entity object is created. It takes no inputs and initialises the object's atrib
     Get funtions:
     Return the value for the following attributes - EntityID, health, strength, xPos, yPos, isAlive.
     
     Set functions - Change the value of the following attributes:
      - health, strength, xPos, yPos. These take one integer as input.
      - isAlive. Takes one boolean as input.
     
     Attack function:
     Takes an object as input and uses the calling object's stats to calculate the damage dealt to the
     input object.
     
     Move function:
     Changes an object's location by 1 based on an input direction of type string.
     */
    protected:
    static int callNo;
    static const int attackCost;
    int _entityID;
    int _health;
    int _strength;
    int _energyLevel;
    int _xPos;
    int _yPos;
    bool _isAlive;
    
    public:
    Entity();
    int getEntityID();
    
    int getHealth();
    void setHealth(int);
    
    int getStrength();
    void setStrength(int);
    
    int getEnergyLevel();
    void setEnergyLevel(int);
    
    int getXPos();
    void setXPos(int);
    
    int getYPos();
    void setYPos(int);
    
    bool getIsAlive();
    void setIsAlive(bool);
    
    void attack(Entity&);
    
    void move(char);
};


int Entity::callNo = 0;
int attackCost = 1;

#endif