#pragma once
#include <vector>

#include "gamegrid.hpp"
// #include "gameobject.hpp"

class GameObject;  // Forward declaration

class Game {
 public:
  Game(const GameGrid& grid);

  void AddObject(GameObject* obj);

  const std::vector<GameObject*>& Objects();
  GameGrid& GetGrid();
  
protected:
    friend class GameObject;
    std::size_t playerMoney_;
    std::size_t enemyMoney_;
    GameGrid grid_;
    std::vector<GameObject*> objects_;
};

