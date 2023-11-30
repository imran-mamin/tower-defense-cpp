#include <assert.h>
#include "missilelauncher.hpp"

void MissileLauncher::fire() {
    assert(!this->getEnemiesWithinRadius().empty());
    Enemy* e = this->getEnemiesWithinRadius().at(0);

    // Missile(Game& game, int travel_speed, int damage, int radius, Enemy target, Pos position, double exp_radius = 0)
    // Create a missile object.
    Pos p = this->getPosition();
    Missile* m = new Missile(this->game_, 18, 6, 18, e, p, 4); 
    
    // Add missile to vector.
    this->game_.AddObject(m); 
}

void MissileLauncher::update() {
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

int MissileLauncher::sell() {
    int p = this->price_;
    this->addPlayerMoney(p);
    this->onDestroy();
    return p;
}

void MissileLauncher::onDestroy() {
    this->~MissileLauncher();
}
