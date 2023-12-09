#include "enemy.hpp"
#include "utility_func_game.hpp"
#include "vec2d.hpp"
#include "gamegrid.hpp"

int Enemy::GetSpeed() const {
    return speed_;
}

bool Enemy::isAlive() const {
    return this->health_ > 0;
}


std::size_t findCurrentPath(const Enemy* e, const std::vector<Vec2D>& path) {
    // This variable will be returned by this method.
    std::size_t currIndex = 0;

    // Find the vector Vec2D, where this position occurs.
    for (std::size_t j = 0; j < path.size(); j++) {
        bool betweenAandB = false;
        // Calculate the difference between ending point and starting point of current Vec2D.
        float diffX = path.at(j).b.x - path.at(j).a.x;
        float diffY = path.at(j).b.y - path.at(j).b.y;

        if ((diffX == 0) && (diffY > 0)) {
            // Is the y-coordinate of the enemy on the interval [a.y, b.y).
            betweenAandB = (path.at(j).a.y <= e->getPosition().y) && (e->getPosition().y < path.at(j).b.y);
        } else if ((diffX > 0) && (diffY == 0)) {
            // Is the x-coordinate of the enemy on the interval [a.x, b.x).
            betweenAandB = (path.at(j).a.x <= e->getPosition().x) && (e->getPosition().x < path.at(j).b.x);
        } else if ((diffX == 0) && (diffY < 0)) {
            // Is the y-coordinate of the enemy on the interval (b.y, a.y].
            betweenAandB = (path.at(j).b.y < e->getPosition().y) && (e->getPosition().y <= path.at(j).a.y);
        } else if ((diffX < 0) && (diffY == 0)) {
            // Is the x-coordinate of the enemy on the interval (b.x, a.x].
            betweenAandB = (path.at(j).b.x < e->getPosition().x) && (e->getPosition().x <= path.at(j).a.x);
        }

        if (betweenAandB) {
            currIndex = j;
            break;
        }
    }
    return currIndex;
}


void Enemy::update() {
    // In case the enemy is alive, advance enemy position by one tick according to the path.
    if (this->isAlive()) {
        const std::vector<Vec2D>& path = getGrid(game_)->EnemyPath();
        int i = 0;

        // Find the vector2D that contains enemy's current position.
        while (i < (int)path.size()) {
            const Vec2D currVec = path.at(i);

            // start position of the currVec to current position of the enemy.
            //Vec2D sPosToEnemPos = Vec2D{ currVec.a, this->position_ };

            // Find a current vector in form of (4i + 2j) for example, which is a point.
            Pos vec1 = Pos{ (currVec.b.x - currVec.a.x), (currVec.b.y - currVec.a.y) };

            // Find a vector between start position and enemy's position.
            Pos vec2 = Pos{ (this->position_.x - currVec.a.x), (this->position_.y - currVec.a.y) };
            
            // Calculate the dot product between vec1 and vec2.
            // If enemy's position is on current vector, then the angle between the vectors should be 0.
            // This means that the cosine should equal 1.
            const int dotP = (vec1.x * vec2.x) + (vec1.y * vec2.y);
            // Calculate the length of the vectors vec1 and vec2.
            const float vec1Length = sqrt((vec1.x * vec1.x) + (vec1.y * vec1.y));
            const float vec2Length = sqrt((vec2.x * vec2.x) + (vec2.y * vec2.y));

            // TODO: Check for the end of the path, enemy wins
            // The length of the vec2 should be smaller than vec1, if the enemy's position is
            // on the current vector.
            if (vec2Length > vec1Length) {
                i++;
                continue;
            }

            // vec2 should not be a zero vector, if so, then the current vector is proper path.
            if (vec2Length != 0) {
                const float cos12 = std::abs(dotP / (vec1Length * vec2Length));
                // Check the angle and the vec2 should not be null vector.
                if (cos12 != 1.0) {
                    i++;
                    continue;
                }
            }

            // Tells the direction of the enemy (North - 'N', East - 'E', South - 'S', West - 'W').
            char direction;

            // Find unit vector of vec1.
            Pos unitVec1 = Pos{ (vec1.x / vec1Length), (vec1.y / vec1Length) };
            
            // Set the direction of the enemy.
            if (unitVec1.y < 0) {
                direction = 'N';
            } else if (unitVec1.x > 0) {
                direction = 'E';
            } else if (unitVec1.y > 0) {
                direction = 'S';
            } else {
                direction = 'W';
            }

            // Advance enemy's position.
            this->position_.x += this->speed_ * unitVec1.x;
            this->position_.y += this->speed_ * unitVec1.y;
 
            // Check that the enemy doesn't go further than the end point of a path vector.
            bool outX = (unitVec1.x > 0) ? (this->position_.x > currVec.b.x) : (this->position_.x < currVec.b.x);
            bool outY = (unitVec1.y > 0) ? (this->position_.y > currVec.b.y) : (this->position_.y < currVec.b.y);

            if (outX || outY) {
                // Check how far does the enemy go from the currVec's end point.
                float outInSpeed = (unitVec1.x != 0) ? std::abs((this->position_.x - currVec.b.x) / unitVec1.x) : std::abs((this->position_.y - currVec.b.y) / unitVec1.y);

                // Restore enemy's position to end point of the currVec.
                position_ = currVec.b;

                int j = i + 1;

                while ((j < (int)path.size()) && (outInSpeed > 0)) {
                    const Vec2D pathPoints = path.at(j);
                    Pos pathVec = Pos{ (pathPoints.b.x - pathPoints.a.x), (pathPoints.b.y - pathPoints.a.y) };
                    float pathVecLength = sqrt((pathVec.x * pathVec.x) + (pathVec.y * pathVec.y));
                    Pos unitPathVec = Pos{ (pathVec.x / pathVecLength), (pathVec.y / pathVecLength) };
                    
                    // Update the direction of the enemy.
                    if (unitPathVec.y < 0) {
                        direction = 'N';
                    } else if (unitPathVec.x > 0) {
                        direction = 'E';
                    } else if (unitPathVec.y > 0) {
                        direction = 'S';
                    } else {
                        direction = 'W';
                    }

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

            // Set rotation angle in degrees according to the direction variable above.
            // Enemy's direction is 'E' at the start.
            switch(direction) {
                case 'N':
                    this->SetAngle(270);
                    break;
                case 'E':
                    this->SetAngle(0);
                    break;
                case 'S':
                    this->SetAngle(90);
                    break;
                case 'W':
                    this->SetAngle(180);
                    break;
                default:
                    throw std::runtime_error("Unknown direction!");
            }
            break;
        }
    }
}