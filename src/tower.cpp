#include "tower.hpp"

// Calculate the distance between this and the enemy object using formula:
// sqrt((x_1 - x_2)^2 + (y_1 - y_2)^2)
// If it is less than radius, then add it to the vector of enemies within the radius.
const std::vector<Enemy*> Tower::getEnemiesWithinRadius() {
    
    // Filter vector based on type (Enemy).
    const std::type_info& enemyType = typeid(Enemy);
    auto isEnem = [&enemyType](const GameObject* obj) {
        return typeid(*obj) == enemyType;
    };
    
    std::vector<GameObject*> enemies;
    std::copy_if(begin(this->game_.Objects()), end(this->game_.Objects()), std::back_inserter(enemies), isEnem);

    // Find all the enemies within the given radius.
    std::vector<GameObject*> enemiesWithinRadius;

    for (int i = 0; i < enemies.size(); i++) {
        int sqrtEq = std::pow((this->position_.x - enemies.at(i)->getPosition().x), 2) + std::pow((this->position_.y - enemies.at(i)->getPosition().y), 2);
        double distance = std::sqrt(static_cast<double>(sqrtEq));

        if (this->radius_ >= distance) {
            enemiesWithinRadius.push_back(enemies.at(i));
        }
    }

    // Change the type of the vector enemiesWithinRadius from GameObject* to Enemy*.
    std::vector<Enemy*> result;
    for (GameObject* obj : enemiesWithinRadius) {
        // Attempt to cast to Enemy*
        if (Enemy* enemy = dynamic_cast<Enemy*>(obj)) {
            result.push_back(enemy);
        }
    }

    return result;
}

Tower::~Tower() {

}
