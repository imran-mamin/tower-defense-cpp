
#include "map_tile_selector_renderer.hpp"
#include "texture_manager.hpp"
#include "tile.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>

#include <cstdint>
#include <iterator>

const sf::Color selectorColor = sf::Color(0x80, 0x80, 0x80, 0x80);
const sf::Color selectorColorGreen = sf::Color(0x00, 0xff, 0x00, 0x80);
const sf::Color selectorColorRed = sf::Color(0xff, 0x00, 0x00, 0x80);
const sf::Color selectorPressedColor = sf::Color(0x80, 0x80, 0x80, 0xc0);
const sf::Color selectorPressedColorGreen = sf::Color(0x00, 0xff, 0x00, 0xc0);
const sf::Color selectorPressedColorRed = sf::Color(0xff, 0x00, 0x00, 0xc0);

MapTileSelectorRenderer::MapTileSelectorRenderer(sf::RenderWindow &renderWindow, GameGrid &gameGrid, TextureManager &textureManager, std::optional<std::uint16_t> &selectedTower)
    : Renderer(renderWindow), gameGrid_(gameGrid), textureManager_(textureManager), selectedTower_(selectedTower) {
		/* Create the selector rectangle. */
		selectorRect_ = sf::RectangleShape(sf::Vector2f(gameGrid_.TileWidth(), gameGrid_.TileWidth()));
		selectorRect_.setFillColor(selectorColor);
		selectorRect_.setPosition(0, 0);
	
		/* Load all the sprites. */
		towerSprites_[248] = sf::Sprite(textureManager.GetTexture(248)); /* Green cannon. */
		towerSprites_[249] = sf::Sprite(textureManager.GetTexture(249)); /* Red cannon. */
		towerSprites_[205] = sf::Sprite(textureManager.GetTexture(205)); /* Missile launcher 1. */
		towerSprites_[204] = sf::Sprite(textureManager.GetTexture(204)); /* Missile launcher 2. */
		towerSprites_[203] = sf::Sprite(textureManager.GetTexture(203)); /* Missile launcher 3. */

		/* Set the selected sprites opaque. */
		for (auto s : towerSprites_) {
			s.second.setColor(sf::Color(0xff, 0xff, 0xff, 0x40));
		}
	}

void MapTileSelectorRenderer::Draw() {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(renderWindow_);

	/* Tilewise positions. */
	int yPos = mousePosition.y / gameGrid_.TileWidth();
	int xPos = mousePosition.x / gameGrid_.TileWidth();
	
	/* TODO: Check also starting position. Because a menu could be spawned somewhere else. */
	
	/* Check whether we are inside the game grid area. */
	if (mousePosition.x >= 0 && mousePosition.y >= 0 && (std::uint32_t) xPos <= gameGrid_.Width() && (std::uint32_t) yPos <= gameGrid_.Height()) {
		Tile &selectedTile = gameGrid_.TileAtCoordinate(xPos, yPos);
		
		selectorRect_.setPosition(xPos * gameGrid_.TileWidth(), yPos * gameGrid_.TileWidth());

		if (selectedTower_.has_value()) {
			/* Draw the tile selector rectangle. */
			/* Are we trying to place the selected item on a path or on a nonempty tile? */
			if (selectedTile.isEmpty() && selectedTile.type() == TileType::Ground) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
					selectorRect_.setFillColor(selectorPressedColorGreen);
				}
				else {
					selectorRect_.setFillColor(selectorColorGreen);
				}
			}
			else {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
					selectorRect_.setFillColor(selectorPressedColorRed);
				}
				else {
					selectorRect_.setFillColor(selectorColorRed);
				}
			}
			renderWindow_.draw(selectorRect_);

			std::uint16_t value = selectedTower_.value();
			/* Ignore all the unknown weapon types not specified in the towerSprites_ mapping. */
			if (towerSprites_.count(value) != 0) {
				towerSprites_[value].setPosition(xPos * gameGrid_.TileWidth(), yPos * gameGrid_.TileWidth());
				renderWindow_.draw(towerSprites_[value]);
			}
		}
		else {
			/* Draw the tile selector rectangle. */
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				selectorRect_.setFillColor(selectorPressedColor);
			}
			else {
				selectorRect_.setFillColor(selectorColor);
			}

			renderWindow_.draw(selectorRect_);
		}

		
	}
}

