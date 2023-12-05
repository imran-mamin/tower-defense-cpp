
#include "gamegrid.hpp"

#include <SFML/Graphics.hpp>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <exception>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>

#include "map_parser.hpp"
#include "path.hpp"
#include "tile.hpp"
#include "vec2d.hpp"

/* Create the gamegrid. */
GameGrid::GameGrid(const MapInfo &mapInfo) : enemyPath_(mapInfo.enemyPath) {
    width_ = mapInfo.mapWidth;
    height_ = mapInfo.mapHeight;
    tileWidth_ = mapInfo.tileWidth;

	// TODO: Check the enemyPath correctness. It HAS to be at a multiple of the tile size (between two tiles).
	// Throw an error if this isn't the case.

	for (auto row : mapInfo.backgroundTiles) {
	    std::vector<Tile> v;
	    for (auto tileId : row) {
		// FIXME: add correct tile types, currently there are no checks
		// paths or water.
			v.push_back(Tile(TileType::Ground, tileId));
	    }
	    tiles_.push_back(v);
	}

	/* Resolve the path tiles from the enemyPath. */
	for (auto path : mapInfo.enemyPath) {
		/* Horizontal line. */
		if (path.a.y == path.b.y && path.a.x != path.b.x) {
			const std::uint32_t smallerX = path.a.x < path.b.x ? path.a.x : path.b.x;
			const std::uint32_t largerX = smallerX == path.a.x ? path.b.x : path.a.x;

			std::uint32_t tileStartX = smallerX > 0 ? smallerX - tileWidth_ : smallerX;
			for (; tileStartX <= largerX && tileStartX < width_ * tileWidth_; tileStartX += tileWidth_) {
				if (tileStartX < tileWidth_ * width_) {
					/* Note: a.y & b.y are the same. */
					const std::uint32_t currentY = path.a.y;

					if (currentY != 0) {
						TileAtAbsoluteCoordinate(tileStartX, currentY - 1).SetType(TileType::Path);
					}
					TileAtAbsoluteCoordinate(tileStartX, currentY).SetType(TileType::Path);
				}
			}
		}
		/* Vertical line. */
		else if (path.a.x == path.b.x && path.a.y != path.b.y) {
			const std::uint32_t smallerY = path.a.y < path.b.y ? path.a.y : path.b.y;
			const std::uint32_t largerY = smallerY == path.a.y ? path.b.y : path.a.y;

			std::uint32_t tileStartY = smallerY > 0 ? smallerY - tileWidth_ : smallerY;
			for (; tileStartY <= largerY && tileStartY < height_ * tileWidth_; tileStartY += mapInfo.tileWidth) {
				if (tileStartY < tileWidth_ * height_) {
					/* Note: a.x & b.x are the same. */
					const std::uint32_t currentX = path.a.x;
					
					if (currentX != 0) {
						TileAtAbsoluteCoordinate(currentX - 1, tileStartY).SetType(TileType::Path);
					}
					TileAtAbsoluteCoordinate(currentX, tileStartY).SetType(TileType::Path);
				}
			}
		}
		else {
			throw std::runtime_error("Diagonal enemyPath lines are not currently supported.");
		}
	}
}

/* Helper method. */
Pos GameGrid::AbsoluteCoordinateToClosestTilePosition(std::uint32_t x, std::uint32_t y) {
	/* Note: Without these intermediate steps the compiler will optimize the division plus multiplication operations out. */
	x = x / tileWidth_ * tileWidth_;
	y = y / tileWidth_ * tileWidth_;
	return Pos{ (float) x, (float) y };
}

Tile &GameGrid::TileAtAbsoluteCoordinate(std::uint32_t x, std::uint32_t y) {
	if (x > tileWidth_ * width_ || y > tileWidth_ * height_) {
		throw std::runtime_error(std::string("Coordinate (") + std::to_string(x) + ", " + std::to_string(y) + ") is out of bounds!");
	}
	return tiles_[y / tileWidth_][x / tileWidth_];
}

Tile &GameGrid::TileAtCoordinate(std::uint8_t x, std::uint8_t y) {
    return tiles_[y][x];
}
