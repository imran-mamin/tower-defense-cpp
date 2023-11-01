#pragma once
#include "projectile.hpp"

class Bullet: public Projectile {
public:
    Vec2D speed_vec;
    void update();
    
};
