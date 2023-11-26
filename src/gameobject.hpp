#pragma once

#include <SFML/Graphics.hpp>

#include "pos.hpp"
#include "game.hpp"

class GameObject {
public:
    GameObject(sf::Sprite sprite, Game& game, Pos position, int health = 2) 
        :   health_(health), sprite_(sprite), game_(game), position_(position) {};

    sf::Sprite GetSprite() const;

    Pos getPosition() const {
        return position_;
    }

    void takeDamage(int damage) {
        this->health_ -= damage;
    }

    // virtual void update() = 0;
    // virtual void onDestroy() = 0;

protected:
    int health_;
    sf::Sprite sprite_;
    Game game_;
    Pos position_;
    void addPlayerMoney(int money) {
        game_.playerMoney_ += money;
    }

    void removePlayerMoney(int money) {
        game_.playerMoney_ -= money;
    }

    void addEnemyMoney(int money) {
        game_.enemyMoney_ += money;
    }
    
    void removeEnemyMoney(int money) {
        game_.enemyMoney_ -= money;
    }

    GameGrid& getGrid() {
        return game_.grid_;
    }

    std::vector<GameObject>& getObjects() {
        return game_.objects_; 
    }
};
