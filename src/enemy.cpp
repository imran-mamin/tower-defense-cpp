#include "enemy.hpp"

int Enemy::GetSpeed() const {
    return speed_;
}

bool Enemy::isAlive() const {
    return this->health_ > 0;
}
