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

// Enemy should be on the first vec2D in enemyPath.
TEST(FootSoldierClass, Update) {
    GameGrid gg = GameGrid(testMapInfoObject1());
    Game game = Game(gg);

    sf::Sprite sp;
    Pos p;
    p.x = gg.EnemyPath().at(0).a.x;
    p.y = gg.EnemyPath().at(0).a.y;
    // (int speed, int value, int price, int hp, sf::Sprite sprite, Game& game, Pos position)
    FootSoldier fs = FootSoldier(18, 6, 6, 18, sp, game, p);
    game.AddObject(fs);
    
    for (int i = 0; i < 2; i++) {
        fs.update();
    }

    EXPECT_EQ(fs.getPosition().x, 36);
    EXPECT_EQ(fs.getPosition().y, 224);
}

TEST(FootSoldierClass, Update2) {
    GameGrid gg = GameGrid(testMapInfoObject1());
    Game game = Game(gg);

    sf::Sprite sp;
    Pos p;
    p.x = gg.EnemyPath().at(0).a.x;
    p.y = gg.EnemyPath().at(0).a.y;
    // (int speed, int value, int price, int hp, sf::Sprite sprite, Game& game, Pos position)
    FootSoldier fs = FootSoldier(20, 6, 6, 18, sp, game, p);
    game.AddObject(fs);

    for (int i = 0; i < 4; i++) {
        fs.update();
    }

    EXPECT_EQ(fs.getPosition().x, 60);
    EXPECT_EQ(fs.getPosition().y, 244);
}

// Enemy should be on the second vec2D in enemyPath.
TEST(FootSoldierClass, Update3) {
    GameGrid gg = GameGrid(testMapInfoObject1());
    Game game = Game(gg);

    std::cout << "EnemyPath()" << std::endl;
    for (int i = 0; i < gg.EnemyPath().size(); i++) {
        std::cout << "Start (x, y): (" << gg.EnemyPath().at(i).a.x << ", " << gg.EnemyPath().at(i).a.y << ")" << std::endl;
        std::cout << "End (x, y): (" << gg.EnemyPath().at(i).b.x << ", " << gg.EnemyPath().at(i).b.y << ")" << std::endl;
    }
    
    std::cout << "EnemPath() ended" << std::endl;
    sf::Sprite sp;
    Pos p;
    p.x = gg.EnemyPath().at(0).a.x;
    p.y = gg.EnemyPath().at(0).a.y;
    // (int speed, int value, int price, int hp, sf::Sprite sprite, Game& game, Pos position)
    FootSoldier fs = FootSoldier(7, 6, 6, 18, sp, game, p);
    game.AddObject(fs);

    std::cout << "Enemy position at the start" << std::endl;
    std::cout << "(x, y) = (" << fs.getPosition().x << ", " << fs.getPosition().y << ")" << std::endl;
    
    for (int i = 0; i < 19; i++) {
        fs.update();

        std::cout << "iteration " << i << "done" << std::endl;
        std::cout << std::endl;
    }
    std::cout << "Enemy position at the end" << std::endl;
    std::cout << "(x, y) = (" << fs.getPosition().x << ", " << fs.getPosition().y << ")" << std::endl;
  
    //(97, 260)
    EXPECT_EQ(fs.getPosition().x, 97);
    EXPECT_EQ(fs.getPosition().y, 260);
}
