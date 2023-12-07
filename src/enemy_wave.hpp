
#pragma once

#include <cstdint>
#include <stdexcept>
#include <vector>

#include "time.hpp"
#include "weapons_and_enemies.hpp"

class EnemyWave {
   public:
    EnemyWave(const std::uint32_t durationSeconds, std::vector<EnemyType> enemyVector)
	: enemyVector_(enemyVector), waveTimer_(durationSeconds, 1.0 * durationSeconds / enemyVector_.size(), [&](float){enemyIsReady_ = true;}, [&](){}), enemyIsReady_(true) {}

	void UpdateTimer() { waveTimer_.Update(); }

    bool hasNext() const;
	bool isNextEnemyReady() const;
    EnemyType getNextEnemyType();

   private:
    std::vector<EnemyType> enemyVector_;

	FiniteTimer waveTimer_;
	bool enemyIsReady_;
};

class EnemyWaveError : public std::runtime_error {
   public:
    EnemyWaveError(const std::string &what) : std::runtime_error(what) {}
};

