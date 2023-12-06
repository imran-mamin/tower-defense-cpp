#include "game.hpp"

#include "gameobject.hpp"
#include <cstdint>

Game::Game(const GameGrid& grid) : level_(0), grid_(grid){};

Game::Game(const GameGrid& grid, int level, MapInfo mapInfo)
    : level_(level), grid_(grid) {
  //enemyMoney_ = mapInfo.enemyStartCash;
  playerMoney_ = mapInfo.playerStartCash;
};

Game::~Game() {
  for (auto gameObject : objects_) {
    delete gameObject;
  }
}

void Game::Update() {
  /* Update the game objects. */
  for (auto gameObject : objects_) {
    gameObject->update();
  }

  /* Remove any dead game object. */
  for (auto it = objects_.begin(); it != objects_.end(); it++) {
    if ((*it)->Health() == 0) {
      delete *it;
      objects_.erase(it);
    }
  }
}

const std::vector<GameObject*>& Game::Objects() { return objects_; }

void Game::AddObject(GameObject* obj) { objects_.push_back(obj); };

GameGrid& Game::GetGrid() { return grid_; }

int Game::GetLevel() { return level_; }

const std::uint32_t &Game::PlayerMoney() const { return playerMoney_; }
