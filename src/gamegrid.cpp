
#include "gamegrid.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Joystick.hpp>
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

	// TODO: Load the tiles.
//	for (auto row : mapInfo.backgroundTiles) {
//		for (auto tileId: row) {
//			// TODO: Add tiles.
//			tiles_.push_back(Tile(/* TODO: Tile should contain the id and the type. */);
//		}
//		tiles_.push_back(row);
//	}
}


