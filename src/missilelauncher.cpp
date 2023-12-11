#include "missilelauncher.hpp"

#include <assert.h>

#include "utility_func_game.hpp"

void MissileLauncher::fire() {
  assert(!this->getEnemiesWithinRadius().empty());
  Enemy* e = this->getEnemiesWithinRadius().at(0);

  // Missile(Game& game, int travel_speed, int damage, int radius, Enemy target,
  // Pos position, double exp_radius = 0) Create a missile object.
  Pos p = this->getPosition();
  p.x += 32;
  p.y += 32;

  // Add missile to vector.
  addObject(game_, new Missile(game_, 4, 200, 30, e, p, 192));

  // Find the rotation angle of the missilelauncher.
  // Unit vector pointing to North according to the picture.
  Pos unitVecN = Pos{0, -1};
  Pos MToEVec = Pos{(e->getPosition().x - position_.x),
                    (e->getPosition().y - position_.y)};

  float MToEVecLen = sqrt(std::pow(MToEVec.x, 2) + std::pow(MToEVec.y, 2));
  // Find dot product of vectors.
  float dotP = unitVecN.y * MToEVec.y;
  float angleInRad = std::acos(dotP / MToEVecLen);
  float angleInDeg = angleInRad * (180.0 / M_PI);

  // Is the enemy on the left side of the missilelauncher?
  bool onTheLeft = (e->getPosition().x <= position_.x);

  if (onTheLeft) {
    this->SetAngle(360.0 - angleInDeg);
  } else {
    this->SetAngle(angleInDeg);
  }
}

void MissileLauncher::update() {
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

int MissileLauncher::sell() {
  int p = this->price_;
  this->onDestroy();
  return p;
}

void MissileLauncher::onDestroy() {}
