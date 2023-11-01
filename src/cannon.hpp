#pragma once
#include "tower.hpp"
#include "bullet.hpp"


// TODO: Implement methods
class Cannon: public Tower {
private:

public:
    Bullet pr_;

    Cannon(int radius, Bullet pr): Tower(radius) {};

    void fire();
    void onDestroy();
    void update();
    void sell();

};