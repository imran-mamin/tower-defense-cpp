#include <fstream>
#include <iostream>

#include "json.hpp"


// TODO: Implementation missing.
GameGrid ParseMap(const std::string &path) {
	std::ifstream is("../rsrc/maps/map1.json");
	nlohmann::json data = nlohmann::json::parse(is);

	for (auto field : data) {
		std::cout << field << std::endl;
	}

	

	std::cout << 
	std::cout << data["background"] << std::endl;


}

