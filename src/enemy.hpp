#pragma once

// TODO: Implement methods
class Enemy {
private:
    int speed_;
    int value_;
    int price_;
    int maxHP_;
public:
    explicit Enemy(int speed, int value, int price, int maxHP)
            : speed_(speed), value_(value), price_(price), maxHP_(maxHP) {};
    
    virtual ~Enemy() {};

    bool isAlive() const;
};
