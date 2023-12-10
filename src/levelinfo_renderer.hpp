
#pragma once

#include "game.hpp"
#include "renderer.hpp"
#include "texture_manager.hpp"
#include <SFML/Graphics/Font.hpp>
#include <cstdint>

class LevelInfoRenderer : public Renderer {
   public:
    LevelInfoRenderer(sf::RenderWindow &renderWindow, Game &game, sf::Font &font, const std::uint32_t level);
    ~LevelInfoRenderer() = default;

    void Draw() override;

   private:
    Game &game_;
	const TextureManager &textureManager_;
	const sf::Font &font_;

	const std::uint32_t level_;
};

