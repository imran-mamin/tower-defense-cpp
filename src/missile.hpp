#pragma once
#include "projectile.hpp"
#include "enemy.hpp"

// TODO: Implement methods
class Missile: public Projectile {
private:
    Enemy target_;
    double explosionRadius_;

public:
    
    Missile(int travel_speed, int damage, int radius, Enemy target, double exp_radius = 0)
        : target_(target), explosionRadius_(exp_radius), Projectile(travel_speed, damage, radius) {};
    // Vec2D speed_vec;
    void update();

};
