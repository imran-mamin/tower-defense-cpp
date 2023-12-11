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
  // Load background image
  sf::Texture backgroundTexture;
  if (!backgroundTexture.loadFromFile("../rsrc/background/gg.png")) {
    std::cerr << "Error loading hsbackground image." << std::endl;
  }
  sf::Sprite backgroundSprite(backgroundTexture);
  backgroundSprite.setScale(static_cast<float>(renderWindow_.getSize().x) /
                                backgroundTexture.getSize().x,
                            static_cast<float>(renderWindow_.getSize().y) /
                                backgroundTexture.getSize().y);
  renderWindow_.draw(backgroundSprite);
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
    std::vector<std::uint64_t> levelScores = highscoretable_[i + 1];

    if (levelScores.size() > 0) {
      for (size_t x = 0; x < levelScores.size(); ++x) {
        sf::Text hsText;
        hsText.setFont(font);
        hsText.setString(std::to_string(levelScores[x]));
        hsText.setPosition(105 + windowWidth_ / levelcount_ * i,
                           190 + (x * 60));
        renderWindow_.draw(hsText);
      }
    }
  }
}