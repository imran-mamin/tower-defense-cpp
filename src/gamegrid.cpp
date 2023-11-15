
#include "gamegrid.hpp"

#include <SFML/Graphics.hpp>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <exception>
#include <stdexcept>
#include <string>
#include <vector>

#include "path.hpp"
#include "map_parser.hpp"
#include "tile.hpp"

/* Create the gamegrid. */
GameGrid::GameGrid(const MapInfo &mapInfo) {
    width_ = mapInfo.mapWidth;
    height_ = mapInfo.mapHeight;
    tileWidth_ = mapInfo.tileWidth;
    //enemyPath_ = mapInfo.enemyPath;

	for (auto row : mapInfo.backgroundTiles) {
        std::vector<Tile> v;
		for (auto tileId: row) {
			// FIXME: add correct tile types, currently there are no checks paths or water.
			v.push_back(Tile(TileType::Ground, tileId));
		}
		tiles_.push_back(v);
	}
}

/* Helper. */
bool GameGrid::CoordinateIsInsideGrid(std::uint32_t x, std::uint32_t y) const {
	/* Since coordinates consist from unsigned values, there is no need to check negative x and y values. */
	return x <= (width_ * tileWidth_) && y <= (height_ * tileWidth_);
}

//Tile &GameGrid::TileAtCoordinate(std::uint32_t x, std::uint32_t y) const {
//	if (!CoordinateIsInsideGrid(x, y)) {
//		throw std::runtime_error(std::string("No tile available at invalid coordinate: (") + std::to_string(x) + ", " + std::to_string(y) + ")!");
//	}
//
//	return tiles_[y / tileWidth_ + (y % tileWidth_ != 0 ? 1 : 0)][x /
//	tileWidth_ + (x % tileWidth_ != 0 ? 1 : 0)];
//}


