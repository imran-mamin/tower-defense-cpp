
#pragma once

#include "gamegrid.hpp"
#include "renderer.hpp"
#include "texture_manager.hpp"
#include "cannon.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <cstdint>
#include <map>
#include <optional>

/*
 * Level specific map tile selector renderer.
 * Obviously needs to be recreated for another level.
 */
class MapTileSelectorRenderer : public Renderer {
   public:
	// TODO: Replace cannon with generic (std::unique) Tower class instance.
	MapTileSelectorRenderer(sf::RenderWindow &renderWindow, GameGrid &gameGrid, TextureManager &textureManager, std::optional<std::uint16_t> &selectedTower);
	~MapTileSelectorRenderer() = default;

	void Draw() override;
   private:
	GameGrid &gameGrid_;
	sf::RectangleShape selectorRect_;
	TextureManager &textureManager_;
	std::optional<std::uint16_t> &selectedTower_;
     
	std::map<std::uint16_t, sf::Sprite> towerSprites_;
};

