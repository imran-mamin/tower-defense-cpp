#pragma once
#include "tower.hpp"
#include "missile.hpp"


class MissileLauncher: public Tower {
private:

public:
    MissileLauncher(int radius, int fireRate, int price, Game& game, Pos position)
        : Tower(radius, fireRate, price, game, position) {};

    ~MissileLauncher() {};

    void fire();
    void onDestroy();
    void update();
    int sell();
};
