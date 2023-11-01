#pragma once
#include <vector>

enum class TileType {
    Path,
    Ground,
    Water,
};

class Tile {
private:
    TileType type_;

public:
    Tile(TileType type) : type_(type) {}
    TileType type() const;
    
    // TODO: Do we need this method?
    bool isEmpty() const;

};
