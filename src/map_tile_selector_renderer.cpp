
#include "map_tile_selector_renderer.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>

#include <cassert>
#include <cstdint>
#include <iostream>

const sf::Color selectorColor = sf::Color(0x80, 0x80, 0x80, 0x80);
const sf::Color selectorPressedColor = sf::Color(0x80, 0x80, 0x80, 0xc0);

MapTileSelectorRenderer::MapTileSelectorRenderer(sf::RenderWindow &renderWindow, GameGrid &gameGrid)
    : Renderer(renderWindow), gameGrid_(gameGrid) {
		/* Create the selector rectangle. */
		selectorRect_ = sf::RectangleShape(sf::Vector2f(gameGrid_.TileWidth(), gameGrid_.TileWidth()));
		selectorRect_.setFillColor(selectorColor);
		selectorRect_.setPosition(0, 0);
	}

void MapTileSelectorRenderer::Draw() {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(renderWindow_);

	/* Tilewise positions. */
	int yPos = mousePosition.y / gameGrid_.TileWidth();
	int xPos = mousePosition.x / gameGrid_.TileWidth();
	
	/* TODO: Check also starting position. Because a menu could be spawned somewhere else. */
	
	/* Check whether we are inside the game grid area. */
	if (mousePosition.x >= 0 && mousePosition.y >= 0 && (std::uint32_t) xPos <= gameGrid_.Width() && (std::uint32_t) yPos <= gameGrid_.Height()) {
		/* Draw the tile selector rectangle. */
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			selectorRect_.setFillColor(selectorPressedColor);
		}
		else {
			selectorRect_.setFillColor(selectorColor);
		}
		selectorRect_.setPosition(xPos * gameGrid_.TileWidth(), yPos * gameGrid_.TileWidth());
		renderWindow_.draw(selectorRect_);
	}
}

