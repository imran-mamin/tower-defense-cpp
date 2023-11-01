
#pragma once

#include <cstdint>
#include <string>
#include <tuple>
#include <vector>

#include "gamegrid.hpp"

struct MapInfo{
	/* tileWidth = tileHeight */
	const std::uint8_t tileWidth;
	const std::uint8_t mapWidth;
	const std::uint8_t mapHeight;
	std::vector<std::vector<std::uint16_t>> backgroundTiles;
	/* Enemy path consisting from vectors. */
	std::vector<std::tuple<std::uint32_t>> enemyPath;
};

MapInfo ParseMap(const std::string &path);

