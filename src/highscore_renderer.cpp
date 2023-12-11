#include "highscore_renderer.hpp"

#include <SFML/Graphics.hpp>

#include "highscores.hpp"
#include "renderer.hpp"

HighScoreRenderer::HighScoreRenderer(sf::RenderWindow& renderWindow,
                                     const HighScores& highscores,
                                     int levelcount)
    : Renderer(renderWindow), highscores_(highscores), levelcount_(levelcount) {
  LoadScores();
}

HighScoreRenderer::LoadScores() {
  for (int level = 1; level <= levelcount_; ++level) {
    highscoretable_[level] = highscores_.LevelHighscores(level);
  }
}

void HighScores::Draw() {
  // load font
  sf::Font font;
  if (!font.loadFromFile("../fonts/pixieboy.ttf")) {
    std::cout << "Error in font loading" << std::endl;
  }

  for (auto i = 0; i < levelcount_; ++i) {
    sf::Text levelNoText;
    levelNoText.setFont(font);
    text.setString("Level" + std::to_string(i));
  }
}