#pragma once
#include "gameobject.hpp"


class Enemy: public GameObject {
protected:
    double speed_;
    int value_;
    int price_;
    // int maxHP_;
public:
    explicit Enemy(int speed, int value, int price, int maxHP, sf::Sprite sprite, Game& game, Pos position)
            : GameObject(sprite, game, position, maxHP), speed_(speed), value_(value), price_(price) {};
    
    virtual ~Enemy() {};

    bool isAlive() const;
};
