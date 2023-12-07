
#pragma once

#include "gamegrid.hpp"
#include "renderer.hpp"
#include "texture_manager.hpp"
#include <SFML/Graphics/Font.hpp>
#include <cstdint>

class LevelInfoRenderer : public Renderer {
   public:
    LevelInfoRenderer(sf::RenderWindow &renderWindow, GameGrid &gameGrid, sf::Font &font, const std::uint64_t &playerMoney, const std::uint32_t level);
    ~LevelInfoRenderer() = default;

    void Draw() override;

   private:
    GameGrid &gameGrid_;
	const TextureManager &textureManager_;
	const sf::Font &font_;

	const std::uint64_t &playerMoney_;
	const std::uint32_t level_;
};

