#include <assert.h>

#include "cannon.hpp"
#include "bullet.hpp"

// Returns the index of current path vector.
int findCurrentPathVec(const Enemy* e, const std::vector<Vec2D>& path) {
    for (int i = 0; i < path.size(); i++) {
        
        bool betweenAandB = false;
        // Calculate the difference between ending point and starting point of current Vec2D.
        float diffX = path.at(i).b.x - path.at(i).a.x;
        float diffY = path.at(i).b.y - path.at(i).b.y;

        if ((diffX == 0) && (diffY > 0)) {
            // Is the y-coordinate of the enemy on the interval [a.y, b.y).
            betweenAandB = (path.at(i).a.y <= e->getPosition().y) && (e->getPosition().y < path.at(i).b.y);
        } else if ((diffX > 0) && (diffY == 0)) {
            // Is the x-coordinate of the enemy on the interval [a.x, b.x).
            betweenAandB = (path.at(i).a.x <= e->getPosition().x) && (e->getPosition().x < path.at(i).b.x);
        } else if ((diffX == 0) && (diffY < 0)) {
            // Is the y-coordinate of the enemy on the interval (b.y, a.y].
            betweenAandB = (path.at(i).b.y < e->getPosition().y) && (e->getPosition().y <= path.at(i).a.y);
        } else if ((diffX < 0) && (diffY == 0)) {
            // Is the x-coordinate of the enemy on the interval (b.x, a.x].
            betweenAandB = (path.at(i).b.x < e->getPosition().x) && (e->getPosition().x <= path.at(i).a.x);
        }
        
        if (betweenAandB) {
            return i;
        }
    }
    // Should find the path vector unless, it's the end of path.
    assert(false);
};

/**
 * This method finds the length of path from enemy's current position to pos p according
 * to the enemypath (path parameter).
*/
float findEnemyDist(const Enemy* e, const std::vector<Vec2D>& path, Pos p, int i) {
    int j = i;
    
    // Distance to the end of current path.
    float dist = sqrt(std::pow(path.at(i).b.x - e->getPosition().x, 2) + std::pow(path.at(i).b.y - e->getPosition().y, 2));
    
    // Positions are different.
    while ((path.at(j).a.x != p.x) || (path.at(j).a.y != p.y)) {
        // Calculate the length of current Vec2D.
        float currLength = sqrt(std::pow(path.at(j).b.x - path.at(j).a.x, 2) + std::pow(path.at(j).b.y - path.at(j).a.y, 2));
        dist += currLength;
        j++;
    }
    return dist;
}

/**
 * This method returns the Vec2D, where the collision between bullet and enemy occurs.
*/
Vec2D findCollisionVec(const Enemy* e, int i, const std::vector<Vec2D>& path, Pos bulletPos, int bulletSpeed) {

    // Check separately for path.at(i).
    float distEnemy = sqrt(std::pow(path.at(i).b.x - e->getPosition().x, 2) + std::pow(path.at(i).b.y - e->getPosition().y, 2));
    float distBullet = sqrt(std::pow(path.at(i).b.x - bulletPos.x, 2) + std::pow(path.at(i).b.y - bulletPos.y, 2));
    float enemyTime = distEnemy / e->GetSpeed();
    float bulletTime = distBullet / bulletSpeed;
    
    // If the collision happens on this Vec2D, then return it.
    if (bulletTime <= enemyTime) {
        return path.at(i);
    }

    int j = i + 1;
    while (j < path.size()) {
        Vec2D currVec = path.at(j);

        // Calculate the distance from enemy and bullet to point a.
        float enemyDistToA = findEnemyDist(e, path, currVec.a, i);
        float bulletDistToA = sqrt(std::pow(currVec.a.x - bulletPos.x, 2) + std::pow(currVec.a.y - bulletPos.y, 2));

        // let's denote t1a, t1b, t2a, t2b as time (ticks) spent by enemy and bullet respectively to reach
        // a point and b point of current Vec2D
        // s = v * t  =>  t = s / v
        float t1a = enemyDistToA / e->GetSpeed();
        float t2a = bulletDistToA / bulletSpeed;
        
        // Calculate the distance from enemy and bullet to point b.
        float enemyDistToB = findEnemyDist(e, path, currVec.b, i);
        float bulletDistToB = sqrt(std::pow(currVec.b.x - bulletPos.x, 2) + std::pow(currVec.b.y - bulletPos.y, 2));

        // s = v * t  =>  t = s / v
        float t1b = enemyDistToB / e->GetSpeed();
        float t2b = bulletDistToB / bulletSpeed;

        if ((t1a <= t1b) && (t2a >= t2b)) {
            return path.at(j);
        }
        j++;
    }
};

