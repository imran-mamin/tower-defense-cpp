#include "missile.hpp"
#include "vec2d.hpp"

#include <cmath>

/**
 * Every time update()-method is called, the position of the Missile object,
 * should be closer to the target object.
 * 
 * Corner cases:
 * 1. Other projectile kills the enemy, then the missile just finds kills the closest enemy, or
 *    goes out of the window.
 * 2. Target goes out of the window. Then the missile should follow it.
 * */ 

void Missile::update() {
    bool isAlive = false;
    /*for (auto it = this->getObjects().begin(); it != this->getObjects().end(); it++) {
        if ((Enemy&)(*it) == target_) { // TODO: Uncomment this block of code.
            isAlive = true;
            break;
        }
    }*/
    /*
    if (isAlive) {
        Vec2D pathToTarget;
        pathToTarget.a = this->position_;
        pathToTarget.b = target_.getPosition();
        
        // Find the direction using two positions. (Vector in e.g. 4i + 2j format).
        uint32_t pathToTargetX = pathToTarget.b.x - pathToTarget.a.x;
        uint32_t pathToTargetY = pathToTarget.b.y - pathToTarget.a.y;

        // this->position_ += this->travel_speed() * pathToTarget
        this->position_.x += this->travel_speed() * pathToTargetX;
        this->position_.y += this->travel_speed() * pathToTargetY;

        // Calculate the distance between missile and target.
        // Formula sqrt((x_1 - x_2)^2 + (y_1 - y_2)^2)
        double dist = sqrt((target_.getPosition().x - this->position_.x) * (target_.getPosition().x - this->position_.x) +
                           (target_.getPosition().y - this->position_.y) * (target_.getPosition().y - this->position_.y));

        // Is target in the explosion radius of missile?
        if (this->explosionRadius_ > dist) {
            this->target_.takeDamage(this->damage());
            
            // The missile will cause damage to all enemies within the given missile radius.
            std::vector<Enemy> enemiesWithinRadius = this->getEnemiesWithinRadius();
            auto it = enemiesWithinRadius.begin();
            while (it != enemiesWithinRadius.end()) {
                (*it).takeDamage(this->damage());
                it++;
            }
            
            // Remove missile object from the vector objects_.
            this->game_.DeleteObject(this);
            delete this;
            
        }
    } else {
        // TODO: Corner cases
        // Collide with the enemies on the way out of the window if there are some.
        if (!this->getEnemiesWithinRadius().empty()) {
            // The missile will cause damage to all enemies within the given missile radius.
            std::vector<Enemy> enemiesWithinRadius = this->getEnemiesWithinRadius();
            auto it = enemiesWithinRadius.begin();
            while (it != enemiesWithinRadius.end()) {
                (*it).takeDamage(this->damage());
                it++;
            }
            
            // Remove missile object from the vector objects_.
            this->game_.DeleteObject(this);
            delete this;

        } else {
            // Else just advance the position of the missile.
            this->position_.x += this->travel_speed();
            this->position_.y += this->travel_speed();
        }
        
    }
    */
}
