#include <cstddef>

#include "projectile.hpp"
#include "utility_func_game.hpp"

// Calculate the distance between this and the enemy object using formula:
// sqrt((x_1 - x_2)^2 + (y_1 - y_2)^2)
// If it is less than radius, then add it to the vector of enemies within the radius.
const std::vector<Enemy*> Projectile::getEnemiesWithinRadius() {
    // Filter vector based on type (Enemy).
    std::vector<Enemy*> enemies;

    for (GameObject* obj : getObjects(game_)) {
        // Attempt to cast to Enemy*
        if (Enemy* enemy = dynamic_cast<Enemy*>(obj)) {
            enemies.push_back(enemy);
        }
    }

    // Find all the enemies within the given radius.
    std::vector<Enemy*> enemiesWithinRadius;

    for (std::size_t i = 0; i < enemies.size(); i++) {
        int sqrtEq = std::pow((this->position_.x - enemies.at(i)->getPosition().x), 2) + std::pow((this->position_.y - enemies.at(i)->getPosition().y), 2);
        double distance = std::sqrt(static_cast<double>(sqrtEq));

        if (this->radius_ >= distance) {
            enemiesWithinRadius.push_back(enemies.at(i));
        }
    }

    return enemiesWithinRadius;
}
