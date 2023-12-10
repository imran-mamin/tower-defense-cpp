
#include "weapon_toolbar_renderer.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include <iterator>
#include <optional>

#include "renderer.hpp"
#include "texture_manager.hpp"
#include "weapons_and_enemies.hpp"

WeaponToolbarRenderer::WeaponToolbarRenderer(
    sf::RenderWindow &renderWindow, GameGrid &gameGrid,
    std::optional<std::uint16_t> &selectedTower, sf::Event &gameEvent)
    : Renderer(renderWindow),
      gameGrid_(gameGrid),
      textureManager_(TextureManager::GetInstance()),
      selectedTower_(selectedTower),
      gameEvent_(gameEvent) {
  /**if (renderWindow_a){

  }**/ // TODO: Validate that the window height is gameGrid.w * tilewidth + toolbarWidth

  greenCannonSprite_ = sf::Sprite(textureManager_.GetTexture(
      weaponToTileIDMapping.at(WeaponType::GreenCannon)));
  redCannonSprite_ = sf::Sprite(textureManager_.GetTexture(
      weaponToTileIDMapping.at(WeaponType::RedCannon)));
  basicMissileLauncherSprite_ = sf::Sprite(textureManager_.GetTexture(
      weaponToTileIDMapping.at(WeaponType::MissileLauncher1)));

  /* Set the sprite positions. */
  greenCannonSprite_.setPosition(gameGrid_.Width() * gameGrid_.TileWidth(), 60);
  redCannonSprite_.setPosition(gameGrid_.Width() * gameGrid_.TileWidth(), 140);
  basicMissileLauncherSprite_.setPosition(
      gameGrid_.Width() * gameGrid_.TileWidth(), 220);
}

/* Helper. */
bool WeaponToolbarRenderer::IsCoordinateInsideTheToolbar(
    std::uint32_t x, std::uint32_t y) const {
  return x >= gameGrid_.Width() * gameGrid_.TileWidth() &&
         x <=
             gameGrid_.Width() * gameGrid_.TileWidth() + WeaponToolbarWidthPx &&
         y <= gameGrid_.Height() * gameGrid_.TileWidth();
}

void WeaponToolbarRenderer::Draw() {
  /* Create vertical toolbar on the right side of the game grid. */
  sf::RectangleShape toolbar(sf::Vector2f(
      WeaponToolbarWidthPx, gameGrid_.Height() * gameGrid_.TileWidth()));
  toolbar.setPosition(renderWindow_.getSize().x - WeaponToolbarWidthPx, 0);
  toolbar.setFillColor(sf::Color(128, 128, 128));

  /* Draw the toolbar. */
  renderWindow_.draw(toolbar);

  /* Draw the button sprites. */
  renderWindow_.draw(greenCannonSprite_);
  renderWindow_.draw(redCannonSprite_);
  renderWindow_.draw(basicMissileLauncherSprite_);
}

const sf::FloatRect WeaponToolbarRenderer::GreenCannonButtonGlobalBounds()
    const {
  return greenCannonSprite_.getGlobalBounds();
}

const sf::FloatRect WeaponToolbarRenderer::RedCannonButtonGlobalBounds() const {
  return redCannonSprite_.getGlobalBounds();
}

const sf::FloatRect WeaponToolbarRenderer::MissileLauncher1ButtonGlobalBounds()
    const {
  return basicMissileLauncherSprite_.getGlobalBounds();
}
