#pragma once
#include "gameobject.hpp"


class Enemy: public GameObject {
protected:
    double speed_;
    int value_;
    int price_;
    // int maxHP_;
public:
    explicit Enemy(int speed, int value, int price, int maxHP, Game& game, Pos position)
            : GameObject(game, position, maxHP), speed_(speed), value_(value), price_(price) {};
    
    virtual ~Enemy() {};

    int GetSpeed() const;
    bool isAlive() const;
};
