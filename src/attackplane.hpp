#pragma once
#include "enemy.hpp"

// TODO: Implement methods
class AttackPlane: public Enemy {
private:

public:
    AttackPlane(int speed, int value, int price, int hp, Game& game)
            : Enemy(speed, value, price, hp, game) {};

    void update();
    void onDestroy();
};
