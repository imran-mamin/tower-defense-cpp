#include "game.hpp"

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <queue>
#include <stdexcept>
#include <vector>

#include "attackplane.hpp"
#include "enemy.hpp"
#include "enemy_wave.hpp"
#include "footsoldier.hpp"
#include "gamegrid.hpp"
#include "gameobject.hpp"
#include "tank.hpp"
#include "weapons_and_enemies.hpp"

/* Helper. */
bool Game::HasEnemiesOnCurrentWave() const {
	for (const GameObject *gameObject : objects_) {
		if (dynamic_cast<const Enemy *>(gameObject)) {
			return true;
		}
	}

	return false;
}

void Game::NextEnemyWave() {
    try {
		currentEnemyWave_ = enemyWaves_.front();
		enemyWaves_.pop();
		currentEnemyWaveNumber_++;
    } catch (const std::out_of_range&) {
		throw std::runtime_error("No more enemy waves available.");
    }
}

Game::Game(const GameGrid& grid, std::uint32_t level, MapInfo mapInfo)
    : grid_(grid),
      level_(level),
      playerMoney_(mapInfo.playerStartCash),
      enemyWaves_(mapInfo.enemyWaves),
      currentEnemyWave_(enemyWaves_.front()) {
		  enemyWaves_.pop();
	  }

Game::~Game() {
    for (auto gameObject : objects_) {
	    delete gameObject;
    }
}

void Game::Update() {
  if (!gameOver) {
	  /* Try to get an enemy from the wave and update the enemy wave. */

    // Reaching last waves and no enemy left.
    if (!currentEnemyWave_.hasEnemy() && !HasEnemiesOnCurrentWave()) {
      if (hasNextWave()) {
        NextEnemyWave();
      }
      else {
        gameOver = true;
        gameWon = true;
      }
    }

    if (currentEnemyWave_.hasEnemy() && currentEnemyWave_.isNextEnemyReady()) {
      EnemyType enemyType = currentEnemyWave_.getNextEnemyType();
      switch (enemyType) {
        case EnemyType::Soldier1:
          objects_.insert(objects_.begin(), new Soldier1(this, grid_.EnemyPath().at(0).a));
          break;
        case EnemyType::Soldier2:
          objects_.insert(objects_.begin(), new Soldier2(this, grid_.EnemyPath().at(0).a));
          break;
        case EnemyType::Soldier3:
          objects_.insert(objects_.begin(), new Soldier3(this, grid_.EnemyPath().at(0).a));
          break;
        case EnemyType::Soldier4:
          objects_.insert(objects_.begin(), new Soldier4(this, grid_.EnemyPath().at(0).a));
          break;
        case EnemyType::Tank1:
          objects_.insert(objects_.begin(), new Tank1(this, grid_.EnemyPath().at(0).a));
          break;
        case EnemyType::Tank2:
          objects_.insert(objects_.begin(), new Tank2(this, grid_.EnemyPath().at(0).a));
          break;
        case EnemyType::Plane1:
          objects_.insert(objects_.begin(), new Plane1(this, grid_.EnemyPath().at(0).a));
          break;
        case EnemyType::Plane2:
          objects_.insert(objects_.begin(), new Plane2(this, grid_.EnemyPath().at(0).a));
          break;
        default:
          throw std::runtime_error("Unknown enemy type.");
          break;
      }
    }

    /* Update the game objects. */
    for (std::size_t i = 0; i < objects_.size(); i++) {
        objects_.at(i)->update();

        /* Remove any dead game objects. */
        auto it = objects_.begin();
        while (it != objects_.end()) {
          if ((*it)->Health() == 0) {
              /* Give the player cash for the kill. */
              if (const Enemy* enemy = dynamic_cast<const Enemy*>(*it); enemy) {
                playerMoney_ += enemy->Value();
              }

              delete *it;
              it = objects_.erase(it);
          } else {
              it++;
          }
        }
    }
	
		currentEnemyWave_.UpdateTimer();
  } else {
    // TODO: This is for game over.
    assert(false);
  }
}

const std::vector<GameObject*>& Game::Objects() { return objects_; }

void Game::AddObject(GameObject* obj) { objects_.push_back(obj); };

GameGrid& Game::GetGrid() { return grid_; }

int Game::GetLevel() { return level_; }

const std::uint64_t& Game::PlayerMoney() const { return playerMoney_; }
