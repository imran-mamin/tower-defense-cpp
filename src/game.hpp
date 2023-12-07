#pragma once
#include <cstdint>
#include <vector>

#include "gamegrid.hpp"
// #include "gameobject.hpp"

class GameObject;  // Forward declaration

class Game {
 public:
  Game(const GameGrid& grid);
  Game(const GameGrid& grid, int level, MapInfo mapInfo);
  ~Game();

  void Update();

  void AddObject(GameObject* obj);
  void DeleteObject(GameObject* obj);

  const std::vector<GameObject*>& Objects();
  GameGrid& GetGrid();
  int GetLevel();

  /* Operations for money. */
  const std::uint64_t &PlayerMoney() const;
  void AddMoney(std::uint32_t money) { playerMoney_ += money; }
  void RemoveMoney(std::uint32_t money) { playerMoney_ -= money <= playerMoney_ ? money : playerMoney_; }

 protected:
  friend class GameObject;
  int level_;
  GameGrid grid_;
  //int enemyMoney_;
  std::uint64_t playerMoney_;
  std::vector<GameObject*> objects_;
};
