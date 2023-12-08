#pragma once
#include "game.hpp"

const GameGrid& getGrid(Game* game) {
    return game->GetGrid();
}

void addObject(Game* game, GameObject* obj) {
    game->AddObject(obj);
}

const std::vector<Enemy*> getEnemiesWithinRadius(Game* game, const GameObject* obj) {
    // Filter vector based on type (Enemy).
    std::vector<Enemy*> enemies;

    for (GameObject* obj : game->Objects()) {
        // Attempt to cast to Enemy*
        if (Enemy* enemy = dynamic_cast<Enemy*>(obj)) {
            enemies.push_back(enemy);
        }
    }

    // Find all the enemies within the given radius.
    std::vector<Enemy*> enemiesWithinRadius;

    for (std::size_t i = 0; i < enemies.size(); i++) {
        int sqrtEq = std::pow((obj->getPosition().x - enemies.at(i)->getPosition().x), 2) + std::pow((obj->getPosition().y - enemies.at(i)->getPosition().y), 2);
        double distance = std::sqrt(static_cast<double>(sqrtEq));

        if (obj->radius_ >= distance) {
            enemiesWithinRadius.push_back(enemies.at(i));
        }
    }

    return enemiesWithinRadius;
}

