#pragma once
#include "tower.hpp"
#include "missile.hpp"


class MissileLauncher: public Tower {
private:

public:
    MissileLauncher(int radius, int fireRate, int price, sf::Sprite& sprite, Game& game, Pos position)
        : Tower(radius, fireRate, price, sprite, game, position) {};

    ~MissileLauncher() {};

    void fire();
    void onDestroy();
    void update();
    int sell();
};
