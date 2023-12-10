#pragma once
#include <assert.h>

#include "gameobject.hpp"

class Enemy : public GameObject {
 protected:
  double speed_;
  int value_;
  int maxHP_;
  int travelDistance_ = 0;

 public:
  explicit Enemy(int speed, int value, int maxHP, Game* game, Pos position)
      : GameObject(game, position, maxHP),
        speed_(speed),
        value_(value),
        maxHP_(maxHP){};

  virtual ~Enemy(){};

  void update();

  int Value() const { return value_; }
  int MaxHP() const { return maxHP_; }
  int TravelDistance() const { return travelDistance_; }
  void Travel(const int distance) { travelDistance_ += distance; }

  int GetSpeed() const;
  bool isAlive() const;
};
