
#include "enemy_path_renderer.hpp"
#include "tile.hpp"
#include "vec2d.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cstdint>
#include <iostream>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>


const float lineThicknessPx = 6.0;
const sf::Color lineColor(0xff, 0x00, 0x00, 0x80);
const sf::Color pathTileColor(0x00, 0x00, 0xff, 0x40);

void EnemyPathRenderer::Draw() {
	/* Render blue path tile overlay. */
	for (std::uint8_t j = 0; j < gameGrid_.Height(); j++) {
		for (std::uint8_t i = 0; i < gameGrid_.Width(); i++) {
			if (gameGrid_.TileAtCoordinate(i, j).type() == TileType::Path) {
				sf::RectangleShape blueTile;
				blueTile.setSize(sf::Vector2f(gameGrid_.TileWidth(), gameGrid_.TileWidth()));
				blueTile.setFillColor(pathTileColor);
				blueTile.setPosition(i * gameGrid_.TileWidth(), j * gameGrid_.TileWidth());

				renderWindow_.draw(blueTile);
			}
		}
	}

	/* Render the red line over the path. */
	for (Vec2D v : gameGrid_.EnemyPath()) {
		sf::RectangleShape line;

		/* Horizontal line. */
		if (v.a.y == v.b.y) {
			const std::uint32_t smallerX = v.a.x < v.b.x ? v.a.x : v.b.x;
			const std::uint32_t largerX = smallerX == v.a.x ? v.b.x : v.a.x;

			line = sf::RectangleShape(sf::Vector2f(largerX - smallerX, lineThicknessPx));
			line.setPosition(smallerX, v.a.y - lineThicknessPx / 2);
		}
		/* Vertical line. */
		else if (v.a.x == v.b.x){
			const std::uint32_t smallerY = v.a.y < v.b.y ? v.a.y : v.b.y;
			const std::uint32_t largerY = smallerY == v.a.y ? v.b.y : v.a.y;
			
			line = sf::RectangleShape(sf::Vector2f(lineThicknessPx, largerY - smallerY));
			line.setPosition(v.a.x - lineThicknessPx / 2, smallerY);
		}
		/* Diagonal */
		else {
			std::cout << "diagonal line rendering implementation missing." << std::endl;
		}

		line.setFillColor(lineColor);
		renderWindow_.draw(line);
	}
}

