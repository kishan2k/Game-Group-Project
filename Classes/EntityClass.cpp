#include "EntityClass.hpp"
#include <iostream>
#include <math.h>

using namespace std;

Entity::Entity() {
    //constructor method
    _entityID = callNo; //assign a unique entityID
    //initialise attribute values
    _health = 50;
    _strength = 10;
    _energyLevel = 5;
    _isAlive = true;
    _xPos = 0;
    _yPos = 0;
    callNo++; //increment the callNo in order to give the next object a unique entityID
    attackCost = 1;
}

int Entity::getEntityID() {
    return _entityID;
}

int Entity::getHealth() {
    return _health;
}

void Entity::setHealth(int val) {
    _health = val;
}

int Entity::getStrength() {
    return _strength;
}

void Entity::setStrength(int val) {
    _strength = val;
}

int Entity::getEnergyLevel() {
    return _energyLevel;
}

void Entity::setEnergyLevel(int val) {
    _energyLevel = val;
}

bool Entity::getIsAlive() {
    return _isAlive;
}

void Entity::setIsAlive(bool val) {
    _isAlive = val;
}

int Entity::getXPos() {
    return _xPos;
}

void Entity::setXPos(int val) {
    _xPos = val;
}

int Entity::getYPos() {
    return _yPos;
}

void Entity::setYPos(int val) {
    _yPos = val;
}

void Entity::attack(Entity& other) { //Takes an object as input and uses the calling object's stats to calculate the damage dealt to the input object.
    if (this->getEnergyLevel() > 0) { //check that the object has enough energy to attack
        other.setHealth(other.getHealth() - floor((this->getEnergyLevel() * this->getStrength()) / 2)); //The lower the attacker's energy level the less powerful the attack
        if (other.getHealth() <= 0) { //check that the object being attacked still has some health
            other.setIsAlive(false); //if not set them to be dead
        }
        this->setEnergyLevel(this->getEnergyLevel() -attackCost); //remove the cost of one attack
    }
}

void Entity::move(char direction) { //Changes an object's location by 1 based on an input direction of type string.
    if (direction == "w") //Up
    {
                this->setYPos(this->getYPos() - 1);
    }
    else if (direction == "a") //Left
    {
                this->setXPos(this->getXPos() - 1);
    }
    else if (direction == "s") //Down
    {
                this->setYPos(this->getYPos() + 1);
    }
    else if (direction == "d") //Right
    {
                this->setXPos(this->getXPos() + 1);
    } 
}
/*
int main() {
    Entity e1;
    Entity e2;
    e1.attack(e2);
    cout << e1.getEnergyLevel() << endl;
    cout << e2.getHealth() << endl;
    return 0;
} */