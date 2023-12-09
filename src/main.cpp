#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>
#include <vector>

#include "game.hpp"
#include "gamegrid.hpp"
#include "gameloop.hpp"
#include "menu_home.hpp"
#include "menu_level.hpp"
#include "music_manager.hpp"
#include "time.hpp"
#include "path.hpp"
#include "weapon_toolbar_renderer.hpp"

int main() {
  int windowWidth = 20 * 64;
  int windowHeight = 12 * 64;

  sf::RenderWindow window(sf::VideoMode(windowWidth + WeaponToolbarWidthPx, windowHeight),
                          "Clash Of Armies");
  window.setFramerateLimit(ticksPerSecond);

  std::vector<std::pair<int, std::string>> levels =
      readLevels("../rsrc/level.csv");

  int page = 0;
  int gameLevel = 0;
  MusicManager musicManager;
  MenuLevel menuLevel(levels);
  MenuHome menuHome(musicManager);

  std::pair<int, int> resp;

  while (window.isOpen()) {
    switch (page) {
      case 1:
        // Level Selection Screen
        resp = menuLevel.run(window);
        page = resp.first;
        gameLevel = resp.second;

        break;
      case 2: {
        auto levelIt = std::find_if(levels.begin(), levels.end(),
                                    [gameLevel](const auto& level) {
                                      return level.first == gameLevel;
                                    });
        if (levelIt == levels.end()) {
          std::cerr << "Error: gameLevel " << gameLevel << " not found"
                    << std::endl;
          return -1;
        }

        std::cout << "Game Start: gameLevel is " << gameLevel << std::endl;
        std::string mapFilename = levelIt->second;
        std::string fullMapPath = "../rsrc/maps/" + mapFilename;

        MapInfo mapInfo = ParseMap(fullMapPath);
        GameGrid gg = GameGrid(mapInfo);
        Game game = Game(gg, gameLevel, mapInfo);
        GameLoop loop(window, game);

        loop.Play();

        // Back to main menu on game exit
        page = 0;
        break;
      }
      default:
        // Main Menu Screen
        if (page < 0) {
          return page;
        }

        page = menuHome.run(window);
        break;
    }
  }

  return 0;
}
