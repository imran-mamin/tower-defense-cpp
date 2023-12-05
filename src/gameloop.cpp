#include "gameloop.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <cstdint>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <optional>
#include <stdexcept>
#include <vector>

#include "background_renderer.hpp"
#include "cannon.hpp"
#include "enemy_path_renderer.hpp"
#include "footsoldier.hpp"
#include "game.hpp"
#include "gamegrid.hpp"
#include "gameobject.hpp"
#include "gameobject_renderer.hpp"
#include "map_tile_selector_renderer.hpp"
#include "testmapinfo.hpp"
#include "texture_manager.hpp"
#include "tower.hpp"
#include "missilelauncher.hpp"

int GameLoop::Play() {
    int windowWidth = 20 * 64;
    int windowHeight = 12 * 64;

    // Toolbar dimensions
    int toolbarWidth = 68;
    int toolbarHeight = window_.getSize().y;

    TextureManager &textureManager = TextureManager::GetInstance();

    std::map<std::string, std::uint16_t> weaponNameIdMapping;
    weaponNameIdMapping["greencannon"] = 248;
    weaponNameIdMapping["redcannon"] = 249;
	weaponNameIdMapping["missilelauncher"] = 205;

    GameGrid &grid = game_.GetGrid();
    
	/* Renderers. */
    BackgroundRenderer ikkuna(window_, grid);
    /* For debug purposes.*/
    EnemyPathRenderer enemyPathRenderer(window_, grid);
    GameObjectRenderer gameobjectRenderer(window_, game_);

    sf::View startView(sf::FloatRect(0, 0, windowWidth, windowHeight));
    sf::View applicationView(sf::FloatRect(0, 0, windowWidth, windowHeight));

    window_.setView(startView);

    // create startbutton
    sf::RectangleShape startButton(sf::Vector2f(200, 100));
    startButton.setFillColor(sf::Color(252, 213, 38));
    startButton.setOutlineColor(sf::Color::Black);
    startButton.setOutlineThickness(4);

    // Center the button horizontally
    sf::FloatRect startButtonBounds = startButton.getLocalBounds();
    startButton.setOrigin(
	startButtonBounds.left + startButtonBounds.width / 2.0f, 0);
    startButton.setPosition(window_.getSize().x / 2.0f, 400);

    sf::Font font;
    if (!font.loadFromFile("../fonts/open-sans/OpenSans-Italic.ttf")) {
	std::cout << "Error in font loading" << std::endl;
	return -1;
    }

    // Add text for the startButton
    sf::Text playText;
    playText.setFont(font);
    playText.setString("Play");
    playText.setCharacterSize(20);
    playText.setFillColor(sf::Color::White);

    // Center the text within the button
    sf::FloatRect playBounds = playText.getLocalBounds();
    playText.setOrigin(playBounds.left + playBounds.width / 2.0f,
		       playBounds.top + playBounds.height / 2.0f);
    playText.setPosition(
	startButton.getPosition().x,
	startButton.getPosition().y + startButton.getSize().y / 2.0f);

    // Create title for the game.
    sf::Text title;
    title.setString("Clash Of Armies");
    title.setCharacterSize(60);
    title.setFont(font);
    title.setFillColor(sf::Color::Red);

    // Center the text horizontally
    sf::FloatRect titleBounds = title.getLocalBounds();
    title.setOrigin(titleBounds.left + titleBounds.width / 2.0f, 0);
    title.setPosition(window_.getSize().x / 2.0f, 100);

    // Create a vertical toolbar on the right side using a rectangle
    sf::RectangleShape toolbar(sf::Vector2f(toolbarWidth, toolbarHeight));
    toolbar.setPosition(window_.getSize().x - toolbarWidth, 0);
    toolbar.setFillColor(sf::Color(128, 128, 128));

	//////////////////////
	// TODO: Move to menu.
    // Add buttons to the toolbar (tower buttons)
    // Creating sprites for the towers.
    sf::Sprite greenCannonSprite(textureManager.GetTexture(weaponNameIdMapping["greencannon"]));
    sf::Sprite redCannonSprite(textureManager.GetTexture(weaponNameIdMapping["redcannon"]));
    sf::Sprite missileLauncherSprite(textureManager.GetTexture(weaponNameIdMapping["missilelauncher"]));

    // Set positions of the buttons
    greenCannonSprite.setPosition(window_.getSize().x - toolbarWidth + 3,
			     60);  // Toolbar x-coordinate + 20
    // 20 + tank x-coordinate + tank width + 20
    redCannonSprite.setPosition(window_.getSize().x - toolbarWidth + 3, 140);
	missileLauncherSprite.setPosition(window_.getSize().x - toolbarWidth + 3, 220);
	// TODO: Move to menu.
	//////////////////////

    bool startButtonClicked = false;


    /* Selected tower id and the renderer that utilizes it. */
    std::optional<std::uint16_t> selectedTower;
    MapTileSelectorRenderer tileSelector(window_, grid, textureManager, selectedTower);

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
			sf::Vector2f mousePos = window_.mapPixelToCoords(
			    sf::Mouse::getPosition(window_));

			if (startButton.getGlobalBounds().contains(mousePos)) {
			    startButtonClicked = true;
			    // Switch to application view
			    window_.setView(applicationView);
			}

			// TODO: Needs to be put in a menu view.
			if (startButtonClicked) {
			    if (greenCannonSprite.getGlobalBounds().contains(
				    mousePos)) {
				std::cout << "green cannon button was clicked."
					  << std::endl;

				if (selectedTower.has_value() &&
				    (selectedTower.value() ==
				     weaponNameIdMapping["greencannon"])) {
				    selectedTower.reset();
				} else {
				    selectedTower =
					weaponNameIdMapping["greencannon"];
				}

				// TODO: When clicking on this button the
				// program should create a new tank instance.
			    } else if (redCannonSprite.getGlobalBounds()
					   .contains(mousePos)) {
				std::cout << "red cannon button was clicked."
					  << std::endl;
				if (selectedTower.has_value() &&
				    (selectedTower.value() ==
				     weaponNameIdMapping["redcannon"])) {
				    selectedTower.reset();
				} else {
				    selectedTower =
					weaponNameIdMapping["redcannon"];
				}


			    } else if (missileLauncherSprite.getGlobalBounds().contains(mousePos)) {
					std::cout << "missile launcher button was clicked." << std::endl;
					if (selectedTower.has_value() && selectedTower.value() == weaponNameIdMapping["missilelauncher"]) {
						selectedTower.reset();
					}
					else {
						selectedTower = weaponNameIdMapping["missilelauncher"];
					}
				}
				// TODO: Wtf??? Remove the redundant else clause.
				else {
				if (auto selectedTile = grid.TileAtAbsoluteCoordinate(mousePos.x, mousePos.y); selectedTower.has_value() && selectedTile.isFree()) {
					//const Pos selectedTilePos = Pos{ mousePos.x / grid.TileWidth() * grid.TileWidth(), mousePos.y / grid.TileWidth() * grid.TileWidth() };
					const Pos selectedTilePos = grid.AbsoluteCoordinateToClosestTilePosition(mousePos.x, mousePos.y);
				    std::cout << "placing tower" << std::endl;
					selectedTile.occupy();
					// TODO: Is the has_value redundant?
					if (selectedTower.has_value() && selectedTower.value() == weaponNameIdMapping["greencannon"]) {
						game_.AddObject(new GreenCannon(game_, selectedTilePos));
					}
					else if (selectedTower.has_value() && selectedTower.value() == weaponNameIdMapping["redcannon"]){
						game_.AddObject(new RedCannon(game_, selectedTilePos));
					}
					else if (selectedTower.has_value() && selectedTower.value()) {
						game_.AddObject(new BasicMissileLauncher(game_, selectedTilePos));
					}
					else { throw std::runtime_error("Not implemented."); }

				    selectedTower.reset();
				}
			    }
			}
		    }
		    break;

		case (sf::Event::MouseButtonReleased):
		    break;

		// Mouse hover event
		case (sf::Event::MouseMoved):
		    // Mouse position in window coordinates.
		    sf::Vector2f mousePos = window_.mapPixelToCoords(
			sf::Mouse::getPosition(window_));

		    if (startButtonClicked) {
		    } else {
			sf::Color color = startButton.getFillColor();
			if (startButton.getGlobalBounds().contains(mousePos)) {
			    // change opacity of the hovered startButton
			    color.a = 128;
			    startButton.setFillColor(color);
			} else {
			    // Restore opacity
			    color.a = 255;
			    startButton.setFillColor(color);
			}
		    }
		break;
	    }
	}

	window_.clear(sf::Color(200, 200, 200));

	if (!startButtonClicked) {
	    window_.draw(startButton);
	    window_.draw(playText);
	    window_.draw(title);
	} else {
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
	    window_.draw(greenCannonSprite);
	    window_.draw(redCannonSprite);
		window_.draw(missileLauncherSprite);
	}

	window_.display();
    }
    return 0;
}
