
/* Note: this class is for debugging purposes. */

#pragma once

#include "renderer.hpp"
#include "gamegrid.hpp"

class EnemyPathRenderer : public Renderer {
   public:
	EnemyPathRenderer(sf::RenderWindow &renderWindow, GameGrid &gameGrid) : Renderer(renderWindow), gameGrid_(gameGrid) {}
	~EnemyPathRenderer() = default;

	void Draw() override;

   private:
	GameGrid &gameGrid_;
};

