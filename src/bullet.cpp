#include "bullet.hpp"

void Bullet::update() {
    std::cout << "Bullet update()-method called" << std::endl;
    // Find the vector between starting point and end point.
    Pos vec = Pos{ (endPos_.x - startPos_.x), (endPos_.y - startPos_.y) };
    float vecLength = sqrt((vec.x * vec.x) + (vec.y * vec.y));

    // Find unit vector of vec.
    Pos unitVec = Pos{ (vec.x / vecLength), (vec.y / vecLength) };

    // Check, whether the enemy is within bullet radius on every position update.
    int i = 0;

    while (i < this->travel_speed()) {
        // Hit the first enemy on the Bullet's path, if there is one.
        std::vector<Enemy*> enemies = this->getEnemiesWithinRadius();

        if (!enemies.empty()) {
            enemies.at(0)->takeDamage(this->damage());
            this->health_ = 0;
            break;
        }

        // Update bullet's position.
        this->position_.x += unitVec.x;
        this->position_.y += unitVec.y;

        // Check that the Bullet is still on the screen.
        bool inX = ((0 <= this->position_.x) && (this->position_.x < (this->getGrid().Width() * this->getGrid().TileWidth() - 1)));
        bool inY = ((0 <= this->position_.y) && (this->position_.y < (this->getGrid().Height() * this->getGrid().TileWidth() - 1)));
         std::cout << "inX = " << inX << "   " << "inY = " << inY << std::endl;
         std::cout << "Pos = (" << position_.x << ", " << position_.y << ")" << std::endl;
        if (!(inX && inY)) {
            this->health_ = 0;
            std::cout << "if block" << std::endl;
            std::cout << "Pos = (" << position_.x << ", " << position_.y << ")" << std::endl;
            break;
        }

        i++;
    }
}

void Bullet::onDestroy() {
}
