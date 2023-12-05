#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>

class ButtonSprite {
 public:
  ButtonSprite() = default;

  ButtonSprite(sf::Sprite sprite, const sf::Vector2f& position,
               const sf::Vector2f& size, const std::function<void()>& callback)
      : sprite_(sprite), callback_(callback) {
    sprite_.setPosition(position - size / 2.0f);
  }

  void draw(sf::RenderWindow& window) const { window.draw(sprite_); }

  bool isMouseOver(sf::Vector2f mousePos) const {
    return sprite_.getGlobalBounds().contains(mousePos);
  }

  void handleHover(sf::Vector2f mousePos) {
    if (isMouseOver(mousePos)) {
    }
  }

  void handleClick(sf::Vector2f mousePos) const {
    if (isMouseOver(mousePos)) {
      callback_();
    }
  }

 public:
  sf::Sprite sprite_;
  std::function<void()> callback_;
};
