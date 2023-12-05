#include "gameloop.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <cstdint>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

#include "background_renderer.hpp"
#include "button_text.hpp"
#include "cannon.hpp"
#include "enemy_path_renderer.hpp"
#include "footsoldier.hpp"
#include "game.hpp"
#include "gamegrid.hpp"
#include "gameobject.hpp"
#include "gameobject_renderer.hpp"
#include "map_tile_selector_renderer.hpp"
#include "missilelauncher.hpp"
#include "testmapinfo.hpp"
#include "texture_manager.hpp"
#include "tower.hpp"

int GameLoop::Play() {
  int windowWidth = 20 * 64;
  int windowHeight = 12 * 64;

  // Toolbar dimensions
  int toolbarWidth = 68;
  int toolbarHeight = window_.getSize().y;

  sf::Font font;
  if (!font.loadFromFile("../fonts/pixieboy.ttf")) {
    std::cout << "Error in font loading" << std::endl;
    return (-1);
  }

  TextureManager &textureManager = TextureManager::GetInstance();

  std::map<std::string, std::uint16_t> weaponNameIdMapping;
  weaponNameIdMapping["greencannon"] = 248;
  weaponNameIdMapping["redcannon"] = 249;
  weaponNameIdMapping["missilelauncher"] = 205;

  GameGrid &grid = game_.GetGrid();
  int level = game_.GetLevel();

  /* Renderers. */
  BackgroundRenderer ikkuna(window_, grid);
  /* For debug purposes.*/
  EnemyPathRenderer enemyPathRenderer(window_, grid);
  GameObjectRenderer gameobjectRenderer(window_, game_);

  sf::View applicationView(sf::FloatRect(0, 0, windowWidth, windowHeight));

  window_.setView(applicationView);

  // Create a vertical toolbar on the right side using a rectangle
  sf::RectangleShape toolbar(sf::Vector2f(toolbarWidth, toolbarHeight));
  toolbar.setPosition(window_.getSize().x - toolbarWidth, 0);
  toolbar.setFillColor(sf::Color(128, 128, 128));

  sf::Text levelText;
  levelText.setString("Level " + std::to_string(level));
  levelText.setPosition(20, 10);
  levelText.setFont(font);
  levelText.setFillColor(sf::Color::White);

  int exit = 0;
  auto onExit = [&exit]() { exit = 1; };
  ButtonText exitButton(sf::Vector2f(windowWidth - 200, windowHeight - 50),
                        sf::Vector2f(200, 50), onExit, "Exit", font);

  //////////////////////
  // TODO: Move to menu.
  // Add buttons to the toolbar (tower buttons)
  // Creating sprites for the towers.
  sf::Sprite greenCannonSprite(
      textureManager.GetTexture(weaponNameIdMapping["greencannon"]));
  sf::Sprite redCannonSprite(
      textureManager.GetTexture(weaponNameIdMapping["redcannon"]));
  sf::Sprite missileLauncherSprite(
      textureManager.GetTexture(weaponNameIdMapping["missilelauncher"]));

  // Set positions of the buttons
  greenCannonSprite.setPosition(window_.getSize().x - toolbarWidth + 3,
                                60);  // Toolbar x-coordinate + 20
  // 20 + tank x-coordinate + tank width + 20
  redCannonSprite.setPosition(window_.getSize().x - toolbarWidth + 3, 140);
  missileLauncherSprite.setPosition(window_.getSize().x - toolbarWidth + 3,
                                    220);
  // TODO: Move to menu.
  //////////////////////

  /* Selected tower id and the renderer that utilizes it. */
  std::optional<std::uint16_t> selectedTower;
  MapTileSelectorRenderer tileSelector(window_, grid, textureManager,
                                       selectedTower);

  // Load window
  while (window_.isOpen()) {
    sf::Event event;

    // TODO: Separate the views.

    while (window_.pollEvent(event)) {
      switch (event.type) {
        case (sf::Event::Closed):
          window_.close();
          break;

        // Button click handling
        case (sf::Event::MouseButtonPressed):
          if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePos =
                window_.mapPixelToCoords(sf::Mouse::getPosition(window_));

            exitButton.handleClick(mousePos);

            // TODO: Needs to be put in a menu view.
            if (greenCannonSprite.getGlobalBounds().contains(mousePos)) {
              std::cout << "green cannon button was clicked." << std::endl;

              if (selectedTower.has_value() &&
                  (selectedTower.value() ==
                   weaponNameIdMapping["greencannon"])) {
                selectedTower.reset();
              } else {
                selectedTower = weaponNameIdMapping["greencannon"];
              }

              // TODO: When clicking on this button the
              // program should create a new tank instance.
            } else if (redCannonSprite.getGlobalBounds().contains(mousePos)) {
              std::cout << "red cannon button was clicked." << std::endl;
              if (selectedTower.has_value() &&
                  (selectedTower.value() == weaponNameIdMapping["redcannon"])) {
                selectedTower.reset();
              } else {
                selectedTower = weaponNameIdMapping["redcannon"];
              }

            } else if (missileLauncherSprite.getGlobalBounds().contains(
                           mousePos)) {
              std::cout << "missile launcher button was clicked." << std::endl;
              if (selectedTower.has_value() &&
                  selectedTower.value() ==
                      weaponNameIdMapping["missilelauncher"]) {
                selectedTower.reset();
              } else {
                selectedTower = weaponNameIdMapping["missilelauncher"];
              }
            }
            // TODO: Wtf??? Remove the redundant else clause.
            else {
              if (auto selectedTile =
                      grid.TileAtAbsoluteCoordinate(mousePos.x, mousePos.y);
                  selectedTower.has_value() && selectedTile.isFree()) {
                // const Pos selectedTilePos = Pos{ mousePos.x /
                // grid.TileWidth() * grid.TileWidth(), mousePos.y /
                // grid.TileWidth() * grid.TileWidth() };
                const Pos selectedTilePos =
                    grid.AbsoluteCoordinateToClosestTilePosition(mousePos.x,
                                                                 mousePos.y);
                std::cout << "placing tower" << std::endl;
                selectedTile.occupy();
                // TODO: Is the has_value redundant?
                if (selectedTower.has_value() &&
                    selectedTower.value() ==
                        weaponNameIdMapping["greencannon"]) {
                  game_.AddObject(new GreenCannon(game_, selectedTilePos));
                } else if (selectedTower.has_value() &&
                           selectedTower.value() ==
                               weaponNameIdMapping["redcannon"]) {
                  game_.AddObject(new RedCannon(game_, selectedTilePos));
                } else if (selectedTower.has_value() && selectedTower.value()) {
                  game_.AddObject(
                      new BasicMissileLauncher(game_, selectedTilePos));
                } else {
                  throw std::runtime_error("Not implemented.");
                }

                selectedTower.reset();
              }
            }
          }
          break;

        case (sf::Event::MouseButtonReleased):
          break;

        // Mouse hover event
        case (sf::Event::MouseMoved):
          // Mouse position in window coordinates.
          sf::Vector2f mousePos =
              window_.mapPixelToCoords(sf::Mouse::getPosition(window_));

          exitButton.handleHover(mousePos);

          break;
      }
    }

    window_.clear(sf::Color(200, 200, 200));

    /* Draw the background. */
    ikkuna.Draw();

    /* Draw the tile selector. */
    tileSelector.Draw();

    /* Debug: Draw the enemy path and hightlight the path tiles on blue. */
    enemyPathRenderer.Draw();

    /* Draw the game object. */
    gameobjectRenderer.Draw();

    window_.draw(levelText);
    exitButton.draw(window_);

    // Draw the toolbar and buttons inside it.
    window_.draw(toolbar);
    window_.draw(greenCannonSprite);
    window_.draw(redCannonSprite);
    window_.draw(missileLauncherSprite);

    window_.display();

    if (exit == 1) {
      return 0;
    }
  }
  return 0;
}
