#include <assert.h>
#include <cstddef>

#include "cannon.hpp"
#include "bullet.hpp"
#include "utility_func_game.hpp"


void Cannon::fire() {
    assert(this->getEnemiesWithinRadius().size() > 0);
    Enemy* e = this->getEnemiesWithinRadius().at(0);
    int bulletSpeed = 40;
    int radius = 4;

    // Bullet(Game& game, int travel_speed, int damage, int radius, Pos position, Pos endPos)
    addObject(game_ ,new Bullet(game_, bulletSpeed, 6, radius, position_, e->getPosition()));
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
    // Destroy the object, when it's sold out.
    this->onDestroy();
    return p;
}

void Cannon::onDestroy() {

}
