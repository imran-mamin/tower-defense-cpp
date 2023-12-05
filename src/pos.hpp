
#pragma once

#include <cstdint>
#include <SFML/System/Vector2.hpp>

struct Pos { 
	float x;
	float y;
	
	bool operator==(const Pos &that) const { return x == that.x && y == that.y; };
	sf::Vector2f ToVector2f() { return sf::Vector2f{ x, y }; }
};

