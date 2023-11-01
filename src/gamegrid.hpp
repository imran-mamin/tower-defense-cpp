
#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <cstdint>
#include <map>
#include <string>
#include <tuple>
#include <vector>

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "map_parser.hpp"
#include "tile.hpp"

class GameGrid {
   public:
	/* Create a new GameGrid object from map file. */
    GameGrid(const MapInfo &mapInfo);
	GameGrid() = delete;

	Tile &TileAtCoordinate(std::uint8_t x, std::uint8_t y);

	void Draw(const sf::RenderWindow& RenderWindow);

   private:
	std::vector<sf::Texture> textures_;
	std::vector<sf::Sprite> sprites_;

	std::uint8_t tileWidth_;
	std::vector<sf::Sprite>
	/* Vector of pairs containing tiles associated with a sprite. */
	std::vector<Vector<std::pair<Tile, const &sf::Sprite>>> backgroundTilesAndSprites_;
    std::uint32_t width_;
    std::uint32_t height_;
};

