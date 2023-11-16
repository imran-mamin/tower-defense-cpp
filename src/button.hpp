#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>

class Button {
 public:
  Button() = default;

  Button(const sf::Vector2f& position, const sf::Vector2f& size,
         const std::function<void()>& callback)
      : callback(callback) {
    shape.setSize(size);
    shape.setPosition(position - size / 2.0f);
  }

  void draw(sf::RenderWindow& window) const { window.draw(shape); }

  bool isMouseOver(sf::Vector2f mousePos) const {
    return shape.getGlobalBounds().contains(mousePos);
  }

  void handleHover(sf::Vector2f mousePos) {
    if (isMouseOver(mousePos)) {
    }
  }

  void handleClick(sf::Vector2f mousePos) const {
    if (isMouseOver(mousePos)) {
      callback();
    }
  }

  void setTexture(const sf::Texture& newTexture) {
    texture = newTexture;
    shape.setTexture(&texture);
  }

 public:
  sf::Texture texture;
  sf::RectangleShape shape;
  std::function<void()> callback;
};
