#include "footsoldier.hpp"

void FootSoldier::update() {
    // In case the enemy is alive, advance enemy position by one tick according to the path.
    if (this->isAlive()) {
        const std::vector<Vec2D> path = this->getGrid().EnemyPath();
        int i = 0;

        // Find the vector2D that contains enemy's current position.
        while (i < (int)path.size()) {
            const Vec2D currVec = path.at(i);
            std::cout << "currVecA: (x, y) = (" << currVec.a.x << ", " << currVec.a.y << ")" << std::endl;

            // start position of the current vector to current position of the enemy.
            Vec2D sPosToEnemPos;
            sPosToEnemPos.a = currVec.a;
            sPosToEnemPos.b = this->position_;
            std::cout << "sPosStart: (x, y) = (" << sPosToEnemPos.a.x << ", " << sPosToEnemPos.a.y << ")" << std::endl;
            std::cout << "sPosEnem: (x, y) = (" << sPosToEnemPos.b.x << ", " << sPosToEnemPos.b.y << ")" << std::endl;
            // Find a current vector in form of (4i + 2j) for example, which is a point.
            Pos vec1;
            vec1.x = currVec.b.x - currVec.a.x;
            vec1.y = currVec.b.y - currVec.a.y;
            std::cout << "vec1: (x, y) = (" << vec1.x << ", " << vec1.y << ")" << std::endl;
            // Find a vector between start position and enemy's position.
            Pos vec2;
            vec2.x = sPosToEnemPos.b.x - sPosToEnemPos.a.x;
            vec2.y = sPosToEnemPos.b.y - sPosToEnemPos.a.y;
            
            std::cout << "vec2: (x, y) = (" << vec2.x << ", " << vec2.y << ")" << std::endl;
            // Calculate the dot product between vec1 and vec2.
            // If enemy's position is on current vector, then the angle between the vectors should be 0.
            // This means that the cosine should equal 1.
            const int dotP = (vec1.x * vec2.x) + (vec1.y * vec2.y);
            // Calculate the length of the vectors vec1 and vec2.
            const double vec1Length = sqrt((vec1.x * vec1.x) + (vec1.y * vec1.y));
            const double vec2Length = sqrt((vec2.x * vec2.x) + (vec2.y * vec2.y));

            std::cout << "vec1Length: " << vec1Length << std::endl;
            std::cout << "vec2Length: " << vec2Length << std::endl;

            const double cos12 = dotP / (vec1Length * vec2Length);
            // Check the angle and the vec2 should not be null vector.
            if ((cos12 != 1.0) && ((vec2.x != 0) && (vec2.y != 0))) {
                i++;
                continue;
            }

            // TODO: Check for the end of the path, enemy wins
            // The length of the vec2 should be smaller than vec1, if the enemy's position is
            // on the current vector.
            if (vec2Length > vec1Length) {
                i++;
                continue;
            }

            // Tells, whether the enemy goes backward or forward.
            bool goesLeftOrUp = false;

            // Advance enemy's position depending on the vec1 direction.
            if (vec1.x != 0) {
                this->position_.x += (vec1.x > 0) ? this->speed_ : -this->speed_;
                goesLeftOrUp = (vec1.x > 0) ? false : true;
            } else {
                this->position_.y += (vec1.y > 0) ? this->speed_ : -this->speed_;
                goesLeftOrUp = (vec1.y > 0) ? false : true;
            }

            if (!goesLeftOrUp) {
                // Check that the enemy doesn't go further than the end point of a path vector.
                if ((this->position_.x > currVec.b.x) || (this->position_.y > currVec.b.y)) {
                    int out = std::max((this->position_.x - currVec.b.x), (this->position_.y - currVec.b.y));
                    // Restore enemy's position to end point of the currVec.
                    this->position_ = currVec.b;
                
                    int j = i + 1;
   
                    while ((j < (int)path.size()) && (out > 0)) {
                        const Vec2D pathPoints = path.at(j);
                        Pos pathVec;
                        pathVec.x = pathPoints.b.x - pathPoints.a.x;
                        pathVec.y = pathPoints.b.y - pathPoints.a.y;
                        
                        // If it goes also out of pathPoints vec2D then continue.
                        bool isOut = (std::max(abs(pathVec.x), abs(pathVec.y)) < out);
                        if (isOut) {
                            out -= std::max(abs(pathVec.x), abs(pathVec.y));
                            j++;
                            continue;
                        }

                        // Update enemy's position according to the path vector.
                        if (pathVec.x == 0) {
                            this->position_ = pathPoints.a;
                            
                            // Check, whether enemy is going (left or up) or (down or right).
                            if (pathVec.y > 0) {
                                this->position_.y += out;
                                out = 0;
                            } else {
                                this->position_.y -= out;
                                out = 0;
                            }
                            
                        } else {
                            this->position_ = pathPoints.a;

                            // Check, whether enemy is going (left or up) or (down or right).
                            if (pathVec.x > 0) {
                                this->position_.x += out;
                                out = 0;
                            } else {
                                this->position_.x -= out;
                                out = 0;
                            }
                        }
                    }

                    if (out > 0) {
                        assert(false); // This is for TODO above.
                    }
                        
                }
            } else {
                if ((this->position_.x < currVec.b.x) || (this->position_.y < currVec.b.y)) {
                    int out = std::max(abs(this->position_.x - currVec.b.x), abs(this->position_.y - currVec.b.y));
                    // Restore enemy's position to end point of the currVec.
                    this->position_ = currVec.b;

                    int j = i + 1;

                    while ((j < (int)path.size()) && (out > 0)) {
                        const Vec2D pathPoints = path.at(j);
                        Pos pathVec;
                        pathVec.x = pathPoints.b.x - pathPoints.a.x;
                        pathVec.y = pathPoints.b.y - pathPoints.a.y;
                        
                        // If it goes also out of pathPoints vec2D then continue.
                        bool isOut = (std::max(abs(pathVec.x), abs(pathVec.y)) < out);
                        if (isOut) {
                            out -= std::max(abs(pathVec.x), abs(pathVec.y));
                            j++;
                            continue;
                        }

                        // Update enemy's position according to the path vector.
                        if (pathVec.x == 0) {
                            this->position_ = pathPoints.a;
                            
                            // Check, whether enemy is going (left or up) or (down or right).
                            if (pathVec.y > 0) {
                                this->position_.y += out;
                                out = 0;
                            } else {
                                this->position_.y -= out;
                                out = 0;
                            }
                            
                        } else {
                            this->position_ = pathPoints.a;

                            // Check, whether enemy is going (left or up) or (down or right).
                            if (pathVec.x > 0) {
                                this->position_.x += out;
                                out = 0;
                            } else {
                                this->position_.x -= out;
                                out = 0;
                            }
                        }
                    }

                    if (out > 0) {
                        assert(false); // This is for TODO above.
                    }
                }
            }
            std::cout << std::endl;
            std::cout << "Enemy updated position" << std::endl;
            std::cout << "(x, y) = (" << this->position_.x << ", " << this->position_.y << ")" << std::endl;
            std::cout << std::endl;
            break;
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
