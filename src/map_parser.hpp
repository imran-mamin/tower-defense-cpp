
#pragma once

#include <cmath>
#include <cstdint>
#include <exception>
#include <string>
#include <tuple>
#include <vector>

#include "vec2d.hpp"

struct MapInfo {
  /* tileWidth = tileHeight */
  const std::uint8_t tileWidth;
  const std::uint8_t mapWidth;
  const std::uint8_t mapHeight;
  std::vector<std::vector<std::uint16_t>> backgroundTiles;
  std::vector<std::pair<u_int16_t, std::pair<u_int16_t, u_int16_t>>>
      obstacleTiles;
  /* Enemy path consisting from vectors. */
  std::vector<Vec2D> enemyPath;
  std::uint64_t playerStartCash;
};

class MapParserError : public std::exception {
 public:
  MapParserError(const std::string &what)
      : what_(std::string("MapParserError: ") + what) {}

  const char *what() const noexcept override { return what_.c_str(); }

 private:
  const std::string what_;
};

MapInfo ParseMap(const std::string &path);
