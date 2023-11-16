#pragma once
#include "tower.hpp"
#include "bullet.hpp"


// TODO: Implement methods
class Cannon: public Tower {
public:
    Cannon(int radius, int fireRate, int price): Tower(radius, fireRate, price) {};

    void fire();
    void onDestroy();
    void update();
    int sell();
};