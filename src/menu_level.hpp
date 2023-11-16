#pragma once

#include <SFML/Graphics.hpp>

class MenuLevel {
 public:
  MenuLevel(std::vector<std::pair<int, std::string>>);

  std::pair<int, int> run(sf::RenderWindow& window);

 private:
  std::vector<std::pair<int, std::string>> levels;
};

std::vector<std::pair<int, std::string>> readLevels(
    const std::string& filename);