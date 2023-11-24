
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
	// TODO:
	for (auto path : mapInfo.enemyPath) {
		/* Horizontal line. */
		if (path.a.y == path.b.y && path.a.x != path.b.x) {
			// TODO: Check a.x > b.x
			for (auto tileStartX = path.a.x; tileStartX < path.b.x; tileStartX += mapInfo.tileWidth) {
				std::cout << tileStartX << std::endl;
				if (tileStartX < tileWidth_ * width_ && tileStartX >= 0) {
					if (path.a.y != 0) {
						std::cout << "path set" << std::endl;
						TileAtAbsoluteCoordinate(tileStartX, path.a.y - 1).SetType(TileType::Path);
					}
					TileAtAbsoluteCoordinate(tileStartX, path.a.y).SetType(TileType::Path);
				}
			}
		}
		/* Vertical line. */
		else if (path.a.x == path.b.x && path.a.y != path.b.y) {
			/* FIXME: path.a.y is arbitrary, where are the bounds checks? Same goes without saying for the above too. */
			for (auto tileStartY = path.a.y; tileStartY < path.a.y; tileStartY += mapInfo.tileWidth) {
				if (tileStartY < tileWidth_ * height_ && tileStartY >= 0) {
					if (path.a.x != 0) {
						TileAtAbsoluteCoordinate(path.a.x - 1, tileStartY).SetType(TileType::Path);
					}
					TileAtAbsoluteCoordinate(path.a.x, tileStartY).SetType(TileType::Path);
				}
			}
		}
		else {
			/* TODO: Better exception type. */
			throw std::runtime_error("Diagonal enemyPath lines are not currently supported.");
		}
	}
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
