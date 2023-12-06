#pragma once
#include "bullet.hpp"
#include "game.hpp"
#include "tower.hpp"
#include "vec2d.hpp"

#include <cstdint>
#include <cmath>

class Cannon : public Tower {
   protected:
    Cannon(int radius, int fireRate, int price, Game &game, Pos position, std::uint32_t health)
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
    GreenCannon(Game &game, Pos position)
	: Cannon(64 * 4, 3, 1000, game, position, 100) {}
    ~GreenCannon() = default;
};

class RedCannon : public Cannon {
   public:
    RedCannon(Game &game, Pos position)
	: Cannon(64 * 7, 1, 4000, game, position, 300) {}
    ~RedCannon() = default;
};

