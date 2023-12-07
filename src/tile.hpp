
#pragma once

#include <cstdint>
#include <vector>

enum class TileType {
  Path,
  Ground,
  Water,
  Obstacle,
};

class Tile {
 private:
  TileType type_;
  std::uint16_t id_;
  bool isEmpty_ = true;

 public:
  Tile(TileType type, std::uint16_t id) : type_(type), id_(id) {}
  TileType type() const;
  void SetType(TileType t) { type_ = t; }

  std::uint16_t Id() const { return id_; }

  bool isFree() const;

  // put something in the tile and set isEmpty to false. returns true is
  // succesful else false.
  void occupy();

  // Set is empty to true
  void free();
};
