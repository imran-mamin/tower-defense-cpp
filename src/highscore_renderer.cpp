#include "highscore_renderer.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "highscores.hpp"
#include "renderer.hpp"

HighScoreRenderer::HighScoreRenderer(sf::RenderWindow& renderWindow,
                                     const HighScores& highscores,
                                     const std::uint8_t levelcount,
                                     int windowWidth)
    : Renderer(renderWindow),
      highscores_(highscores),
      levelcount_(levelcount),
      windowWidth_(windowWidth) {
  LoadScores();
}

void HighScoreRenderer::LoadScores() {
  for (int level = 1; level <= levelcount_; ++level) {
    highscoretable_[level] = highscores_.LevelHighscores(level);
  }
}

void HighScoreRenderer::Draw() {
  // load font
  sf::Font font;
  if (!font.loadFromFile("../fonts/pixieboy.ttf")) {
    std::cout << "Error in font loading for highscores" << std::endl;
  }

  for (auto i = 0; i < levelcount_; ++i) {
    sf::Text levelNoText;
    levelNoText.setFont(font);
    levelNoText.setString("Level" + std::to_string(i + 1));
    levelNoText.setPosition(100 + windowWidth_ / levelcount_ * i, 130);
    renderWindow_.draw(levelNoText);
  }
}