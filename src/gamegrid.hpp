
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

class GameGrid {
 public:
  /* Create a new GameGrid object from map file. */
  GameGrid(const MapInfo &mapInfo);
  GameGrid() = delete;

  Tile &TileAtCoordinate(std::uint8_t x, std::uint8_t y) const;
  std::vector<std::vector<Tile>> Tiles() { return tiles_; }

  std::uint32_t Width() const { return width_; }
  std::uint32_t Height() const { return height_; }
  std::uint8_t TileWidth() const { return tileWidth_; }

 private:
  std::vector<std::vector<Tile>> tiles_;
  // std::vector<std::tuple<std::uint32_t>> enemyPath_;

  // LevelInfo
  std::uint8_t tileWidth_;
  std::uint32_t width_;
  std::uint32_t height_;
};
