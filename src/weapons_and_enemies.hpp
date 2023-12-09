
#pragma once

#include <cstdint>
#include <map>
#include <string>
#include <utility>

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

enum class ProjectileType{
	Missile,
	Bullet
};

const std::map<std::string, EnemyType> stringToEnemyTypeMapping =  {
	std::make_pair("FootSoldier1", EnemyType::Soldier1),
	std::make_pair("FootSoldier2", EnemyType::Soldier2),
	std::make_pair("FootSoldier3", EnemyType::Soldier3),
	std::make_pair("FootSoldier4", EnemyType::Soldier4),
	std::make_pair("Tank1", EnemyType::Tank1),
	std::make_pair("Tank2", EnemyType::Tank2),
	std::make_pair("Plane1", EnemyType::Plane1),
	std::make_pair("Plane2", EnemyType::Plane2)
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

const std::map<ProjectileType, std::uint16_t> projectileToTileIDMapping = {
	std::make_pair(ProjectileType::Missile, 250),
	std::make_pair(ProjectileType::Bullet, 271)
};
