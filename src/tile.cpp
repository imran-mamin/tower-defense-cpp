#include "tile.hpp"

TileType Tile::type() const {
    return type_;
}

bool Tile::isFree() const {
	return isEmpty_ && type_ == TileType::Ground;
}

void Tile::occupy() {
	isEmpty_ = false;
}

void Tile::free() {
    isEmpty_ = true;
}
