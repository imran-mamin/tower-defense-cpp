
#pragma once

#include <cstdint>

struct Pos {
	std::uint32_t x;
	std::uint32_t y;

	bool operator ==(const Pos &that) const { return x == that.x && y == that.y; }
};

