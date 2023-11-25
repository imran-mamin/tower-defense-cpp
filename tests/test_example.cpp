#include <gtest/gtest.h>

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <optional>
#include <vector>

#include "cannon.hpp"
#include "game.hpp"
#include "gamegrid.hpp"
#include "gameloop.hpp"
#include "gameobject.hpp"
#include "map_tile_selector_renderer.hpp"
#include "testmapinfo.hpp"
#include "tower.hpp"
#include "footsoldier.hpp"

TEST(FootSoldierClass, Update) {
    GameGrid gg = GameGrid(testMapInfoObject1());
    Game game = Game(gg);

    std::cout << "EnemyPath()" << std::endl;
    for (int i = 0; i < gg.EnemyPath().size(); i++) {
        std::cout << "Start (x, y): (" << gg.EnemyPath().at(0).a.x << ", " << gg.EnemyPath().at(0).a.y << ")" << std::endl;
        std::cout << "End (x, y): (" << gg.EnemyPath().at(0).b.x << ", " << gg.EnemyPath().at(0).b.y << ")" << std::endl;
    }
    

    sf::Sprite sp;
    Pos p;
    p.x = gg.EnemyPath().at(0).a.x;
    p.y = gg.EnemyPath().at(0).a.y;
    // (int speed, int value, int price, int hp, sf::Sprite sprite, Game& game, Pos position)
    FootSoldier fs = FootSoldier(0.05 / 60.0, 6, 6, 18, sp, game, p);
    game.AddObject(fs);

    std::cout << "Enemy position at the start" << std::endl;
    std::cout << "(x, y) = (" << fs.getPosition().x << ", " << fs.getPosition().y << ")" << std::endl;
    fs.update();
    std::cout << "Enemy position at the end" << std::endl;
    std::cout << "(x, y) = (" << fs.getPosition().x << ", " << fs.getPosition().y << ")" << std::endl;
  

    EXPECT_EQ(fs.getPosition().x, 1);
    EXPECT_EQ(fs.getPosition().y, 224);
}

TEST(FootSoldierClass, Update2) {
     GameGrid gg = GameGrid(testMapInfoObject1());
    Game game = Game(gg);

    std::cout << "EnemyPath()" << std::endl;
    for (int i = 0; i < gg.EnemyPath().size(); i++) {
        std::cout << "Start (x, y): (" << gg.EnemyPath().at(0).a.x << ", " << gg.EnemyPath().at(0).a.y << ")" << std::endl;
        std::cout << "End (x, y): (" << gg.EnemyPath().at(0).b.x << ", " << gg.EnemyPath().at(0).b.y << ")" << std::endl;
    }
    

    sf::Sprite sp;
    Pos p;
    p.x = gg.EnemyPath().at(0).a.x;
    p.y = gg.EnemyPath().at(0).a.y;
    // (int speed, int value, int price, int hp, sf::Sprite sprite, Game& game, Pos position)
    FootSoldier fs = FootSoldier(2.0 / 60.0, 6, 6, 18, sp, game, p);
    game.AddObject(fs);

    std::cout << "Enemy position at the start" << std::endl;
    std::cout << "(x, y) = (" << fs.getPosition().x << ", " << fs.getPosition().y << ")" << std::endl;
    fs.update();
    std::cout << "Enemy position at the end" << std::endl;
    std::cout << "(x, y) = (" << fs.getPosition().x << ", " << fs.getPosition().y << ")" << std::endl;
  

    EXPECT_EQ(fs.getPosition().x, 42);
    EXPECT_EQ(fs.getPosition().y, 224);
}