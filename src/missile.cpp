#include "missile.hpp"

#include <memory>

#include "enemy.hpp"
#include "gamegrid.hpp"
#include "utility_func_game.hpp"
#include "vec2d.hpp"

/**
 * Every time update()-method is called, the position of the Missile object,
 * should be closer to the target object.
 *
 * Corner cases:
 * 1. Other projectile kills the enemy, then the missile just finds kills the
 * closest enemy, or goes out of the window.
 * 2. Target goes out of the window. Then the missile should follow it.
 * */

void Missile::update() {
  bool isAlive = false;
  for (const auto& obj : getObjects(game_)) {
    // Attempt to cast to Enemy*
    if (const auto enemy = dynamic_cast<const Enemy*>(obj); enemy) {
      if (enemy == target_) {
        isAlive = true;
        break;
      }
    }
  }

  if (isAlive) {
    Vec2D pathToTarget = Vec2D{position_, target_->getPosition()};

    // Find the vector (type Pos) using two positions. (Vector in e.g. 4i + 2j
    // format).
    Pos vectorToTarget = Pos{(pathToTarget.b.x - pathToTarget.a.x),
                             (pathToTarget.b.y - pathToTarget.a.y)};

    // Find the length of the vectorToTarget.
    float vectorToTargetLength = sqrt((vectorToTarget.x * vectorToTarget.x) +
                                      (vectorToTarget.y * vectorToTarget.y));

    // Find unit vector of vectorToTarget.
    Pos unitVec = Pos{(vectorToTarget.x / vectorToTargetLength),
                      (vectorToTarget.y / vectorToTargetLength)};
    lastDirection_ = unitVec;
    // Set the rotation of missile.
    Pos unitVecN = Pos{0, -1};

    // Calculate dot product of unitVec and unitVecN.
    float dotP = unitVec.x * unitVecN.x + unitVec.y * unitVecN.y;

    // Calculate the rotation angle.
    float angleInRad = std::acos(dotP);
    float angleInDeg = angleInRad * (180.0 / M_PI);
    bool enemyOnTheLeftSide = (target_->getPosition().x < position_.x);
    if (enemyOnTheLeftSide) {
      this->SetAngle(360.0 - angleInDeg);
    } else {
      this->SetAngle(angleInDeg);
    }

    // Check, whether the enemy is within missile radius on every position
    // update.
    int i = 0;

    while (i < this->travel_speed()) {
      // The missile will cause damage to all enemies within the given missile
      // radius.
      std::vector<Enemy*> enemiesWithinRadius = this->getEnemiesWithinRadius();
      if (!enemiesWithinRadius.empty()) {
        auto it = enemiesWithinRadius.begin();
        while (it != enemiesWithinRadius.end()) {
          (*it)->takeDamage(this->damage());
          it++;
        }
        // Remove missile object from the vector objects_.
        health_ = 0;
        break;
      }
      // Update missile's position.
      position_.x += unitVec.x;
      position_.y += unitVec.y;

      i++;
    }

  } else {
    int i = 0;
    while (i < travel_speed()) {
      // The missile will cause damage to all enemies within the given missile
      // radius.
      std::vector<Enemy*> enemiesWithinRadius = this->getEnemiesWithinRadius();
      if (!enemiesWithinRadius.empty()) {
        auto it = enemiesWithinRadius.begin();
        while (it != enemiesWithinRadius.end()) {
          (*it)->takeDamage(this->damage());
          it++;
        }
        // Remove missile object from the vector objects_.
        health_ = 0;
        break;
      }
      // Update missile's position.
      position_.x += lastDirection_.x;
      position_.y += lastDirection_.y;
      i++;
    }

    // Is missile still on the screen?
    bool isOutHeight =
        ((this->getPosition().y >
          getGrid(game_)->Height() * getGrid(game_)->TileWidth() - 1) ||
         (this->getPosition().y < 0));
    bool isOutWidth =
        ((this->getPosition().x >
          getGrid(game_)->Width() * getGrid(game_)->TileWidth() - 1) ||
         (this->getPosition().x < 0));

    if (isOutWidth || isOutHeight) {
      // Remove missile object from the vector objects_.
      health_ = 0;
    }
  }
}