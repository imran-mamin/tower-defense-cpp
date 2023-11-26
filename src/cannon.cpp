#include <assert.h>

#include "cannon.hpp"
#include "bullet.hpp"

void Cannon::fire() {
    Enemy* e = this->getEnemiesWithinRadius().at(0);

    // Bullet(sf::Sprite sprite, Game& game, Enemy* target, int travel_speed, int damage, int radius, Pos position)
    // Create a Bullet-class instance.
    sf::Sprite sp;
    Bullet* b = new Bullet(sp, this->game_, e, 20, 20, 2, this->position_);

    // Add bullet to vector of objects.
    this->game_.AddObject(b);
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
