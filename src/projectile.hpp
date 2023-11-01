#pragma once

class Projectile {
private:
    int travel_speed_;
    int damage_;
    int radius_;

public:

    /**
     * @brief Construct a new Projectile object.
     * 
     * @param travel_speed the speed of projectile (int)
     * @param damage damage caused by projectile (int)
     * @param radius radius of damage (int)
    */
    explicit Projectile(int travel_speed, int damage, int radius)
            : travel_speed_(travel_speed), damage_(damage), radius_(radius) {};
    
    int travel_speed() const {
        return travel_speed_;
    }

    int damage() const {
        return damage_;
    }

    int radius() {
        return radius_;
    }
    
    /**
     * @brief destroy Projectile object.
     **/
    virtual ~Projectile() {};
    
    /**
     * @brief updates all the objects in the game that are affected by projectile.
    */
    virtual void update() = 0;
};

