#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <optional>
#include <vector>

#include "background_renderer.hpp"
#include "cannon.hpp"
#include "game.hpp"
#include "gamegrid.hpp"
#include "gameobject.hpp"
#include "testmapinfo.hpp"
#include "tower.hpp"

int main() {
  int windowWidth = 20 * 64;
  int windowHeight = 12 * 64;

  GameGrid gg = GameGrid(testMapInfoObject1());

  sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight),
                          "TestiPiirto");

  BackgroundRenderer ikkuna(window, gg);

  sf::View startView(sf::FloatRect(0, 0, windowWidth, windowHeight));
  sf::View applicationView(sf::FloatRect(0, 0, windowWidth, windowHeight));

  // Set the startView
  window.setView(startView);

  // Create startButton
  sf::RectangleShape startButton(sf::Vector2f(200, 100));
  startButton.setFillColor(sf::Color(252, 213, 38));
  startButton.setOutlineColor(sf::Color::Black);
  startButton.setOutlineThickness(4);

  // Center the button horizontally
  sf::FloatRect startButtonBounds = startButton.getLocalBounds();
  startButton.setOrigin(startButtonBounds.left + startButtonBounds.width / 2.0f,
                        0);
  startButton.setPosition(window.getSize().x / 2.0f, 400);

  sf::Font font;
  if (!font.loadFromFile("../fonts/open-sans/OpenSans-Italic.ttf")) {
    std::cout << "Error in font loading" << std::endl;
    return -1;
  }

  // Add text for the startButton
  sf::Text playText;
  playText.setFont(font);
  playText.setString("Play");
  playText.setCharacterSize(20);
  playText.setFillColor(sf::Color::White);

  // Center the text within the button
  sf::FloatRect playBounds = playText.getLocalBounds();
  playText.setOrigin(playBounds.left + playBounds.width / 2.0f,
                     playBounds.top + playBounds.height / 2.0f);
  playText.setPosition(
      startButton.getPosition().x,
      startButton.getPosition().y + startButton.getSize().y / 2.0f);

  // Create title for the game.
  sf::Text title;
  title.setString("Clash Of Armies");
  title.setCharacterSize(60);
  title.setFont(font);
  title.setFillColor(sf::Color::Red);

  // Center the text horizontally
  sf::FloatRect titleBounds = title.getLocalBounds();
  title.setOrigin(titleBounds.left + titleBounds.width / 2.0f, 0);
  title.setPosition(window.getSize().x / 2.0f, 100);

  // Toolbar parameters
  int toolbarWidth = 100;
  int toolbarHeight = window.getSize().y;

  // Create a vertical toolbar on the right side using a rectangle
  sf::RectangleShape toolbar(sf::Vector2f(toolbarWidth, toolbarHeight));
  toolbar.setPosition(window.getSize().x - toolbarWidth, 0);
  toolbar.setFillColor(sf::Color(128, 128, 128));

  // Towers to protect base: Cannon, MissileLauncher and FighterPlane
  std::vector<std::string> towersVec = {"../rsrc/tiles/weapons/tile249.png",
                                        "../rsrc/tiles/weapons/tile250.png"};

  // Add buttons to the toolbar (tower buttons)
  sf::Texture cannon, bigCannon;

  // Load tank texture
  if (!cannon.loadFromFile(towersVec[0])) {
    std::cout << "cannon loadFromFile problem." << std::endl;
    return -1;
  }

  // Load plane texture
  if (!bigCannon.loadFromFile(towersVec[1])) {
    std::cout << "bigCannon loadFromFile problem." << std::endl;
    return -1;
  }

  // Creating sprites for the towers.
  sf::Sprite cannonSprite(cannon);
  sf::Sprite bigCannonSprite(bigCannon);

  // Set positions of the buttons
  cannonSprite.setPosition(
      window.getSize().x - toolbarWidth + toolbarWidth * 0.2,
      60);  // Toolbar x-coordinate + 20

  // 20 + tank x-coordinate + tank width + 20
  bigCannonSprite.setPosition(
      window.getSize().x - toolbarWidth + toolbarWidth * 0.2, 140);

  // Creating board of tiles
  int rows = 14;
  int columns = 20;

  float tileWidth = (window.getSize().x - toolbarWidth) / (1.0 * columns);
  float tileHeight = tileWidth;

  bool startButtonClicked = false;

  std::optional<Cannon> towerClicked;

  std::vector<sf::Sprite> objects;

  // Load window
  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      switch (event.type) {
        case (sf::Event::Closed):
          window.close();
          break;

        // Button click handling
        case (sf::Event::MouseButtonPressed):
          if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePos =
                window.mapPixelToCoords(sf::Mouse::getPosition(window));

            // Is mouse over the button?

            if (startButton.getGlobalBounds().contains(mousePos)) {
              std::cout << "startButton clicked" << std::endl;
              startButtonClicked = true;
              // Switch to application view
              window.setView(applicationView);
            }

            if (startButtonClicked) {
              if (cannonSprite.getGlobalBounds().contains(mousePos)) {
                std::cout << "cannon button was clicked." << std::endl;
                towerClicked = Cannon(10, 10);
                // TODO: When clicking on this button the program should create
                // a new tank instance.
              } else if (bigCannonSprite.getGlobalBounds().contains(mousePos)) {
                std::cout << "bigCannon button was clicked." << std::endl;
              } else {
                if (towerClicked.has_value()) {
                  std::cout << "placing tower" << std::endl;
                  Cannon can = towerClicked.value();
                  sf::Sprite canSprite;

                  canSprite.setTexture(cannon);
                  canSprite.setPosition(mousePos);

                  objects.push_back(canSprite);
                  towerClicked.reset();
                }
              }
            }
          }
          break;
        case (sf::Event::MouseButtonReleased):

          break;
        // Mouse hover event
        case (sf::Event::MouseMoved):
          // Mouse position in window coordinates.
          sf::Vector2f mousePos =
              window.mapPixelToCoords(sf::Mouse::getPosition(window));

          if (startButtonClicked) {
          } else {
            sf::Color color = startButton.getFillColor();
            if (startButton.getGlobalBounds().contains(mousePos)) {
              // change opacity of the hovered startButton
              color.a = 128;
              startButton.setFillColor(color);
            } else {
              // Restore opacity
              color.a = 255;
              startButton.setFillColor(color);
            }
          }
          break;
      }
    }

    window.clear(sf::Color(200, 200, 200));
    if (!startButtonClicked) {
      window.draw(startButton);
      window.draw(playText);
      window.draw(title);
    } else {
      // Draw the tiles
      ikkuna.Draw();

      for (auto it : objects) {
        window.draw(it);
      }

      // Draw the toolbar and buttons inside it.
      window.draw(toolbar);
      window.draw(cannonSprite);
      window.draw(bigCannonSprite);
    }

    // if (window.getView().getViewport() == applicationView.getViewport()) {

    // }
    window.display();
  };
};
