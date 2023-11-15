#include "game.hpp"

Game::Game(GameGrid grid) : grid_(grid) {};

void Game::AddObject(GameObject obj) {
    objects_.push_back(obj);
    };