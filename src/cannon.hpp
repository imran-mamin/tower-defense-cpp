#pragma once
#include "tower.hpp"
#include "bullet.hpp"


// TODO: Implement methods
class Cannon: public Tower {
private:
    Bullet pr_;
public:
    Cannon(int radius, Bullet pr): Tower(radius), pr_(pr) {};

    void fire();
    void onDestroy();
    void update();
    void sell();

};