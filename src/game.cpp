#include "game.hpp"
#include "gameobject.hpp"

Game::Game(const GameGrid& grid) : grid_(grid){};

const std::vector<GameObject*>& Game::Objects() { return objects_; }

void Game::AddObject(GameObject* obj) { objects_.push_back(obj); };

void Game::DeleteObject(GameObject* obj) {
    // TODO: Implement this method
}

GameGrid& Game::GetGrid() { return grid_; }

