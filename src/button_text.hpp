#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>

#include "button.hpp"

class ButtonText : public Button {
 public:
  ButtonText(const sf::Vector2f& position, const sf::Vector2f& size,
             const std::function<void()>& callback,
             const std::string& buttonText, sf::Font& font)
      : Button(position, size, callback), text(buttonText, font) {
    shape.setPosition(position - size / 2.0f);
    shape.setSize(size);
    shape.setFillColor(sf::Color(36, 39, 54, 255));

    text.setString(buttonText);
    text.setFillColor(sf::Color::White);

    centerText();
  }

  void draw(sf::RenderWindow& window) const {
    window.draw(shape);
    window.draw(text);
  }

  void handleHover(sf::Vector2f mousePos) {
    if (isMouseOver(mousePos)) {
      shape.setFillColor(sf::Color(49, 55, 81, 255));
    }

    shape.setFillColor(sf::Color(36, 39, 54, 255));
  }

 public:
  sf::RectangleShape shape;
  sf::Text text;
  sf::Font font;
  std::function<void()> callback;

  void centerText() {
    // Center the text within the button
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.left + textBounds.width / 2.0f,
                   textBounds.top + textBounds.height / 2.0f);
    text.setPosition(shape.getPosition().x + shape.getSize().x / 2.0f,
                     shape.getPosition().y + shape.getSize().y / 2.0f);
  }
};
