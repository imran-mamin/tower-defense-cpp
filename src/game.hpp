#include <vector>

#include "gamegrid.hpp"
#include "gameobject.hpp"

class Game {
 public:
  Game(const GameGrid& grid);

  void AddObject(GameObject obj);

  std::vector<GameObject> Objects() const;

  GameGrid& GetGrid();

 protected:
  std::size_t playerMoney_;
  std::size_t enemyMoney_;
  GameGrid grid_;
  std::vector<GameObject> objects_;
};