#pragma once
#include "tower.hpp"
#include "bullet.hpp"


// TODO: Implement methods
class Cannon: public Tower {
public:
    Cannon(int radius, int fireRate, int price, sf::Sprite sprite, Game game)
            : Tower(radius, fireRate, price, sprite, game) {};

    ~Cannon() {};
    void fire();
    void onDestroy();
    void update();
    int sell();
};