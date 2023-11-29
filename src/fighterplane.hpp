#pragma once
#include "tower.hpp"
#include "bullet.hpp"


// TODO: Implement methods
class FighterPlane: public Tower {
private:

public:
    FighterPlane(int radius, int fireRate, int price, Game& game)
            : Tower(radius, fireRate, price, game) {};

    ~FighterPlane() {};
    void fire();
    void onDestroy();
    void update();
    int sell();

};
