#include "game.hpp"

Game::Game(const GameGrid& grid) : grid_(grid){};

std::vector<GameObject> Game::Objects() const { return objects_; }

void Game::AddObject(GameObject obj) { objects_.push_back(obj); };

GameGrid& Game::GetGrid() { return grid_; }

