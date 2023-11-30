#pragma once
#include "tower.hpp"
#include "bullet.hpp"


// TODO: Implement methods
class Cannon: public Tower {
public:
    Cannon(int radius, int fireRate, int price, Game& game, Pos position)
            : Tower(radius, fireRate, price, game, position) {};

    ~Cannon() {};
    void fire();
    void onDestroy();
    void update();
    int sell();
};