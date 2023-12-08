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
    Game game = Game(gg, 1, testMapInfoObject1());
    
    Pos p1 = Pos{ 0, 620 };

    Pos p2;
    p2.x = gg.EnemyPath().at(0).a.x;
    p2.y = gg.EnemyPath().at(0).a.y;
    // MissileLauncher(int radius, int fireRate, int price, Game& game, Pos position)
    MissileLauncher* ml = new MissileLauncher(20, 2, 100, &game, p1);
    // (int speed, int value, int price, int hp, Game& game, Pos position)
    FootSoldier* fs = new FootSoldier(18, 6, 6, 18, &game, p2);
    game.AddObject(fs);
    game.AddObject(ml);
    
    std::vector<Enemy*> v = ml->getEnemiesWithinRadius();
    // Enemy position should be (0, 640).
    EXPECT_EQ(v.at(0)->getPosition().x, 0);
    EXPECT_EQ(v.at(0)->getPosition().y, 640);
    
    // There should be only one enemy within the radius.
    EXPECT_EQ(v.size(), 1);
}

// --------------------- TEST FOOTSOLDIER CLASS --------------------------

// Enemy should be on the first vec2D in enemyPath.
TEST(FootSoldierClass, Update) {
    GameGrid gg = GameGrid(testMapInfoObject1());
    Game game = Game(gg, 1, testMapInfoObject1());

    Pos p;
    p.x = gg.EnemyPath().at(0).a.x;
    p.y = gg.EnemyPath().at(0).a.y;
    // (int speed, int value, int price, int hp, Game& game, Pos position)
    FootSoldier* fs = new FootSoldier(18, 6, 6, 18, &game, p);
    game.AddObject(fs);
    
    for (int i = 0; i < 2; i++) {
        fs->update();
    }

    EXPECT_EQ(fs->getPosition().x, 36);
    EXPECT_EQ(fs->getPosition().y, 640);
    EXPECT_EQ(fs->GetRotation(), 0);
}

// Enemy should be on the second vec2D in enemyPath.
TEST(FootSoldierClass, Update2) {
    GameGrid gg = GameGrid(testMapInfoObject1());
    Game game = Game(gg, 1, testMapInfoObject1());

    Pos p;
    p.x = gg.EnemyPath().at(0).a.x;
    p.y = gg.EnemyPath().at(0).a.y;
    // (int speed, int value, int price, int hp, Game& game, Pos position)
    FootSoldier* fs = new FootSoldier(20, 6, 6, 18, &game, p);
    game.AddObject(fs);

    for (int i = 0; i < 11; i++) {
        fs->update();
    }

    EXPECT_EQ(fs->getPosition().x, 192);
    EXPECT_EQ(fs->getPosition().y, 612);
    EXPECT_EQ(fs->GetRotation(), 270);
}

// Enemy should be on the third vec2D in enemyPath.
TEST(FootSoldierClass, Update3) {
    GameGrid gg = GameGrid(testMapInfoObject1());
    Game game = Game(gg, 1, testMapInfoObject1());

    Pos p;
    p.x = gg.EnemyPath().at(0).a.x;
    p.y = gg.EnemyPath().at(0).a.y;
    // (int speed, int value, int price, int hp, Game& game, Pos position)
    FootSoldier* fs = new FootSoldier(7, 6, 6, 18, &game, p);
    game.AddObject(fs);

    for (int i = 0; i < 101; i++) {
        fs->update();
    }
 
    // (195, 128)
    EXPECT_EQ(fs->getPosition().x, 195);
    EXPECT_EQ(fs->getPosition().y, 128);
    EXPECT_EQ(fs->GetRotation(), 0);
}

// Enemy should be on the fourth vec2D in enemyPath.
TEST(FootSoldierClass, Update4) {
    GameGrid gg = GameGrid(testMapInfoObject1());
    Game game = Game(gg, 1, testMapInfoObject1());

    Pos p;
    p.x = gg.EnemyPath().at(1).a.x;
    p.y = gg.EnemyPath().at(1).a.y;
    // (int speed, int value, int price, int hp, Game& game, Pos position)
    FootSoldier* fs = new FootSoldier(18, 6, 6, 18, &game, p);
    game.AddObject(fs);

    for (int i = 0; i < 80; i++) {
        fs->update();
    }

    // (1088, 160)
    EXPECT_EQ(fs->getPosition().x, 1088);
    EXPECT_EQ(fs->getPosition().y, 160);
    EXPECT_EQ(fs->GetRotation(), 90);
}


