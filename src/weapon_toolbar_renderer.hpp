
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Window/Event.hpp>
#include <cstdint>
#include <optional>

#include "game.hpp"
#include "gamegrid.hpp"
#include "renderer.hpp"
#include "texture_manager.hpp"

const std::uint32_t WeaponToolbarWidthPx = 68;

class WeaponToolbarRenderer : public Renderer {
 public:
  WeaponToolbarRenderer(sf::RenderWindow &renderWindow, GameGrid &gameGrid,
                        std::optional<std::uint16_t> &selectedTower,
                        sf::Event &gameEvent);
  ~WeaponToolbarRenderer() = default;

  void Draw() override;

  /* Hack. */
  const sf::FloatRect GreenCannonButtonGlobalBounds() const;
  const sf::FloatRect RedCannonButtonGlobalBounds() const;
  const sf::FloatRect MissileLauncher1ButtonGlobalBounds() const;

  bool IsCoordinateInsideTheToolbar(std::uint32_t x, std::uint32_t y) const;

 private:
  GameGrid &gameGrid_;
  TextureManager &textureManager_;
  std::optional<std::uint16_t> &selectedTower_;
  sf::Event &gameEvent_;

  sf::Sprite greenCannonSprite_;
  sf::Sprite redCannonSprite_;
  sf::Sprite basicMissileLauncherSprite_;
};
