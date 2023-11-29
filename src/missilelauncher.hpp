#pragma once
#include "tower.hpp"
#include "missile.hpp"


// TODO: Implement methods
class MissileLauncher: public Tower {
private:

public:
    MissileLauncher(int radius, int fireRate, int price, Game& game)
        : Tower(radius, fireRate, price, game) {};

    ~MissileLauncher() {};

    void fire();
    void onDestroy();
    void update();
    int sell();

};
