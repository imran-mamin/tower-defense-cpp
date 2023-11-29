#include "enemy.hpp"

bool Enemy::isAlive() const {
    return this->health_ > 0;
}
