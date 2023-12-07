#pragma once
#include <vector>
#include <iostream>

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
  int GetPlayerMoney();

 protected:
  friend class GameObject;
  int level_;
  GameGrid grid_;
  int enemyMoney_;
  int playerMoney_;
  std::vector<GameObject*> objects_;
};
