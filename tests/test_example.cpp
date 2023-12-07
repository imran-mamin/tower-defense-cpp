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
#include "missilelauncher.hpp"

// --------------- TEST TOWERCLASS -----------------

// Enemy should be on the first vec2D in enemyPath.
TEST(TowerClass, getEnemiesWithinRadius) {
    GameGrid gg = GameGrid(testMapInfoObject1());
    Game game = Game(gg);
    
    Pos p1 = Pos{ 2, 220 };

    Pos p2;
    p2.x = gg.EnemyPath().at(0).a.x;
    p2.y = gg.EnemyPath().at(0).a.y;
    // MissileLauncher(int radius, int fireRate, int price, sf::Sprite sprite, Game& game, Pos position)
    MissileLauncher* ml = new MissileLauncher(6, 2, 100, game, p1);
    // (int speed, int value, int price, int hp, sf::Sprite sprite, Game& game, Pos position)
    FootSoldier* fs = new FootSoldier(18, 6, 6, 18, game, p2);
    game.AddObject(fs);
    game.AddObject(ml);
    
    std::vector<Enemy*> v = ml->getEnemiesWithinRadius();
    
    // Enemy position should be (0, 224).
    EXPECT_EQ(v.at(0)->getPosition().x, 0);
    EXPECT_EQ(v.at(0)->getPosition().y, 224);
    
    // There should be only one enemy within the radius.
    EXPECT_EQ(v.size(), 1);
}


// --------------------- TEST FOOTSOLDIER CLASS --------------------------

// Enemy should be on the first vec2D in enemyPath.
TEST(FootSoldierClass, Update) {
    GameGrid gg = GameGrid(testMapInfoObject1());
    Game game = Game(gg);

    Pos p;
    p.x = gg.EnemyPath().at(0).a.x;
    p.y = gg.EnemyPath().at(0).a.y;
    // (int speed, int value, int price, int hp, sf::Sprite sprite, Game& game, Pos position)
    FootSoldier* fs = new FootSoldier(18, 6, 6, 18, game, p);
    game.AddObject(fs);
    
    for (int i = 0; i < 2; i++) {
        fs->update();
    }

    EXPECT_EQ(fs->getPosition().x, 36);
    EXPECT_EQ(fs->getPosition().y, 224);
    EXPECT_EQ(fs->GetRotation(), 0);
}

// Enemy should be on the second vec2D in enemyPath.
TEST(FootSoldierClass, Update2) {
    GameGrid gg = GameGrid(testMapInfoObject1());
    Game game = Game(gg);

    Pos p;
    p.x = gg.EnemyPath().at(0).a.x;
    p.y = gg.EnemyPath().at(0).a.y;
    // (int speed, int value, int price, int hp, sf::Sprite sprite, Game& game, Pos position)
    FootSoldier* fs = new FootSoldier(20, 6, 6, 18, game, p);
    game.AddObject(fs);

    for (int i = 0; i < 4; i++) {
        fs->update();
    }

    EXPECT_EQ(fs->getPosition().x, 60);
    EXPECT_EQ(fs->getPosition().y, 244);
    EXPECT_EQ(fs->GetRotation(), 90);
}


// Enemy should be on the third vec2D in enemyPath.
TEST(FootSoldierClass, Update3) {
    GameGrid gg = GameGrid(testMapInfoObject1());
    Game game = Game(gg);

    std::cout << "EnemyPath()" << std::endl;
    for (int i = 0; i < gg.EnemyPath().size(); i++) {
        std::cout << "Start (x, y): (" << gg.EnemyPath().at(i).a.x << ", " << gg.EnemyPath().at(i).a.y << ")" << std::endl;
        std::cout << "End (x, y): (" << gg.EnemyPath().at(i).b.x << ", " << gg.EnemyPath().at(i).b.y << ")" << std::endl;
    }
    
    std::cout << "EnemPath() ended" << std::endl;
    Pos p;
    p.x = gg.EnemyPath().at(0).a.x;
    p.y = gg.EnemyPath().at(0).a.y;
    // (int speed, int value, int price, int hp, sf::Sprite sprite, Game& game, Pos position)
    FootSoldier* fs = new FootSoldier(7, 6, 6, 18, game, p);
    game.AddObject(fs);

    std::cout << "Enemy position at the start" << std::endl;
    std::cout << "(x, y) = (" << fs->getPosition().x << ", " << fs->getPosition().y << ")" << std::endl;
    
    for (int i = 0; i < 14; i++) {
        fs->update();

        std::cout << "iteration " << i << "done" << std::endl;
        std::cout << std::endl;
    }
    std::cout << "Enemy position at the end" << std::endl;
    std::cout << "(x, y) = (" << fs->getPosition().x << ", " << fs->getPosition().y << ")" << std::endl;
  
    // (58, 260)
    EXPECT_EQ(fs->getPosition().x, 58);
    EXPECT_EQ(fs->getPosition().y, 260);
    EXPECT_EQ(fs->GetRotation(), 180);
}

