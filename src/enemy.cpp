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

/**
 * This method finds the current Vec2D of the Enemy 'e' and returns
 * an index of that Vec2D-instance in path.
*/
int findCurrentPath(const Enemy* e, const std::vector<Vec2D>& path, Game* game) {
    // This variable will be returned by this method.
    int currIndex = -1;

    // Find the vector Vec2D, where this position occurs.
    for (int j = 0; j < (int)path.size(); j++) {
        bool betweenAandB = false;
        // Calculate the difference between ending point and starting point of current Vec2D.
        float diffX = path.at(j).b.x - path.at(j).a.x;
        float diffY = path.at(j).b.y - path.at(j).a.y;

        if ((diffX == 0) && (diffY > 0)) {
            if (e->getPosition().x == path.at(j).b.x) {
                // Is the y-coordinate of the enemy on the interval [a.y, b.y).
                betweenAandB = (path.at(j).a.y <= e->getPosition().y) && (e->getPosition().y < path.at(j).b.y);
            }
        } else if ((diffX > 0) && (diffY == 0)) {
            if (e->getPosition().y == path.at(j).b.y) {
                // Is the x-coordinate of the enemy on the interval [a.x, b.x).
                betweenAandB = (path.at(j).a.x <= e->getPosition().x) && (e->getPosition().x < path.at(j).b.x);
            }
        } else if ((diffX == 0) && (diffY < 0)) {
            if (e->getPosition().x == path.at(j).b.x) {
                // Is the y-coordinate of the enemy on the interval (b.y, a.y].
                betweenAandB = (path.at(j).b.y < e->getPosition().y) && (e->getPosition().y <= path.at(j).a.y);
            }
        } else if ((diffX < 0) && (diffY == 0)) {
            if (e->getPosition().y == path.at(j).b.y) {
                // Is the x-coordinate of the enemy on the interval (b.x, a.x].
                betweenAandB = (path.at(j).b.x < e->getPosition().x) && (e->getPosition().x <= path.at(j).a.x);
            }
        }

        if (betweenAandB) {
            currIndex = j;
            break;
        }
    }
    
    if (currIndex == -1) {
        std::cout << "b" << std::endl;
        setGameOver(game);
    }
    
    assert(currIndex != -1);
    return currIndex;
}

// Pos is a vector in form of 2i + 4j, for example.
// Takes a Pos (vector) as parameter and returns
// the direction of the Enemy.
char checkDirection(Pos vec) {
    // Find the direction of the enemy.
    char dir;
    if (vec.y < 0) {
        dir = 'N';
    } else if (vec.x > 0) {
        dir = 'E';
    } else if (vec.y > 0) {
        dir = 'S';
    } else {
        dir = 'W';
    }
    return dir;
}

/**
 * This method is a helper function for calculating new position of the Enemy-instance, when it goes
 * out of the current Vec2D. It returns a pair of new position and the direction of the enemy.
*/
std::pair<Pos, char> advanceEnemyByOut(const Enemy* e, const float out, const int currIndex, const std::vector<Vec2D>& path, Game* game) {
    Pos updatePos = e->getPosition();
    float remain = out;
    char dir;
    // Since this method is called, when the enemy goes out of the current Vec2D, we start from
    // currIndex + 1.
    int i = currIndex + 1;
    for (i; i < (int)path.size(); i++) {
        float distAB = std::abs((path.at(i).b.x - path.at(i).a.x) + (path.at(i).b.y - path.at(i).a.y));

        // If current distance AB is smaller than offset, then remove offset from remaining and
        // continue with the next Vec2D.
        if (distAB < remain) {
            remain -= distAB;
            continue;
        }
        
        // Find new position of the enemy.
        float diffX = path.at(i).b.x - path.at(i).a.x;
        float diffY = path.at(i).b.y - path.at(i).a.y;

        if ((diffX == 0) && (diffY > 0)) {
            updatePos.x = path.at(i).a.x;
            updatePos.y = path.at(i).a.y + remain;
            dir = checkDirection(Pos{ diffX, diffY });
            break;
        } else if ((diffX > 0) && (diffY == 0)) {
            updatePos.x = path.at(i).a.x + remain;
            updatePos.y = path.at(i).a.y;
            dir = checkDirection(Pos{ diffX, diffY });
            break;
        } else if ((diffX == 0) && (diffY < 0)) {
            updatePos.x = path.at(i).a.x;
            updatePos.y = path.at(i).a.y - remain;
            dir = checkDirection(Pos{ diffX, diffY });
            break;
        } else if ((diffX < 0) && (diffY == 0)) {
            updatePos.x = path.at(i).a.x - remain;
            updatePos.y = path.at(i).a.y;
            dir = checkDirection(Pos{ diffX, diffY });
            break;
        }
    }

    // TODO: Instead of assert the flag gameOver should be set.
    if (updatePos == e->getPosition()) {
        std::cout << "a" << std::endl;
        setGameOver(game);
    }

    return std::make_pair(updatePos, dir);
}

void Enemy::update() {
    // In case the enemy is alive, advance enemy position by one tick according to the path.
    if (this->isAlive()) {
        const std::vector<Vec2D>& path = getGrid(game_)->EnemyPath();

        // Find the vector2D that contains enemy's current position.
        int currVecIndex = findCurrentPath(this, path, game_);
        const Vec2D currVec = path.at(currVecIndex);
        // Find a current vector in form of (4i + 2j) for example, which is a point.
        Pos vec1 = Pos{ (currVec.b.x - currVec.a.x), (currVec.b.y - currVec.a.y) };
        const float vec1Length = sqrt((vec1.x * vec1.x) + (vec1.y * vec1.y));
  
        // Find unit vector of vec1.
        Pos unitVec1 = Pos{ (vec1.x / vec1Length), (vec1.y / vec1Length) };
        
        // Tells the direction of the enemy (North - 'N', East - 'E', South - 'S', West - 'W').
        char direction = checkDirection(unitVec1);

        // Advance enemy's position.
        position_.x += speed_ * unitVec1.x;
        position_.y += speed_ * unitVec1.y;

        // Check that the enemy doesn't go further than the end point of a path vector.
        bool outX = (unitVec1.x > 0) ? (position_.x > currVec.b.x) : (position_.x < currVec.b.x);
        bool outY = (unitVec1.y > 0) ? (position_.y > currVec.b.y) : (position_.y < currVec.b.y);

        if (outX || outY) {
            // Check how much enemy goes out.
            float out = (unitVec1.x != 0) ? std::abs(position_.x - currVec.b.x) : std::abs(position_.y - currVec.b.y);
            std::pair<Pos, char> res = advanceEnemyByOut(this, out, currVecIndex, path, game_);
            position_.x = res.first.x;
            position_.y = res.first.y;
            direction = res.second;
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
    }
}
