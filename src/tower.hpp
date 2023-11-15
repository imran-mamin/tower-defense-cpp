#pragma once

#include "enemy.hpp"
#include <vector>

// TODO: Implement methods
class Tower {
private:
    int radius_;
    // int fireRate(game ticks);
public:
    
    /**
     * @brief Construct a new Tower object.
     * 
     * @param radius the radius of damage caused by projectile (int)
    */
    explicit Tower(int radius) : radius_(radius) {};
    
    const std::vector<Enemy> getEnemiesWithinRadius();
    
    /**
     * @brief Destroy the Tower object.
     */
    virtual ~Tower() {};

    virtual void update() = 0;
    virtual void fire() = 0;
    //virtual bool takeDamage() = 0;
    virtual void onDestroy() = 0;
    //int fireIntervalCounter() const;
    virtual void sell() = 0;

};
