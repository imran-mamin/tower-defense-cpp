#include "footsoldier.hpp"

void FootSoldier::update() {
    // In case the enemy is alive, advance enemy position by one tick according to the path.
    if (this->isAlive()) {
        const std::vector<Vec2D> path = this->getGrid().EnemyPath();
        int i = 0;
        // Find the vector2D that contains enemy's current position.
        while (i < (int)path.size()) {
            const Vec2D currVec = path.at(i);

            // start position of the currVec to current position of the enemy.
            Vec2D sPosToEnemPos = Vec2D{ currVec.a, this->position_ };

            // Find a current vector in form of (4i + 2j) for example, which is a point.
            Pos vec1 = Pos{ (currVec.b.x - currVec.a.x), (currVec.b.y - currVec.a.y) };

            // Find a vector between start position and enemy's position.
            Pos vec2 = Pos{ (this->position_.x - currVec.a.x), (this->position_.y - currVec.a.y) };
            
            // Calculate the dot product between vec1 and vec2.
            // If enemy's position is on current vector, then the angle between the vectors should be 0.
            // This means that the cosine should equal 1.
            const int dotP = (vec1.x * vec2.x) + (vec1.y * vec2.y);
            // Calculate the length of the vectors vec1 and vec2.
            const double vec1Length = sqrt((vec1.x * vec1.x) + (vec1.y * vec1.y));
            const double vec2Length = sqrt((vec2.x * vec2.x) + (vec2.y * vec2.y));

            // TODO: Check for the end of the path, enemy wins
            // The length of the vec2 should be smaller than vec1, if the enemy's position is
            // on the current vector.
            if (vec2Length > vec1Length) {
                i++;
                continue;
            }

            const double cos12 = std::abs(dotP / (vec1Length * vec2Length));
            // Check the angle and the vec2 should not be null vector.
            if ((cos12 != 1.0) || ((vec2.x != 0) && (vec2.y != 0))) {
                i++;
                continue;
            }

            // Find unit vector of vec1.
            Pos unitVec1 = Pos{ (vec1.x / vec1Length), (vec1.y / vec1Length) };
            
            // Advance enemy's position.
            this->position_.x += this->speed_ * unitVec1.x;
            this->position_.y += this->speed_ * unitVec1.y;
            std::cout << "unitVec1 = (" << unitVec1.x << ", " << unitVec1.y << ")" << std::endl;
            
            // Check that the enemy doesn't go further than the end point of a path vector.
            bool outX = (unitVec1.x > 0) ? (this->position_.x > currVec.b.x) : (this->position_.x < currVec.b.x);
            bool outY = (unitVec1.y > 0) ? (this->position_.y > currVec.b.y) : (this->position_.y < currVec.b.y);
            std::cout << "outX = " << outX << std::endl;
            std::cout << "outY = " << outY << std::endl;
            if (outX || outY) {
                // Check how far does the enemy go from the currVec's end point.
                double outInSpeed = (unitVec1.x != 0) ? std::abs((this->position_.x - currVec.b.x) / unitVec1.x) : std::abs((this->position_.y - currVec.b.y) / unitVec1.y);
                std::cout << "outInSpeed = " << outInSpeed << std::endl;
                // Restore enemy's position to end point of the currVec.
                this->position_ = currVec.b;

                int j = i + 1;

                while ((j < (int)path.size()) && (outInSpeed > 0)) {
                    // If enemy switches to another Vec2D, then rotate the enemy by 90 degrees.
                    this->RotateArtillery(90);
                    const Vec2D pathPoints = path.at(j);
                    Pos pathVec = Pos{ (pathPoints.b.x - pathPoints.a.x), (pathPoints.b.y - pathPoints.a.y) };
                    double pathVecLength = sqrt((pathVec.x * pathVec.x) + (pathVec.y * pathVec.y));
                    Pos unitPathVec = Pos{ (pathVec.x / pathVecLength), (pathVec.y / pathVecLength) };

                    // Update enemy's position.
                    this->position_.x += outInSpeed * unitPathVec.x;
                    this->position_.y += outInSpeed * unitPathVec.y;

                    // If it goes also out of pathPoints vec2D then continue.
                    bool isOutX = (unitPathVec.x > 0) ? (this->position_.x > pathPoints.b.x) : (this->position_.x < pathPoints.b.x);
                    bool isOutY = (unitPathVec.y > 0) ? (this->position_.y > pathPoints.b.y) : (this->position_.y < pathPoints.b.y);
                    
                    if (isOutX || isOutY) {
                        // Remove the length of pathVec from the outInSpeed.
                        outInSpeed -= (unitPathVec.x != 0) ? std::abs((this->position_.x - pathPoints.b.x) / unitPathVec.x) : std::abs((this->position_.y - pathPoints.b.y) / unitPathVec.y);
                        j++;
                        continue;
                    }
                    // If it doesn't go into if-block, then the next path vector2D is found.
                    outInSpeed = 0;
                }
                
                assert(outInSpeed <= 0); // This is for TODO above.
            }
            std::cout << "Enemy's position = (" << this->position_.x << ", " << this->position_.y << ")" << std::endl;
            break;
        }
    } else {
        // Remove enemy object from vector of objects.
        this->game_.DeleteObject(static_cast<GameObject*>(this));

        // Add profit to player.
        this->addPlayerMoney(this->value_);
        
        // Destroy the Enemy object.
        this->onDestroy();
    }
}

void FootSoldier::onDestroy() {
    this->game_.DeleteObject(this);
}
