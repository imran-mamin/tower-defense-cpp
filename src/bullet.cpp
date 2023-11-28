#include "bullet.hpp"

void Bullet::update() {
    // Find the vector between starting point and end point.
    Pos vec = Pos{ (endPos_.x - startPos_.x), (endPos_.y - startPos_.y) };
    double vecLength = sqrt((vec.x * vec.x) + (vec.y * vec.y));

    // Find unit vector of vec.
    Pos unitVec = Pos{ (vec.x / vecLength), (vec.y / vecLength) };

    // Check, whether the enemy is within missile radius on every position update.
    int i = 0;

    // TODO: Hit another enemy, if it appears earlier on the Bullet's path.
    while (i < this->travel_speed()) {
        // Calculate the distance between bullet and target.
        // Formula sqrt((x_1 - x_2)^2 + (y_1 - y_2)^2)
        Pos currPos = this->getPosition();
        double xPow2 = std::pow((this->target_->getPosition().x - currPos.x), 2);
        double yPow2 = std::pow((this->target_->getPosition().y - currPos.y), 2);
        double dist = sqrt(xPow2 + yPow2);

        if (dist <= this->radius()) {
            this->target_->takeDamage(this->damage());
            this->onDestroy();
        }

        // Update bullet's position.
        this->position_.x += unitVec.x;
        this->position_.y += unitVec.y;

        // Check that the Bullet is still on the screen.
        bool outX = ((0 <= this->position_.x) && (this->position_.x < (this->getGrid().Width() - 1)));
        bool outY = ((0 <= this->position_.y) && (this->position_.y < (this->getGrid().Height() - 1)));

        if (outX || outY) {
            this->onDestroy();
        }

        i++;
    }
}

void Bullet::onDestroy() {
    this->game_.DeleteObject(this);
    delete this;
}
