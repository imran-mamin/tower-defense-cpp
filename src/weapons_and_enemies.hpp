
#pragma once

#include <cstdint>
#include <map>
#include <utility>

enum class Weapons{
	GreenCannon,
	RedCannon,
	MissileLauncher1,
	MissileLauncher2,
	MissileLauncher3
};

enum class Enemies{
	Soldier1,
	Soldier2,
	Soldier3,
	Soldier4,
	Tank1,
	Tank2,
	Plane1,
	Plane2
};

const std::map<Weapons, std::uint16_t> weaponToTileIDMapping = {
	std::make_pair(Weapons::GreenCannon, 248),
	std::make_pair(Weapons::RedCannon, 249),
	std::make_pair(Weapons::MissileLauncher1, 205),
	std::make_pair(Weapons::MissileLauncher2, 204),
	std::make_pair(Weapons::MissileLauncher3, 203)
};

const std::map<Enemies, std::uint16_t> enemyToTileIDMapping = {
	std::make_pair(Enemies::Soldier1, 244),
	std::make_pair(Enemies::Soldier2, 245),
	std::make_pair(Enemies::Soldier3, 246),
	std::make_pair(Enemies::Soldier4, 247),
	std::make_pair(Enemies::Tank1, 267),
	std::make_pair(Enemies::Tank2, 268),
	std::make_pair(Enemies::Plane1, 269),
	std::make_pair(Enemies::Plane2, 270)
};

