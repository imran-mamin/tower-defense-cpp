#include "map_parser.hpp"

#include <cmath>
#include <cstddef>
#include <cstdint>
#include <exception>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "json.hpp"
#include "pos.hpp"
#include "vec2d.hpp"

const std::string tileWidthKey = "tile_width";
const std::string mapWidthKey = "map_width";
const std::string mapHeightKey = "map_height";
const std::string backgroundTilesKey = "background";
const std::string obstacleTilesKey = "obstacles";
const std::string enemyPathKey = "enemy_path";
const std::string playerStartCashKey = "player_start_cash";

MapInfo ParseMap(const std::string &path) {
  std::ifstream is(path);
  if (is.fail()) {
    throw MapParserError(std::string("Failed to open level map at '") + path +
                         "'.");
  }

  /* Create a parser instance. */
  nlohmann::json data = nlohmann::json::parse(is);
  try {
    std::uint8_t tileWidth;
    std::uint8_t mapWidth;
    std::uint8_t mapHeight;
    std::vector<std::vector<std::uint16_t>> backgroundTiles;
    std::vector<std::pair<u_int16_t, std::pair<u_int16_t, u_int16_t>>>
        obstacleTiles;
    std::vector<std::vector<std::vector<std::uint32_t>>> enemyPath_;
    std::uint64_t playerStartCash;

    /* Read the input. */
    data.at(tileWidthKey).get_to(tileWidth);
    data.at(mapWidthKey).get_to(mapWidth);
    data.at(mapHeightKey).get_to(mapHeight);
    data.at(backgroundTilesKey).get_to(backgroundTiles);
    data.at(obstacleTilesKey).get_to(obstacleTiles);
    data.at(enemyPathKey).get_to(enemyPath_);
    data.at(playerStartCashKey).get_to(playerStartCash);

    /* ===== Validate the input. ===== */

    /*
     * Make sure the background tile count matches the grid size and the widths
     * and heights match.
     */
    if (backgroundTiles.size() != mapHeight) {
      throw MapParserError(
          "Column-wise background tile count must be equal to the map height!");
    }
    std::size_t tileTotalCount = 0;
    for (auto row : backgroundTiles) {
      tileTotalCount += row.size();
      if (row.size() != mapWidth) {
        throw MapParserError(
            "Row-wise background tile count must be equal to the map width!");
      }
    }
    if (tileTotalCount != mapWidth * mapHeight) {
      throw MapParserError(
          "Tile count of the map must be equal to tileWidth * mapHeight!");
    }

    /*
     * Validate the enemy path vector.
     */
    if (enemyPath_.size() < 1) {
      throw MapParserError("Empty enemy path!");
    }
    for (auto vec : enemyPath_) {
      /* Check that the vectors (only) have start point (a) and the ending point
       * (b). */
      if (vec.size() != 2) {
        throw MapParserError(
            "Error in the enemy path. Each vector must have both a starting "
            "point and an ending point and nothing else.");
      }
      /* Check for each point that: that the points have only the x and y
       * values. */
      for (auto point : vec) {
        /* the point has only x and y value, */
        if (point.size() != 2) {
          throw MapParserError(
              "Error in one of the points of one of the enemy vectors. Each "
              "point must have its x and y value and nothing else.");
        }
        /* and that the point is within the level bounds. */
        if (point[0] > tileWidth * mapWidth) {
          throw MapParserError(std::string("Erroneous value for x. Value ") +
                               std::to_string(point[0]) +
                               " is not within the level bounds.");
        }
        if (point[1] > tileWidth * mapHeight) {
          throw MapParserError(std::string("Erroneous value for y. Value ") +
                               std::to_string(point[1]) +
                               " is not within the level bounds.");
        }
      }
    }
    // TODO
    /* Make sure the enemy path starts from a legal value.  */
    // if (enemyPath_[0][0][0] == 0 && enemyPath_[0][0][]) {
    //
    // }
    /* TODO: Make sure the enemy path and ends to a legal value.  */
    /* TODO: Make sure that the vectors come in order. */

    /* Convert the enemy path into the Vec2D format. */
    std::vector<Vec2D> enemyPath;
    for (auto vec : enemyPath_) {
      Pos a{(float)vec[0][0], (float)vec[0][1]};
      Pos b{(float)vec[1][0], (float)vec[1][1]};

      enemyPath.push_back(Vec2D{a, b});
    }

    return MapInfo{tileWidth,     mapWidth,  mapHeight,      backgroundTiles,
                   obstacleTiles, enemyPath, playerStartCash};
  }
  /* TODO: Catch correct exceptions: missing field and incorrect data format. */
  catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
    // TODO: Implement new exception throwing besides just rethrowing.
    throw e;
  }
}
