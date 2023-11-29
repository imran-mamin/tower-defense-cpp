#pragma once
#include "enemy.hpp"

// TODO: Implement methods
class FootSoldier: public Enemy {
private:

public:
    FootSoldier(int speed, int value, int price, int hp, sf::Sprite sprite, Game& game)
            : Enemy(speed, value, price, hp, sprite, game) {};

    ~FootSoldier() {};

    void update();
    void onDestroy();
};
