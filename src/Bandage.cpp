#include "Bandage.h"

Bandage::Bandage(const std::string& name) : Item(name){
    this->healAmount = 10;
    this->used = false;
}

bool Bandage::isUsed() const {
    return this->used;
}

void Bandage::use(Entity& target) {
    if (target.getHp() < 100) {
        target.heal(this->healAmount);
        this->used = true;
    }
}