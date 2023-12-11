
#include "gameobject_renderer.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <type_traits>
#include <typeinfo>
#include <vector>

#include "attackplane.hpp"
#include "bullet.hpp"
#include "cannon.hpp"
#include "enemy.hpp"
#include "footsoldier.hpp"
#include "game.hpp"
#include "gameobject.hpp"
#include "missile.hpp"
#include "missilelauncher.hpp"
#include "projectile.hpp"
#include "tank.hpp"
#include "texture_manager.hpp"
#include "tower.hpp"
#include "weapons_and_enemies.hpp"

template <typename T>
bool isOfType(const GameObject *g) {
    return dynamic_cast<const T *>(g);
}

/* Helper to render a vector of gameobjects. */
void renderGameObjects(sf::RenderWindow &renderWindow, Game &game) {
    const std::vector<GameObject *> &gameObjects = game.Objects();
    TextureManager &textureManager = TextureManager::GetInstance();

    // for (const std::unique_ptr<GameObject> &gameObject : gameObjects) {
    for (const auto &gameObject : gameObjects) {
	sf::Sprite currentSprite;

	/*
	 * 1. Get the correct texture and create the sprite based on it.
	 */

	/* Note: C++17 allows to assignment inside if statement (visible in the
	 * block scope only). */
	if (isOfType<Projectile>(gameObject)) {
	    if (isOfType<Missile>(gameObject)) {
		currentSprite.setTexture(textureManager.GetTexture(
		    projectileToTileIDMapping.at(ProjectileType::Missile)));
	    } else if (isOfType<Bullet>(gameObject)) {
		currentSprite.setTexture(textureManager.GetTexture(
		    projectileToTileIDMapping.at(ProjectileType::Bullet)));
	    } else {
		throw std::runtime_error("Unknown projectile type.");
	    }
	    currentSprite.setOrigin(sf::Vector2f{32, 32});
	    /* 2. Set the sprite position. */
	    sf::Vector2f centerPosition =
		gameObject->getPosition().ToVector2f();
	    centerPosition.x += 1.0 * game.GetGrid().TileWidth() / 2;
	    centerPosition.y += 1.0 * game.GetGrid().TileWidth() / 2;
	    currentSprite.setPosition(gameObject->getPosition().ToVector2f());
	} else if (isOfType<Tower>(gameObject)) {
	    if (isOfType<Cannon>(gameObject)) {
		if (isOfType<GreenCannon>(gameObject)) {
		    currentSprite.setTexture(textureManager.GetTexture(
			weaponToTileIDMapping.at(WeaponType::GreenCannon)));
		} else if (isOfType<RedCannon>(gameObject)) {
		    currentSprite.setTexture(textureManager.GetTexture(
			weaponToTileIDMapping.at(WeaponType::RedCannon)));
		} else {
		    throw std::runtime_error("Unknown cannon type.");
		}
		currentSprite.setOrigin(sf::Vector2f{32, 32});

		// Add circle to display Cannon radius.
		Cannon *cn = dynamic_cast<Cannon *>(gameObject);
		sf::Vector2f centerPosition(cn->getPosition().x,
					    cn->getPosition().y);
		// Create a circle shape
		sf::CircleShape circle(cn->getRadius());
		// Set the position of the circle
		circle.setPosition(centerPosition.x - cn->getRadius() +
				       (float) game.GetGrid().TileWidth() / 2,
				   centerPosition.y - cn->getRadius() +
				       (float) game.GetGrid().TileWidth() / 2);
		// Set a color for the circle
		sf::Color fillColor = sf::Color(0x80, 0x80, 0x80, 0x10);
		circle.setFillColor(fillColor);
		renderWindow.draw(circle);
	    } else if (isOfType<MissileLauncher>(gameObject)) {
		if (isOfType<BasicMissileLauncher>(gameObject)) {
		    currentSprite.setTexture(
			textureManager.GetTexture(weaponToTileIDMapping.at(
			    WeaponType::MissileLauncher1)));
		} else {
		    throw std::runtime_error("Unknown missile launcher type.");
		}
		currentSprite.setOrigin(sf::Vector2f{32, 32});

		MissileLauncher *ml =
		    dynamic_cast<MissileLauncher *>(gameObject);
		sf::Vector2f centerPosition(ml->getPosition().x,
					    ml->getPosition().y);
		// Create a circle shape
		sf::CircleShape circle(ml->getRadius());
		// Set the position of the circle
		circle.setPosition(centerPosition.x + ml->getRadius(),
				   centerPosition.y + ml->getRadius());
		// Set a color for the circle
		sf::Color fillColor = sf::Color::Red;
		fillColor.a = 60;
		circle.setFillColor(fillColor);
		renderWindow.draw(circle);
	    }

	    /* 2. Set the sprite position. */
	    sf::Vector2f centerPosition =
		gameObject->getPosition().ToVector2f();
	    centerPosition.x += 1.0 * game.GetGrid().TileWidth() / 2;
	    centerPosition.y += 1.0 * game.GetGrid().TileWidth() / 2;
	    currentSprite.setPosition(centerPosition);

	} else if (isOfType<Enemy>(gameObject)) {
	    if (isOfType<FootSoldier>(gameObject)) {
		if (isOfType<Soldier1>(gameObject)) {
		    currentSprite.setTexture(textureManager.GetTexture(
			enemyToTileIDMapping.at(EnemyType::Soldier1)));
		} else if (isOfType<Soldier2>(gameObject)) {
		    currentSprite.setTexture(textureManager.GetTexture(
			enemyToTileIDMapping.at(EnemyType::Soldier2)));
		} else if (isOfType<Soldier3>(gameObject)) {
		    currentSprite.setTexture(textureManager.GetTexture(
			enemyToTileIDMapping.at(EnemyType::Soldier3)));
		} else if (isOfType<Soldier4>(gameObject)) {
		    currentSprite.setTexture(textureManager.GetTexture(
			enemyToTileIDMapping.at(EnemyType::Soldier4)));
		} else {
		    throw std::runtime_error("Unknown soldier type.");
		}
		currentSprite.setOrigin(sf::Vector2f{32, 32});
	    } else if (isOfType<Tank>(gameObject)) {
		if (isOfType<Tank1>(gameObject)) {
		    currentSprite.setTexture(textureManager.GetTexture(
			enemyToTileIDMapping.at(EnemyType::Tank1)));
		} else if (isOfType<Tank2>(gameObject)) {
		    currentSprite.setTexture(textureManager.GetTexture(
			enemyToTileIDMapping.at(EnemyType::Tank2)));
		} else {
		    throw std::runtime_error("Unknown tank type.");
		}
		currentSprite.setOrigin(sf::Vector2f{32, 32});
	    } else if (isOfType<AttackPlane>(gameObject)) {
		if (isOfType<Plane1>(gameObject)) {
		    currentSprite.setTexture(textureManager.GetTexture(
			enemyToTileIDMapping.at(EnemyType::Plane1)));
		} else if (isOfType<Plane2>(gameObject)) {
		    currentSprite.setTexture(textureManager.GetTexture(
			enemyToTileIDMapping.at(EnemyType::Plane2)));
		} else {
		    throw std::runtime_error("Unknown plane type.");
		}
		}
		const Enemy *enemy = dynamic_cast<const Enemy *>(gameObject);
		currentSprite.setOrigin(sf::Vector2f{32, 32});
		currentSprite.setPosition(
		    gameObject->getPosition().ToVector2f());

		/* Draw a healthbar over the game object. */
		if ((int)enemy->Health() < enemy->MaxHP()) {
		    const std::uint32_t healthBarHeight = 6;
		    const std::uint32_t healthBarWidth = 48;
			const std::uint32_t healthBarPadding = 16;

		    /* Set the healthbar position. */
		    sf::Vector2f healthBarPosition =
			gameObject->getPosition().ToVector2f();
		    sf::Vector2f underlayHealthBarSize(healthBarWidth,
						       healthBarHeight);
		    sf::Vector2f overlayHealthBarSize(
			(1.0 * enemy->Health() / enemy->MaxHP()) /
			    healthBarWidth,
			healthBarHeight);
		    healthBarPosition.x -= 1.0 * healthBarWidth / 2;
		    healthBarPosition.y -= currentSprite.getLocalBounds().height / 2 - healthBarPadding - healthBarHeight;

			std::cout << "overlay width = " << overlayHealthBarSize.x << std::endl;
		    sf::RectangleShape healthBarUnderlay(underlayHealthBarSize);
		    sf::RectangleShape healthBarOverlay(overlayHealthBarSize);
			healthBarOverlay.setFillColor(sf::Color(0xff * (1 - (1.0 * enemy->Health() / enemy->MaxHP())), 0xff * (1.0 * enemy->Health() / enemy->MaxHP()), 0x00));
		    healthBarUnderlay.setFillColor(sf::Color::Red);
			healthBarUnderlay.setPosition(healthBarPosition);
		    healthBarOverlay.setPosition(healthBarPosition);

		    renderWindow.draw(healthBarUnderlay);
		    renderWindow.draw(healthBarOverlay);
		}
	    } else {
		throw GameObjectRendererError("Unsupported gameobject type.");
	    }

	    // sf::Vector2f centerPosition =
	    // gameObject->getPosition().ToVector2f(); centerPosition.x += 1.0 *
	    // game.GetGrid().TileWidth() / 2; centerPosition.y += 1.0 *
	    // game.GetGrid().TileWidth() / 2;
	    // currentSprite.setPosition(centerPosition);
	    /* 2. Set the sprite position. */
	    //currentSprite.setPosition(gameObject->getPosition().ToVector2f());

		/*
		 * 3. Rotate the sprite according to the game object rotation.
		 */
		currentSprite.setRotation(gameObject->GetRotation());

		/*
		 * 4. Draw the sprite.
		 */
		renderWindow.draw(currentSprite);

		/* For tanks draw the cannon on top of them. */
		if (isOfType<Tank>(gameObject)) {
			sf::Sprite tankCannonSprite;
			if (isOfType<Tank1>(gameObject)) {
				tankCannonSprite.setTexture(textureManager.GetTexture(enemyToTileIDMapping.at(EnemyType::Tank1Cannon)));
			}
			else if (isOfType<Tank2>(gameObject)) {
				tankCannonSprite.setTexture(textureManager.GetTexture(enemyToTileIDMapping.at(EnemyType::Tank2Cannon)));
			}
			else {
				throw std::runtime_error("Unknown tank type.");
			}
			
			tankCannonSprite.setRotation(gameObject->GetRotation());
			tankCannonSprite.setOrigin(35, 35);
			tankCannonSprite.setPosition(currentSprite.getPosition());
			renderWindow.draw(tankCannonSprite);
		}

    }
}

void GameObjectRenderer::Draw() {
    renderGameObjects(renderWindow_, game_);
    // TODO: Animation rendering here. 1. filter by animation type. 2. render them.
}

