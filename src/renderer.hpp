
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

/* Abstract renderer class. */
class Renderer {
   public:
    Renderer(sf::RenderWindow &r) : renderWindow_(r) {}
    virtual ~Renderer() {}

    virtual void Draw() = 0;

   protected:
    sf::RenderWindow &renderWindow_;
};

