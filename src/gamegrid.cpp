
#include "gamegrid.hpp"
#include <cstdint>
#include <vector>



GameGrid::GameGrid(const std::string &path) {

	// TODO: Parse the map.
}

GameGrid::GameGrid ParseMap(const std::string &path) {

}

	const std::uint8_t tileWidth;
	const std::uint8_t mapWidth;
	const std::uint8_t mapHeight;
	std::vector<std::vector<int>> backgroundTiles;
	std::vector<std::tuple<int>>
}


void GameGrid::Draw(const sf::RenderWindow& RenderWindow);

GameGrid::GameGrid(const MapInfo &mapInfo) {
	tileWidth_ = mapInfo.tileWidth;
	backgroundTiles_ = std::vector<std::vector<std::uint16_t>>;
    std::uint32_t width_;
    std::uint32_t height_;
}

GameGrid::Tile &TileAtCoordinate(std::uint8_t x, std::uint8_t y) const {
	return tiles_[y / tileWidth_ + (y % tileWidth_ != 0 ? 1 : 0)][x / tileWidth_ + (x % tileWidth_ != 0 ? 1 : 0)];
}



