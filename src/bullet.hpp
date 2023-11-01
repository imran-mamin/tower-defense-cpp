#pragma once
#include "projectile.hpp"

// TODO: Implement methods
class Bullet: public Projectile {
public:
    
    Bullet(int travel_speed, int damage, int radius): Projectile(travel_speed, damage, radius) {};
    // Vec2D speed_vec;
    void update();

};
