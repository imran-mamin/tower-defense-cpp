#include "gameobject.hpp"
#include "gamegrid.hpp"
#include <vector>

class Game {
public:
    Game(GameGrid grid);

    void AddObject(GameObject obj);

protected:
    std::size_t playerMoney_;
    std::size_t enemyMoney_;
    GameGrid grid_;
    std::vector<GameObject> objects_;
};