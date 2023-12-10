#include "menu_home.hpp"

#include <iostream>

#include "button_text.hpp"
#include "menu_level.hpp"
#include "music_manager.hpp"

MenuHome::MenuHome(MusicManager& musicManager) : musicManager(musicManager) {
  textureMusicOn.loadFromFile("../rsrc/icons/music-on.png");
  textureMusicOff.loadFromFile("../rsrc/icons/music-off.png");
}

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
  ButtonText playButton(sf::Vector2f(windowWidth / 2.0f, windowHeight / 2.5f),
                        sf::Vector2f(200, 50), onPlay, "Play", font);

  auto onExit = [&window]() { window.close(); };
  ButtonText exitButton(
      sf::Vector2f(windowWidth / 2.0f, windowHeight / 2.5f + 100),
      sf::Vector2f(200, 50), onExit, "Quit", font);

  auto onHS = [&page]() { page = 5; };
  ButtonText hsButton(
      sf::Vector2f(windowWidth / 2.0f, windowHeight / 2.5f + 200),
      sf::Vector2f(200, 50), onHS, "HighScores", font);

  auto onMute = [this]() {
    musicManager.toggleMusic();
    musicButton.setTexture(musicManager.isMusicOn() ? textureMusicOn
                                                    : textureMusicOff);
  };
  musicButton =
      Button(sf::Vector2f(windowWidth - 60, 60), sf::Vector2f(50, 50), onMute);
  musicButton.setTexture(musicManager.isMusicOn() ? textureMusicOn
                                                  : textureMusicOff);
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
          hsButton.handleHover(mousePos);
          musicButton.handleHover(mousePos);
          break;

        case sf::Event::MouseButtonPressed:
          if (event.mouseButton.button == sf::Mouse::Left) {
            mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            playButton.handleClick(mousePos);
            exitButton.handleClick(mousePos);
            hsButton.handleClick(mousePos);
            musicButton.handleClick(mousePos);
          }
          break;
        default:
          break;
      }
    }
    window.clear();

    window.draw(backgroundSprite);
    musicButton.draw(window);
    playButton.draw(window);
    exitButton.draw(window);
    hsButton.draw(window);

    window.display();
  }

  return page;
}
