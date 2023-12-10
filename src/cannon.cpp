#include "cannon.hpp"

#include <assert.h>

#include <cstddef>

#include "bullet.hpp"
#include "utility_func_game.hpp"

void Cannon::fire() {
  assert(this->getEnemiesWithinRadius().size() > 0);
  Enemy* e = this->getEnemiesWithinRadius().at(0);
  int bulletSpeed = 160;
  int radius = 16;

  // Initialize unit vector pointing to north (e.g. 0i - 1j).
  Pos unitVecN = Pos{0, -1};
  // Initialize vector pointing to enemy from current position.
  Pos vecToEnemy =
      Pos{e->getPosition().x - position_.x, e->getPosition().y - position_.y};
  float vecToEnemyLen =
      sqrt(vecToEnemy.x * vecToEnemy.x + vecToEnemy.y * vecToEnemy.y);
  // Find unit vector of vecToEnemy.
  Pos unitVecToEnemy =
      Pos{vecToEnemy.x / vecToEnemyLen, vecToEnemy.y / vecToEnemyLen};
  // Find dot product of unitVecToEnemy and unitVecN.
  float dotP = unitVecN.x * unitVecToEnemy.x + unitVecN.y * unitVecToEnemy.y;
  assert(fabs(dotP) <= 1);
  // Calculate the rotation angle.
  float angleInRad = std::acos(dotP);
  float angleInDeg = angleInRad * (180.0 / M_PI);
  bool enemyOnTheLeftSide = (e->getPosition().x < position_.x);
  if (enemyOnTheLeftSide) {
    this->SetAngle(360.0 - angleInDeg);
  } else {
    this->SetAngle(angleInDeg);
  }

  // Bullet(Game& game, int travel_speed, int damage, int radius, Pos position,
  // Pos endPos)
  addObject(game_, new Bullet(game_, bulletSpeed, 6, radius, position_,
                              e->getPosition()));
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
  // Destroy the object, when it's sold out.
  this->onDestroy();
  return p;
}

void Cannon::onDestroy() {}
