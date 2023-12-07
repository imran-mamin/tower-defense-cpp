#pragma once

#include <assert.h>

#include <algorithm>
#include <cmath>
#include <iostream>

#include "enemy.hpp"

class FootSoldier : public Enemy {
    // TODO: Make the constructor protected.
    // protected:
   public:
    FootSoldier(int speed, int value, int price, int hp, Game &game,
		Pos position)
	: Enemy(speed, value, price, hp, game, position){};

    ~FootSoldier() = default;
    void onDestroy();
};

class Soldier1 : public FootSoldier {
   public:
    Soldier1(Game &game, Pos position)
	: FootSoldier(1, 100, 200, 200, game, position) {}
    ~Soldier1() = default;
};
class Soldier2 : public FootSoldier {
   public:
    Soldier2(Game &game, Pos position)
	: FootSoldier(3, 150, 300, 300, game, position) {}
    ~Soldier2() = default;
};
class Soldier3 : public FootSoldier {
   public:
    Soldier3(Game &game, Pos position)
	: FootSoldier(6, 200, 500, 400, game, position) {}
    ~Soldier3() = default;
};
class Soldier4 : public FootSoldier {
   public:
    Soldier4(Game &game, Pos position)
	: FootSoldier(8, 300, 800, 600, game, position) {}
    ~Soldier4() = default;
};

