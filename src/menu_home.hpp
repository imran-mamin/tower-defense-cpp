#pragma once

#include <SFML/Graphics.hpp>

#include "button.hpp"
#include "music_manager.hpp"

class MenuHome {
 public:
  MenuHome(MusicManager& musicManager);

  int run(sf::RenderWindow& window);

 private:
  Button musicButton;
  MusicManager& musicManager;
  sf::Texture textureMusicOn;
  sf::Texture textureMusicOff;
};
