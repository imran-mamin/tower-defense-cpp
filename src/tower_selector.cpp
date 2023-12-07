
#include "tower_selector.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <cstdint>

#include "cannon.hpp"
#include "missilelauncher.hpp"
#include "weapons_and_enemies.hpp"

void TowerSelector::OnClickAction() {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(renderWindow_);

    if (weaponToolbarRenderer_.IsCoordinateInsideTheToolbar(mousePosition.x, mousePosition.y)) {
		if (weaponToolbarRenderer_.GreenCannonButtonGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
		    if (selectedTower_.has_value() && selectedTower_.value() == weaponToTileIDMapping.at(WeaponType::GreenCannon)) {
				selectedTower_.reset();
	    	}
			else {
				selectedTower_ = weaponToTileIDMapping.at(WeaponType::GreenCannon);
	    	}
		}
		else if (weaponToolbarRenderer_.RedCannonButtonGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
	    	if (selectedTower_.has_value() && selectedTower_.value() == weaponToTileIDMapping.at(WeaponType::RedCannon)) {
				selectedTower_.reset();
	    	}
			else {
				selectedTower_ = weaponToTileIDMapping.at(WeaponType::RedCannon);
	    	}
		}
		else if (weaponToolbarRenderer_.MissileLauncher1ButtonGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
	    	if (selectedTower_.has_value() && selectedTower_.value() == weaponToTileIDMapping.at(WeaponType::MissileLauncher1)) {
				selectedTower_.reset();
	    	}
			else {
				selectedTower_ = weaponToTileIDMapping.at(WeaponType::MissileLauncher1);
	    	}
		}
    }
	/* Buying action. */
	else if (selectedTower_.has_value()) {
		sf::Vector2f mousePos = renderWindow_.mapPixelToCoords(sf::Mouse::getPosition(renderWindow_));
		const std::uint64_t &playerMoney = game_.PlayerMoney();

		if (Tile &selectedTile = game_.GetGrid().TileAtAbsoluteCoordinate(mousePos.x, mousePos.y); selectedTile.isFree()) {
		    const Pos selectedTilePos = game_.GetGrid().AbsoluteCoordinateToClosestTilePosition(mousePos.x, mousePos.y);

		    if (selectedTower_.value() == weaponToTileIDMapping.at(WeaponType::GreenCannon) && playerMoney >= GreenCannonPrice) {
				game_.AddObject(new GreenCannon(game_, selectedTilePos));
				game_.RemoveMoney(GreenCannonPrice);
		    	selectedTile.occupy();
		    	selectedTower_.reset();
		    }
			else if (selectedTower_.value() == weaponToTileIDMapping.at(WeaponType::RedCannon) && playerMoney >= RedCannonPrice) {
				game_.AddObject(new RedCannon(game_, selectedTilePos));
				game_.RemoveMoney(RedCannonPrice);
		    	selectedTile.occupy();
		    	selectedTower_.reset();
		    }
			else if (selectedTower_.value() == weaponToTileIDMapping.at(WeaponType::MissileLauncher1) && playerMoney >= BasicMissileLauncherPrice) {
				game_.AddObject(new BasicMissileLauncher(game_, selectedTilePos));
				game_.RemoveMoney(BasicMissileLauncherPrice);
		    	selectedTile.occupy();
		    	selectedTower_.reset();
		    }
		}
    }


}

