#pragma once
#include "enemy.hpp"

// TODO: Implement methods
class AttackPlane: public Enemy {
private:

public:
    AttackPlane(int speed, int value, int price, int hp, sf::Sprite sprite) : Enemy(speed, value, price, hp, sprite) {};

    void update();
    void onDestroy();
};
