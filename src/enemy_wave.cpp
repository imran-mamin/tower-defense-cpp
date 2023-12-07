
#include "enemy_wave.hpp"
#include <stdexcept>


bool EnemyWave::hasNext() const {
	return enemyVector_.size() != 0;
}

bool EnemyWave::isNextEnemyReady() const {
	return enemyIsReady_;
}

EnemyType EnemyWave::getNextEnemyType() {
	if (enemyVector_.size() == 0) {
		throw EnemyWaveError("Enemy wave finished already thus no next enemies available.");
	}
	if (!enemyIsReady_) {
		throw EnemyWaveError("Next enemy is not ready yet.");
	}

	try {
		/* Remove the current enemy from the vector, erase it and return its value. */
		EnemyType e = enemyVector_.front();
		enemyVector_.erase(enemyVector_.begin());
		enemyIsReady_ = false;
		return e;
	}
	catch (const std::out_of_range &e) {
		throw EnemyWaveError("No more enemies available.");
	}
}

