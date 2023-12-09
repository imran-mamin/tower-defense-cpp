
#include "footsoldier.hpp"
#include "cannon.hpp"
#include "gameobject.hpp"
#include "gameobject_renderer.hpp"
#include "game.hpp"
#include "missilelauncher.hpp"
#include "tank.hpp"
#include "attackplane.hpp"
#include "texture_manager.hpp"
#include "weapons_and_enemies.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <stdexcept>
#include <type_traits>
#include <typeinfo>
#include <vector>

template <typename T>
bool isOfType(const GameObject *g) {
	return dynamic_cast<const T*>(g);
}

/* Helper to render a vector of gameobjects. */
void renderGameObjects(sf::RenderWindow &renderWindow, const std::vector<GameObject *> &gameObjects) {
	TextureManager &textureManager = TextureManager::GetInstance();

	//for (const std::unique_ptr<GameObject> &gameObject : gameObjects) {
	for (const auto &gameObject : gameObjects) {
		sf::Sprite currentSprite;

		/*
		 * 1. Get the correct texture and create the sprite based on it.
		 */

		/* Note: C++17 allows to assignment inside if statement (visible in the block scope only). */
		//if (dynamic_cast<const std::unique_ptr<Cannon> &>(gameObject)) {
		if (isOfType<Cannon>(gameObject)) {
			if (isOfType<GreenCannon>(gameObject)) {
				currentSprite.setTexture(textureManager.GetTexture(weaponToTileIDMapping.at(WeaponType::GreenCannon)));
			}
			else if (isOfType<RedCannon>(gameObject)) {
				currentSprite.setTexture(textureManager.GetTexture(weaponToTileIDMapping.at(WeaponType::RedCannon)));
			}
			else {
				throw std::runtime_error("Unknown cannon type.");
			}
		}
		else if (isOfType<MissileLauncher>(gameObject)) {
			if (isOfType<BasicMissileLauncher>(gameObject)) {
				currentSprite.setTexture(textureManager.GetTexture(weaponToTileIDMapping.at(WeaponType::MissileLauncher1)));
			}
			else {
				throw std::runtime_error("Unknown missile launcher type.");
			}
		}
		else if (isOfType<FootSoldier>(gameObject)) {
			if (isOfType<Soldier1>(gameObject)) {
				currentSprite.setTexture(textureManager.GetTexture(enemyToTileIDMapping.at(EnemyType::Soldier1)));
			}
			else if (isOfType<Soldier2>(gameObject)) {
				currentSprite.setTexture(textureManager.GetTexture(enemyToTileIDMapping.at(EnemyType::Soldier2)));
			}
			if (isOfType<Soldier3>(gameObject)) {
				currentSprite.setTexture(textureManager.GetTexture(enemyToTileIDMapping.at(EnemyType::Soldier3)));
			}
			else if (isOfType<Soldier4>(gameObject)) {
				currentSprite.setTexture(textureManager.GetTexture(enemyToTileIDMapping.at(EnemyType::Soldier4)));
			}
			else {
				throw std::runtime_error("Unknown soldier type.");
			}
		}
		else if (isOfType<Tank>(gameObject)) {
			if (isOfType<Tank1>(gameObject)) {
				currentSprite.setTexture(textureManager.GetTexture(enemyToTileIDMapping.at(EnemyType::Tank1)));
			}
			else if (isOfType<Tank2>(gameObject)) {
				currentSprite.setTexture(textureManager.GetTexture(enemyToTileIDMapping.at(EnemyType::Tank2)));
			}
			else {
				throw std::runtime_error("Unknown tank type.");
			}
		}
		else if (isOfType<AttackPlane>(gameObject)) {
			if (isOfType<Plane1>(gameObject)) {
				currentSprite.setTexture(textureManager.GetTexture(enemyToTileIDMapping.at(EnemyType::Plane1)));
			}
			else if (isOfType<Plane2>(gameObject)) {
				currentSprite.setTexture(textureManager.GetTexture(enemyToTileIDMapping.at(EnemyType::Plane2)));
			}
			else {
				throw std::runtime_error("Unknown tank type.");
			}
		}
		else {
			throw GameObjectRendererError("Unsupported gameobject type.");
		}

		/*
		 * 2. Set the sprite position and rotate it according to the game object rotation.
		 */
		currentSprite.setOrigin(sf::Vector2f{ 32, 32 });
		currentSprite.setPosition(gameObject->getPosition().ToVector2f());
		currentSprite.setRotation(gameObject->GetRotation());

		/*
		 * 3. Draw the sprite.
		 */
		renderWindow.draw(currentSprite);
	}


}

void GameObjectRenderer::Draw() {
	renderGameObjects(renderWindow_, game_.Objects());
	// TODO: Animation rendering here. 1. filter by animation type. 2. render them.
}

