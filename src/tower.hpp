#pragma once

#include "enemy.hpp"
#include <cmath>
#include <vector>


// TODO: Implement methods
class Tower {
private:
    int radius_;
	/* Current rotation (in degrees) angle of the artillery. */
	/* This is needed for the sprite rotation. */
	/* For further information, see SFML documentation for method sf::Transformable::rotate. */
	/* Should be always within the range [0, 360). */
	float artilleryAngleDegrees_;
    // int fireRate(game ticks);
public:
    
    /**
     * @brief Construct a new Tower object.
     * 
     * @param radius the radius of damage caused by projectile (int)
    */
    explicit Tower(int radius) : radius_(radius), artilleryAngleDegrees_(0) {};


    /**
     * @brief Destroy the Tower object.
     */
    virtual ~Tower() {};

	/* Comment: Shouldn't this belong to Game / Level class? This doesn't seem to be Tower's responsibility. */
    const std::vector<Enemy> getEnemiesWithinRadius();
    
	void RotateArtillery(float degree) { artilleryAngleDegrees_ = std::fmod(artilleryAngleDegrees_ + degree, 360); }
	float ArtilleryAngle() { return artilleryAngleDegrees_; }
	void SetArtilleryAngle(float degree) { artilleryAngleDegrees_ = std::fmod(degree, 360.0);}

	virtual void update() = 0;
    virtual void fire() = 0;
    //virtual bool takeDamage() = 0;
    virtual void onDestroy() = 0;
    //int fireIntervalCounter() const;
    virtual void sell() = 0;

};
