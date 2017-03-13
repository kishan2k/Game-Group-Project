#include "EnemyClass.hpp"
#include <iostream>

using namespace std;

Enemy::Enemy() {//Constructor method
    //initialise attribute value
    _lootType = 0; 
}

int Enemy::getLoot() {
    return _lootType;
}

void Enemy::setLoot(int val) {
    _lootType = val;
}
/*
int main() {
    Enemy e1;
    cout << e1.getHealth() << endl;
    e1.setLoot(14);
    cout << e1.getLoot() << endl;
    return 0;
}
*/