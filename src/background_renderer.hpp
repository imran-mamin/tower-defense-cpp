
#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "map_parser.hpp"
#include "renderer.hpp"
#include "gamegrid.hpp"


/* The tiles are static since background shouldn't change in the middle of the game. */
class BackgroundRenderer : public Renderer {
   public:
    BackgroundRenderer(sf::RenderWindow &renderWindow, GameGrid &gameGrid);
	~BackgroundRenderer() = default;

	void Draw() override;

   private:
    std::map<std::uint16_t, sf::Texture> textures_;
    std::vector<sf::Sprite> sprites_;

    bool textureAlreadyLoaded(std::uint16_t textureId) const;
};

