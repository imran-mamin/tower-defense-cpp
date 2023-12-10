#include "utility_func_game.hpp"
#include "game.hpp"

const GameGrid* getGrid(Game* game) {
    return &game->GetGrid();
}

void addObject(Game* game, GameObject* obj) {
    game->AddObject(obj);
}

const std::vector<GameObject*> getObjects(Game* game) {
    return game->Objects();
}

void setGameOver(Game* game) {
    game->setOver();
    game->Update();
}

