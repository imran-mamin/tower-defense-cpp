#include <assert.h>
#include "missilelauncher.hpp"

void MissileLauncher::fire() {
    assert(!this->getEnemiesWithinRadius().empty());
    Enemy e = this->getEnemiesWithinRadius().at(0);

    // Missile(sf::Sprite sprite, Game game, int travel_speed, int damage, int radius, Enemy target, double exp_radius = 0)
    // Create a missile object.
    sf::Sprite sp;
    // Missile m = Missile(sp, this->game_, 6, 6, 4, e, 4); 
    
    // Add missile to vector.
    // this->getObjects().push_back(m); 
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
