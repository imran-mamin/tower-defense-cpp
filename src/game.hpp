#pragma once
#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

#include "enemy_wave.hpp"
#include "gamegrid.hpp"
#include "footsoldier.hpp"
#include "tank.hpp"
#include "attackplane.hpp"
#include "gameobject.hpp"

class Game {
 public:
  Game(const GameGrid& grid, std::uint32_t level, MapInfo mapInfo);
  ~Game();

  void Update();

  void AddObject(GameObject* obj);
  void DeleteObject(GameObject* obj);

  const std::vector<GameObject*>& Objects();
  GameGrid& GetGrid();
  int GetLevel();

  std::uint32_t CurrentEnemyWaveNumber() const { return currentEnemyWaveNumber_; }

  /* Operations for money. */
  const std::uint64_t& PlayerMoney() const;
  void AddMoney(std::uint32_t money) { playerMoney_ += money; }
  void RemoveMoney(std::uint32_t money) {
    playerMoney_ -= money <= playerMoney_ ? money : playerMoney_;
  }

  bool GameOver() const { return gameOver; }
  bool GameWon() const { return gameWon; }

  void setOver() { gameOver = true; }
  
 private:
  bool gameOver = false;
  bool gameWon = false;
  GameGrid grid_;
  std::uint32_t level_;
  std::uint64_t playerMoney_;
  std::vector<GameObject*> objects_;
  std::queue<EnemyWave> enemyWaves_;

  std::uint32_t currentEnemyWaveNumber_ = 1;
  EnemyWave currentEnemyWave_;

  bool hasNextWave() const { return !enemyWaves_.empty(); }
  void NextEnemyWave();
};
