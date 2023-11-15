#include "menu.hpp"

#include <iostream>

#include "state.hpp"

void centerButtonAndText(sf::RectangleShape& button, sf::Text& buttonText,
                         float yPos, sf::RenderWindow& window) {
  // Center the button horizontally
  sf::FloatRect buttonBounds = button.getLocalBounds();
  button.setOrigin(buttonBounds.left + buttonBounds.width / 2.0f, 0);
  button.setPosition(window.getSize().x / 2.0f, yPos);

  // Center the text within the button
  sf::FloatRect textBounds = buttonText.getLocalBounds();
  buttonText.setOrigin(textBounds.left + textBounds.width / 2.0f,
                       textBounds.top + textBounds.height / 2.0f);
  buttonText.setPosition(button.getPosition().x,
                         button.getPosition().y + button.getSize().y / 2.0f);
}

MainMenu::MainMenu() {
  if (!font.loadFromFile("../fonts/open-sans/OpenSans-Italic.ttf")) {
    std::cout << "Error in font loading" << std::endl;
    return;
  }

  setupMenu();
}

void MainMenu::setupMenu() {
  // Set up title
  title.setFont(font);
  title.setCharacterSize(40);
  title.setString("Clash of Armies");
  title.setFillColor(sf::Color::Black);

  // Set up Level 1 button
  level1Button.setSize(sf::Vector2f(200, 50));
  level1Button.setFillColor(sf::Color(230, 126, 34));  // Carrot orange

  // Set up "Level 1" text
  level1Text.setFont(font);
  level1Text.setCharacterSize(30);
  level1Text.setString("Level 1");

  // Set up Level 2 button
  level2Button.setSize(sf::Vector2f(200, 50));
  level2Button.setFillColor(sf::Color(211, 84, 0));  // Pumpkin orange

  // Set up "Level 2" text
  level2Text.setFont(font);
  level2Text.setCharacterSize(30);
  level2Text.setString("Level 2");

  // Set up Level 3 button
  level3Button.setSize(sf::Vector2f(200, 50));
  level3Button.setFillColor(sf::Color(26, 188, 156));  // Turquoise green

  // Set up "Level 3" text
  level3Text.setFont(font);
  level3Text.setCharacterSize(30);
  level3Text.setString("Level 3");
}

void MainMenu::draw(sf::RenderWindow& window) {
  window.clear(sf::Color(236, 240, 241));  // Light gray background

  int windowWidth = window.getSize().x;
  int windowHeight = window.getSize().y;

  title.setPosition(windowWidth * 0.5f - title.getGlobalBounds().width * 0.5f,
                    windowHeight * 0.1f);

  centerButtonAndText(level1Button, level1Text, windowHeight * 0.4f, window);
  centerButtonAndText(level2Button, level2Text, windowHeight * 0.5f, window);
  centerButtonAndText(level3Button, level3Text, windowHeight * 0.6f, window);

  window.draw(title);
  window.draw(level1Button);
  window.draw(level1Text);
  window.draw(level2Button);
  window.draw(level2Text);
  window.draw(level3Button);
  window.draw(level3Text);
}

void MainMenu::handleHover(sf::Vector2f mousePosition) {
  // Check if the mouse is over the Level 1 button
  if (level1Button.getGlobalBounds().contains(mousePosition)) {
    level1Button.setFillColor(
        sf::Color(243, 156, 18));  // Brighter orange on hover
  } else {
    level1Button.setFillColor(
        sf::Color(230, 126, 34));  // Original carrot orange
  }

  // Check if the mouse is over the Level 2 button
  if (level2Button.getGlobalBounds().contains(mousePosition)) {
    level2Button.setFillColor(
        sf::Color(230, 74, 25));  // Brighter pumpkin orange on hover
  } else {
    level2Button.setFillColor(
        sf::Color(211, 84, 0));  // Original pumpkin orange
  }

  // Check if the mouse is over the Level 3 button
  if (level3Button.getGlobalBounds().contains(mousePosition)) {
    level3Button.setFillColor(
        sf::Color(22, 160, 133));  // Brighter turquoise green on hover
  } else {
    level3Button.setFillColor(
        sf::Color(26, 188, 156));  // Original turquoise green
  }
}

void MainMenu::handleClick(sf::Vector2f mousePosition, GameState& gameState,
                           GameLevel& gameLevel) {
  if (level1Button.getGlobalBounds().contains(mousePosition)) {
    std::cout << "Level 1 Clicked" << std::endl;
    gameState = IN_GAME;
    gameLevel = LEVEL_1;
  }

  else if (level2Button.getGlobalBounds().contains(mousePosition)) {
    std::cout << "Level 2 Clicked" << std::endl;
    gameState = IN_GAME;
    gameLevel = LEVEL_2;
  }

  else if (level3Button.getGlobalBounds().contains(mousePosition)) {
    std::cout << "Level 3 Clicked" << std::endl;
    gameState = IN_GAME;
    gameLevel = LEVEL_3;
  }
}
