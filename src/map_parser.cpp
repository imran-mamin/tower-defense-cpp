#include <cstdint>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

#include "json.hpp"
#include "map_parser.hpp"


MapInfo ParseMap(const std::string &path) {
	std::ifstream is(path);
	if (is.fail()) {
		throw MapParserError(std::string("Failed to open file at '") + path + "'.");
	}
	nlohmann::json data = nlohmann::json::parse(is);

	try {
		MapInfo mapInfo =  MapInfo{ data["tile_width"], data["map_width"], data["map_height"], data["background"], data["enemy_path"] };
	
		if (mapInfo.mapWidth * mapInfo.mapHeight != mapInfo.backgroundTiles.size()) {
			throw MapParserError("Tile count of the map must be equal to tileWidth * mapHeight!");
		}

		return mapInfo;
	}
	catch (const std::exception &e) {
		// TODO: Implement new exception throwing besides just rethrowing.
		throw e;
	}
	// TODO: More precise error output.
	//catch (/* TODO: Catch correct exception (trying to read data field that is incorrect, or type error idk.) */) {
	//	throw MapParserError("TODO");
	//}
}