// Enemy should be on the fourth vec2D in enemyPath.
TEST(FootSoldierClass, Update4) {
    GameGrid gg = GameGrid(testMapInfoObject1());
    Game game = Game(gg);

    std::cout << "EnemyPath()" << std::endl;
    for (int i = 0; i < gg.EnemyPath().size(); i++) {
        std::cout << "Start (x, y): (" << gg.EnemyPath().at(i).a.x << ", " << gg.EnemyPath().at(i).a.y << ")" << std::endl;
        std::cout << "End (x, y): (" << gg.EnemyPath().at(i).b.x << ", " << gg.EnemyPath().at(i).b.y << ")" << std::endl;
    }
    
    std::cout << "EnemPath() ended" << std::endl;

    Pos p;
    p.x = gg.EnemyPath().at(0).a.x;
    p.y = gg.EnemyPath().at(0).a.y;
    // (int speed, int value, int price, int hp, sf::Sprite sprite, Game& game, Pos position)
    FootSoldier* fs = new FootSoldier(7, 6, 6, 18, game, p);
    game.AddObject(fs);

    std::cout << "Enemy position at the start" << std::endl;
    std::cout << "(x, y) = (" << fs->getPosition().x << ", " << fs->getPosition().y << ")" << std::endl;
    
    for (int i = 0; i < 23; i++) {
        fs->update();

        std::cout << "iteration " << i << "done" << std::endl;
        std::cout << std::endl;
    }
    std::cout << "Enemy position at the end" << std::endl;
    std::cout << "(x, y) = (" << fs->getPosition().x << ", " << fs->getPosition().y << ")" << std::endl;
  
    // (0, 255)
    EXPECT_EQ(fs->getPosition().x, 0);
    EXPECT_EQ(fs->getPosition().y, 255);
    EXPECT_EQ(fs->GetRotation(), 270);
}


// ----------------- TEST MISSILE CLASS --------------------
// TODO: Checkout the commented unit test
/*
TEST(MissileClass, update) {
    GameGrid gg = GameGrid(testMapInfoObject1());
    Game game = Game(gg);
    
    Pos p1 = Pos{ 2, 220 };

    Pos p2;
    p2.x = gg.EnemyPath().at(0).a.x;
    p2.y = gg.EnemyPath().at(0).a.y;
    // MissileLauncher(int radius, int fireRate, int price, sf::Sprite sprite, Game& game, Pos position)
    MissileLauncher* ml = new MissileLauncher(100, 2, 100, game, p1);
    // (int speed, int value, int price, int hp, sf::Sprite sprite, Game& game, Pos position)
    FootSoldier* fs = new FootSoldier(18, 6, 6, 18, game, p2);
    game.AddObject(fs);
    game.AddObject(ml);

    game.Update();

    // Enemy health 18 should be reduced by 6 (missile's damage is 6)

    // After hitting the enemy, the Missile-instance should be removed from game->objects_.
    EXPECT_EQ(game.Objects().size(), 2);
}


TEST(MissileClass, update2) {
    GameGrid gg = GameGrid(testMapInfoObject1());
    Game game = Game(gg);
    
    Pos p1 = Pos{ 2, 220 };

    Pos p2;
    p2.x = gg.EnemyPath().at(0).a.x;
    p2.y = gg.EnemyPath().at(0).a.y;
    // MissileLauncher(int radius, int fireRate, int price, sf::Sprite sprite, Game& game, Pos position)
    MissileLauncher* ml = new MissileLauncher(100, 2, 100, game, p1);
    // (int speed, int value, int price, int hp, sf::Sprite sprite, Game& game, Pos position)
    FootSoldier* fs = new FootSoldier(18, 6, 6, 6, game, p2);
    game.AddObject(fs);
    game.AddObject(ml);

    for (int i = 0; i < 2; i++) {
        int j = 0;
    
        while (j < (int)game.Objects().size()) {
            game.Objects().at(j)->update();
            j++;
        }
    }
    

    // Enemy health 6 should be reduced by 6 (missile's damage is 6) --> Enemy-instance should be
    // removed from game->objects_.

    // After hitting the enemy, the Missile-instance should be removed from game->objects_.
    EXPECT_EQ(game.Objects().size(), 1);
}
*/

// ----------- TEST CANNON CLASS -------------
TEST(CannonClass, update) {
    GameGrid gg = GameGrid(testMapInfoObject1());
    Game game = Game(gg);

    Pos p2;
    p2.x = gg.EnemyPath().at(0).a.x;
    p2.y = gg.EnemyPath().at(0).a.y;

    FootSoldier* fs = new FootSoldier(18, 6, 6, 6, game, p2);
    game.AddObject(fs);

    Pos canPos = Pos{ 20, 240 };
    Cannon* cn = new GreenCannon(game, canPos);
    game.AddObject(cn);
    for (int i = 0; i < game.Objects().size(); i++) {
        std::cout << "Pos = (" << game.Objects().at(i)->getPosition().x << ", " << game.Objects().at(i)->getPosition().y << ")" << std::endl;
    }
    game.Objects().at(1)->update();
    // game.Update();
    std::cout << "a" << std::endl;
    for (int i = 0; i < game.Objects().size(); i++) {
        std::cout << "Pos = (" << game.Objects().at(i)->getPosition().x << ", " << game.Objects().at(i)->getPosition().y << ")" << std::endl;
    }

    EXPECT_EQ(game.Objects().size(), 3);
}

TEST(CannonClass, update2) {
    GameGrid gg = GameGrid(testMapInfoObject1());
    Game game = Game(gg);

    Pos p2;
    p2.x = gg.EnemyPath().at(0).a.x;
    p2.y = gg.EnemyPath().at(0).a.y;

    FootSoldier* fs = new FootSoldier(2, 2, 2, 2, game, p2);
    game.AddObject(fs);

    Pos canPos = Pos{ 20, 240 };
    Cannon* cn = new GreenCannon(game, canPos);
    game.AddObject(cn);

    for (auto obj : game.Objects()) {
        std::cout << "Pos = (" << obj->getPosition().x << ", " << obj->getPosition().y << ")" << std::endl;
    }
    // game.Objects().at(1)->update();
    game.Update();
    std::cout << "a" << std::endl;
    for (int i = 0; i < game.Objects().size(); i++) {
        std::cout << "Pos = (" << game.Objects().at(i)->getPosition().x << ", " << game.Objects().at(i)->getPosition().y << ")" << std::endl;
    }
    
    EXPECT_EQ(game.Objects().size(), 1);
}