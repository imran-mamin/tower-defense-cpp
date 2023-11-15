
#include "background_renderer.hpp"
#include "gamegrid.hpp"
#include "path.hpp"
#include <SFML/Graphics/RenderWindow.hpp>


bool BackgroundRenderer::textureAlreadyLoaded(std::uint16_t textureId) const {
    std::map<std::uint16_t, sf::Texture> textures_;
    try {
	sf::Texture t = textures_.at(textureId);
    } catch (const std::out_of_range &e) {
	return false;
    }

    return true;
}

BackgroundRenderer::BackgroundRenderer(sf::RenderWindow &renderWindow, const GameGrid &gameGrid) : Renderer(renderWindow) {
	/* Load background textures and sprites. */
	for (auto rows : gameGrid.) {

	}


	/* Load background textures and sprites. */
	for (std::uint16_t j = 0; j < mapInfo.mapHeight; j++) {
		for (std::uint16_t i = 0; i < mapInfo.mapWidth; i++) {
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
			s.setPosition(sf::Vector2f(i, j));
			s.setTexture(textures_[bgTextureId]);
			sprites_.push_back(s);
		}
	}

}

void BackgroundRenderer::Draw() {
	for (auto sprite : sprites_) {
		renderWindow_.draw(sprite);
	}
}

