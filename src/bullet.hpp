#pragma once
#include "projectile.hpp"
#include "enemy.hpp"

// TODO: Implement methods
class Bullet : public Projectile {
private:
  Enemy* target_;

public:
  Bullet(sf::Sprite sprite, Game& game, Enemy* target, int travel_speed, int damage, int radius, Pos position)
      : Projectile(sprite, game, travel_speed, damage, radius, position), target_(target) {};

  // Destructor implementation
  ~Bullet() override {}

  // Implement the update function
  void update() override {
    // TODO: Add your implementation for updating the bullet here

  }

  void onDestroy() override {

  }

  
};
