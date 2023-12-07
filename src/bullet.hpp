#pragma once
#include <cmath>

#include "projectile.hpp"
#include "enemy.hpp"

#include <iostream>
// TODO: Implement methods
class Bullet : public Projectile {
private:
  Pos endPos_;
  Pos startPos_;

public:
  Bullet(Game& game, int travel_speed, int damage, int radius, Pos position, Pos endPos)
      : Projectile(game, travel_speed, damage, radius, position), endPos_(endPos), startPos_(position) {};

  // Destructor implementation
  ~Bullet() override {}

  // Implement the update function
  void update();

  void onDestroy();

};
