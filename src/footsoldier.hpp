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
    FootSoldier(int speed, int value, int hp, Game* game,
		Pos position)
	: Enemy(speed, value, hp, game, position){};

    ~FootSoldier() = default;
    void onDestroy();
};

class Soldier1 : public FootSoldier {
   public:
    Soldier1(Game* game, Pos position)
	: FootSoldier(1, 50, 20, game, position) {}
    ~Soldier1() = default;
};
class Soldier2 : public FootSoldier {
   public:
    Soldier2(Game* game, Pos position)
	: FootSoldier(3, 100, 40, game, position) {}
    ~Soldier2() = default;
};
class Soldier3 : public FootSoldier {
   public:
    Soldier3(Game* game, Pos position)
	: FootSoldier(4, 200, 80, game, position) {}
    ~Soldier3() = default;
};
class Soldier4 : public FootSoldier {
   public:
    Soldier4(Game* game, Pos position)
	: FootSoldier(6, 400, 160, game, position) {}
    ~Soldier4() = default;
};

