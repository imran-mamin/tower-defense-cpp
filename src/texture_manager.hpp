
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <cstdint>
#include <exception>
#include <map>

/* A simple class to make sure that textures don't get loaded  */
class TextureManager {
   public:
    /* Currently just loads all the textures into memory. */
    TextureManager();

    sf::Texture &GetTexture(std::uint16_t textureId);

   private:
	std::map<std::uint16_t, sf::Texture> textures_;
};

// TODO: Error message.
class TextureManagerError : public std::exception {

};

// TODO: Error message.
class TextureDoesNotExistError : public TextureManagerError {

};

