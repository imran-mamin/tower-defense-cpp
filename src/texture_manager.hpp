
#pragma once

#include <SFML/Graphics.hpp>
#include <cstdint>
#include <map>
#include <stdexcept>

/* A simple class to make sure that textures don't get loaded  */
class TextureManager {
   public:
	TextureManager(TextureManager &other) = delete;
	void operator=(const TextureManager &other) = delete;

	static TextureManager &GetInstance();

    sf::Texture &GetTexture(std::uint16_t textureId);

   protected:
    /* Essentially what this does is, it just loads all the textures into memory. */
    TextureManager();
	static TextureManager textureManager_;

   private:
    std::map<std::uint16_t, sf::Texture> textures_;
};

class TextureManagerError : public std::runtime_error {
   public:
    TextureManagerError(const std::string &what) : std::runtime_error(what) {}
};

class TextureDoesNotExistError : public TextureManagerError {
   public:
    TextureDoesNotExistError(const std::string &what)
	: TextureManagerError(what) {}
};

