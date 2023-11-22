
#pragma once

#include "game.hpp"

enum class GameEndStatus { Lost, Won };

class GameLoop {
   public:
    GameLoop(const Game &game);

    GameEndStatus Play();

   private:
	// TODO: Create renderers for the level.

    const Game &game_;
};

