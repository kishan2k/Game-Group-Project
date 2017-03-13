#include "PlayerClass.hpp"
#include <iostream>

using namespace std;

Player::Player() {//Constructor method
    //initialise attributes
    _currentScore = 0;
    _name = "Player";
}

int Player::getScore() {
    return _currentScore;
}

void Player::setScore(int val) {
    _currentScore = val;
}

string Player::getName() {
    return _name;
}

void Player::setName(string val) {
    _name = val;
}
/*
int main() {
    Player p1;
    cout << p1.getHealth() << endl;
    return 0;
}
*/