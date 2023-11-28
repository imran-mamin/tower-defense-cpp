#pragma once
#include "projectile.hpp"
#include "enemy.hpp"

// TODO: Implement methods
class Bullet : public Projectile {
private:
  Enemy* target_;
  Pos endPos_;

public:
  Bullet(sf::Sprite sprite, Game& game, Enemy* target, int travel_speed, int damage, int radius, Pos position, Pos endPos)
      : Projectile(sprite, game, travel_speed, damage, radius, position), target_(target), endPos_(endPos) {};

  // Destructor implementation
  ~Bullet() override {}

  // Implement the update function
  void update() override {
    // TODO: Add your implementation for updating the bullet here

  }

  void onDestroy() override {

  }

  
};
