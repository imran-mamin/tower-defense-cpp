#include <assert.h>

#include "cannon.hpp"
#include "bullet.hpp"

Vec2D findCurrentPathVec(const Enemy* e, const std::vector<Vec2D>& path) {
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
            return path.at(i);
        }
    }
    // Should find the path vector unless, it's the end of path.
    assert(false);
};

/**
 * The collision between enemy and bullet may happen on
*/
// TODO: Cannon should set the direction for the Bullet-instance.
void Cannon::fire() {
    assert(this->getEnemiesWithinRadius().size() > 0);
    Enemy* e = this->getEnemiesWithinRadius().at(0);

    Vec2D currVec = findCurrentPathVec(e, game_.GetGrid().EnemyPath());

    /*
    // This is constant - representing 18px motion per "time unit".
    int bulletSpeed = 18;
    // Find the vector from cannon to enemy.
    Pos vecToEnem;
    vecToEnem.x = e->getPosition().x - this->getPosition().x;
    vecToEnem.y = e->getPosition().y - this->getPosition().y;

    // Find the length of vecToEnem.
    float vecToEnemLen = sqrt((vecToEnem.x * vecToEnem.x) + (vecToEnem.y * vecToEnem.y));
    */
    // Adjust for target position based on the amount of "time units" to travel "dist"
    // and the targets speed vector.


    // Bullet(Game& game, Enemy* target, int travel_speed, int damage, int radius, Pos position, Pos endPos)
    // Create a Bullet-class instance.

    // Add bullet to vector of objects.
    // this->game_.AddObject(b);
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
