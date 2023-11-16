#pragma once
#include "tower.hpp"
#include "bullet.hpp"


// TODO: Implement methods
class Cannon: public Tower {
private:
    int fireRate_;
public:
    Cannon(int radius, int fireRate): Tower(radius), fireRate_(fireRate) {};

    void fire();
    void onDestroy();
    void update();
    void sell();
};