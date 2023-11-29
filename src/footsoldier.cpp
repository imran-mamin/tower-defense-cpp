#include "footsoldier.hpp"

void FootSoldier::update() {
    // In case the enemy is alive, advance enemy position by one tick according to the path.
    if (this->isAlive()) {
        const std::vector<Vec2D>& path = this->getGrid().EnemyPath();
        int i = 0;

        // Find the vector that contains enemy's current position.
        while (i < (int)path.size()) {
            const Vec2D& currVec = path.at(i);
            // start position of the current vector to current position of the enemy.
            Vec2D sPosToCurrPos;
            sPosToCurrPos.a = currVec.a;
            sPosToCurrPos.b = this->position_;

            // Find a current vector in form of (4i + 2j) for example, which is a point.
            Pos vec1;
            vec1.x = currVec.b.x - currVec.a.x;
            vec1.y = currVec.b.y - currVec.a.y;

            // Find a vector between start position and enemy's position.
            Pos vec2;
            vec2.x = sPosToCurrPos.b.x - sPosToCurrPos.a.x;
            vec2.y = sPosToCurrPos.b.y - sPosToCurrPos.a.y;

            // Calculate the dot product between vec1 and vec2.
            // If enemy's position is on current vector, then the dotproduct between the vectors should be 0.
            int dotP = (vec1.x * vec2.x) + (vec1.y * vec2.y);
            if (dotP != 0) {
                i++;
                continue;
            }
            
            // Calculate the length of the vectors vec1 and vec2.
            double vec1Length = sqrt((vec1.x * vec1.x) + (vec1.y * vec1.y));
            double vec2Length = sqrt((vec2.x * vec2.x) + (vec2.y * vec2.y));

            // TODO: Check for the end of the path, enemy wins
            // The length of the vec2 should be smaller than vec1, if the enemy's position is
            // on the current vector.
            if (vec2Length > vec1Length) {
                i++;
                continue;
            } else if (vec2Length == vec1Length) {
                if ((i + 1) != (int)path.size()) {
                    const Vec2D& pathPoints = path.at(i + 1);
                    Pos pathVec;
                    pathVec.x = pathPoints.b.x - pathPoints.a.x;
                    pathVec.y = pathPoints.b.y - pathPoints.a.y;
                    
                    this->position_.x += this->speed_ * pathVec.x;
                    this->position_.y += this->speed_ * pathVec.y;
                } else {
                    assert(false); // This is for TODO above.
                }
                break;
            } else {
                // Check that the enemy doesn't go further than the end point of a path vector.
                this->position_.x += this->speed_ * vec1.x;
                this->position_.y += this->speed_ * vec2.y;

                if ((this->position_.x > currVec.b.x) || (this->position_.y  > currVec.b.y)) {
                    if (this->position_.x > currVec.b.x) {
                        int out = this->position_.x - currVec.b.x;
                        int overSpeed = out / vec1.x;
                        if ((i + 1) != (int)path.size()) {
                            const Vec2D& pathPoints = path.at(i + 1);
                            Pos pathVec;
                            pathVec.x = pathPoints.b.x - pathPoints.a.x;
                            pathVec.y = pathPoints.b.y - pathPoints.a.y;
                            
                            this->position_.x += overSpeed * pathVec.x;
                            this->position_.y += overSpeed * pathVec.y;
                        } else {
                            assert(false); // This is for TODO above.
                        }
                    } else {
                        int out = this->position_.y  - currVec.b.y;
                        int overSpeed = out / vec1.y;
                        if ((i + 1) != (int)path.size()) {
                            const Vec2D& pathPoints = path.at(i + 1);
                            Pos pathVec;
                            pathVec.x = pathPoints.b.x - pathPoints.a.x;
                            pathVec.y = pathPoints.b.y - pathPoints.a.y;
                            
                            this->position_.x += overSpeed * pathVec.x;
                            this->position_.y += overSpeed * pathVec.y;
                        } else {
                            assert(false); // This is for TODO above.
                        }
                    }
                }
                
                break;
            }

            i++;
        }

    } else {
        auto it = this->getObjects().begin();

        // Remove enemy object from vector of objects.
        while (it != this->getObjects().end()) {
            if (&(*it) == this) {
                // TODO: Uncomment this line.
                // this->getObjects().erase(it);
                break;
            }
            it++;
        }
        
        // Add profit to player.
        this->addPlayerMoney(this->value_);
        
        // Destroy the Enemy object.
        this->onDestroy();
    }
}

void FootSoldier::onDestroy() {
    this->~FootSoldier();
}
