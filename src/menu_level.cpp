#include "menu_level.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

#include "button_text.hpp"

MenuLevel::MenuLevel(std::vector<std::pair<int, std::string>> l) { levels = l; }

// Function to read levels from CSV
std::vector<std::pair<int, std::string>> readLevels(
    const std::string& filename) {
  std::vector<std::pair<int, std::string>> levels;
  std::ifstream csvFile(filename);
  if (csvFile.is_open()) {
    std::string line;
    while (std::getline(csvFile, line)) {
      std::istringstream iss(line);
      std::string level, map;
      if (std::getline(iss, level, ',') && std::getline(iss, map, ',')) {
        levels.push_back({std::stoi(level), map});
      }
    }
    csvFile.close();
  }
  return levels;
}

// Function to create buttons based on levels
std::vector<ButtonText> createLevelButtons(
    const std::vector<std::pair<int, std::string>>& levels,
    std::function<void(int)> callback, sf::Font& font,
    sf::RenderWindow& window) {
  std::vector<ButtonText> buttons;
  int marginX = 150;
  int gridColumns = 4;
  int buttonHeight = 100;
  int buttonSpacingX = 50;
  int buttonSpacingY = 50;
  int windowWidth = window.getSize().x;

  int buttonWidth =
      (windowWidth - (gridColumns - 1) * buttonSpacingX - 2 * marginX) /
      gridColumns;

  int totalWidth =
      gridColumns * (buttonWidth + buttonSpacingX) - buttonSpacingX;
  int startX = (windowWidth - totalWidth) / 2 + buttonWidth / 2;

  int currentColumn = 0;
  int currentRow = 0;

  for (const auto& level : levels) {
    auto onClick = [callback, level]() { callback(level.first); };
    ButtonText levelButton(
        sf::Vector2f(startX + currentColumn * (buttonWidth + buttonSpacingX),
                     currentRow * (buttonHeight + buttonSpacingY) + 300),
        sf::Vector2f(buttonWidth, buttonHeight), onClick,
        "Level " + std::to_string(level.first), font);
    buttons.push_back(levelButton);

    currentColumn++;
    if (currentColumn >= gridColumns) {
      currentColumn = 0;
      currentRow++;
    }
  }

  return buttons;
}

std::pair<int, int> MenuLevel::run(sf::RenderWindow& window) {
  window.clear();
  int windowWidth = window.getSize().x;
  int windowHeight = window.getSize().y;

  // Load background image
  sf::Texture backgroundTexture;
  if (!backgroundTexture.loadFromFile("../rsrc/background/menu.jpg")) {
    std::cerr << "Error loading background image." << std::endl;
    return std::make_pair(-1, 0);
  }
  sf::Sprite backgroundSprite(backgroundTexture);
  backgroundSprite.setScale(
      static_cast<float>(windowWidth) / backgroundTexture.getSize().x,
      static_cast<float>(windowHeight) / backgroundTexture.getSize().y);

  sf::Font font;
  if (!font.loadFromFile("../fonts/pixieboy.ttf")) {
    std::cout << "Error in font loading" << std::endl;
    return std::make_pair(-1, 0);
  }

  int gameLevel = 0;
  auto onLevelSelect = [this, &gameLevel](int selectedLevel) {
    std::cout << "Selected level: " << selectedLevel << std::endl;
    gameLevel = selectedLevel;
  };
  std::vector<ButtonText> levelButtons =
      createLevelButtons(levels, onLevelSelect, font, window);

  sf::Vector2f mousePos =
      window.mapPixelToCoords(sf::Mouse::getPosition(window));

  while (window.isOpen()) {
    sf::Event event;

    if (gameLevel != 0) {
      return std::make_pair(2, gameLevel);
    }

    while (window.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
          window.close();
          break;

        case sf::Event::MouseMoved:
          mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
          for (auto& button : levelButtons) {
            button.handleHover(mousePos);
          }
          break;

        case sf::Event::MouseButtonPressed:
          if (event.mouseButton.button == sf::Mouse::Left) {
            mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            for (const auto& button : levelButtons) {
              button.handleClick(mousePos);
            }
          }
          break;
      };
    }

    window.clear();

    window.draw(backgroundSprite);
    for (const auto& button : levelButtons) {
      button.draw(window);
    }

    window.display();
  }

  return std::make_pair(2, gameLevel);
}