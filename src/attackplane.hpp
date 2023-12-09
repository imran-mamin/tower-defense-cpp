#pragma once
#include "enemy.hpp"

// TODO: Implement methods
class AttackPlane : public Enemy {
 private:
 public:
  AttackPlane(int speed, int value, int price, int hp, Game &game, Pos position)
      : Enemy(speed, value, price, hp, game, position){};
  void onDestroy();
};

class Plane1 : public AttackPlane {
 public:
  Plane1(Game &game, Pos position)
      : AttackPlane(1, 100, 200, 200, game, position) {}
  ~Plane1() = default;
};

class Plane2 : public AttackPlane {
 public:
  Plane2(Game &game, Pos position)
      : AttackPlane(1, 100, 200, 200, game, position) {}
  ~Plane2() = default;
};