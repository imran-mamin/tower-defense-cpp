#pragma once

#include <SFML/Graphics.hpp>

#include "pos.hpp"
#include "game.hpp"

class GameObject {
public:
    GameObject(sf::Sprite sprite, Game game, int health = 0) 
        :   sprite_(sprite), game_(game), health_(health) {};

protected:
    sf::Sprite sprite_;
    int health_;
    Game& game_;
    Pos position_;
};
