#include "game.hpp"

#include <cstddef>
#include <cstdint>

#include "gamegrid.hpp"
#include "gameobject.hpp"

Game::Game(const GameGrid &grid) : grid_(grid), level_(0) {}

Game::Game(const GameGrid &grid, std::uint32_t level, MapInfo mapInfo)
    : level_(level), grid_(grid), playerMoney_(mapInfo.playerStartCash), enemyWaves_(mapInfo.enemyWaves) {
};

Game::~Game() {
  for (auto gameObject : objects_) {
    delete gameObject;
  }
}

void Game::Update() {
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
		}
		else {
			it++;
		}
	}
}

const std::vector<GameObject*>& Game::Objects() { return objects_; }

void Game::AddObject(GameObject* obj) { objects_.push_back(obj); };

GameGrid& Game::GetGrid() { return grid_; }

int Game::GetLevel() { return level_; }

const std::uint64_t& Game::PlayerMoney() const { return playerMoney_; }
