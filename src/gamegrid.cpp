
#include "gamegrid.hpp"

#include <SFML/Graphics.hpp>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <exception>
#include <stdexcept>
#include <string>
#include <vector>

#include "map_parser.hpp"
#include "path.hpp"
#include "tile.hpp"

/* Create the gamegrid. */
GameGrid::GameGrid(const MapInfo &mapInfo) {
  width_ = mapInfo.mapWidth;
  height_ = mapInfo.mapHeight;
  tileWidth_ = mapInfo.tileWidth;
  // enemyPath_ = mapInfo.enemyPath;

  for (auto row : mapInfo.backgroundTiles) {
    std::vector<Tile> v;
    for (auto tileId : row) {
      // FIXME: add correct tile types, currently there are no checks paths or
      // water.
      v.push_back(Tile(TileType::Ground, tileId));
    }
    tiles_.push_back(v);
  }
}
