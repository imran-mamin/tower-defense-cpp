#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>

#include "state.hpp"

class MainMenu {
 public:
  MainMenu();

  void draw(sf::RenderWindow& window);
  void handleHover(sf::Vector2f mousePosition);
  void handleClick(sf::Vector2f mousePosition, GameState& gameState,
                   GameLevel& gameLevel);

 private:
  sf::Font font;
  sf::Text title;
  sf::RectangleShape level1Button;
  sf::Text level1Text;
  sf::RectangleShape level2Button;
  sf::Text level2Text;
  sf::RectangleShape level3Button;
  sf::Text level3Text;

  void setupMenu();
};

#endif
