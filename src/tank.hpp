#pragma once
#include "enemy.hpp"

// TODO: Implement methods
class Tank: public Enemy {
private:

public:
    Tank(int speed, int value, int price, int hp, sf::Sprite sprite, Game& game)
        : Enemy(speed, value, price, hp, sprite, game) {};

    void update();
    void onDestroy();
};
