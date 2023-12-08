#include "testmapinfo.hpp"

#include <cstdint>
#include <tuple>
#include <vector>

#include "map_parser.hpp"
#include "pos.hpp"
#include "vec2d.hpp"

const std::uint32_t mapWidth = 32;
const std::uint32_t mapHeight = 12;

MapInfo testMapInfoObject1() {
        const std::uint8_t tileWidth = 64;
        const std::uint8_t mapWidth = 20;
        const std::uint8_t mapHeight = 12;
        const std::uint64_t playerStartCash = 6000;
        //Create the background tiles.
        std::vector<std::vector<std::uint16_t>> backgroundTiles;
        for (std::uint32_t j = 0; j < mapHeight; j++) {
                std::vector<uint16_t> row;
                for (std::uint32_t i = 0; i < mapWidth; i++) {
                         //Grass.
                        row.push_back(23);
                }
                backgroundTiles.push_back(row);
        }

        //Add path tiles.
        for (std::uint16_t j = 3; j <= 4; j++) {
                for (std::uint16_t i = 0; i < 20; i++) {
                        backgroundTiles[j][i] = 92;
                }
        }

        std::vector<Vec2D> enemyPath;
        enemyPath.push_back(Vec2D{ Pos{0, 640}, Pos{192, 640} });
        enemyPath.push_back(Vec2D{ Pos{192, 640}, Pos{192, 128} });
        enemyPath.push_back(Vec2D{ Pos{192, 128}, Pos{1088, 128} });
        enemyPath.push_back(Vec2D{ Pos{1088, 128}, Pos{1088, 320} });
        enemyPath.push_back(Vec2D{ Pos{1088, 320}, Pos{384, 320} });
        enemyPath.push_back(Vec2D{ Pos{384, 320}, Pos{384, 640} });
        enemyPath.push_back(Vec2D{ Pos{384, 640}, Pos{1280, 640} });

        std::vector<std::pair<u_int16_t, std::pair<u_int16_t, u_int16_t>>> obstacleTiles = {{135, {0, 0}}, {134, {640, 512}}};
        std::vector<EnemyType> enemyTypes;
        std::vector<EnemyWave> enemyWaves;
        for (int i = 0; i < 60; i++) {
                enemyTypes.push_back(EnemyType::Soldier1);
        }
        enemyWaves.push_back(EnemyWave(60, enemyTypes));
        /*
        enemyPath.push_back(Vec2D{ Pos{ 0, 224 }, Pos{ 60, 224 } });
        enemyPath.push_back(Vec2D{ Pos{ 60, 224 }, Pos{ 60, 260 } });
        enemyPath.push_back(Vec2D{ Pos{ 60, 260 }, Pos{ 0, 260 } });
        enemyPath.push_back(Vec2D{ Pos{ 0, 260 }, Pos{ 0, 224 } });
        */

        return MapInfo{ tileWidth, mapWidth, mapHeight, backgroundTiles, obstacleTiles, playerStartCash, enemyPath, enemyWaves};
}
