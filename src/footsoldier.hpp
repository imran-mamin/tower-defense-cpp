#pragma once
#include <cmath>
#include <assert.h>
#include <algorithm>

#include "enemy.hpp"
#include <iostream>

// TODO: Implement methods
class FootSoldier: public Enemy {
private:

public:
    FootSoldier(int speed, int value, int price, int hp, Game& game, Pos position)
            : Enemy(speed, value, price, hp, game, position) {};

    ~FootSoldier() {};

    void update();
    void onDestroy();
};
