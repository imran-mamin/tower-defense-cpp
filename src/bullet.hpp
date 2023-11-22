#pragma once
#include "projectile.hpp"
#include "enemy.hpp"

// TODO: Implement methods
class Bullet : public Projectile {
private:
  Enemy target_;

public:
  Bullet(Game& game, Enemy& target, int travel_speed, int damage, int radius)
      : Projectile(game, travel_speed, damage, radius), target_(target) {};

  // Destructor implementation
  ~Bullet() override {}

  // Implement the update function
  void update() override {
    // Add your implementation for updating the bullet here

  }
};