Pos binarySearch(const Enemy* e, int i, const std::vector<Vec2D>& path, Pos start, Pos end, Pos bulletPos, int bulletSpeed, int radius) {
    Pos left = start;
    Pos mid;
    mid.x = start.x + (end.x - start.x) / 2;
    mid.y = start.y + (end.y - start.y) / 2;
    Pos right = end;

    while (((right.x - left.x) + (right.y - left.y)) > radius) {
        float enemyDistToMidLen = findEnemyDist(e, path, mid, i);
        // Calculate times for enemy to reach left, mid and right positions.
        float tEnemM = enemyDistToMidLen / e->GetSpeed();

        float bulletDistToMidLen = sqrt(std::pow(mid.x - bulletPos.x, 2) + std::pow(mid.y - bulletPos.y, 2));
        // Calculate times for enemy to reach left mid and right positions.
        float tBullM = bulletDistToMidLen / bulletSpeed;

        if (tEnemM > tBullM) {
            right = mid;
            mid.x = left.x + (right.x - left.x) / 2;
            mid.y = left.y + (right.y - left.y) / 2;
        } else {
            left = mid;
            mid.x = left.x + (right.x - left.x) / 2;
            mid.y = left.y + (right.y - left.y) / 2;
        }
    }

    return mid;
    
}

Pos findCollisionPos(const Enemy* e, int i, const std::vector<Vec2D>& path, Vec2D collisionVec, Pos bulletPos, int bulletSpeed, int radius) {
    float diffX = collisionVec.b.x - collisionVec.a.x;
    float diffY = collisionVec.b.y - collisionVec.a.y;

    if ((diffX < 0) || (diffY < 0)) {
        return binarySearch(e, i, path, collisionVec.b, collisionVec.a, bulletPos, bulletSpeed, radius);
    }

    return binarySearch(e, i, path, collisionVec.a, collisionVec.b, bulletPos, bulletSpeed, radius);
}

/**
 * The collision between enemy and bullet may happen starting from
 * enemy's current position and to the end of the path. It is also
 * assumed that it appears between start and end points of Vec2D
 * which occurs on the path.
*/
// TODO: Cannon should set the direction for the Bullet-instance.
void Cannon::fire() {
    assert(this->getEnemiesWithinRadius().size() > 0);
    Enemy* e = this->getEnemiesWithinRadius().at(0);
    int bulletSpeed = 18;
    int radius = 2;

    // Returns current vec2D and its index in enemyPath vector.
    int currIndex = findCurrentPathVec(e, game_.GetGrid().EnemyPath());
    Vec2D collisionVec = findCollisionVec(e, currIndex, game_.GetGrid().EnemyPath(), this->getPosition(), bulletSpeed);
    Pos collisionPos = findCollisionPos(e, currIndex, game_.GetGrid().EnemyPath(), collisionVec, this->getPosition(), bulletSpeed, radius);

    // Bullet(Game& game, int travel_speed, int damage, int radius, Pos position, Pos endPos)
    // TODO: The Bullet-instance should be added to the vector of objects.
    // game_.AddObject(std::make_unique<Bullet>(Bullet(game_, bulletSpeed, 6, radius, position_, collisionPos)));
    
};

void Cannon::update() {
    assert(this->fireIntervalCounter_ >= 0);
    
    if (this->fireIntervalCounter_ == 0) {
        // Check if there are enemies within the radius.
        if (!this->getEnemiesWithinRadius().empty()) {
            // Fire the first enemy in the radius.
            this->fire();

            // Start projectile reloading.
            fireIntervalCounter_ = fireRate_;
        }
    } else {
        fireIntervalCounter_--;
    }
}

int Cannon::sell() {
    int p = this->price_;
    this->addPlayerMoney(p);
    // Destroy the object, when it's sold out.
    this->onDestroy();
    return p;
}

void Cannon::onDestroy() {

}
