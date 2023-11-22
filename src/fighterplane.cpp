#include "fighterplane.hpp"

void FighterPlane::fire() {

};

void FighterPlane::onDestroy() {
    this->~FighterPlane();
};

void FighterPlane::update() {

};

int FighterPlane::sell() {
    int p = this->price_;
    this->addPlayerMoney(p);
    this->onDestroy();
    return p;
};
