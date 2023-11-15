
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "menu.hpp"
#include "state.hpp"

int main() {
  int windowWidth = 20 * 64;
  int windowHeight = 12 * 64 - 12;

  sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight),
                          "TestiPiirto");

  sf::View startView(sf::FloatRect(0, 0, windowWidth, windowHeight));
  sf::View applicationView(sf::FloatRect(0, 0, windowWidth, windowHeight));

  window.setView(startView);

  MainMenu mainMenu;
  GameState gameState = MAIN_MENU;
  GameLevel gameLevel = LEVEL_NONE;
  sf::Vector2f mousePos;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
          window.close();
          break;

        case sf::Event::Resized:
          // TODO: Update the view when the window is resized
          windowWidth = event.size.width;
          windowHeight = event.size.height;

          startView.setSize(windowWidth, windowHeight);
          applicationView.setSize(windowWidth, windowHeight);

          if (gameState == MAIN_MENU) {
            window.setView(startView);
          } else {
            window.setView(applicationView);
          }
          break;

        case sf::Event::MouseMoved:
          mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

          if (gameState == MAIN_MENU) {
            mainMenu.handleHover(mousePos);
          }
          break;

        case sf::Event::MouseLeft:
          mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

          if (gameState == MAIN_MENU) {
            mainMenu.handleClick(mousePos, gameState, gameLevel);
          }
          break;
      }
    }

    if (gameState == MAIN_MENU) {
      window.setView(startView);
      mainMenu.draw(window);
    } else {
      window.setView(applicationView);
      // TODO: Separate application view into its own class
      sf::Font font;
      if (!font.loadFromFile("../fonts/open-sans/OpenSans-Italic.ttf")) {
        std::cout << "Error in font loading" << std::endl;
        return -1;
      }

      sf::RectangleShape applicationBackground(
          sf::Vector2f(windowWidth, windowHeight));
      applicationBackground.setFillColor(sf::Color(0, 255, 255));

      // Create title for the game.
      sf::Text title;
      // Combine the string with Level number
      std::string titleString = "Level " + std::to_string(gameLevel);
      title.setString("Clash Of Armies" + titleString);
      title.setCharacterSize(60);
      title.setFont(font);
      title.setFillColor(sf::Color::Red);

      // Center the text horizontally
      sf::FloatRect titleBounds = title.getLocalBounds();
      title.setOrigin(titleBounds.left + titleBounds.width / 2.0f, 0);
      title.setPosition(window.getSize().x / 2.0f, 100);

      window.draw(applicationBackground);
      window.draw(title);
    }

    window.display();
  }

  return 0;
}
