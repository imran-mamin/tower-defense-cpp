
#include "gamegrid.hpp"
#include "map_parser.hpp"
#include <cstdint>
#include <exception>
#include <vector>



/* TODO: Create the gamegrid. */
GameGrid::GameGrid(const std::string &path) {
	try {
		MapInfo mapInfo = ParseMap(path);

		/* TODO: Initialize the values. */

	}
	catch (const std::exception &e) {
		
	}
}

void GameGrid::Draw(const sf::RenderWindow& RenderWindow) {

}

GameGrid::GameGrid(const MapInfo &mapInfo) {
	tileWidth_ = mapInfo.tileWidth;
	std::vector<std::vector<std::uint16_t>> backgroundTiles_;
    std::uint32_t width_;
    std::uint32_t height_;
}

//Tile &GameGrid::TileAtCoordinate(std::uint8_t x, std::uint8_t y) const {
//	return tiles_[y / tileWidth_ + (y % tileWidth_ != 0 ? 1 : 0)][x / tileWidth_ + (x % tileWidth_ != 0 ? 1 : 0)];
//}



