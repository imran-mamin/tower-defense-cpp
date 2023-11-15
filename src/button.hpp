#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>

class Button {
 public:
  Button(const sf::Vector2f& position, const sf::Vector2f& size,
         const std::function<void()>& callback, const std::string& buttonText,
         sf::Font& font)
      : callback(callback) {
    // Initialize button appearance
    shape.setPosition(position - size / 2.0f);
    shape.setSize(size);
    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(2.0f);

    text.setFont(font);
    text.setString(buttonText);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);

    centerText();
  }

  void draw(sf::RenderWindow& window) const {
    window.draw(shape);
    window.draw(text);
  }

  bool isMouseOver(sf::Vector2f mousePos) const {
    return shape.getGlobalBounds().contains(mousePos);
  }

  bool handleHover(sf::Vector2f mousePos) {
    if (isMouseOver(mousePos)) {
      shape.setFillColor(sf::Color::White);
      text.setFillColor(sf::Color::Black);
      return true;
    }

    shape.setFillColor(sf::Color::Transparent);
    text.setFillColor(sf::Color::White);
    return false;
  }

  bool handleClick(sf::Vector2f mousePos) const {
    if (isMouseOver(mousePos)) {
      callback();
      return true;
    }
    return false;
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

#endif
