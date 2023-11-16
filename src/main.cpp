#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>
#include <vector>

#include "menu_home.hpp"
#include "menu_level.hpp"
#include "music_manager.hpp"

int main() {
  int windowWidth = 20 * 64;
  int windowHeight = 12 * 64 - 12;

  sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight),
                          "TestiPiirto");

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
      case 2:
        // TODO: Game Screen
        if (gameLevel <= 0) {
          std::cerr << "Error: gameLevel is " << gameLevel << std::endl;
          return -1;
        }
        std::cout << "Game Start: gameLevel is " << gameLevel << std::endl;
        window.close();
        break;

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
