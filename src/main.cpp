#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <optional>
#include <vector>

#include "background_renderer.hpp"
#include "cannon.hpp"
#include "game.hpp"
#include "gamegrid.hpp"
#include "gameloop.hpp"
#include "gameobject.hpp"
#include "map_tile_selector_renderer.hpp"
#include "testmapinfo.hpp"
#include "tower.hpp"

// Imran includes
#include "footsoldier.hpp"


int main() {
  int windowWidth = 20 * 64;
  int windowHeight = 12 * 64;

  GameGrid gg = GameGrid(testMapInfoObject1());
  Game game = Game(gg);

  sf::Sprite sp;
  Pos p;
  p.x = gg.EnemyPath().at(0).a.x;
  p.y = gg.EnemyPath().at(0).a.y;
  // (int speed, int value, int price, int hp, sf::Sprite sprite, Game& game, Pos position)
  FootSoldier fs = FootSoldier(1, 6, 6, 18, sp, game, p);
  game.AddObject(fs);
  
  std::cout << "(x, y) = (" << fs.getPosition().x << ", " << fs.getPosition().y << ")" << std::endl;
  fs.update();
  std::cout << "(x, y) = (" << fs.getPosition().x << ", " << fs.getPosition().y << ")" << std::endl;

  sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight),
                          "TestiPiirto");

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
          window.close();
          break;
      }
    }
  }
  return 0;
  // GameLoop loop(window, game);

  // loop.Play();
};
