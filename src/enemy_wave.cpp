
#include "enemy_wave.hpp"

#include <stdexcept>

void EnemyWave::UpdateTimer() {
  if (waveTimer_.Update()) {
    enemyIsReady_ = true;
  }
}

bool EnemyWave::hasEnemy() const { return enemyQueue_.size() != 0; }

bool EnemyWave::isNextEnemyReady() const { return enemyIsReady_; }

EnemyType EnemyWave::getNextEnemyType() {
  if (enemyQueue_.size() == 0) {
    throw EnemyWaveError(
        "Enemy wave finished already thus no next enemies available.");
  }
  if (!enemyIsReady_) {
    throw EnemyWaveError("Next enemy is not ready yet.");
  }

  try {
    /* Remove the current enemy from the queue. */
    EnemyType e = enemyQueue_.front();
	enemyQueue_.pop();
    enemyIsReady_ = false;

    return e;
  } catch (const std::out_of_range &e) {
    throw EnemyWaveError("No more enemies available.");
  }
}

