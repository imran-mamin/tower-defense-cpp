#pragma once
#include "tower.hpp"
#include "bullet.hpp"


// TODO: Implement methods
class FighterPlane: public Tower {
private:

public:
    FighterPlane(int radius, int fireRate, int price, sf::Sprite sprite, Game game)
            : Tower(radius, fireRate, price, sprite, game) {};

    void fire();
    void onDestroy();
    void update();
    int sell();

};
