
#pragma once

#include <cstdint>
#include <iostream>
#include <queue>
#include <stdexcept>
#include <vector>

#include "time.hpp"
#include "weapons_and_enemies.hpp"

class EnemyWave {
 public:
  EnemyWave(const std::uint32_t durationSeconds,
            std::vector<EnemyType> enemyVector)
      : enemyIsReady_(true),
        waveTimer_(durationSeconds, 1.0 * durationSeconds / enemyVector.size())
		{
			for (EnemyType e : enemyVector) {
				enemyQueue_.push(e);
			}
		}

  //EnemyWave &operator=(const EnemyWave &) { return *this; }

  void UpdateTimer();

  bool hasEnemy() const;
  bool isNextEnemyReady() const;
  EnemyType getNextEnemyType();

 private:
  bool enemyIsReady_;
  std::queue<EnemyType> enemyQueue_;
  FiniteTimer waveTimer_;
};

class EnemyWaveError : public std::runtime_error {
 public:
  EnemyWaveError(const std::string &what) : std::runtime_error(what) {}
};
