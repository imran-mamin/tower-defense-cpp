#include "missile.hpp"
#include "vec2d.hpp"


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
    for (GameObject* obj : this->game_.Objects()) {
        // Attempt to cast to Enemy*
        if (Enemy* enemy = dynamic_cast<Enemy*>(obj)) {
            if (enemy == this->target_) {
                isAlive = true;
                break;
            }
        }
    }
    
    if (isAlive) {
        Vec2D pathToTarget = Vec2D{ this->position_, this->target_->getPosition() };
        
        // Find the vector (type Pos) using two positions. (Vector in e.g. 4i + 2j format).
        Pos vectorToTarget = Pos{ (pathToTarget.b.x - pathToTarget.a.x), (pathToTarget.b.y - pathToTarget.a.y) };

        // Find the length of the vectorToTarget.
        double vectorToTargetLength = sqrt((vectorToTarget.x * vectorToTarget.x) + (vectorToTarget.y * vectorToTarget.y));

        // Find unit vector of vectorToTarget.
        Pos unitVec = Pos{ (vectorToTarget.x / vectorToTargetLength), (vectorToTarget.y / vectorToTargetLength) };
        
        // Check, whether the enemy is within missile radius on every position update.
        int i = 0;

        while (i < this->travel_speed()) {
            // Calculate the distance between missile and target.
            // Formula sqrt((x_1 - x_2)^2 + (y_1 - y_2)^2)
            Pos currPos = this->getPosition();
            double xPow2 = std::pow((this->target_->getPosition().x - currPos.x), 2);
            double yPow2 = std::pow((this->target_->getPosition().y - currPos.y), 2);
            double dist = sqrt(xPow2 + yPow2);

            // Is target in the explosion radius of missile?
            if (this->explosionRadius_ > dist) {
                // The missile will cause damage to all enemies within the given missile radius.
                std::vector<Enemy*> enemiesWithinRadius = this->getEnemiesWithinRadius();
                auto it = enemiesWithinRadius.begin();
                while (it != enemiesWithinRadius.end()) {
                    (*it)->takeDamage(this->damage());
                    it++;
                }
                
                // Remove missile object from the vector objects_ and from heap.
                this->game_.DeleteObject(this);
                delete this;
                break;
            }
            i++;
        }
        
    } else {
        // TODO: Corner cases
        // Collide with the enemies on the way out of the window if there are some.
        if (!this->getEnemiesWithinRadius().empty()) {
            // The missile will cause damage to all enemies within the given missile radius.
            std::vector<Enemy*> enemiesWithinRadius = this->getEnemiesWithinRadius();
            auto it = enemiesWithinRadius.begin();
            while (it != enemiesWithinRadius.end()) {
                (*it)->takeDamage(this->damage());
                it++;
            }
            
            // Remove missile object from the vector objects_.
            this->game_.DeleteObject(this);
            delete this;

        } else {
            // TODO: Improve this, so that missile goes straight.
            // Else just advance the position of the missile.
            this->position_.x += this->travel_speed();
            this->position_.y += this->travel_speed();
            
            // Is missile still on the screen?
            bool isOutHeight = ((this->getPosition().y > this->game_.GetGrid().Height()) || (this->getPosition().y < 0));
            bool isOutWidth = ((this->getPosition().x > this->game_.GetGrid().Width()) || (this->getPosition().x < 0));

            if (isOutWidth || isOutHeight) {
                // Remove missile object from the vector objects_.
                this->game_.DeleteObject(this);
                delete this;
            }
        }
        
    }
    
}
