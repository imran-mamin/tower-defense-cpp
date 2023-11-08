
#pragma once

#include <cstdint>
#include <map>
#include <string>
#include <tuple>
#include <vector>

#include <SFML/Graphics.hpp>

#include "map_parser.hpp"
#include "tile.hpp"

class GameGrid {
   public:
	/* Create a new GameGrid object from map file. */
    GameGrid(const MapInfo &mapInfo);
	GameGrid(const std::string& path);
	GameGrid() = delete;

	Tile &TileAtCoordinate(std::uint8_t x, std::uint8_t y) const;

	void Draw(const sf::RenderWindow& RenderWindow);

   private:
	std::vector<std::tuple<std::uint32_t>> enemyPath_;
	std::vector<sf::Texture> textures_;
	std::vector<sf::Sprite> sprites_;

	std::uint8_t tileWidth_;
	/* Vector of pairs containing tiles associated with a tile sprite. */
	//std::vector<std::vector<std::pair<Tile, const sf::Sprite&>>> backgroundTilesAndSprites_;
    std::uint32_t mapWidth_;
	std::uint32_t mapHeight_;
};

