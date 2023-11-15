
#include "testmapinfo.hpp"

#include "map_parser.hpp"
#include <cstdint>
#include <tuple>
#include <vector>

const std::uint32_t mapWidth = 32;
const std::uint32_t mapHeight = 12;

MapInfo testMapInfoObject1() {
	/* Create the background tiles. */
	std::vector<std::vector<std::uint16_t>> backgroundTiles;
	for (std::uint32_t j = 0; j < mapHeight; j++) {
		std::vector<uint16_t> row;
		for (std::uint32_t i = 0; i < mapWidth; i++) {
			/* Grass. */
			row.push_back(0);
		}
		backgroundTiles.push_back(row);
	}

	/* TODO: Create enemy path. */
	std::vector<std::tuple<std::uint32_t>> enemyPath;

	return MapInfo{ 64, 20, 12, backgroundTiles, enemyPath };
}


