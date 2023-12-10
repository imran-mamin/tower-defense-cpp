#pragma once
#include "enemy.hpp"

class Tank: public Enemy {
private:

public:
    Tank(int speed, int value, int hp, Game* game, Pos position)
        : Enemy(speed, value, hp, game, position) {};
    ~Tank() = default;
    void onDestroy();
};

class Tank1: public Tank {
public:
    Tank1(Game* game, Pos position)
    : Tank(2, 200, 400, game, position) {}
    ~Tank1() = default;
};

class Tank2: public Tank {
public:
    Tank2(Game* game, Pos position)
    : Tank(3, 200, 1000, game, position) {}
    ~Tank2() = default;
};
