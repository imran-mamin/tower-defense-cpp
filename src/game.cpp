#include "game.hpp"

#include "gameobject.hpp"

Game::Game(const GameGrid& grid) : level_(0), grid_(grid){};

Game::Game(const GameGrid& grid, int level, MapInfo mapInfo)
    : level_(level), grid_(grid) {
  enemyMoney_ = mapInfo.enemyStartCash;
  playerMoney_ = mapInfo.playerStartCash;
};

Game::~Game() {
  for (auto gameObject : objects_) {
    delete gameObject;
  }
}

void Game::Update() {
  /* Update the game objects. */
  int i = 0;
  while (i < objects_.size()) {
    objects_.at(i)->update();
    i++;
  }

  std::cout << "Bullet Pos = (" << objects_.at(2)->getPosition().x << ", " << objects_.at(2)->getPosition().y << ")" << std::endl;
  /* Remove any dead game object. */
  auto it = objects_.begin();
  while (it != objects_.end()) {
    if ((*it)->Health() == 0) {
      delete *it;
      objects_.erase(it);
      continue;
    }
    it++;
  }
}

const std::vector<GameObject*>& Game::Objects() { return objects_; }

void Game::AddObject(GameObject* obj) { objects_.push_back(obj); };

GameGrid& Game::GetGrid() { return grid_; }

int Game::GetLevel() { return level_; }

int Game::GetPlayerMoney() { return static_cast<int>(playerMoney_); }
