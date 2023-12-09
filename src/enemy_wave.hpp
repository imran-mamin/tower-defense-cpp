
#pragma once

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "time.hpp"
#include "weapons_and_enemies.hpp"

class EnemyWave {
 public:
  EnemyWave(const std::uint32_t durationSeconds,
            std::vector<EnemyType> enemyVector)
      : enemyIsReady_(true),
        enemyVector_(enemyVector),
        waveTimer_(durationSeconds,
                   1.0 * durationSeconds / enemyVector_.size()) {}

  EnemyWave &operator=(const EnemyWave &) { return *this; }

  void UpdateTimer();

  bool hasNext() const;
  bool isNextEnemyReady() const;
  EnemyType getNextEnemyType();

 private:
  bool enemyIsReady_;
  std::vector<EnemyType> enemyVector_;
  FiniteTimer waveTimer_;
};

class EnemyWaveError : public std::runtime_error {
 public:
  EnemyWaveError(const std::string &what) : std::runtime_error(what) {}
};
