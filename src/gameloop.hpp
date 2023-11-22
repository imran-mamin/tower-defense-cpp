
#pragma once

#include "game.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

enum class GameEndStatus { Lost, Won };

class GameLoop {
   public:
    GameLoop(sf::RenderWindow &window, Game &game) : window_(window), game_(game) {}

    GameEndStatus Play();

   private:
	sf::RenderWindow &window_;
    Game &game_;
};

