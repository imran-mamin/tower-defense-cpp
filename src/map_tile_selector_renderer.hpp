
#pragma once

#include "gamegrid.hpp"
#include "renderer.hpp"

#include <SFML/Graphics.hpp>

/*
 * Level specific map tile selector renderer.
 * Obviously needs to be recreated for another level.
 */
class MapTileSelectorRenderer : public Renderer {
   public:
	MapTileSelectorRenderer(sf::RenderWindow &renderWindow, GameGrid &gameGrid);
	~MapTileSelectorRenderer() = default;

	void Draw() override;
   private:
	GameGrid &gameGrid_;
	sf::RectangleShape selectorRect_;
};

