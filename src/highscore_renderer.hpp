#pragma once

#include <SFML/Graphics.hpp>

#include "highscores.hpp"
#include "renderer.hpp"

class HighScoreRenderer : public Renderer {
 public:
  HighScoreRenderer(sf::RenderWindow& renderWindow,
                    const HighScores& highscores,
                    const std::uint8_t levelcount);

  ~WeaponToolbarRenderer() = default;

  void Draw() override;

  void LoadScores();

 private:
  HighScores& highscores_;
  int levelcount_;
  std::map<std::uint32_t, std::vector<std::uint64_t>> highscoretable_;
}