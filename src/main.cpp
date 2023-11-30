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
#include "map_parser.hpp"
#include "tower.hpp"

int main() {
  int windowWidth = 20 * 64;
  int windowHeight = 12 * 64;

  GameGrid gg = GameGrid(ParseMap("../rsrc/maps/map1.json"));
  Game game = Game(gg);

  sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight),
                          "TestiPiirto");

  GameLoop loop(window, game);

  loop.Play();
};
