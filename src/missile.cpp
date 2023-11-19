#include "missile.hpp"
#include "vec2d.hpp"

#include <cmath>

/**
 * Every time update()-method is called, the position of the Missile object,
 * should be closer to the target object.
 * 
 * Corner cases:
 * 1. Other projectile kills the enemy, then the target should change to another
 *    Enemy object.
 * 2. Target goes out of the window. Then the missile should follow it.
 * */ 

void Missile::update() {
   /*if (target_.isAlive()) {
        Vec2D pathToTarget;
        pathToTarget.a = this->position_;
        pathToTarget.b = target_.position_;
        
        // Find the direction using two positions.
        uint32_t pathToTargetX = pathToTarget.b.x - pathToTarget.a.x;
        uint32_t pathToTargetY = pathToTarget.b.y - pathToTarget.a.y;

        // this->position_ += this->travel_speed() * pathToTarget
        this->position_.x += this->travel_speed() * pathToTargetX;
        this->position_.y += this->travel_speed() * pathToTargetY;

        // Calculate the distance between missile and target.
        // Formula sqrt((x_1 - x_2)^2 + (y_1 - y_2)^2)
        double dist = sqrt((target_.position_.x - this->position_.x) * (target_.position_.x - this->position_.x) +
                           (target_.position_.y - this->position_.y) * (target_.position_.y - this->position_.y));

        // TODO: Missile should hit all the enemies within the explosion radius.
        // Is target in the explosion radius of missile?
        if (this->explosionRadius_ > dist) {
            target_.health_ -= this->damage();
            this->~Missile(); // Call the destructor for missile object.
        }
    }*/
    // TODO: Corner cases.
}
