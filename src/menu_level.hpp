#ifndef MENU_LEVEL_HPP
#define MENU_LEVEL_HPP

#include <SFML/Graphics.hpp>

class MenuLevel {
 public:
  MenuLevel(std::vector<std::pair<int, std::string>>);

  std::pair<int, int> run(sf::RenderWindow& window);

 private:
  std::vector<std::pair<int, std::string>> levels;
};

#endif

std::vector<std::pair<int, std::string>> readLevels(
    const std::string& filename);