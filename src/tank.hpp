#pragma once
#include "enemy.hpp"

// TODO: Implement methods
class Tank: public Enemy {
private:

public:
    Tank(int speed, int value, int price, int hp, sf::Sprite sprite, Game& game, Pos position)
        : Enemy(speed, value, price, hp, sprite, game, position) {};

    void update();
    void onDestroy();
};
