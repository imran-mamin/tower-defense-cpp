#pragma once
#include "gameobject.hpp"

#include <assert.h>

class Enemy: public GameObject {
protected:
    double speed_;
    int value_;
    // int maxHP_;
public:
    explicit Enemy(int speed, int value, int maxHP, Game* game, Pos position)
            : GameObject(game, position, maxHP), speed_(speed), value_(value) {};
    
    virtual ~Enemy() {};

    void update();

	int Value() const {
		return value_;
	}
    
    int GetSpeed() const;
    bool isAlive() const;
};
