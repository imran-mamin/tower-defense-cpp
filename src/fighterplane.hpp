#pragma once
#include "tower.hpp"
#include "bullet.hpp"


// TODO: Implement methods
class FighterPlane: public Tower {
private:
    Bullet pr_;
public:
    FighterPlane(int radius, int fireRate, int price, Bullet pr): Tower(radius, fireRate, price), pr_(pr) {};

    void fire();
    void onDestroy();
    void update();
    int sell();

};
