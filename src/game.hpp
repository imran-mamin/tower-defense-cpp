#pragma once
#include <vector>

#include "gamegrid.hpp"
// #include "gameobject.hpp"

class GameObject;  // Forward declaration

class Game {
 public:
  Game(const GameGrid& grid);
  Game(const GameGrid& grid, int level);
  ~Game();

  void Update();

  void AddObject(GameObject* obj);
  void DeleteObject(GameObject* obj);

  const std::vector<GameObject*>& Objects();
  GameGrid& GetGrid();
  int GetLevel();

 protected:
  friend class GameObject;
  int level_;
  GameGrid grid_;
  std::size_t enemyMoney_;
  std::size_t playerMoney_;
  std::vector<GameObject*> objects_;
};
