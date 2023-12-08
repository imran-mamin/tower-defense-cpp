#include "game.hpp"

#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <vector>

#include "enemy_wave.hpp"
#include "gamegrid.hpp"
#include "gameobject.hpp"
#include "weapons_and_enemies.hpp"

/* Helper. */
EnemyWave GetFirstEnemyWaveFromTheList(std::vector<EnemyWave> &enemyWaves) {
	try {
		EnemyWave e = enemyWaves.at(0);
		enemyWaves.erase(enemyWaves.begin());
		return e;
	}
	catch (const std::out_of_range &) {
		throw std::runtime_error("No more enemy waves available.");
	}
}

Game::Game(const GameGrid& grid, std::uint32_t level, MapInfo mapInfo)
    : grid_(grid),
	  level_(level),
      playerMoney_(mapInfo.playerStartCash),
      enemyWaves_(mapInfo.enemyWaves),
	  currentEnemyWave_(GetFirstEnemyWaveFromTheList(enemyWaves_)) {};

Game::~Game() {
    for (auto gameObject : objects_) {
	delete gameObject;
    }
}

void Game::Update() {
	/* Try to get an enemy from the wave and update the enemy wave. */
	if (!currentEnemyWave_.hasNext() && !gameWon) {
		if (enemyWaves_.empty()) {
			gameWon = true;
		}
		else {
			currentEnemyWave_ = GetFirstEnemyWaveFromTheList(enemyWaves_);
		}
	}
	else if (currentEnemyWave_.isNextEnemyReady()) {
		// TODO: Add enemies to the list of gameobjects.
		EnemyType enemyType = currentEnemyWave_.getNextEnemyType();
		switch (enemyType) {
			case EnemyType::Soldier1:
			// AddObject(new Soldier1(*this, grid_.EnemyPath().at(0).a));
			break;
			case EnemyType::Soldier2:
			break;
			case EnemyType::Soldier3:
			break;
			case EnemyType::Soldier4:
			break;
			case EnemyType::Tank1:
			break;
			case EnemyType::Tank2:
			break;
			case EnemyType::Plane1:
			break;
			case EnemyType::Plane2:
			break;
			default:
				throw std::runtime_error("Unknown enemy type.");
			break;
		}
	}

	if (!gameWon && !gameOver) {
		currentEnemyWave_.UpdateTimer();
	}

    /* Update the game objects. */
    for (std::size_t i = 0; i < objects_.size(); i++) {
		objects_.at(i)->update();
    }

    /* Remove any dead game objects. */
    auto it = objects_.begin();
    	while (it != objects_.end()) {
		if ((*it)->Health() == 0) {
	   		delete *it;
			 it = objects_.erase(it);
		} else {

		it++;
		}
    }
}

const std::vector<GameObject*>& Game::Objects() { return objects_; }

void Game::AddObject(GameObject* obj) { objects_.push_back(obj); };

GameGrid& Game::GetGrid() { return grid_; }

int Game::GetLevel() { return level_; }

const std::uint64_t& Game::PlayerMoney() const { return playerMoney_; }
