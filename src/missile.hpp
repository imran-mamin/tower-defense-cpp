#pragma once
#include <cmath>

#include "projectile.hpp"
#include "enemy.hpp"

// TODO: Implement methods
class Missile: public Projectile {
private:
    Enemy* target_;
    double explosionRadius_;
    Pos lastDirection_;

public:
    Missile(Game* game, int travel_speed, int damage, int radius, Enemy* target, Pos position, double exp_radius = 0)
        : Projectile(game, travel_speed, damage, radius, position), target_(target), explosionRadius_(exp_radius),
            lastDirection_(Pos{ target->getPosition().x - position.x, target->getPosition().y - position.y }) {};
    // Vec2D speed_vec;
    void update();
    void onDestroy() {};
};
