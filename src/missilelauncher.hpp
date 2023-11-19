#pragma once
#include "tower.hpp"
#include "missile.hpp"


// TODO: Implement methods
class MissileLauncher: public Tower {
private:
    std::vector<Missile> missiles_ = {};

public:
    MissileLauncher(int radius, int fireRate, int price)
        : Tower(radius, fireRate, price) {};

    void fire();
    void onDestroy() {};
    void update();
    int sell() {};

};
