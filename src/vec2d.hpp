
#pragma once

#include <cstdint>

#include "pos.hpp"

struct Vec2D {
	Pos a;
	Pos b;

	bool operator==(const Vec2D &that) {
		return a == that.a && b == that.b;
	}
};

