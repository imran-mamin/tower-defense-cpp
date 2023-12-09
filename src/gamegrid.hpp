
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <cstdint>
#include <map>
#include <string>
#include <tuple>
#include <vector>

#include "map_parser.hpp"
#include "tile.hpp"
#include "vec2d.hpp"

class GameGrid {
 public:
  /* Create a new GameGrid object from map file. */
  GameGrid(const MapInfo &mapInfo);
  GameGrid() = delete;

  Pos AbsoluteCoordinateToClosestTilePosition(std::uint32_t x, std::uint32_t y);

  Tile &TileAtCoordinate(std::uint8_t x, std::uint8_t y);
  Tile &TileAtAbsoluteCoordinate(std::uint32_t x, std::uint32_t y);
  std::vector<std::vector<Tile>> &Tiles() { return tiles_; }
  std::vector<std::pair<u_int16_t, std::pair<u_int16_t, u_int16_t>>>
  ObstacleInfo() {
    return obstacleTiles_;
  }

  const std::vector<Vec2D> &EnemyPath() const { return enemyPath_; }

  std::uint32_t Width() const { return width_; }
  std::uint32_t Height() const { return height_; }
  std::uint8_t TileWidth() const { return tileWidth_; }

 private:
  std::vector<std::vector<Tile>> tiles_;
  std::vector<std::pair<u_int16_t, std::pair<u_int16_t, u_int16_t>>>
      obstacleTiles_;
  const std::vector<Vec2D> enemyPath_;

  // LevelInfo
  std::uint8_t tileWidth_;
  // FIXME: Should be uint8_t since these are the sizes in TILES not absolutes.
  std::uint32_t width_;
  std::uint32_t height_;
};
