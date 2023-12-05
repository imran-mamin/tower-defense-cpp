
#pragma once

#include <stdexcept>

#include "game.hpp"
#include "renderer.hpp"

class GameObjectRenderer : public Renderer {
   public:
    GameObjectRenderer(sf::RenderWindow &renderWindow, Game &game)
	: Renderer(renderWindow), game_(game) {}
    ~GameObjectRenderer() = default;

    void Draw() override;

   private:
    Game &game_;
};

class GameObjectRendererError : public std::runtime_error {
   public:
    GameObjectRendererError(const std::string &what)
	: std::runtime_error(what) {}
};

