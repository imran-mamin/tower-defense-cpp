#pragma once

#include <SFML/Graphics.hpp>

#include "pos.hpp"
#include "game.hpp"

class GameObject {
public:
    GameObject(sf::Sprite sprite, Game& game, int health = 0) 
        :   sprite_(sprite), health_(health), game_(game) {};

protected:
    sf::Sprite sprite_;
    int health_;
    Game& game_;
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

    GameGrid getGrid() {
        return game_.grid_;
    }

    std::vector<GameObject> getObjects() {
        return game_.objects_;   
    }
};
