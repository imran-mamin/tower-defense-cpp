
#include "background_renderer.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <cstddef>
#include <vector>

#include "gamegrid.hpp"
#include "path.hpp"

bool BackgroundRenderer::textureAlreadyLoaded(std::uint16_t textureId) const {
  std::map<std::uint16_t, sf::Texture> textures_;
  try {
    sf::Texture t = textures_.at(textureId);
  } catch (const std::out_of_range &e) {
    return false;
  }

  return true;
}

BackgroundRenderer::BackgroundRenderer(sf::RenderWindow &renderWindow,
                                       GameGrid &gameGrid)
    : Renderer(renderWindow) {
  /* Load background textures and sprites. */
  for (std::size_t j = 0; j < gameGrid.Height(); j++) {
    for (std::size_t i = 0; i < gameGrid.Width(); i++) {
      std::uint16_t bgTextureId = gameGrid.Tiles()[j][i].Id();

      /* Load texture if it's not already loaded. */
      if (!textureAlreadyLoaded(bgTextureId)) {
        /* TODO: Create a function for getting resource paths. */
        const std::string texturePath = BACKGROUND_TILE_DIRECTORY +
                                        std::to_string(bgTextureId) + "" +
                                        ".png";

        sf::Texture texture;
        if (!texture.loadFromFile(texturePath)) {
          /* TODO: Replace with a proper exception type. */
          throw std::runtime_error(
              std::string("Failed to load texture from '") + texturePath + "'");
        }
        textures_[bgTextureId] = texture;
      }

      /* Load sprite. */
      sf::Sprite sprite;
      sprite.setPosition(
          sf::Vector2f(i * gameGrid.TileWidth(), j * gameGrid.TileWidth()));
      sprite.setTexture(textures_[bgTextureId]);
      sprites_.push_back(sprite);
    }
  }
  // Load obstacles
  for (auto obstacle : gameGrid.ObstacleInfo()) {
    std::uint16_t obTextureId = obstacle.first;
    if (!textureAlreadyLoaded(obTextureId)) {
      sf::Texture texture;
      if (!texture.loadFromFile("../rsrc/tiles/obstacles/" +
                                std::to_string(obstacle.first) + ".png")) {
        throw std::runtime_error("Error loading obstacle Texture");
      };
      textures_[obTextureId] = texture;
    }
    sf::Sprite sprite(textures_[obTextureId]);
    sprite.setPosition(obstacle.second.first, obstacle.second.second);
    sprites_.push_back(sprite);
  }
}

void BackgroundRenderer::Draw() {
  for (auto sprite : sprites_) {
    renderWindow_.draw(sprite);
  }
}
