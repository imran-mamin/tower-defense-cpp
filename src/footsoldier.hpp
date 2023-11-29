#pragma once
#include "enemy.hpp"

// TODO: Implement methods
class FootSoldier: public Enemy {
private:

public:
    FootSoldier(int speed, int value, int price, int hp, Game& game)
            : Enemy(speed, value, price, hp, game) {};

    ~FootSoldier() {};

    void update();
    void onDestroy();
};
