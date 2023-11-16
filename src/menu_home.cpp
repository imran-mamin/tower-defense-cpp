#include "menu_home.hpp"

#include <iostream>

#include "button.hpp"
#include "menu_level.hpp"

MenuHome::MenuHome() {}

int MenuHome::run(sf::RenderWindow& window) {
  window.clear();
  int windowWidth = window.getSize().x;
  int windowHeight = window.getSize().y;

  // Load background image
  sf::Texture backgroundTexture;
  if (!backgroundTexture.loadFromFile("../rsrc/background/menu.jpg")) {
    std::cerr << "Error loading background image." << std::endl;
    return (-1);
  }
  sf::Sprite backgroundSprite(backgroundTexture);
  backgroundSprite.setScale(
      static_cast<float>(windowWidth) / backgroundTexture.getSize().x,
      static_cast<float>(windowHeight) / backgroundTexture.getSize().y);

  sf::Font font;
  if (!font.loadFromFile("../fonts/pixieboy.ttf")) {
    std::cout << "Error in font loading" << std::endl;
    return (-1);
  }

  // Define a function to be executed when the button is clicked
  int page = 0;
  auto onPlay = [&page]() { page = 1; };
  Button playButton(sf::Vector2f(windowWidth / 2.0f, windowHeight / 2.0f),
                    sf::Vector2f(200, 50), onPlay, "Play", font);

  auto onExit = [&window]() { window.close(); };
  Button exitButton(sf::Vector2f(windowWidth / 2.0f, windowHeight / 2.0f + 100),
                    sf::Vector2f(200, 50), onExit, "Quit", font);

  sf::Vector2f mousePos =
      window.mapPixelToCoords(sf::Mouse::getPosition(window));

  while (window.isOpen()) {
    if (page != 0) {
      return page;
    }

    sf::Event event;

    while (window.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
          window.close();
          break;

        case sf::Event::MouseMoved:
          mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
          playButton.handleHover(mousePos);
          exitButton.handleHover(mousePos);
          break;

        case sf::Event::MouseButtonPressed:
          if (event.mouseButton.button == sf::Mouse::Left) {
            mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            playButton.handleClick(mousePos);
            exitButton.handleClick(mousePos);
          }
          break;
      };
    }
    window.clear();

    window.draw(backgroundSprite);
    playButton.draw(window);
    exitButton.draw(window);

    window.display();
  }

  return page;
}