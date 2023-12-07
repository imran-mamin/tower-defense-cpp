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
#include "button_sprite.hpp"
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
  int playerMoney = game_.GetPlayerMoney();

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

  //////////////////////
  // Add buttons to the toolbar (tower buttons)
  /* Selected tower id and the renderer that utilizes it. */
  std::optional<std::uint16_t> selectedTower;
  MapTileSelectorRenderer tileSelector(window_, grid, textureManager,
                                       selectedTower);

  sf::Sprite greenCannonSprite(
      textureManager.GetTexture(weaponNameIdMapping["greencannon"]));
  sf::Sprite redCannonSprite(
      textureManager.GetTexture(weaponNameIdMapping["redcannon"]));
  sf::Sprite missileLauncherSprite(
      textureManager.GetTexture(weaponNameIdMapping["missilelauncher"]));

  auto onGreenCannonClick = [&selectedTower, &weaponNameIdMapping]() {
    std::cout << "green cannon button was clicked." << std::endl;

    if (selectedTower.has_value() &&
        (selectedTower.value() == weaponNameIdMapping["greencannon"])) {
      selectedTower.reset();
    } else {
      selectedTower = weaponNameIdMapping["greencannon"];
    }
  };
  auto onRedCannonClick = [&selectedTower, &weaponNameIdMapping]() {
    std::cout << "red cannon button was clicked." << std::endl;
    if (selectedTower.has_value() &&
        (selectedTower.value() == weaponNameIdMapping["redcannon"])) {
      selectedTower.reset();
    } else {
      selectedTower = weaponNameIdMapping["redcannon"];
    }
  };
  auto onMissileLauncherClick = [&selectedTower, &weaponNameIdMapping]() {
    std::cout << "missile launcher button was clicked." << std::endl;
    if (selectedTower.has_value() &&
        selectedTower.value() == weaponNameIdMapping["missilelauncher"]) {
      selectedTower.reset();
    } else {
      selectedTower = weaponNameIdMapping["missilelauncher"];
    }
  };

  ButtonSprite greenCannon = ButtonSprite(
      greenCannonSprite, sf::Vector2f(window_.getSize().x - toolbarWidth, 60),
      sf::Vector2f(6, 6), onGreenCannonClick);
  ButtonSprite redCannon = ButtonSprite(
      redCannonSprite, sf::Vector2f(window_.getSize().x - toolbarWidth, 140),
      sf::Vector2f(6, 6), onRedCannonClick);
  ButtonSprite missileLauncher =
      ButtonSprite(missileLauncherSprite,
                   sf::Vector2f(window_.getSize().x - toolbarWidth, 220),
                   sf::Vector2f(6, 6), onMissileLauncherClick);

  // Game Decoration (Level, Exit Button, Money)
  sf::Text levelText;
  levelText.setString("Level " + std::to_string(level));
  levelText.setPosition(20, 10);
  levelText.setFont(font);
  levelText.setFillColor(sf::Color::White);

  int exit = 0;
  auto onExit = [&exit]() { exit = 1; };
  ButtonText exitButton(sf::Vector2f(windowWidth - 200, windowHeight - 50),
                        sf::Vector2f(200, 50), onExit, "Exit", font);

  // Money Text
  sf::Text moneyTextTitle;
  moneyTextTitle.setString("Money");
  moneyTextTitle.setPosition(window_.getSize().x - toolbarWidth,
                             window_.getSize().y - 60);
  moneyTextTitle.setFont(font);
  moneyTextTitle.setCharacterSize(20);
  moneyTextTitle.setFillColor(sf::Color::White);

  sf::Text moneyText;
  moneyText.setString(std::to_string(playerMoney));
  moneyText.setPosition(window_.getSize().x - toolbarWidth,
                        window_.getSize().y - 30);
  moneyText.setFont(font);
  moneyText.setCharacterSize(20);
  moneyText.setFillColor(sf::Color::White);

  // Load window
  while (window_.isOpen()) {
    sf::Event event;

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
            greenCannon.handleClick(mousePos);
            redCannon.handleClick(mousePos);
            missileLauncher.handleClick(mousePos);

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
                  selectedTower.value() == weaponNameIdMapping["greencannon"]) {
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

    // Draw the toolbar and buttons inside it.
    window_.draw(toolbar);
    greenCannon.draw(window_);
    redCannon.draw(window_);
    missileLauncher.draw(window_);

    /* Game Decoration. */
    window_.draw(levelText);
    window_.draw(moneyTextTitle);
    window_.draw(moneyText);
    exitButton.draw(window_);

    window_.display();

    if (exit == 1) {
      return 0;
    }
  }
  return 0;
}
