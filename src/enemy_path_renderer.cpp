
#include "enemy_path_renderer.hpp"
#include "vec2d.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>


const float lineThicknessPx = 20.0;
const sf::Color lineColor(0xff, 0x00, 0x00);

void EnemyPathRenderer::Draw() {
	for (Vec2D v : gameGrid_.EnemyPath()) {
		sf::RectangleShape line;

		/* Horizontal line. */
		if (v.a.x == v.b.x) {
			line = sf::RectangleShape(sf::Vector2f(v.b.x, lineThicknessPx));
			line.setPosition(v.a.x, v.a.y - lineThicknessPx / 2);
		}
		/* Vertical */
		else if (v.a.y == v.b.y){
			line = sf::RectangleShape(sf::Vector2f(lineThicknessPx, v.b.y));
			line.setPosition(v.a.x - lineThicknessPx / 2, v.a.y);
		}
		/* Diagonal */
		else {
			std::cout << "diagonal line rendering implementation missing." << std::endl;
		}

		line.setFillColor(lineColor);
		renderWindow_.draw(line);
	}
}

