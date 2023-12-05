#pragma once

#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "pos.hpp"

class GameObject {
   public:
    GameObject(Game& game, Pos position, int health = 2)
	: health_(health), game_(game), position_(position){};

    Pos getPosition() const { return position_; }

    void takeDamage(int damage) {
		if (damage > health_) {
	    	health_ = 0;
		}
		else {
	    	health_ -= damage;
		}
    }

	template <typename T>
	bool isOfType() {
		return dynamic_cast<T>(this);
	}

    virtual void update() = 0;
    virtual void onDestroy() = 0;
    virtual ~GameObject(){};

    float GetRotation() const { return rotationAngleDeg_; }
    void RotateArtillery(float degree) {
		rotationAngleDeg_ = std::fmod(rotationAngleDeg_ + degree, 360);
    }
    void SetArtilleryAngle(float degree) {
		rotationAngleDeg_ = std::fmod(degree, 360.0);
    }

   protected:
    int health_;
    Game& game_;
    Pos position_;

    /* Current rotation (in degrees) angle of the GameObject-instance. */
    /* This is needed for the sprite rotation. */
    /* For further information, see SFML documentation for method
     * sf::Transformable::rotate. */
    /* Should be always within the range [0, 360). */
    float rotationAngleDeg_ = 0;

    void addPlayerMoney(int money) { game_.playerMoney_ += money; }

    void removePlayerMoney(int money) { game_.playerMoney_ -= money; }

    void addEnemyMoney(int money) { game_.enemyMoney_ += money; }

    void removeEnemyMoney(int money) { game_.enemyMoney_ -= money; }

    GameGrid& getGrid() { return game_.grid_; }
};