// ----------------- TEST MISSILE CLASS --------------------

TEST(MissileClass, update) {
    GameGrid gg = GameGrid(testMapInfoObject1());
    Game game = Game(gg, 1, testMapInfoObject1());
    
    Pos p1 = Pos{ 0, 620 };

    Pos p2;
    p2.x = gg.EnemyPath().at(0).a.x;
    p2.y = gg.EnemyPath().at(0).a.y;
    // MissileLauncher(int radius, int fireRate, int price, Game& game, Pos position)
    MissileLauncher* ml = new MissileLauncher(100, 2, 100, &game, p1);
    // (int speed, int value, int price, int hp, Game& game, Pos position)
    FootSoldier* fs = new FootSoldier(18, 6, 6, 18, &game, p2);
    game.AddObject(fs);
    game.AddObject(ml);

    // Update all GameObjects once.
    game.Update();

    // Enemy health 18 should be reduced by 6 (missile's damage is 6)

    // After hitting the enemy, the Missile-instance should be removed from game->objects_.
    EXPECT_EQ(game.Objects().size(), 2);
}


TEST(MissileClass, update2) {
    GameGrid gg = GameGrid(testMapInfoObject1());
    Game game = Game(gg, 1, testMapInfoObject1());
    
    Pos p1 = Pos{ 20, 620 };

    Pos p2;
    p2.x = gg.EnemyPath().at(0).a.x;
    p2.y = gg.EnemyPath().at(0).a.y;
    // MissileLauncher(int radius, int fireRate, int price, Game& game, Pos position)
    MissileLauncher* ml = new MissileLauncher(100, 2, 100, &game, p1);
    // (int speed, int value, int price, int hp, Game& game, Pos position)
    FootSoldier* fs = new FootSoldier(18, 6, 6, 6, &game, p2);
    game.AddObject(fs);
    game.AddObject(ml);

    game.Update();
    
    // Enemy health 6 should be reduced by 6 (missile's damage is 6) --> Enemy-instance should be
    // removed from game->objects_.

    // After hitting the enemy, the Missile-instance should be removed from game->objects_.
    EXPECT_EQ(game.Objects().size(), 1);
}

// ----------- TEST CANNON CLASS -------------
TEST(CannonClass, update) {
    GameGrid gg = GameGrid(testMapInfoObject1());
    Game game = Game(gg, 1, testMapInfoObject1());

    Pos p2;
    p2.x = gg.EnemyPath().at(0).a.x;
    p2.y = gg.EnemyPath().at(0).a.y;

    FootSoldier* fs = new FootSoldier(18, 6, 6, 6, &game, p2);
    game.AddObject(fs);

    Pos canPos = Pos{ 20, 500 };
    Cannon* cn = new GreenCannon(&game, canPos);
    game.AddObject(cn);

    game.Objects().at(1)->update();

    EXPECT_EQ(game.Objects().size(), 3);
}

TEST(CannonClass, update2) {
    GameGrid gg = GameGrid(testMapInfoObject1());
    Game game = Game(gg, 1, testMapInfoObject1());

    Pos p2;
    p2.x = gg.EnemyPath().at(0).a.x;
    p2.y = gg.EnemyPath().at(0).a.y;

    FootSoldier* fs = new FootSoldier(2, 2, 2, 2, &game, p2);
    game.AddObject(fs);

    Pos canPos = Pos{ 2, 620 };
    Cannon* cn = new GreenCannon(&game, canPos);
    game.AddObject(cn);

    game.Update();

    EXPECT_EQ(game.Objects().size(), 1);
}

TEST(CannonClass, update3) {
    GameGrid gg = GameGrid(testMapInfoObject1());
    Game game = Game(gg, 1, testMapInfoObject1());

    Pos p2;
    p2.x = gg.EnemyPath().at(0).a.x;
    p2.y = gg.EnemyPath().at(0).a.y;

    FootSoldier* fs = new FootSoldier(4, 2, 2, 2, &game, p2);
    game.AddObject(fs);

    Pos canPos = Pos{ 0, 650 };
    Cannon* cn = new GreenCannon(&game, canPos);
    game.AddObject(cn);

    game.Update();
    
    EXPECT_EQ(game.Objects().size(), 1);
}
