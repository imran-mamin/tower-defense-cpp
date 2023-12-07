
#include "levelinfo_renderer.hpp"

#include "gamegrid.hpp"
#include "renderer.hpp"
#include "texture_manager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cstdint>
#include <iostream>

const std::uint32_t characterSize = 50;
const std::uint32_t shadowTextXOffset = 2;
const std::uint32_t shadowTextYOffset = 2;

LevelInfoRenderer::LevelInfoRenderer(sf::RenderWindow &renderWindow,
				     GameGrid &gameGrid, sf::Font &font,
				     const std::uint64_t &playerMoney,
					 const std::uint32_t level)
    : Renderer(renderWindow),
      gameGrid_(gameGrid),
      textureManager_(TextureManager::GetInstance()),
      font_(font),
      playerMoney_(playerMoney),
	  level_(level) {}


/* Helper to create a "shadow" text for the text. */
sf::Text CreateShadowText(const sf::Text &originalText) {
	sf::Text shadowText;

	auto font = originalText.getFont();
	shadowText.setFont(*font);
	shadowText.setCharacterSize(originalText.getCharacterSize());
	shadowText.setFillColor(sf::Color::Black);
	shadowText.setString(originalText.getString());
	shadowText.setPosition(originalText.getPosition().x + shadowTextXOffset, originalText.getPosition().y + shadowTextYOffset);

	return shadowText;
}

sf::Text CreateMoneyText(const GameGrid &gameGrid, const sf::Font &font, const std::uint32_t &playerMoney) {
	/* Create two text objects: one for the text and other for a shadow effect. */
    sf::Text moneyText;
	moneyText.setFont(font);
	moneyText.setCharacterSize(characterSize);
	moneyText.setFillColor(sf::Color::White);
    moneyText.setString(std::string("$") + std::to_string(playerMoney));

	/* Place the text horizontally on the center of the game grid. */
	sf::Rect textRect = moneyText.getGlobalBounds();
	std::uint32_t textWidthInPixels = textRect.width;
	
	auto textStartPosX = gameGrid.Width() / 2 * gameGrid.TileWidth() - textWidthInPixels / 2;
    moneyText.setPosition(textStartPosX, 0);

	return moneyText;
}

// TODO: Also draw the wave name here. E.g. "level 1: enemy wave 2".
sf::Text CreateLevelNameText(const sf::Font &font, const std::uint32_t level) {
	sf::Text levelNameText;
  	levelNameText.setFont(font);
	levelNameText.setCharacterSize(40);
  	levelNameText.setFillColor(sf::Color::White);
  	levelNameText.setString("Level " + std::to_string(level));
  	
	levelNameText.setPosition(20, 10);
	
	return levelNameText;
}

void LevelInfoRenderer::Draw() {
	/* Create the money text. */
	sf::Text moneyText = CreateMoneyText(gameGrid_, font_, playerMoney_);
	sf::Text moneyTextShadow = CreateShadowText(moneyText);
	/* Create the level name text. */
	sf::Text levelNameText = CreateLevelNameText(font_, level_);
	sf::Text levelNameTextShadow = CreateShadowText(levelNameText);

	/* Draw the texts. */
	renderWindow_.draw(moneyTextShadow);
	renderWindow_.draw(moneyText);
	renderWindow_.draw(levelNameTextShadow);
	renderWindow_.draw(levelNameText);
}

