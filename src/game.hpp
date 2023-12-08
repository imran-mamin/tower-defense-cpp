#pragma once
#include <cstdint>
#include <vector>
#include <iostream>

#include "enemy_wave.hpp"
#include "gamegrid.hpp"
#include "footsoldier.hpp"
#include "gameobject.hpp"

class Game {
 public:
  Game(const GameGrid &grid, std::uint32_t level, MapInfo mapInfo);
  ~Game();

  void Update();

  void AddObject(GameObject* obj);
  void DeleteObject(GameObject* obj);

  const std::vector<GameObject*>& Objects();
  GameGrid& GetGrid();
  int GetLevel();

  /* Operations for money. */
  const std::uint64_t& PlayerMoney() const;
  void AddMoney(std::uint32_t money) { playerMoney_ += money; }
  void RemoveMoney(std::uint32_t money) {
    playerMoney_ -= money <= playerMoney_ ? money : playerMoney_;
  }

 private:
  bool gameOver = false;
  bool gameWon = false;
  GameGrid grid_;
  std::uint32_t level_;
  std::uint64_t playerMoney_;
  std::vector<GameObject*> objects_;
  std::vector<EnemyWave> enemyWaves_;
  EnemyWave currentEnemyWave_;

};
