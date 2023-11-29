#pragma once

#include <cmath>
#include <vector>
#include <cmath>

#include "enemy.hpp"
#include "gameobject.hpp"

// TODO: Implement methods
class Tower: public GameObject {
private:
    int radius_;
	/* Current rotation (in degrees) angle of the artillery. */
	/* This is needed for the sprite rotation. */
	/* For further information, see SFML documentation for method sf::Transformable::rotate. */
	/* Should be always within the range [0, 360). */
	float artilleryAngleDegrees_;
protected:
    int fireRate_; // game ticks
    int fireIntervalCounter_; // goes from fireRate to 0. Tells when fire()-method is executed.
    int price_;

public:
    /**
     * @brief Construct a new Tower object.
     * 
     * @param radius the radius of damage caused by projectile (int)
    */

    explicit Tower(int radius, int fireRate, int price, sf::Sprite sprite, Game& game, Pos position)
            : GameObject(sprite, game, position), radius_(radius), fireRate_(fireRate), fireIntervalCounter_(fireRate), price_(price), artilleryAngleDegrees_(0) {};

    /**
     * @brief Returns all the enemies within the given radius (tower radius).
     * Does not take any parameters.
    */

    const std::vector<Enemy*> getEnemiesWithinRadius();
    
   /**
     * @brief Destructor of Tower object.
     */
    virtual ~Tower() = 0;

	/* Comment: Shouldn't this belong to Game / Level class? This doesn't seem to be Tower's responsibility. */
    const std::vector<Enemy> getEnemiesWithinRadius();
    
	void RotateArtillery(float degree) { artilleryAngleDegrees_ = std::fmod(artilleryAngleDegrees_ + degree, 360); }
	float ArtilleryAngle() { return artilleryAngleDegrees_; }
	void SetArtilleryAngle(float degree) { artilleryAngleDegrees_ = std::fmod(degree, 360.0);}

	virtual void update() = 0;
    virtual void fire() = 0;
    // virtual bool takeDamage() = 0;
    virtual void onDestroy() = 0;
    virtual int sell() = 0;

};
