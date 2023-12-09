#pragma once
#include <vector>

// Forward declaration
class Game;
class GameGrid;
class GameObject;

const GameGrid* getGrid(Game* game);

const std::vector<GameObject*> getObjects(Game* game);

void addObject(Game* game, GameObject* obj);

