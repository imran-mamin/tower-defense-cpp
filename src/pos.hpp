
#pragma once

#include <cstdint>

struct Pos {
	bool operator ==(const Pos &that) const { return x == that.x && y == that.y; }
	std::int32_t x;
	std::int32_t y;
};

