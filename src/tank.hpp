#pragma once
#include "enemy.hpp"

// TODO: Implement methods
class Tank : public Enemy {
 private:
 public:
  Tank(int speed, int value, int price, int hp, Game &game, Pos position)
      : Enemy(speed, value, price, hp, game, position){};
  void onDestroy();
};

class Tank1 : public Tank {
 public:
  Tank1(Game &game, Pos position) : Tank(1, 100, 200, 200, game, position) {}
  ~Tank1() = default;
};

class Tank2 : public Tank {
 public:
  Tank2(Game &game, Pos position) : Tank(1, 100, 200, 200, game, position) {}
  ~Tank2() = default;
};