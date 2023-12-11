#pragma once
#include <cmath>
#include <cstdint>
#include <iostream>

#include "bullet.hpp"
#include "game.hpp"
#include "tower.hpp"
#include "vec2d.hpp"

const std::uint32_t GreenCannonPrice = 1000;
const std::uint32_t RedCannonPrice = 3000;

class Cannon : public Tower {
 protected:
  Cannon(int radius, int fireRate, int price, Game* game, Pos position,
         std::uint32_t health)
      : Tower(radius, fireRate, price, game, position, health) {}

 public:
  ~Cannon() = default;
  void fire() override;
  void onDestroy() override;
  void update() override;
  int sell() override;
};

class GreenCannon : public Cannon {
 public:
  GreenCannon(Game* game, Pos position)
      : Cannon(64 * 4, 11, GreenCannonPrice, game, position, 100) {}
  ~GreenCannon() = default;
};

class RedCannon : public Cannon {
 public:
  RedCannon(Game* game, Pos position)
      : Cannon(64 * 6, 4, RedCannonPrice, game, position, 100) {}
  ~RedCannon() = default;
};
