#pragma once
#include "projectile.hpp"

// TODO: Implement methods
class Bullet : public Projectile {
 public:
  Bullet(sf::Sprite sprite, Game& game, int travel_speed, int damage, int radius)
      : Projectile(sprite, game, travel_speed, damage, radius) {};

  // Destructor implementation
  ~Bullet() override {}

  // Implement the update function
  void update() override {
    // Add your implementation for updating the bullet here
  }
};
