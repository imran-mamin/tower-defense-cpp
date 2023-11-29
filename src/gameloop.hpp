/*
#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "game.hpp"

enum class GameEndStatus { Lost, Won };

class GameLoop {
 public:
  GameLoop(sf::RenderWindow &window, Game &game)
      : window_(window), game_(game) {}

  int Play();

 private:
  sf::RenderWindow &window_;
  Game &game_;
};
*/