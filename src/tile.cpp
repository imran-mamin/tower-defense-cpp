#include "tile.hpp"

TileType Tile::type() const {
    return type_;
}

bool Tile::isFree() const {
	return isEmpty_ && type_ == TileType::Ground;
}

/*bool Tile::isEmpty() const {
    return isEmpty_;
}*/

bool Tile::occupy() {
    if (isEmpty_) {
        isEmpty_ = false;
        return true;
    } else {
        return false;
    }
}

void Tile::free() {
    isEmpty_ = true;
}
