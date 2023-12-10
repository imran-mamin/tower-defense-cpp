#include "tower.hpp"

#include <cstddef>

#include "enemy.hpp"
#include "utility_func_game.hpp"

// Calculate the distance between this and the enemy object using formula:
// sqrt((x_1 - x_2)^2 + (y_1 - y_2)^2)
// If it is less than radius, then add it to the vector of enemies within the
// radius.
template <typename T>
bool CompareTravel(T e1, T e2) {
  return e1->TravelDistance() > e2->TravelDistance();
}

const std::vector<Enemy*> Tower::getEnemiesWithinRadius() {
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

  // Add enemies to enemiesWithinRadius in reverse order.
  for (auto it = enemies.rbegin(); it != enemies.rend(); it++) {
    int sqrtEq = std::pow((position_.x - (*it)->getPosition().x), 2) +
                 std::pow((position_.y - (*it)->getPosition().y), 2);
    double distance = std::sqrt(static_cast<double>(sqrtEq));

    if (radius_ >= distance) {
      enemiesWithinRadius.push_back(*it);
    }
  }

  std::sort(enemiesWithinRadius.begin(), enemiesWithinRadius.end(),
            CompareTravel<Enemy*>);

  return enemiesWithinRadius;
}

Tower::~Tower() {}
