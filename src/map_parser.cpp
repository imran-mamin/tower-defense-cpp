#include <cstdint>
#include <exception>
#include <fstream>
#include <iostream>

#include "json.hpp"
#include "map_parser.hpp"


MapInfo ParseMap(const std::string &path) {
	std::ifstream is("rsrc/maps/map1.json");
	nlohmann::json data = nlohmann::json::parse(is);

	try {
		MapInfo mapInfo =  MapInfo{ data["tile_width"], data["map_width"], data["map_height"], data["background"], data["enemy_path"] };
	
		if (mapInfo.mapWidth * mapInfo.mapHeight != mapInfo.backgroundTiles.size()) {
			throw MapParserError("Tile count of the map must be equal to tileWidth * mapHeight!");
		}

		return mapInfo;
	}
	catch (const std::exception &e) {

	}
	// TODO: More precise error output.
	//catch (/* TODO: Catch correct exception (trying to read data field that is incorrect, or type error idk.) */) {
	//	throw MapParserError("TODO");
	//}
}

