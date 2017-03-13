#include <iostream>
#include "EnemyClass.cpp"
#include "PlayerClass.cpp"

using namespace std;

int main() {
    Player p1;
    Enemy e1;
    cout << "Enemy starting health: " << e1.getHealth() << endl;
    p1.attack(e1);
    cout << p1.getEnergyLevel() << endl;
    cout << "Enemy new health: " << e1.getHealth() << endl;
    cout << p1.getXPos() << endl;
    p1.move('d');
    cout << p1.getXPos() << endl;
}