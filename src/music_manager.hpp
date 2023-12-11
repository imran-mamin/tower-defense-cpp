#pragma once

#include <SFML/Audio.hpp>
#include <iostream>

class MusicManager {
 public:
  MusicManager() {
    if (!music.openFromFile("../rsrc/music/lady-of-the-80s.ogg")) {
      std::cerr << "Error loading music." << std::endl;
    }
    music.setVolume(3);
    music.play();
  }

  void toggleMusic() {
    musicOn = !musicOn;
    if (musicOn) {
      music.play();
    } else {
      music.pause();
    }
  }

  bool isMusicOn() const { return musicOn; }

 private:
  sf::Music music;
  bool musicOn = true;
};