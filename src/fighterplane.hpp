#pragma once
#include "tower.hpp"
#include "bullet.hpp"


// TODO: Implement methods
class FighterPlane: public Tower {
private:
    Bullet pr_;
public:
    FighterPlane(int radius, Bullet pr): Tower(radius), pr_(pr) {};

    void fire();
    void onDestroy();
    void update();
    void sell();

};
