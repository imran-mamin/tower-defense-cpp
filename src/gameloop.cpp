#include "gameloop.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <optional>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "background_renderer.hpp"
#include "button_sprite.hpp"
#include "button_text.hpp"
#include "cannon.hpp"
#include "enemy_path_renderer.hpp"
#include "weapon_toolbar_renderer.hpp"
#include "footsoldier.hpp"
#include "game.hpp"
#include "gamegrid.hpp"
#include "gameobject.hpp"
#include "gameobject_renderer.hpp"
#include "map_tile_selector_renderer.hpp"
#include "missilelauncher.hpp"
#include "renderer.hpp"
#include "testmapinfo.hpp"
#include "texture_manager.hpp"
#include "tower.hpp"
#include "levelinfo_renderer.hpp"
#include "tower_selector.hpp"


int GameLoop::Play() {
  int windowWidth = 20 * 64;
  int windowHeight = 12 * 64;

  sf::Font font;
  if (!font.loadFromFile("../fonts/pixieboy.ttf")) {
    std::cout << "Error in font loading" << std::endl;
    return (-1);
  }

  TextureManager &textureManager = TextureManager::GetInstance();

  GameGrid &grid = game_.GetGrid();
  int level = game_.GetLevel();
  std::optional<std::uint16_t> selectedTower;
  sf::Event gameEvent;
  
  /* Renderers. */
  std::vector<std::unique_ptr<Renderer>> renderers;
  renderers.push_back(std::make_unique<BackgroundRenderer>(window_, grid));
  /* Selected tower id and the renderer that utilizes it. */
  // TODO: Pass mouse event straight to tile renderer.
  renderers.push_back(std::make_unique<MapTileSelectorRenderer>(window_, grid, textureManager, selectedTower));
  /* For debug purposes. */
  renderers.push_back(std::make_unique<EnemyPathRenderer>(window_, grid));
  renderers.push_back(std::make_unique<GameObjectRenderer>(window_, game_));
  // TODO: Pass mouse evenet straight to toolbar renderer.
  std::unique_ptr<WeaponToolbarRenderer> weaponToolBarRenderer = std::make_unique<WeaponToolbarRenderer>(window_, grid, selectedTower, gameEvent);
  TowerSelector towerSelector(window_, game_, *weaponToolBarRenderer, selectedTower);
  renderers.push_back(std::move(weaponToolBarRenderer));
  renderers.push_back(std::make_unique<LevelInfoRenderer>(window_, grid, font, game_.PlayerMoney(), level));


  sf::View applicationView(sf::FloatRect(0, 0, windowWidth + WeaponToolbarWidthPx, windowHeight));

  window_.setView(applicationView);

  int exit = 0;
  auto onExit = [&exit]() { exit = 1; };
  ButtonText exitButton(sf::Vector2f(windowWidth - 200, windowHeight - 50),
                        sf::Vector2f(200, 50), onExit, "Exit", font);

  // Load window
  while (window_.isOpen()) {

    while (window_.pollEvent(gameEvent)) {
      switch (gameEvent.type) {
		default:
			break;
        case (sf::Event::Closed):
          window_.close();
          break;
		case sf::Event::MouseButtonPressed:
		  	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				towerSelector.OnClickAction();
			}
		break;  
        
		// Mouse hover event
        //case (sf::Event::MouseMoved):
        //  // Mouse position in window coordinates.
        //  sf::Vector2f mousePos =
        //      window_.mapPixelToCoords(sf::Mouse::getPosition(window_));
		//
        //  exitButton.handleHover(mousePos);
		//
        //  break;
      }
	}

    window_.clear(sf::Color(200, 200, 200));

    /* Draw the background. */
	for (auto it = renderers.begin(); it != renderers.end(); it++) {
		(*it)->Draw();
	}

    window_.display();

    if (exit == 1) {
      return 0;
    }
  
}
  return 0;
}

