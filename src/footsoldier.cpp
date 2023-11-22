#include "footsoldier.hpp"

void FootSoldier::update() {
    // In case the enemy is alive, advance enemy position by one tick according to the path.
    if (this->isAlive()) {
        // TODO: When there is an enemy path available, then advance enemy position by one tick.
    } else {
        auto it = this->getObjects().begin();

        // Remove enemy object from vector of objects.
        while (it != this->getObjects().end()) {
            if (&(*it) == this) {
                this->getObjects().erase(it);
                break;
            }
            it++;
        }
        // Destroy the Enemy object.
        this->onDestroy();
    }
}

void FootSoldier::onDestroy() {
    this->~FootSoldier();
}
