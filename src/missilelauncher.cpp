#include <assert.h>
#include "missilelauncher.hpp"

void MissileLauncher::fire() {
    Enemy e = this->getEnemiesWithinRadius().at(0);

    // Missile(int travel_speed, int damage, int radius, Enemy target, double exp_radius = 0)
    // Create a missile object.
    sf::Sprite sprite;
    //Missile m = Missile(sprite, 6, 6, 4, e, 4); // TODO: Make sure that radius != exp_radius.
    
    // Add missile to vector.
    // missiles_.push_back(m);    
}

void MissileLauncher::update() {
    assert(this->fireIntervalCounter_ >= 0);

    if (this->fireIntervalCounter_ == 0) {
        // Fire the first enemy in the radius.
        this->fire();

        // Remove missile if it explodes.
        

        // Start projectile reloading.
        fireIntervalCounter_ = fireRate_;
    } else {
        fireIntervalCounter_--;
    }
}

int MissileLauncher::sell() {
    int p = this->price_;
    this->addPlayerMoney(p);
    this->~MissileLauncher();
    return p;
}
