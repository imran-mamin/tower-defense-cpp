#include "tower.hpp"

// Calculate the distance between this and the enemy object using formula:
// sqrt((x_1 - x_2)^2 + (y_1 - y_2)^2)
// If it is less than radius, then add it to the vector of enemies within the radius.
const std::vector<Enemy> Tower::getEnemiesWithinRadius() {
    /*
    // Filter vector based on type (Enemy).
    const std::type_info& enemyType = typeid(Enemy);
    auto isEnem = [&enemyType](const GameObject* obj) {
        return typeid(*obj) == enemyType;
    };

    std::vector<GameObject> enemies;
    std::copy_if(begin(this->getObjects()), end(this->getObjects()), std::back_inserter(enemies), isEnem);

    for (auto it = enemies.begin(); it != enemies.end(); it++) {
        // enemies.push_back(dynamic_cast<Enemy&>(obj));
        (*it) = dynamic_cast<Enemy&>(*it);
    }
   
    // Find all the enemies within the given radius.
    std::vector<GameObject> enemiesWithinRadius;
    */
}

Tower::~Tower() {

}
