
#include "gamegrid.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <exception>
#include <stdexcept>
#include <string>
#include <vector>

#include "directory.hpp"
#include "map_parser.hpp"

bool GameGrid::textureAlreadyLoaded(std::uint16_t textureId) const {
    std::map<std::uint16_t, sf::Texture> textures_;
    try {
	sf::Texture t = textures_.at(textureId);
    } catch (const std::out_of_range &e) {
	return false;
    }

    return true;
}

/* Create the gamegrid. */
GameGrid::GameGrid(const std::string &path) {
    MapInfo mapInfo = ParseMap(path);
    mapWidth_ = mapInfo.mapWidth;
    mapHeight_ = mapInfo.mapHeight;
    tileWidth_ = mapInfo.tileWidth;
    enemyPath_ = mapInfo.enemyPath;

    /* Load background textures and sprites. */
	for (std::uint16_t j = 0; j < mapHeight_; j++) {
		for (std::uint16_t i = 0; i < mapWidth_; i++) {
			std::size_t bgTextureId = mapInfo.backgroundTiles[j][i];
			
			/* Load texture if it's not already loaded. */
			if (!textureAlreadyLoaded(bgTextureId)) {
				/* TODO: Create a function for getting resource paths. */
	    		const std::string texturePath = BACKGROUND_TILE_DIRECTORY + std::to_string(bgTextureId) + ".png";
				
				sf::Texture t;
				if (!t.loadFromFile(texturePath)) {
					/* TODO: Replace with a proper exception type. */
					throw std::runtime_error(std::string("Failed to load texture from '") + texturePath + "'");
				}
				textures_[bgTextureId] = t;
			}
		
			/* Load sprite. */
			sf::Sprite s;
			s.setTexture(textures_[bgTextureId]);
			sprites_.push_back(s);
		}
	}

}

void GameGrid::DrawBackground(sf::RenderWindow &renderWindow) {
	for (auto sprite : sprites_) {
		renderWindow.draw(sprite);
	}
}

// GameGrid::GameGrid(const MapInfo &mapInfo) {
//	tileWidth_ = mapInfo.tileWidth;
//	std::vector<std::vector<std::uint16_t>> backgroundTiles_;
//     std::uint32_t width_;
//     std::uint32_t height_;
// }

// Tile &GameGrid::TileAtCoordinate(std::uint8_t x, std::uint8_t y) const {
//	return tiles_[y / tileWidth_ + (y % tileWidth_ != 0 ? 1 : 0)][x /
//tileWidth_ + (x % tileWidth_ != 0 ? 1 : 0)];
// }

