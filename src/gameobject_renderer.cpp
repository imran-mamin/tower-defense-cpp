
#include "footsoldier.hpp"
#include "cannon.hpp"
#include "gameobject.hpp"
#include "gameobject_renderer.hpp"
#include "game.hpp"
#include "tank.hpp"
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
				currentSprite.setTexture(textureManager.GetTexture(weaponToTileIDMapping.at(Weapons::GreenCannon)));
			}
			else if (isOfType<RedCannon>(gameObject)) {
				currentSprite.setTexture(textureManager.GetTexture(weaponToTileIDMapping.at(Weapons::RedCannon)));
			}
			else {
				throw std::runtime_error("Unknown cannon type.");
			}
		}
		else if (isOfType<FootSoldier>(gameObject)) {
			// FIXME: Select correct footsoldier texture. Currently does not differentiate between the four of them.
			sf::Texture &currentTexture = textureManager.GetTexture(enemyToTileIDMapping.at(Enemies::Soldier1));
			currentSprite.setTexture(currentTexture);
		}
		else if (isOfType<Tank>(gameObject)) {
			// FIXME: Select correct tank texture. Currently does not differentiate between Tank1 and Tank2.
			sf::Texture &currentTexture = textureManager.GetTexture(enemyToTileIDMapping.at(Enemies::Tank1));
			currentSprite.setTexture(currentTexture);
		}
		// TODO: Enemy plane.
		//else if (dynamic_cast<const >()) {
		//
		//}
		else {
			throw GameObjectRendererError("Unsupported gameobject type.");
		}

		/*
		 * 2. Set the sprite position and rotate it according to the game object rotation.
		 */
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

