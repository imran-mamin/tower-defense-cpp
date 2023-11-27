#include "game.hpp"
#include "gameobject.hpp"

Game::Game(const GameGrid& grid) : grid_(grid){};

const std::vector<GameObject*>& Game::Objects() { return objects_; }

void Game::AddObject(GameObject* obj) { objects_.push_back(obj); };

void Game::DeleteObject(GameObject* obj) {
    auto it = this->objects_.begin();

    while (it != this->objects_.end()) {
        if ((*it) == obj) {
            this->objects_.erase(it);
            break;
        }
        it++;
    }
}

GameGrid& Game::GetGrid() { return grid_; }

