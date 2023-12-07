
#pragma once

#include <cstdint>
#include <map>
#include <utility>

enum class GameObjectType {
	Dick
};

enum class WeaponType {
	GreenCannon,
	RedCannon,
	MissileLauncher1,
	MissileLauncher2,
	MissileLauncher3
};

enum class EnemyType{
	Soldier1,
	Soldier2,
	Soldier3,
	Soldier4,
	Tank1,
	Tank2,
	Plane1,
	Plane2
};

const std::map<WeaponType, std::uint16_t> weaponToTileIDMapping = {
	std::make_pair(WeaponType::GreenCannon, 248),
	std::make_pair(WeaponType::RedCannon, 249),
	std::make_pair(WeaponType::MissileLauncher1, 205),
	std::make_pair(WeaponType::MissileLauncher2, 204),
	std::make_pair(WeaponType::MissileLauncher3, 203)
};

const std::map<EnemyType, std::uint16_t> enemyToTileIDMapping = {
	std::make_pair(EnemyType::Soldier1, 244),
	std::make_pair(EnemyType::Soldier2, 245),
	std::make_pair(EnemyType::Soldier3, 246),
	std::make_pair(EnemyType::Soldier4, 247),
	std::make_pair(EnemyType::Tank1, 267),
	std::make_pair(EnemyType::Tank2, 268),
	std::make_pair(EnemyType::Plane1, 269),
	std::make_pair(EnemyType::Plane2, 270)
};

