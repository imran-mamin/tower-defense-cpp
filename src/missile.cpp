#include <memory>

#include "missile.hpp"
#include "enemy.hpp"
#include "vec2d.hpp"
#include "utility_func_game.hpp"
#include "gamegrid.hpp"

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
    for (const auto & obj : getObjects(game_)) {
        // Attempt to cast to Enemy*
        if (const auto enemy = dynamic_cast<const Enemy *>(obj); enemy) {
            if (enemy == target_) {
                isAlive = true;
                break;
            }
        }
    }
    
    if (isAlive) {
        Vec2D pathToTarget = Vec2D{ position_, target_->getPosition() };
        
        // Find the vector (type Pos) using two positions. (Vector in e.g. 4i + 2j format).
        Pos vectorToTarget = Pos{ (pathToTarget.b.x - pathToTarget.a.x), (pathToTarget.b.y - pathToTarget.a.y) };

        // Find the length of the vectorToTarget.
        float vectorToTargetLength = sqrt((vectorToTarget.x * vectorToTarget.x) + (vectorToTarget.y * vectorToTarget.y));

        // Find unit vector of vectorToTarget.
        Pos unitVec = Pos{ (vectorToTarget.x / vectorToTargetLength), (vectorToTarget.y / vectorToTargetLength) };
        
        // Set the rotation of missile.
        Pos unitVecN = Pos{ 0, -1 };

        // Calculate dot product of unitVec and unitVecN.
        float dotP = unitVec.y * unitVecN.y;
        // Calculate the rotation angle.
        float angleInRad = std::acos(dotP);
        float angleInDeg = angleInRad * (180.0 / M_PI);
        this->SetAngle(360.0 - angleInDeg);

        // Check, whether the enemy is within missile radius on every position update.
        int i = 0;

        while (i < this->travel_speed()) {
            // The missile will cause damage to all enemies within the given missile radius.
            std::vector<Enemy*> enemiesWithinRadius = this->getEnemiesWithinRadius();
            if (!enemiesWithinRadius.empty()) {
                auto it = enemiesWithinRadius.begin();
                while (it != enemiesWithinRadius.end()) {
                    (*it)->takeDamage(this->damage());
                    it++;
                }
                // Remove missile object from the vector objects_.
                health_ = 0;
                break;
            }
            // Update missile's position.
            position_.x += unitVec.x;
            position_.y += unitVec.y;

            i++;
        }
        
    } else {
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
            health_ = 0;

        } else {
            // TODO: Improve this, so that missile goes straight.
            // Suppose we have a right-angled triangle, with a = 1, b = sqrt(3) and hypotenuse = 2.
            // Now, the angle between a and hypotenuse is 60 degrees (pi / 3 in rad).
            // Thus, the hypotenuse vector (v) is
            Pos v = Pos{ 1, sqrt(3) }; 
            
            // Lets denote the direction vector (unit vector) we are looking for with w.
            Pos w;
            // The angle between direction vector w and vector v is theta.
            // (30.0 is the degrees between vectors (0, -1) and v).
            // theta should be between 0 and 180 degrees.
            float theta = std::min(this->GetRotation() - 30.0, 360.0 - (this->GetRotation() - 30.0));
            
            // Let's use rotation matrix.
            w.x = v.x * std::cos(theta) - v.y * std::sin(theta); 
            w.y = v.x * sin(theta) + v.y * cos(theta);

            // Check, whether the enemy is within missile radius on every position update.
            int i = 0;

            while (i < this->travel_speed()) {
                // The missile will cause damage to all enemies within the given missile radius.
                std::vector<Enemy*> enemiesWithinRadius = this->getEnemiesWithinRadius();
                if (!enemiesWithinRadius.empty()) {
                    auto it = enemiesWithinRadius.begin();
                    while (it != enemiesWithinRadius.end()) {
                        (*it)->takeDamage(this->damage());
                        it++;
                    }
                    // Remove missile object from the vector objects_.
                    health_ = 0;
                    break;
                }
                // Update missile's position.
                position_.x += w.x;
                position_.y += w.y;

                i++;
            }
            // Is missile still on the screen?
            bool isOutHeight = ((this->getPosition().y > getGrid(game_)->Height() * getGrid(game_)->TileWidth() - 1) || (this->getPosition().y < 0));
            bool isOutWidth = ((this->getPosition().x > getGrid(game_)->Width() * getGrid(game_)->TileWidth() - 1) || (this->getPosition().x < 0));

            if (isOutWidth || isOutHeight) {
                // Remove missile object from the vector objects_.
				health_ = 0;
            }
        }
    }
}
