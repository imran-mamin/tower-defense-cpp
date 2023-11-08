#pragma once
#include "tower.hpp"
#include "missile.hpp"


// TODO: Implement methods
class MissileLauncher: public Tower {
private:
    Missile pr_;

public:
    MissileLauncher(int radius, Missile pr): Tower(radius), pr_(pr) {};

    void fire();
    void onDestroy();
    void update();
    void sell();

};
