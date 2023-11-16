#include "cannon.hpp"

void Cannon::fire() {
    
};

void Cannon::onDestroy() {

};

void Cannon::update() {
    if (this->fireIntervalCounter_ <= 0) {
        // Fire the first enemy in the radius.
        this->fire();

        // Start projectile reloading.
        fireIntervalCounter_ = fireRate_;
    } else {
        fireIntervalCounter_--;
    }
};

int Cannon::sell() {
    int p = this->price_;
    // Destroy the object, when it's sold out.
    this->~Cannon();
    return p;
};
