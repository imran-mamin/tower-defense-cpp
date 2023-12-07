
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdint>
#include <optional>

#include "game.hpp"
#include "weapon_toolbar_renderer.hpp"

class TowerSelector {
   public:
    TowerSelector(sf::RenderWindow &renderWindow, Game &game,
		  const WeaponToolbarRenderer &weaponToolbarRenderer,
		  std::optional<std::uint16_t> &selectedTower)
	: renderWindow_(renderWindow),
	  game_(game),
	  weaponToolbarRenderer_(weaponToolbarRenderer),
	  selectedTower_(selectedTower) {}

    void OnClickAction();

   private:
    sf::RenderWindow &renderWindow_;
    Game &game_;
    const WeaponToolbarRenderer &weaponToolbarRenderer_;
    std::optional<std::uint16_t> &selectedTower_;
};

